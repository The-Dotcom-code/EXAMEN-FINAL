#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void print_matrix(int p1[30][30]){
  int i,j;
  for(i=0; i<30;i++){
    for(j=0; j<30; j++){
      printf("%d ", p1[i][j]);
    }
    printf("\n");
  }
}

void mult(int p1[30][30],int p2[30][30]){
  int r1[30][30];
  int i,j,k,p=0;
  for(i=0; i<30;i++){
    for(j=0; j<30; j++){
      for(k=0; k<30; k++){
        p+=p1[i][k]*p2[k][j];
      }
      r1[i][j]=p;
      printf("%d ",r1[i][j]);
    }
    printf("\n");
  }
}

int main(void) {
  int i,j,n;
  srand(time(NULL));
  int p1[30][30], p2[30][30], r1[30][30];
  for(i=0; i<30; i++){
    for(j=0; j<30; j++){
      p1[i][j]=rand() % 10 ;
      p2[i][j]=rand() % 10 ;
    }
  }

  print_matrix(p1);
  printf("\n");
  print_matrix(p2);
  printf("\n");

  clock_t tic=clock();
  
  mult(p1,p2);
  
  clock_t toc=clock();
  
  printf("Tiempo en ejecutar: %f seconds\n", (double)(toc-tic)/CLOCKS_PER_SEC);
  
  return 0;
}