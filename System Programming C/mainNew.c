// DISCLAIMER: These files are only for studying and teaching purposes!
// They are not intendet to be a direct example of good coding practices
// or C expert usage.
//

/*
    Copyright 2019 Desislav Andreev: desislav.andreev@gmail.com
    Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"),
    to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute,
    sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:
    The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.
    THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHAN    ILITY,
    FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,
    DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
    ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/

#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>

/* Define valid parameters */
#define TITLE_STRING   "title"
#define ARTIST_STRING  "artist"
#define ALBUM_STRING   "album"
#define YEAR_STRING    "year"

/* Define basic sizes */
#define NMR_METADATA_FIELDS ((size_t) 5)
#define METADATA_SIZE       NMR_METADATA_FIELDS * (size_t) eMaxSize
#define FIFO_NAME           "metadata_fifo"
#define RESPONSE_LEN        ((size_t) 30)

typedef enum Sizes
{
    TAG_SIZE    = 3,
    YEAR_SIZE   = 4,
    ARTIST_SIZE = 30,
    TITLE_SIZE  = 30,
    ALBUM_SIZE  = 30,
    eMaxSize    = 31
} eSizes;

typedef enum Offsets
{
    TAG_OFFSET    = -128,
    YEAR_OFFSET   = -35,
    TITLE_OFFSET  = -125,
    ARTIST_OFFSET = -95,
    ALBUM_OFFSET  = -65,
    eMaxOffset    = 0
} eOffsets;

typedef enum Response
{
    NOT_REQUIRED = 0,
    REQUIRED     = 1
} eResponses;

typedef struct Message
{
    eResponses flag;
    size_t     expected_msg_count;
    char       msg_buf[eMaxSize];
} sPackage;

typedef struct ThreadArg
{
    int* pipe1;
    int* pipe2;
    char** argv;
    int argc
} ThreadArg;

/* Define function prototypes */
char *getTitle(const int);
char *getArtist(const int);
char *getAlbum(const int);
char *getYear(const int);

/* Define arrays in the Data segment */
static char buffer[eMaxSize]          = {0};
static char mp3_data[METADATA_SIZE]   = {0};
static char response_buf[RESPONSE_LEN] = {0};
static const char response_msg[]      = "!Response successful!";

/* TODO: Split to additional functions */

// define thread methods
void* thread1(void* args);
void* thread2(void* args);
// end

sem_t mutex;

int main2(int argc,char **argv){

    mqd_t mq;
    struct mq_attr attr;
    char buffer[MAX_SIZE + 1];
    int must_stop = 0;

    /* initialize the queue attributes */
    attr.mq_flags = 0;
    attr.mq_maxmsg = 10;
    attr.mq_msgsize = MAX_SIZE;
    attr.mq_curmsgs = 0;

    /* create the message queue */
    mq = mq_open(QUEUE_NAME, O_CREAT | O_RDONLY, 0644, &attr);
    if((mqd_t)-1 != mq){
        pthread_t tid1;
        pthread_t tid2;
        pthread_create(&tid1, NULL, thread1, (void *) &arg);
        pthread_create(&tid2, NULL, thread2, (void *) &arg);
        pthread_join(tid1, NULL);
        pthread_join(tid2, NULL);

    }

    return 0;
}




int main(int argc, char **argv) //Must remain int
{

    int named_pipe_fd = 0;

    sem_init(&mutex, 0, 1);

    /* Create the FIFO (named pipe) - it will be executed
    for child and parent - the first one, who executes this
    code will create it. The second one will fail, but this
    is not an issue, because it's already in the file system.
    */
    // (void) mkfifo(FIFO_NAME, 0666);

    int pipe1[2];
    int pipe2[2];

    int r1 = pipe(pipe1);
    int r2 = pipe(pipe2);

    struct ThreadArg arg = {
            pipe1,
            pipe2,
            argv,
            argc
    };
    if (argc >= 1){
        pthread_t tid1;
        pthread_t tid2;
        pthread_create(&tid1, NULL, thread1, (void *) &arg);
        pthread_create(&tid2, NULL, thread2, (void *) &arg);
        pthread_join(tid1, NULL);
        pthread_join(tid2, NULL);
    }

    /* Why do we do that? */
    // (void) unlink(FIFO_NAME);

    return 0;
}

/* TODO: Check funtions' returned values. */
char *getTitle(const int fd_param)
{
    // Get the offset char.
    (void) lseek(fd_param, TITLE_OFFSET, SEEK_END);

    // Read the data and put into buffer.
    (void) read(fd_param, buffer, sizeof(char) * TITLE_SIZE);

    // Remove the white-space characters.
    (void) strtok(buffer, " ");

    return buffer;
}

char *getArtist(const int fd_param)
{
    // Get the offset char.
    (void) lseek(fd_param, ARTIST_OFFSET, SEEK_END);

    // Read the data and put into buffer.
    (void) read(fd_param, buffer, sizeof(char) * ARTIST_SIZE);

    // Remove the white-space characters.
    (void) strtok(buffer, " ");

    return buffer;
}

char *getAlbum(const int fd_param)
{
    // Get the offset char.
    (void) lseek(fd_param, ALBUM_OFFSET, SEEK_END);

    // Read the data and put into buffer.
    (void) read(fd_param, buffer, sizeof(char) * ALBUM_SIZE);

    // Remove the white-space characters.
    (void) strtok(buffer, " ");

    return buffer;
}

char *getYear(const int fd_param)
{
    // Get the offset char.
    (void) lseek(fd_param, YEAR_OFFSET, SEEK_END);

    // Read the data and put into buffer.
    (void) read(fd_param, buffer, sizeof(char) * YEAR_SIZE);

    // Remove the white-space characters.
    (void) strtok(buffer, " ");

    return buffer;
}

void *thread1(void* args)  {
    /* Initialize the message var */
    sPackage message = {0};
    int* pipe1;
    pipe1 =  ((struct ThreadArg*) args)->pipe1;
    int* pipe2;
    pipe2 = ((struct ThreadArg*) args)->pipe2;

    /* Creates a named pipe */
    // named_pipe_fd = open(FIFO_NAME, O_RDWR);

    {
        // sleep(1);
        size_t iterator = 0;

        // Should be endless loop!
        for(;;)
        {
            size_t bytes_recv = read(pipe1[0], &message, sizeof(message));

            sem_wait(&mutex);

            if(bytes_recv > 0)
            {
                if(message.expected_msg_count > 0)
                {
                    (void) strcat(mp3_data, " ");
                    (void) strcat(mp3_data, message.msg_buf);
                }
                else
                {
                    (void) printf("Child received: %s in pid = %d\n", mp3_data, pthread_self());

                    if (REQUIRED == message.flag)
                    {
                        /* TODO: Check read's output */
                        (void) write(pipe2[1], response_msg, sizeof(response_msg));

                        // Disables the child's pipe end;
                        // (void) close(pipe);
                        break;
                    }

                    // We don't expect any more messages.
                    // We use this as a condition to exit the child process.
                    break;
                }
            }
            else
            {
                // Do nothing.
            }
        }
    }
}

void* thread2(void* args){

    int* pipe1;
    pipe1 =  ((struct ThreadArg*) args)->pipe1;
    int* pipe2;
    pipe2 = ((struct ThreadArg*) args)->pipe2;
    char** argv = ((struct ThreadArg*) args)->argv;
    int argc = ((struct ThreadArg*) args)->argc;

    int fd = open(argv[1], O_RDONLY);


    if (0 <= fd)
    {
        size_t iterator  = 0;
        // named_pipe_fd    = open(FIFO_NAME, O_RDWR);
        sPackage message = {0};

        for (iterator = 2; iterator < argc; iterator++)
        {
            // If input parameters for the metadata are provided:
            sem_wait(&mutex);

            if (strcmp(argv[iterator], TITLE_STRING) == 0)
            {
                (void) strncpy(message.msg_buf, getTitle(fd), TITLE_SIZE);
            }
            else if (strcmp(argv[iterator], ARTIST_STRING) == 0)
            {
                (void) strncpy(message.msg_buf, getArtist(fd), ARTIST_SIZE);
            }
            else if (strcmp(argv[iterator], ALBUM_STRING) == 0)
            {
                (void) strncpy(message.msg_buf, getAlbum(fd), ALBUM_SIZE);
            }
            else if (strcmp(argv[iterator], YEAR_STRING) == 0)
            {
                (void) strncpy(message.msg_buf, getYear(fd), YEAR_SIZE);
            }
            else
            {
                (void) printf("Parameter %d is unknown\n", (int)iterator);
            }

            /* Send the content. */
            /* TODO: Check the returned value. */
            message.flag = NOT_REQUIRED;

            // Ignoring the first two cmd arguments;
            message.expected_msg_count = argc-1;

            sem_post(&mutex);

            // Reinitialize the message to 0.
            memset(&message, 0, sizeof(message));

            // Makes sure duplex communication appears on different systems.
            // sleep(1);
        }

        message.flag = REQUIRED;
        message.expected_msg_count = 0;
        (void) write(pipe1[1], &message, sizeof(message));
        memset(message.msg_buf, 0, sizeof(eMaxSize));

        /* Receive the final response. */
        /* TODO: Check the returned value. */
        (void) read(pipe2[0], response_buf, sizeof(response_buf));

        // sleep(1);
        (void) printf("Response in parent: %s in pid = %d\n", response_buf, pthread_self());

        /* TODO: Check the returned value. */
        (void) close(fd);
        // (void) close(named_pipe_fd);
    }
}