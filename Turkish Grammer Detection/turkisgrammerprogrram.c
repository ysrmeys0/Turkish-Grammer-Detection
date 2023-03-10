#include <locale.h>
#include <string.h>
#include <stdio.h>
#include <conio.h>
#include <windows.h>

#define SIZE_TEXT 50000
#define SIZE_WORD 30
#define SIZE_LENGTH 2000
#define ALPHABET "abcçdefgðhiýjklmnoöprsþtuüvyzABCDEFGÐHIÝJKLMNOÖPRSÞTUÜVYZ"
#define STRONG_CONSONENT "çfhkpsþt"
#define SOFT_CONSONENT "bcdgðjlmnrvyz"
#define BOLD_VOWEL "aýou"
#define NARROW_VOWEL "eiöü"
#define UNROUNDED_VOWEL "aeýi"
#define ROUNDED_VOWEL "oöuü"
#define WIDE_VOWEL "aeoö"
#define CLOSE_VOWEL "ýiuü"



int numwords(unsigned char text[]);
int numsentences(unsigned char text[]);
int numletters(unsigned char text[]);
int numplural(unsigned char text[]);
int connexion(unsigned char text[]);
int palatalharmony(unsigned char text[],unsigned char word[][SIZE_LENGTH]);
void tokwords(unsigned char text[],unsigned char word[][SIZE_LENGTH]);



int main()
{
    setlocale(LC_ALL,"Turkish_turkish.1254");
    SetConsoleOutputCP(1254);
    SetConsoleCP(1254);

    unsigned char text[SIZE_TEXT]={0};
    unsigned char word[SIZE_WORD][SIZE_LENGTH]={0};
   
   

  printf("Please enter the text:\n");
  fgets(text,SIZE_TEXT,stdin);

  printf("Number of words=%d\n",numwords(text));
  printf("Number of sentences=%d\n",numsentences(text));
  printf("Number of letters=%d\n",numletters(text));
  printf("Number of plural words=%d\n",numplural(text));
  printf("Number of connexion=%d\n",connexion(text));
  tokwords(text,word);
  printf("palatal harmonys=%s\n",palatalharmony(text,word));
 

   return 0;
}

 int  numwords(unsigned char text[])
{
    int i;
   int count=1;
   char str[]=" ";

   for(i=0;i<strlen(text)-1;i++)
   {
     if(strchr(str, text[i]) != NULL)
     {
        count++;
     }
   }

 return count;
}




int numsentences(unsigned char text[])
{
   int i;
   int count=0;
   char str[]=".:?!";

   for(i=0;i<strlen(text);i++)
   {
     if(strchr(str, text[i]) != NULL)
     {
        while(text[i]=='.')
        {
          i++;
        }
        count++;
     }
   }


  return count;

}


int numletters(unsigned char text[])
{
  int i;
  int count=0;

   for(i=0; text[i] != '\0'; i++)
   {

     {
         if(strchr(ALPHABET,text[i]))
         {
           count++;
         }


     }
   }

  return count;
}

int numplural(unsigned char text[])
{
  int i,count=0;
  for(i=0;i<strlen(text);i++)
  {
    if((text[i]=='l' && text[i+1]=='e' && text[i+2]=='r')|| (text[i]=='l' && text[i+1]=='a' && text[i+2]=='r'))
    {
        count++;
    }
  }

  return count;
}



int connexion(unsigned char text[])
{
  int count=0, i=0, size=0;
  char vowel[8]="aeýioöuü";
  char consonent[22]="bcçdfgðhjklmnprsþtvyz";

  size = strlen(text);
  for(i=0; i<size;i++)
  {
        if ((strchr(consonent, text[i]) != NULL) && (text[i+1] == ' ') && (strchr(vowel, text[i + 2]) != NULL))
    {
             count++;
    }
  }

  return count;
}


int palatalharmony(unsigned char text[],unsigned char word[][SIZE_LENGTH])
{
  
   int i,j,count=0;
  
  for(i=0;i!=NULL;i++)
  {
    for(j=0;j!=' ';j++)
    {
      if(strchr(BOLD_VOWEL,word[i][j]) || strchr(NARROW_VOWEL,word[i][j]))
      {
        count++;
        printf("Number of palatal harmony=%d\n palatal harmonys=%s\n",count,word[i]);
      }
    }
  }
  return count;
}


void tokwords(unsigned char text[],unsigned char word[][SIZE_LENGTH])
{
 int i;
 unsigned char *ptr;
 unsigned char copy[SIZE_TEXT];

 strcpy(copy,text);
 
 ptr=strtok(copy,"' '");
 for(i=0; ptr!=NULL ;i++)
 {
  strncpy(word[i],ptr,SIZE_LENGTH);
  ptr=strtok(NULL,"' '");
  }

}