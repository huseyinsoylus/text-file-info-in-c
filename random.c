#include<stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, char*argv[]){
  
  FILE * fp_file_pointer = malloc(sizeof(FILE *));
  fp_file_pointer = fopen ("random.txt", "w+");
  char cdizi[1000000];
  for(int i=0;i<1000000;i++)
  {
    int sayi = rand()%123+65;
    cdizi[i] = sayi;
    if(i%1000 == 0)
    fwrite("\n", 1, 1, fp_file_pointer);
  }
  //printf("%s",cdizi);
  fwrite(cdizi, strlen(cdizi), 1, fp_file_pointer);
  

}
