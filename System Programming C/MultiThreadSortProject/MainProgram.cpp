#include<iostream>

// For process
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/param.h>
#include <fstream>
#include <vector>
#include <thread>
#include <algorithm>
#include <list>

#include "Algorithms/ParallelMergeSort/MergeSort.h"
#include "Utils/FileUtils.h"
#include "Algorithms/ParallelQuickSort/ParralellQuickSort.h"


//
// Created by bzahov on 24.05.20 г..
//
const int ALL_CHILD_PROCESSES = 2;
const int PIPE_WRITE = 1;
const int PIPE_READ = 0;
const int EXIT_SUCCESSFULLY_MERGED_SORT_FIRST = 25;
const int EXIT_SUCCESSFULLY_QUICK_SORT_FIRST = 52;
const int EXIT_TASK_ALREADY_DONE = 99;

using namespace std;

void quickSortAlgorithmProcess(int data[MergeSort::MAX]);

void mergeSortAlgorithmProcess(int data[MergeSort::MAX]);

void handle_sigint(int sig) {
    printf("Caught signal %d\n", sig);
}

static void terminationHandler(int signo) {
    cout << endl << "Terminate process with sigNo: " << signo;
}

static void killHandler(int signo) {
    cout << endl << "Kill process with sigNo: " << signo;
}

int main() {
    pid_t child_a, child_b;


    // The descriptors will be available to both parent and child.
    int out_fd[2];// child B pipe

    if (pipe(out_fd) == -1) { // Open pipe for communication
        cerr<<"Pipe Out Failed"<< endl;
        return 1;
    }

    if ((child_a = fork()) < 0) { // create first child process
        cerr<<"Fork of first child process Failed" << endl;
        return 1;
    }
    if (child_a == 0) {
        /* Child A code */

        signal(SIGTERM, terminationHandler);
        signal(SIGKILL, killHandler);
        //close(out_fd[PIPE_READ]);
        close(out_fd[PIPE_WRITE]);
        int receivedData[MergeSort::MAX];
        size_t readDataSize = sizeof(receivedData);
        if (read(out_fd[PIPE_READ], receivedData, readDataSize) <= 0) {
            cerr << "error with reading" << readDataSize << endl;
            exit(EXIT_FAILURE);
        } else {
            quickSortAlgorithmProcess(receivedData);
        }

    } else {
        if ((child_b = fork()) < 0) { // create second child process
            fprintf(stderr, "Fork of second child process Failed");
            return 1;
        }
        if (child_b == 0) {
            /* Child B code */
            signal(SIGTERM, terminationHandler);
            signal(SIGKILL, killHandler);
            //close(out_fd[PIPE_READ]); // child B will receive unsorted data from parent
            close(out_fd[PIPE_WRITE]);

            int receivedData[MergeSort::MAX];
            size_t readDataSize = sizeof(receivedData);
            if (read(out_fd[PIPE_READ], receivedData, readDataSize) <= 0) {
                cerr << "error with reading" << readDataSize << endl;
                exit(EXIT_FAILURE);
            } else {
                mergeSortAlgorithmProcess(receivedData);
            }
            mergeSortAlgorithmProcess(receivedData);
        } else {
            /* Parent Code */
            close(out_fd[PIPE_READ]); // parent will not read data
            // close(out_fd[PIPE_WRITE]);// parent will send unsorted data

            int data[MergeSort::MAX];

            FileUtils::readInputDataFromFile(FileUtils::INPUT_FILE_NAME, data);
            for (int i = 0; i < ALL_CHILD_PROCESSES; ++i) {
                if (write(out_fd[PIPE_WRITE], data, sizeof(data)) < 0){
                    cerr<< "No data was written to pipe"<<endl;
                    continue;
                }
            }
            close(out_fd[PIPE_WRITE]); // we will not write anymore

            cout << "Parent is waiting first child to finish, to terminate other" << endl;

            int childExitStatus;
            wait(&childExitStatus);
            if (WIFEXITED(childExitStatus)) { // WIFEXITED(status) : returns true if the child terminated normally.
                if (W_EXITCODE(childExitStatus, EXIT_SUCCESS)) {
                    if (WEXITSTATUS(childExitStatus) == EXIT_SUCCESSFULLY_MERGED_SORT_FIRST) {
                        printf("Exit status!: EXIT_SUCCESSFULLY_MERGED_SORT_FIRST(%d)\n", WEXITSTATUS(childExitStatus));
                        //The SIGTERM signal is sent to sortedData process to request its termination
                        // WEXITSTATUS(status) : returns the exit status of the child.
                        //This allows the process to perform nice termination releasing resources and saving state if appropriate?
                        kill(child_a, SIGKILL);
                        _exit(EXIT_SUCCESS);
                    } else if (WEXITSTATUS(childExitStatus) == EXIT_SUCCESSFULLY_QUICK_SORT_FIRST) {
                        printf("Exit status!!: EXIT_SUCCESSFULLY_QUICK_SORT_FIRST(%d)\n", WEXITSTATUS(childExitStatus));
                        kill(child_b, SIGKILL);
                        _exit(EXIT_SUCCESS);
                    }
                } else{
                    printf("Exit FAIL status>: %d\n", WEXITSTATUS(childExitStatus));
                    _exit(EXIT_FAILURE);
                }
            } else if (WIFSIGNALED(childExitStatus))
                psignal(WTERMSIG(childExitStatus), "Killed by signal"); //if we want to print information about sortedData signal
        }
    }
    return 0;
}


void quickSortAlgorithmProcess(int data[MergeSort::MAX]) {
    //sleep(10);
    cerr << "QUICK, CHILD A executing sort algorithm " << endl;
    /*for (int i = 0; i < MergeSort::MAX; ++i) {
        cout<<"("<< data[i]<< "),";
    }*/
    //sleep(10);
    ParallelQuickSort::initQuickSort(data);
    cerr << "Quick, CHILD A  finished sorting " << endl;
    //sleep(10);
    _exit(EXIT_SUCCESSFULLY_QUICK_SORT_FIRST);

}

void mergeSortAlgorithmProcess(int data[MergeSort::MAX]) {
   // sleep(10);
    cerr << endl<< "MERGE, CHILD B executing sort algorithm" << endl;
   /* for (int i = 0; i < MergeSort::MAX; ++i) {
        cout<<"["<< data[i]<< "],";
    }
    cout<< endl;*/

    //sleep(10);
    MergeSort mergeSort = MergeSort(data) ;
    mergeSort.initMergeSort();
    cerr <<endl<< "MERGE, CHILD B finished sorting" << endl;
    _exit(EXIT_SUCCESSFULLY_MERGED_SORT_FIRST);
}


