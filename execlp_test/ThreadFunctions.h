#ifndef THREADFUNCTIONS_H
#define THREADFUNCTIONS_H
#include <iostream>
#include <fstream>
#include <stdlib.h>
//#include "pthread.h"

void FillMatrix(int array[4][4]);
void matrixToString(int A[4][4],int B[4][4],char *str);


int theClock=0;
int buffer=0;
int max=3;
int min=0;


using namespace std;
ifstream myfile;
ifstream myfile2;
ifstream myfilereadfrom;


void dotProduct(long *presult, long X[], long Y[], int len)
{  
    printf("presult before dp=%d",presult);
    for (int i = 0; i < len; i++)
        {
        *presult += X[i]*Y[i];
        printf("");
        }
        printf("result after =%d",presult);
     return;
     
}

void fillMatrix(long A[4][4])
{
     //printf("begin fillmatrix\n\n");
     //getchar();
     //fseek(stdin,0,SEEK_END);
     int i=0;
int j=0;
char s='0';
bool end=false;



     for(i=0;i<4;i++)
     {
             for(j=0;j<4;j++)
             {
       //      printf("begin myfilereadfrom\n\n");
       //      getchar();
       //      fseek(stdin,0,SEEK_END);  
             myfilereadfrom.get(s);
             s=s-'0';
             if(s==40){printf("ENDOFFILE\n\n");break;}
             printf("end readfrom,s=");
             printf("%d\n",s); 
         //    getchar();
         //    fseek(stdin,0,SEEK_END);
             A[i][j]= s;
             }
             if(s==40){break;}
     }
 
      
// end while loop
          
     if(s==40)
     {
     end_flag=true;
     printf("endflagtrue!!\n");
     }


}

void matrixToString(long A[4][4],long B[4][4],char *str)
{

     
}

void printMatrix(long A[4][4])
{int i=0;
int j=0;
     printf("matrix:\n");
     
for(i=0;i<4;i++)
{
                for(j=0;j<4;j++)
                {
                printf("%d",A[i][j]);
                }
                printf("\n");
}

     
}



#endif
