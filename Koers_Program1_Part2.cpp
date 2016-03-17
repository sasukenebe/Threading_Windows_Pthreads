#define buffersize 5
#define PROGRAMSPEED 0 //in milliseconds
#define DATASIZE 2000
bool end_flag=false;
int counter=0;
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
//#include "pthread.h"
#include <pthread.h>
#include <fstream>
#include <sys/types.h>
#include <sys/wait.h>
char str[32];
char str2[16];
#define BUFFERSIZE 50
using namespace std;


        typedef struct dotProductInput
        {
          long A[4][4];
          long B[4][4];
          long C[4][4];
          int count;
          int i;
          int j;

        };
        pthread_t th0,th1,th2,th3,th4,th5,th6,th7,th8,th9,th10,th11,th12,th13,th14,th15;
        pthread_t threadarray[16]={th0,th1,th2,th3,th4,th5,th6,th7,th8,th9,th10,th11,th12,th13,th14,th15};
        dotProductInput DPI[16];//{DPI0,DPI1,DPI2,DPI3,DPI4,DPI5,DPI6,DPI7,DPI8,DPI9,DPI10,DPI11,DPI12,DPI13,DPI14,DPI15};
        
        dotProductInput DP;


 /* data is shared by the thread(s) */
/* the thread runs in this separate function */


        void *DPI_VOIDPTR;
        //DPI_VOIDPTR=&DPI[0];
long A[4][4], B[4][4], C[4][4];
char input;
long presult;  
//char str[32];
char Astring[16];
char Bstring[16];
char ABstring[32];
char *c; 
pid_t pid;

#include "ThreadFunctions.h"
    
               
                                                                                    // begin main
int main(int argc, char *argv[])
{     
         
        //DP.C=0;
        DP.count=0;
  DPI_VOIDPTR=&DPI[0];
  str[32]=NULL; 
  Bstring[16]=NULL;
  Astring[16]=NULL; 
  ABstring[32]=NULL;   
      
    printf("\nBEGIN_MAIN_PART2:\n\n ");   
    
    getchar(); 
    fseek(stdin,0,SEEK_END);

       myfile.open ("stuff.txt",fstream::app);
       myfile2.open ("debug.txt",fstream::app);

printf("Begin Part 2 of Program, press any key\n\n\t=\t=\t=\t=\t=\t=\t=\t=\t=");
myfilereadfrom.open ("stuff.txt");







while((input!='0')&&(input!='1')&&(input!='2')&&(input!='3')&&(input!='4'))
{                                                                                        
  printf("enter a command\n1-\n2-\n3-\n4-\n");

  fseek(stdin,0,SEEK_END);
  input=getchar();
  fseek(stdin,0,SEEK_END);
}
  while(end_flag!=true)
  {

   if(input=='0')
      {
      printf("========BEGIN option 0, ADD Matrices=========\n");
      fillMatrix(A);
      if(end_flag==true){break;}
      fillMatrix(B);
      if(end_flag==true){break;};
      printf("Matrix A:\n");
      printMatrix(A);
      printf("Matrix B:\n");
      printMatrix(B);
      
      matrixToString(A,B,str);
      printf("(Matrix A)+(Matrix B) string: ");
      puts(str);

  // begin fork
  pid_t parent = getpid();
  pid_t pid0 = fork();
                                                                                  
  if (pid0 == -1)
  {
      printf("fork failed\n");
  } 
          // if CHILD 
          if(pid0 == 0)
          {
              printf("Now entering execlp\n\n");
               execlp("./matrix.out","matrix.out","0","4","4",str,NULL);
              _exit(EXIT_FAILURE);   // exec never returns                                              // you could just wait for child, but that would
          }
          else// Parent Process
          {
      printf("========END option 0, until no more stuff.txt=========\n");
      //getchar();
      //fseek(stdin,0,SEEK_END);
       
       }
       
                                                                                    
  printf("========END option 0, ADD Matrices=========\n");
      } // end option 0
      



  if(input=='1')
  {

  printf("========BEGIN option 1, SUBTRACT Matrices=========\n");
      printf("we execute “add” matrix.out using execlp, we pass the arguments 0 4 4 str arguments are: cmd row col string"); 
       fillMatrix(A);
      if(end_flag==true){break;}
      fillMatrix(B);
      if(end_flag==true){break;};
      printf("Matrix A:\n");
      printMatrix(A);
      printf("Matrix B:\n");
      printMatrix(B);
      
      printf("(Matrix A)+(Matrix B) string: ");
      matrixToString(A,B,str);
      puts(str);

     // begin fork          
  pid_t parent = getpid();
  pid_t pid1 = fork();
                                                                                  // error, failed to fork()
  if (pid1 == -1)
  {
      printf("fork failed\n");
  } 
          // if CHILD 
          if(pid1 == 0)
          {
              printf("Now entering execlp\n\n");
               execlp("./matrix.out","matrix.out","1","4","4",str,NULL);
              _exit(EXIT_FAILURE);   // exec never returns                                              // you could just wait for child, but that would
          }
          else// Parent Process
          {
      printf("========END option 1, ADD MATRICES=========\n");
      getchar();
      fseek(stdin,0,SEEK_END);
       
       }                                                                             
      printf("matrix out was called successfully\nend option 0\n"); 

}// end option 1

      if(input=='2')
      {
        printf("========BEGIN option 2 DETERMINANT of Matrices=============");
          fillMatrix(A);

      if(end_flag==true){break;}; 
          
          singleMatrixToString(A,B,str2);

      if(end_flag==true){break;}; 

      pid_t parent = getpid();
      pid_t pid2 = fork();
         // error, failed to fork()
  if (pid2 == -1)
  {
      printf("fork failed\n");
  } 
          // if CHILD 
          if(pid2 == 0)
          {
              printf("Now entering execlp\n\n");
               execlp("./matrix.out","matrix.out","2","4","4",str2,NULL);
              _exit(EXIT_FAILURE);   // exec never returns                                              // you could just wait for child, but that would
          }
          else // Parent Process
          {
      printf("========END option 2, DETERMINANT Matrix=========\n");
      getchar();
      fseek(stdin,0,SEEK_END);
      }
      

}// end option 2
    if(input=='3')
    { 
        printf("=============begin option 3 MULTIPLY Matrices=========================\n");
        DP.i=0;
        DP.j=0;
        int initx, inity;
        for(initx = 0; initx < 4; initx ++) 
        {for(inity = 0; inity < 4; inity ++){DP.A[initx][inity] = 0;}}
              for(initx = 0; initx < 4; initx ++) 
        {for(inity = 0; inity < 4; inity ++){DP.B[initx][inity] = 0;}}
              for(initx = 0; initx < 4; initx ++) 
        {for(inity = 0; inity < 4; inity ++){DP.C[initx][inity] = 0;}}


        DP.count=0;
        //fDP.C=0;
        counter=0;
        
      // pthread_create (&threadarray[0], NULL, dotProduct,&DPI[0]);
      //pthread_create (&threadarray[1], NULL, dotProduct,&DPI[1]);

      int i=0;
      int j=0;


        fillMatrix(DP.A);
      if(end_flag==true){break;}
      fillMatrix(DP.B);
      if(end_flag==true)
        {break;}
      matrixPrint(DP.A,4,4);
      matrixPrint(DP.B,4,4);

// create 16 threads in a nested for loop 
 for((DP.i)=0;(DP.i)<4;(DP.i)++)
     {
             for((DP.j)=0;(DP.j)<4;(DP.j++))
             {
              printf("creating thread %d\n",DP.count);
            pthread_create(&threadarray[DP.count], NULL, multiplyThreaded , (void *) NULL);
            DP.count++;
            /////////////////////////////////////////////////ISSUE///////////////////////////////////////////
            //pthread_join(threadarray[DP.count],NULL); // errors occur if i dont wait for it to complete here...
             /////////////////////////////////////////////////ISSUE//////////////////////////////////////////////
            
             }
     }

//                                        if you wait for the threads to finish out here, it returns all 0s, why?
/*     for (i=0;i<16;i++)
{   pthread_join (threadarray[i],NULL) ;
    
}
*/
if(pthread_join(threadarray[15],NULL)!=0){printf("error rejoining thread\n\n");}


      printMatrix(DP.A);
      printMatrix(DP.B);
      printf("Multiplication: ");
      matrixPrint(DP.C,4,4);
      getchar();
      fseek(stdin,0,SEEK_END);



printf("end option 3==========================================");
  }// end option 3


printf("reached end of while loop, end_flag=%d\n\n",end_flag);
}
//end while loop, end flag is true

printf("program done, have a great day buddy\n");
getchar();
return 0;

} // end main
