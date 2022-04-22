/*
Huseyin Soylu - 171418012
Marmara Universitesi Bilgisayar Muhendisligi Bolumu
BLM3010-Sistem Programlama Dersi - Proje-1

Asağıdaki program verilen .txt uzantili dosyalardaki satır, karakter ve kelime sayılarını hesaplayıp ekrana basan fonksiyon ve kodları içermektedir.

Kodlama yapılırken macar notasyonu esas alınmış ve tüm değişkenler için aşağıda belirtilen esaslarda kodlama yapılmıştır. 
_____________________________________________________________________________________

------For Variable-----------------
variable = v; tip sonrasi eki
-------------------------------

------Use Case-----------------
integer icin = i_v;
char icin =c_v;
double icin = d_v;
float icin = f_v;
-------------------------------
_____________________________________________________________________________________

------For Pointer------------------
pointer = p; tip sonrasi eki
-------------------------------

------Use Case-----------------
int pointer icin = i_p;
char pointer icin = c_p;
-------------------------------
_____________________________________________________________________________________

------ For Array---------------
array = a; tip sonrasi eki
-------------------------------

------Use Case-----------------
int array = i_a;
char array = c_a;
-------------------------------
_____________________________________________________________________________________

------For Function-------------
function = f; tip sonrasi eki
-------------------------------

------Use Case-----------------
int geri donuslu fonksiyon = i_f;
char geri donuslu fonksiyon = c_f;

int pointer geri donuslu fonksiyon = i_p_f;
char pointer geri donuslu fonksiyon = c_p_f;

geri donussuz fonksiyon icin = v_f;
-------------------------------
_____________________________________________________________________________________

------For Function Parameter---
parameter = p;
-------------------------------

------Use Case-----------------
int geri donuslu parametreli fonsiyon = i_f_p;
int pointer donuslu parametreli fonksiyon = i_p_f_p;

Seklinde tanimlanmistir.
-------------------------------
_____________________________________________________________________________________
*/
//-------------------------------------Program Code Area-----------------------------

//-------------------------------------Libraries-------------------------------------
#include<stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
//___________________________________________________________________________________

//-------------------------------------Global Variables------------------------------
int giv_total_words=0;
int giv_total_char=0;
int giv_total_line=0;

int giv_char_count=0; 
int giv_word_count=0; 
int giv_line_count=0;

//Error durumunda fonksiyonu çalıştırmamak ve ekrana çıktı basmamak için
int giv_file_err = 0;

//___________________________________________________________________________________
//void vf_stdin_counter();
//----------------------------------Function Declare Area----------------------------

//--------------------------------is_word Function------------------------------------
int ifp_is_word(char a, char b)
{
  return (isspace(a) && !isspace(b)) || (a == '\n' && !isspace(b));
}
//___________________________________________________________________________________

//--------------------------------STDIN-Word Count Function--------------------------------

void vf_stdin_counter()
{
  giv_char_count =0;giv_line_count=0;giv_word_count=0;
  char cv_char1='-',cv_char2='+';
  int iv_sum_word=0;
  while(cv_char2 != EOF)
  {
    
    cv_char1 = cv_char2;
    cv_char2 = fgetc(stdin);
    if(cv_char1 != EOF && cv_char2 != EOF)
    {
      if(cv_char2 == '\n')
      {
        giv_line_count++;
      }
      giv_char_count++;
      if (ifp_is_word(cv_char1,cv_char2))
      {
        giv_word_count++;
      } 
    }
  }
  giv_total_words += giv_word_count + 1;
  giv_total_char+=giv_char_count;
  giv_total_line+=giv_line_count;

}
//___________________________________________________________________________________


//--------------------------------Word Count Function--------------------------------

int ifp_file_counter(FILE * fp_file_pointer, char * cp_file_path)
{
  giv_char_count =0;giv_line_count=0;giv_word_count=0;
  char cv_char1='-',cv_char2='+';
  int iv_sum_word=0;
  if ((fp_file_pointer = fopen (cp_file_path, "r")) != NULL) 
  {
    while(cv_char2 != EOF)
    {
      cv_char1 = cv_char2;
      cv_char2 = fgetc(fp_file_pointer);
      if(cv_char2 == '\n')
      {
        giv_line_count++;
      }
      if(cv_char1 != EOF && cv_char2 != EOF)
      {
        giv_char_count++;
        if (ifp_is_word(cv_char1,cv_char2))
        {
          giv_word_count++;
        } 
      }
    }
    
    giv_file_err=0;
    fclose(fp_file_pointer); 
  }
  else
  {
    if(*cp_file_path == '+'){
      giv_file_err=0;
    }
    else
    {
      fprintf(stderr, "HATA: %s dosyası açılamıyor\n",cp_file_path);
      printf("--------------------------------\n");
      giv_file_err=1;
    }
  }
  giv_total_words += giv_word_count + 1;
  giv_total_char+=giv_char_count;
  giv_total_line+=giv_line_count;
}
//___________________________________________________________________________________


//--------------------------------lwc-Selector Function--------------------------------
void vfp_wlc_selector(int *l, int *w, int *c, int * total, int argc, char*argv[])
{
  int iv_argc = argc;

  for (int i = 1; i < argc; i++)
    {
      if(argv[i][0]=='-')
      {
        if(!strcmp(argv[i], "-w"))
        {
          *w=1;
          *total+=1;
          
        }
        else if(!strcmp(argv[i], "-l"))
        {
          *l=1;
          *total+=1;        
        }
        else if(!strcmp(argv[i], "-c"))
        {
          *c=1;
          *total+=1;      
        }
        else
        {
          fprintf(stderr, "HATA: bilinmeyen seçenek %s\n",argv[i]);
          _Exit(0);
        }
      }
    }
}
//___________________________________________________________________________________

//--------------------------------Normal Print Function--------------------------------
void vfp_print(int l, int w, int c, char*argv[],int i)
{
  if(l && !w && !c)
  {
    printf("File Name: %s\nLine: %d\n",argv[i],giv_line_count);
    printf("--------------------------------\n");
  }
  if(w && !l && !c)
  {
    printf("File Name: %s\nWord: %d\n",argv[i],++giv_word_count);
    printf("--------------------------------\n");
  }
  if(c && !l && !w)
  {
    printf("File Name: %s\nChar: %d\n",argv[i],giv_char_count);
    printf("--------------------------------\n");
  }
  if(c && l && !w)
  {
    printf("File Name: %s\nLine: %d Char: %d\n",argv[i],giv_line_count,giv_char_count);
    printf("--------------------------------\n");
  }
  if(c && w && !l)
  {
    printf("File Name: %s\nWord: %d Char: %d\n",argv[i],++giv_word_count,giv_char_count);
    printf("--------------------------------\n");
  }
  if(l && w && !c)
  {
    printf("File Name: %s\nLine: %d Word: %d\n",argv[i],giv_line_count,++giv_word_count);
    printf("--------------------------------\n");
  }
  if(l && w && c)
  {
    printf("File Name: %s\nLine: %d Word: %d Char: %d\n",argv[i],giv_line_count,giv_word_count,giv_char_count);
    printf("--------------------------------\n");
  }
  if(!l && !w && !c)
  {
    printf("File Name: %s\nLine: %d Word: %d Char: %d\n",argv[i],giv_line_count,++giv_word_count,giv_char_count);
    printf("--------------------------------\n");
  }
}
//___________________________________________________________________________________

//--------------------------------STDIN-print Function--------------------------------
void vfp_stdin_print(int l, int w, int c)
{
  if(l && !w && !c)
  {
    printf("File Name: %s\nLine: %d\n","STDIN",giv_line_count);
    printf("--------------------------------\n");
  }
  if(w && !l && !c)
  {
    printf("File Name: %s\nWord: %d\n","STDIN",++giv_word_count);
    printf("--------------------------------\n");
  }
  if(c && !l && !w)
  {
    printf("File Name: %s\nChar: %d\n","STDIN",giv_char_count);
    printf("--------------------------------\n");
  }
  if(c && l && !w)
  {
    printf("File Name: %s\nLine: %d Char: %d\n","STDIN",giv_line_count,giv_char_count);
    printf("--------------------------------\n");
  }
  if(c && w && !l)
  {
    printf("File Name: %s\nWord: %d Char: %d\n","STDIN",++giv_word_count,giv_char_count);
    printf("--------------------------------\n");
  }
  if(l && w && !c)
  {
    printf("File Name: %s\nLine: %d Word: %d\n","STDIN",giv_line_count,++giv_word_count);
    printf("--------------------------------\n");
  }
  if(l && w && c)
  {
    printf("File Name: %s\nLine: %d Word: %d Char: %d\n","STDIN",giv_line_count,++giv_word_count,giv_char_count);
    printf("--------------------------------\n");
  }
  if(!l && !w && !c)
  {
    printf("File Name: %s\nLine: %d Word: %d Char: %d\n","STDIN",giv_line_count,++giv_word_count,giv_char_count);
    printf("--------------------------------\n");
  }
}
//___________________________________________________________________________________


//--------------------------------is true argv Function--------------------------------

void ifp_is_it_true_argv(char *argv[], int argc)
{
  char array[4096];
  
  for(int i=1;i<argc;i++)
  {
    strcat(array, argv[i]);
  }
  int iv_length = strlen(array);
  //printf("%s\n",array);
  for(int i=0; i< iv_length;i++)
  {
    char cv_a='a',cv_b='a',cv_c='a';
    
    if(cv_a != '\0' && cv_b != '\0' && cv_c != '\0')
    {
      if(array[i] != '-' && array[i+1] != '-' && array[i+2] == '-')
      {
        fprintf(stderr, "HATA: Argümanlar -w , -l , -c olabilir ve dosyalardan önce bildirilmelidir.\n");
        _Exit(0); 
      }
      else
      {
        
      }
    }
  }
}
	
//___________________________________________________________________________________

int main(int argc, char *argv[]){

  //Argüman kontrolü tani file dosyasından sonra parametre girilemesin
  ifp_is_it_true_argv(argv, argc);
  
  FILE * fp_file_pointer = malloc(sizeof(FILE *));
  char * cp_file_path = malloc(sizeof(char)*100);
  
  
  if(argc < 2)
  {
    printf("(!)Program parametre almadan başlatıldı. Bu yüzden girdi olarak STDIN Dosyası kullanıldı.\n");
    vf_stdin_counter();
    printf("File Name: STDIN\nLine: %d Word: %d Char: %d\n",giv_line_count,++giv_word_count,giv_char_count);
  }
  else
  {
    int l=0, w=0, c=0, total=1;
    
    //deneme(&w, &l, &c, &total);
    
    vfp_wlc_selector(&l, &w, &c, &total, argc, argv);
    //printf("%d %d %d %d %d %s\n",l,w,c,total,argc,argv[1]); //Unit Test
    if(argv[total]!=NULL)
    {
      for(int i=total;i<argc;i++)
      {
        cp_file_path = argv[i];
        if(argv[i][0]=='+')
        {
          vf_stdin_counter();
          vfp_stdin_print(l, w, c);
        }
        else
        {
          ifp_file_counter(fp_file_pointer,cp_file_path);
          //printf("TOTAL --> Line: %d Word: %d Char: %d\n",giv_total_line,giv_total_words,giv_total_char);
          if(giv_file_err == 0)
          {
            vfp_print(l,w,c,argv,i);
          }
          else
          {
        
          }
        }
      }
    }
    else
    {
      vf_stdin_counter();
      vfp_stdin_print(l, w, c);
    }
  }

  free(fp_file_pointer);
  
  
  printf("TOTAL --> Line: %d Word: %d Char: %d\n",giv_total_line,giv_total_words,giv_total_char);
}
