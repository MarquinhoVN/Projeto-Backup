#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <string.h>
#define max 255

void *car();
void *num();
void *esp();
void *lin();

void *choose(){
  FILE *arq;
  arq = fopen("arquivo.txt","r");
  pthread_t threads[4];
  char str[max],stcar[max],stnum[max],stesp[max];
  int cont = 0;
  
  remove("car.txt");
  remove("num.txt");
  remove("esp.txt");
  remove("lin.txt");
  
  while(fgets(str,max,arq)!=NULL){
    cont++;
    
    
    if(stcar!=NULL){
      pthread_create(&threads[0], NULL, car, &stcar);
    }
    else if(stnum!=NULL){
      pthread_create(&threads[1], NULL, num, &stnum);
    }
    else if(stesp!=NULL){
      pthread_create(&threads[2], NULL, esp, &stesp);
    }
    for(int j=0;j<3;j++){
      pthread_join(threads[j], NULL);
    }
  }
  pthread_create(&threads[3], NULL, lin, &cont);
  pthread_join(threads[3], NULL);
  fclose(arq);
}


int main() {
  pthread_t thread;
  pthread_create(&thread, NULL, choose, NULL);
  pthread_join(thread, NULL);
}