#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>

int main(){
    pid_t pid;
    pid =fork();
    if (pid<0){
        perror("Fork Failed!\n");
        return 1;
    }
    else if (pid==0){
        printf("PCCSL307\n");
    }
    else{
        wait(NULL);
        printf("OPERATING SYSTEMS\n");
    }
    return 0;
}