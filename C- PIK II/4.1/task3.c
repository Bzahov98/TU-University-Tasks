#include <stdio.h>
int main(){
  int N,M,average = 0;
  scanf("%d\n", &N);
  scanf("%d\n", &M);
  int array[N][M];

  for (size_t x = 0; x < M; x++) {
    for (size_t y = 0; y < N; y++) {
      scanf("%d\n", &array[x][y]);
    }
  }

  printf("\n" );
  for (size_t x = 0; x < M; x++) {
    for (size_t y = 0; y < N; y++) {
      printf("%d ", array[x][y]);
    }
    printf("\n" );
  }

  for (size_t x = 0; x < M; x++) {
    for (size_t y = 0; y < N; y++) {
      if (x%2 == 0) {
        array[x][y] *= 7;
      }else{
        array[x][y] /= 3;
      }
      average += array[x][y];
    }
  }
  average /= M * N;
  //printf("Average: %d\n", average);

  printf("\n" );
  for (size_t x = 0; x < M; x++) {
    for (size_t y = 0; y < N; y++) {
      printf("%d ", array[x][y]);
    }
    printf("\n");
  }
int count;
  for (int i = 0; i < count; i++) {
    if (array[i][i] >= average) {
      count++;
    }
  }
  printf("Average count:%d\n", count);
  return 0;
}
