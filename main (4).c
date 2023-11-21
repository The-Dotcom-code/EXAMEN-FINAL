#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int secuencial(int arr[], int elemento, int num){
  int i;
  for(i=0; i<num; i++){
    if(arr[i]==elemento){
      return (i+1);
    }
  }
  return -1;
}

int binario(int arr[], int elemento, int num, int primero, int ultimo) {
  if (primero <= ultimo) {
    int mitad = (primero + ultimo) / 2;
    
    if (elemento == arr[mitad]) {
      return (mitad + 1);
    } else if (elemento < arr[mitad]) {
      return binario(arr, elemento, num, primero, mitad - 1);
    } 
    else {
      return binario(arr, elemento, num, mitad + 1, ultimo);
    }
  }
  return -1; 
}

////////

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
/////

int main() {
  int arr[50000];
  float t1[100], t2[100], cont=0;
  int i, num, elemento;

  for(i=0; i<50000; i++){
    arr[i] = i;
  }

  for(i=0; i<=100; i++){
    elemento = rand()%50000;
    clock_t tic=clock();
    binario(arr,elemento,50000,0,50000);
    clock_t toc=clock();
    cont = ((double)(toc-tic)/CLOCKS_PER_SEC);
    t1[i]= cont;
    
    clock_t ticc=clock();
    secuencial(arr, elemento, 50000);
    clock_t tocc=clock();
    cont = ((double)(tocc-ticc)/CLOCKS_PER_SEC);
    t2[i]= cont;
  }

  printf("Promedio del tiempo de ejecucion de binario: %f\n", prom(t1, 100));
  printf("Tiempo Max de binario: %f\n", t1[max(t1,100)]);
  printf("Tiempo min de binario: %f\n", t1[min(t1,100)]);

  printf("\n");
  
  printf("Promedio del tiempo de ejecucion de secuencial: %f\n", prom(t2, 100));
  printf("Tiempo Max de secuencial: %f\n", t2[max(t2,100)]);
  printf("Tiempo min de secuencial: %f\n", t2[min(t1,100)]);
  
  return 0;
}