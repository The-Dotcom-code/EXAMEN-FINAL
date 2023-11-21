#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void quicksort(int arr[], int primero, int ultimo) {
  int pivot, i, j;
  if (primero < ultimo) {
    pivot = primero;
    i = primero;
    j = ultimo;
    
    while (i < j) {
      while (arr[i] <= arr[pivot] && i <= ultimo) {
        i++;
      }
      while (arr[j] > arr[pivot] && j >= primero) {
        j--;
      }
      if (i < j) {
        swap(&arr[i], &arr[j]);
      }
    }
    
    swap(&arr[j], &arr[pivot]);
    pivot = j;
    quicksort(arr, primero, pivot - 1);
    quicksort(arr, pivot + 1, ultimo);
  }
}

void insertsort(int arr[], int n) {
  int i, posant = 0, posact = 0;
  for (i=0; i<n; i++) {
    posact=arr[i];
    posant=i-1;
    while (posant>=0 && arr[posant]>posact) {
      arr[posant+1] = arr[posant];
      posant--;
    }
    arr[posant+1] = posact;
  }
}

void bubbleSort(int arr[], int n) {
  int i, j;
  for (i=0; i<n-1; i++) {
    for (j=0; j<n-i-1; j++) {
      if (arr[j] > arr[j + 1]) {
        swap(&arr[j], &arr[j + 1]);
      }
    }
  }
}

float prom(float arr[], int n){
  float sum = 0;
  int i;
  for (i = 0; i < n; i++){
    sum += arr[i];
  }
  return sum / n;
}

int max(float arr[], int n) {
  int i, index=0;
  float a=-10000;
  for(i=0; i<n; i++) {
    if(arr[i] > a) {
      index=i;
      a=arr[i];
    }
  }
  return index;
}

int min(float arr[], int n) {
  int i, index=0;
  float a=10000;
  for(i=0; i<n; i++) {
    if(arr[i] < a) {
      index=i;
      a=arr[i];
    }
  }
  return index;
}

int main() {
  int i,j,k,n;
  int arr[10000], cop[10000];
  float t1[10000], t2[10000], t3[10000],cont;
  
  srand(time(NULL));

  for(i=0;i<10000;i++){
    arr[i]=rand()%10000;
    cop[i]=arr[i];
  }

  for(i=0;i<=100;i++){
    clock_t tic=clock();
    quicksort(arr,0,10000);
    clock_t toc=clock();
    cont = ((double)(toc-tic)/CLOCKS_PER_SEC);
    t1[i]= cont;
    
    for(j=0;j<10000;j++){
      arr[j]=cop[j];
    }

    clock_t tic2=clock();
    insertsort(arr,10000);
    clock_t toc2=clock();
    cont = ((double)(toc2-tic2)/CLOCKS_PER_SEC);
    t2[i]= cont;

    for(j=0;j<10000;j++){
      arr[j]=cop[j];
    }

    clock_t tic3=clock();
    bubbleSort(arr,10000);
    clock_t toc3=clock();
    cont = ((double)(toc3-tic3)/CLOCKS_PER_SEC);
    t3[i]= cont;

    for(j=0;j<10000;j++){
      arr[j]=cop[j];
    }
    
  }
  printf("Promedio del tiempo de ejecucion de quicksort: %f\n", prom(t1, 100));
  printf("Tiempo Max de quicksort: %f\n", t1[max(t1,100)]);
  printf("Tiempo min de quicksort: %f\n", t1[min(t1,100)]);
  printf("\n");

  printf("Promedio del tiempo de ejecucion de insertsort: %f\n", prom(t2, 100));
  printf("Tiempo Max de insertsort: %f\n", t2[max(t2,100)]);
  printf("Tiempo min de insertsort: %f\n", t2[min(t2,100)]);
  printf("\n");

  printf("Promedio del tiempo de ejecucion de bubblesort: %f\n", prom(t3, 100));
  printf("Tiempo Max de bubblesort: %f\n", t3[max(t3,100)]);
  printf("Tiempo min de bubblesort: %f\n", t3[min(t3,100)]);
  printf("\n");
  
  return 0;
}