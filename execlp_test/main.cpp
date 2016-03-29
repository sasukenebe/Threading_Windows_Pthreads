#define buffersize 5
#define PROGRAMSPEED 0 //in milliseconds
#define DATASIZE 2000
bool end_flag=0;
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
//#include "pthread.h"
#include <pthread.h>
#include <fstream>
#include "ThreadFunctions.h"
#define BUFFERSIZE 5
using namespace std;
char *str;
int main()
{
    printf("========begin main=========\n");
pid_t parent = getpid();
pid_t pid = fork();
                                                                                // error, failed to fork()
if (pid == -1)
{
    
} 
else                                                                            // parent 
if(pid > 0)
{
    int status;
    //waitpid(pid, &status, 0);                                                 // you could just wait for child, but that would
                                                                                // defeat purpose of parallelism
                                                                                
    printf("the parent continues to run normally.....\n");
    sleep(5);
}
else 
{
    // we are the child
    execlp("./matrix2.out","matrix2.out",NULL);
    _exit(EXIT_FAILURE);   // exec never returns
}

printf("\nend main======");
return 0;
}
