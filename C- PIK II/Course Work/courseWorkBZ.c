#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct {
  char ID[41];
  char receiver[41];
  char copyTo[41];
  char sender[41];
  char title[41];
  char content[151];
  char date[20];
} letter;

typedef struct Node {
  letter data;
  struct Node *next;
} node;

void loadFile(node **head);
void saveFile(node *head);
char *getFileName();
void addNode(node **head, letter data, int mode);
letter initLetter(node *head);
int getID(node *head, char *ID, int mode);
int isUnique(node *head, char *ID);
void getDate(char *date);
int validateDate(int day, int month, int year, int hour, int minute,
                 int second);
int leapYear(int year);
void printSpecificLetters(node *head);
void printLetterByID(node *head);
void deleteSpam(node **head);
void deleteNodeAtPoss(node **head, int poss);
void printNode(node *head);
void printData(letter data);
void deleteNode(node **head);

int menuMain() {
  int i;

  printf("> MAIN MENU**********************************\n");
  printf("*   1. LOAD FILE                            *\n");
  printf("*   2. SAVE FILE                            *\n");
  printf("*   3. ADD NEW LETTER                       *\n");
  printf("*   4. PRINT SPECIFIC LETTERS               *\n");
  printf("*   5. PRINT LETTER BY ID                   *\n");
  printf("*   6. DETELE SPAM                          *\n");
  printf("*   7. PRINT ALL DATA                       *\n");
  printf("*   0. EXIT                                 *\n");
  printf("*********************************************\n");
  do {
    printf("SELECT OPTION: ");
    fflush(stdin);
    scanf("%d", &i);
  } while (i < 0 || i > 7);

  return i;
}
int main() {
  node *head = NULL;

  while (1) {
    switch (menuMain()) {
    case 1:
      loadFile(&head);
      break;
    case 2:
      saveFile(head);
      break;
    case 3:
      addNode(&head, initLetter(head), 1);
      break;
    case 4:
      printSpecificLetters(head);
      break;
    case 5:
      printLetterByID(head);
      break;
    case 6:
      deleteSpam(&head);
      break;
    case 7:
      printNode(head);
      break;
    default:
      deleteNode(&head);
      return 0;
    }
  }
}
void loadFile(node **head) {
  FILE *fp;
  letter data;
  char *fileName;

  fileName = getFileName();

  if (!(fp = fopen(fileName, "rb"))) {
    printf("Error loading file!\a\n");
    free(fileName);
    return;
  }

  if (*head)
    deleteNode(head);

  while (1) {
    if (!fread(&data, sizeof(data), 1, fp))
      break;

    addNode(head, data, 2);
  }

  fclose(fp);

  if (!(*head))
    printf("No data loaded from \"%s\"\n", fileName);
  else
    printf("Info loaded successfully from \"%s\"\n", fileName);

  free(fileName);
}

void saveFile(node *head) {
  FILE *fp;
  char *fileName;

  if (!head) {
    printf("List is empty!\n");
    printf("Add some new letters first!\n");
    return;
  }

  fileName = getFileName();

  if (!(fp = fopen(fileName, "wb"))) {
    exit(1);
  }

  while (head) {
    if (fwrite(&head->data, sizeof(letter), 1, fp) != 1) {
      printf("Error occurred while writing on file\n");
      exit(1);
    }
    head = head->next;
  }

  fclose(fp);

  printf("Info saved successfully to \"%s\"\n", fileName);
  free(fileName);
}

char *getFileName() {
  char *fileName = (char *)malloc(51 * sizeof(char));

  fflush(stdin);
  do {
    printf("\nEnter file name: ");
    //gets(fileName);
    scanf("%s", fileName);
    fflush(stdin);
  } while (!strlen(fileName));

  if (!strchr(fileName, '.')) {
    strcat(fileName, ".dat");
  }

  return fileName;
}
void addNode(node **head, letter data, int mode) {
  node *temp = (node *)malloc(sizeof(node));
  node *temp2 = *head;

  temp->data = data;
  temp->next = NULL;

  if (!(*head)) {
    *head = temp;
    if (mode == 1)
      printf("First letter added successfully!\n");
    return;
  }

  while (temp2->next) {
    temp2 = temp2->next;
  }

  temp2->next = temp;
  if (mode == 1)
    printf("New letter added successfully!\n");
}
letter initLetter(node *head) {
  letter newLetter;

  getID(head, newLetter.ID, 1);
  fflush(stdin);
  do {
    printf("Enter receiver: ");
  //  gets(newLetter.receiver);
    scanf("%s", newLetter.receiver);
    //printf("(%s)\n",newLetter.receiver);
  } while (!strlen(newLetter.receiver));

  do {
    printf("Enter copy to: ");
    //gets(newLetter.copyTo);
    scanf("%s", newLetter.copyTo);
    fflush(stdin);
  } while (!strlen(newLetter.copyTo));

  do {
    printf("Enter sender: ");
    //gets(newLetter.sender);
    scanf("%s", newLetter.copyTo);
    //printf("(%s)\n",newLetter.copyTo );
    fflush(stdin);
  } while (strlen(newLetter.sender));

  do {
    printf("Enter title: ");
    //gets(newLetter.title);
    scanf("%s", newLetter.title);
    fflush(stdin);
  } while (!strlen(newLetter.title));

  do {
    printf("Enter content: ");
    //scanf("%150[0-9a-zA-Z ]", newLetter.content);
    scanf(" %[^\t\n]s",newLetter.content);
    //fgets(newLetter.content, 150, stdin);
    //fflush(stdin);
    //printf("(%s)\n", newLetter.content);
  } while (!strlen(newLetter.content));

  getDate(newLetter.date);

  return newLetter;
}

void getDate(char *date) {
  int year, month, day, hour, minute, second;
  int isValidDate;

  printf("Please add date and time info!\n");

  while (1) {
    //fflush(stdin);
    printf("Day: ");
    scanf("%d", &day);
    //printf("\n(%d)\n", day);
    printf("\nMonth: ");
    fflush(stdin);
    scanf("%d", &month);
    fflush(stdin);
    printf("\nYear: ");
    scanf("%d", &year);
    fflush(stdin);
    printf("Hours: ");
    scanf("%d", &hour);
    fflush(stdin);
    printf("Minutes: ");
    scanf("%d", &minute);
    fflush(stdin);
    printf("Seconds: ");
    scanf("%d", &second);
    fflush(stdin);

    isValidDate = validateDate(day, month, year, hour, minute, second);

    if (!isValidDate) {
      printf("Date is not valid!\n");
      //continue;
    } else {
      printf("Data is valid: day: %d  month: %d year: %d hour: %d minute: %d second: %d\n", \
      day, month, year, hour, minute, second );
      break;
    }
  }
  sprintf(date, "%d.%.2d.%.2d %.2d:%.2d:%.2d", \
          day, month, year, hour, minute,second);
}

int getID(node *head, char *ID, int mode) {
  while (1) {
    printf("\nEnter unique code: ");
    fflush(stdin);
    //gets(ID);
    scanf("%s", ID);
    if (!isUnique(head, ID)) {
      if (mode == 1) {
        printf("Code already exist!\n");
        continue;
      } else // mode == 2
        return 1;
    }
    break;
  }
  if (mode == 2)
    printf("Code not found!\n");
  return 0;
}
int isUnique(node *head, char *ID) {
  while (head) {
    if (!strcmp(ID, head->data.ID)) {
      return 0;
    }
    head = head->next;
  }
  return 1;
}
void printNode(node *head) {
  int i = 1;

  if (!head) {
    printf("List is empty!\n");
    return;
  }
  while (head) {
    printf("\nLetter %d", i);
    printData(head->data);
    i++;
    head = head->next;
  }
}
void printData(letter data) {
  printf("\nID:            %s", data.ID);
  printf("\nReceiver:      %s", data.receiver);
  printf("\nCopy to        %s", data.copyTo);
  printf("\nSender         %s", data.sender);
  printf("\nTitle:         %s", data.title);
  printf("\nContent:       %s", data.content);
  printf("\nDate:          %s\n", data.date);
}
void deleteNode(node **head) {
  node *temp;

  while (*head) {
    temp = *head;
    *head = (*head)->next;
    free(temp);
  }
}

int validateDate(int day, int month, int year, int hour, int minute,
                 int second) {
  int monLength[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

  if (month < 1 || month > 12 || day < 1 || year < 1900 || year > 2100 ||
      hour < 0 || hour > 24 || minute < 0 || minute > 60 || second < 0 ||
      second > 60)
    return 0;
  else if (month == 2) {
    if (leapYear(year)) {
      if (day > 29)
        return 0;
    } else if (day > 28)
      return 0;
  } else if (day > monLength[month])
    return 0;

  return 1;
}
int leapYear(int year) {
  if (!(year & 3) && ((year % 25) || !(year & 15)))
    return 1;
  else
    return 0;
}
void printSpecificLetters(node *head) {
  int i = 0;

  if (!head) {
    printf("List is empty!\n");
    return;
  }
  while (head) {
    printf("\nLetter %d", ++i);
    printf("\nID:            %s", head->data.ID);
    printf("\nSender         %s", head->data.sender);
    printf("\nTitle:         %s", head->data.title);
    printf("\nDate:          %s\n", head->data.date);
    head = head->next;
  }
}
void printLetterByID(node *head) {
  char ID[21] = {0};

  if (!head) {
    printf("List is empty!\n");
    return;
  }
  if (!getID(head, ID, 2)) {
    return;
  }
  while (head) {
    if (!strcmp(head->data.ID, ID)) {
      printData(head->data);
      return;
    }
    head = head->next;
  }
}
void deleteSpam(node **head) {
  int i, poss = 1;
  char *token, word[20], content[150];
  double flag = 0, count = 0, flag2 = 0;
  node *temp = *head;
  FILE *fp;

  if (!(fp = fopen("bad_words.txt", "r"))) {
    printf("Error opening file\n");
    return;
  }

  while (temp) {
    strcpy(content, temp->data.content);
    token = strtok(content, " ");
    while (token != NULL) {
      while (fscanf(fp, "%s", word) != EOF) {
        for (i = 0; i < strlen(word); i++) {
          word[i] = tolower(word[i]);
        }
        for (i = 0; i < strlen(token); i++) {
          token[i] = tolower(token[i]);
        }
          //printf("(1)%s - %s flag: %lf\n", word, token, flag);
        if (!strcmp(word, token))
          flag++;
          //printf("(2)(%s - %s flag: %lf)\n", word, token, flag);
      }
      rewind(fp);
      count++;
      token = strtok(NULL, " ");
    }
    if (flag / count > 0.2) {
      deleteNodeAtPoss(head, poss);
      poss--;
      flag2 = 1;
    }

    poss++;
    flag = 0;
    count = 0;
    temp = temp->next;
  }
  if (flag2)
    printf("All spam is deleted!\n");
  else
    printf("Not found spam!\n");
  fclose(fp);
}
void deleteNodeAtPoss(struct Node **head_ref, int position) {
  if (*head_ref == NULL)
    return;
  node *temp = *head_ref;
  if (position == 1) {
    *head_ref = temp->next;
    free(temp);
    return;
  }
  for (int i = 0; temp != NULL && i < position - 2; i++)
    temp = temp->next;
  if (temp == NULL || temp->next == NULL)
    return;
  node *next = temp->next->next;
  free(temp->next);
  temp->next = next;
}
