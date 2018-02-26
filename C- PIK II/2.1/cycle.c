#include<stdio.h>

int reversNumbers();
int reversNumbersPerc();

int main() {
  reversNumbers();
  return 0;
}

// 1 2 3 -> 3 2 1
int reversNumbers(int a, int b){
  for (int i = 3; i != 0; i--) {
    printf("%d\n", i);
  }
  return 0;
}
int reversNumbers();
