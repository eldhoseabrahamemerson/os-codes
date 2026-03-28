#include<stdio.h>
#include<time.h>
#include<unistd.h>

int main(){
    while (1){
        time_t now;
        time(&now);
        printf("Current time: %s", ctime(&now));
        sleep(30);
    }
    return 0;

}