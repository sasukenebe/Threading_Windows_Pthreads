#ifndef THREADFUNCTIONS_H
#define THREADFUNCTIONS_H
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include "pthread.h"
#include "garystring.h"

void FillMatrix(int array[4][4]);
void matrixToString(int A[4][4],int B[4][4],char *str);


DWORD ConsumerThreadId,ProducerThreadId;
HANDLE ConsumerThreadHandle,ProducerThreadHandle;
DWORD Sum;
int theClock=0;
int buffer=0;
int buf[buffersize];
int max=3;
int min=0;


using namespace std;
ofstream myfile;
ofstream myfile2;
ifstream myfilereadfrom;

//ofstream myfile;

/*
typedef struct {
     char *buf;
     int head;
     int tail;
     int size;
} buf;
*/


                                                                                    // Begin Producer()
DWORD WINAPI Producer(LPVOID Param)
{            myfile2.open ("debug.txt");
      int max=3;
      int min=0;
int random_number;

while(TRUE)
{         if(theClock==DATASIZE){return 0;}
          printf("begin producer theClock=%d, buffer=%d, buf[buffer]=%d\n\n",theClock,buffer,buf[buffer]);
          fseek(stdin,0,SEEK_END);
          //getchar();
          random_number=(rand() % (max+1-min))+min;         
   if(buffer==buffersize-1)                                                         // at the end of the buffer
   {
                         if(buf[buffer]!=-1)                                       // and it has a non negative..(FULL)
                         {printf("buffer FULL\n");}
                         else
                         {
                                  buf[buffer]=random_number;                        // fill end of buffer if not full...
                                   
                                   cout<<"clock incremented";
                                   printf(" %d written to buf[%d]\n",random_number,buffer);
                                   theClock++;  
                         }
                         
   }
   else                                                                             // buffer not full, not at end
   {
                                                                                    
   if((buf[buffer]!=-1)&&(buffer!=buffersize-1))
   {
   buffer++;
   }
                                                                                    
   if(buf[buffer]==-1)
       {
       buf[buffer]=random_number;

       cout<<"clock incremented";
       printf(" %d written to buf[%d]\n",random_number,buffer);
       theClock++;
       if(buffer!=buffersize-1)
       buffer++;
       }
   //else {buffer++;}
   
   }
             printf("end producer\n\n");
                     printf("buf[]=");      
        for(int i=0;i<buffersize;i++)
        {
       // buf[i]=-1;                         
        printf("%d ",buf[i]);
        }
             Sleep(PROGRAMSPEED);
}//end while loop
//myfile2.close();
return 0;
}   
//end consumer




DWORD WINAPI Consumer(LPVOID Param)
{
      
while(TRUE)
{          
           if(theClock==DATASIZE){return 0;}
           printf("begin consumer theClock=%d, buffer=%d, buf[buffer]=%d\n\n",theClock,buffer,buf[buffer]);
           fseek(stdin,0,SEEK_END);
           //getchar();
 
           if(buffer==0)
           {
                        if(buf[buffer]==-1)
                        {
                                           printf("buffer EMPTY\n\n");
                        }             
                        else
                        {
                            if(buf[buffer]>=0)
                            {
                            myfile<<abs(buf[buffer]);
                            printf("consumer just ATE %d from buf[%d]\n",buf[buffer],buffer);
                            buf[buffer]=-1;
                            // were at 0, soo dont dont decrement buffer
                            }
                        }
           }
           else  // buffer not 0
           {
                                                                    // walk down to next edible piece
            if((buf[buffer]==-1)&&buffer!=0)   
            {buffer--;}
                   if(buf[buffer]>=0)
                   {
                   printf("consumer just ATE %d from buf[%d]\n",buf[buffer],buffer);
                   myfile<<abs(buf[buffer]); 
                   buf[buffer]=-1;
                  if(buffer!=0) 
                  {buffer--;}          
                   else
                   {
                       if(buffer==0){buf[buffer]=-1;}
                   }
                   
                   }    
             
             
           }

 printf("end consumer\n\n");
         printf("buf[]=");      
        for(int i=0;i<buffersize;i++)
        {
        //buf[i]=-1;                         
        printf("%d ",buf[i]);
        }
        Sleep(PROGRAMSPEED);
}//end while loop
        
        
                   

//myfile.close();
return 0;
}
// end producer

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
{int i=0;
int j=0;
char *s;
     for(i=0;i<4;i++)
     {
             for(j=0;j<4;j++)
             {
             myfilereadfrom.get(s,1);
             printf("%s",s);
             A[i][j]= (long)atoi(s);
             }
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
