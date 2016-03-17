#define buffersize 5
#define PROGRAMSPEED 0 //in milliseconds
#define DATASIZE 2000


#include <windows.h>
#include <stdio.h>
#include <unistd.h>
#include "ThreadFunctions.h"
#include "garystring.h"
#include <stdlib.h>
#include "pthread.h"
 /* data is shared by the thread(s) */
/* the thread runs in this separate function */
long A[4][4], B[4][4], C[4][4];
char input;
long presult;  
char *str;  
               
                                                                                    // begin main
int main(int argc, char *argv[])
{     
              
      
    printf("\nBEGIN_MAIN:\n\n ");   
    
    getchar(); 
    fseek(stdin,0,SEEK_END);

       myfile.open ("stuff.txt");
       myfile2.open ("debug.txt");
        printf("buf[]=");      
        for(int i=0;i<buffersize;i++)
        {
        buf[i]=-1;                        
        printf("%d",buf[i]);
        }
        

        int Param;
        getchar();
        fseek(stdin,0,SEEK_END);
    /* create the thread */
        ConsumerThreadHandle = CreateThread(
        NULL, /* default security attributes */
        0, /* default stack size */
        Consumer, /* thread function */
        &Param, /* parameter to thread function */
        0, /* default creation flags */
        &ConsumerThreadId); /* returns the thread identifier */
    
    
        ProducerThreadHandle = CreateThread(
        NULL, /* default security attributes */
        0, /* default stack size */
        Producer, /* thread function */
        &Param, /* parameter to thread function */
        0, /* default creation flags */
        &ProducerThreadId); /* returns the thread identifier */



        
      if (ConsumerThreadHandle != NULL)
            {
            /* now wait for the thread to finish */
            WaitForSingleObject(ConsumerThreadHandle,INFINITE);
            /* close the thread handle */
            CloseHandle(ConsumerThreadHandle);
            }
        
        if (ProducerThreadHandle != NULL) 
            {
            /* now wait for the thread to finish */
            WaitForSingleObject(ProducerThreadHandle,INFINITE);
            /* close the thread handle */
            CloseHandle(ProducerThreadHandle);
            }
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
printf("theClock=%d, program over, check stuff.txt",theClock);


cout<<"program done, have a great day buddy\n";
myfile<<"X"
myfile.close ("stuff.txt");
myfile2.close ("debug.txt");
getchar();
return 0;
}
