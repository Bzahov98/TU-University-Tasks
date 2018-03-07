#include<stdio.h>

int main(){
  int count,max = 0;

  scanf("%d\n", &count);
  int array[count];

  for (int i = 0; i < count; i++) {
    scanf("%d\n", &array[i]);
  }

  for (int j = 0; j < count; j++) {
    if(j>0){
      if (j%2 == 0) {
        printf(">> %d %d\n",array[j],j );
        array[j]*=3;
      }else{
          printf(">%d %d\n",array[j],j );
        array[j]+=array[j-1];
        if (max<array[j]) {
          max = array[j];
        }
      }
    }
  }
  printf("\n" );
  for (int s = 0; s < count; s++) {
    printf("%d\n", array[s]);
  }

  (max!=0)?printf("Max is: %d\n", max):printf("\n");;
  return 0;
}
