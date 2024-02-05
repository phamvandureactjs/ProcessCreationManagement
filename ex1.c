#include <stdio.h>
#include <unistd.h>
int main(){
    int pid;
    pid = fork(); // create a child process
    if(pid == -1){
        printf("Cant create child process\n");
    }else if(pid == 0){
        printf("Child Process\n");
    }else{
        printf("Parent Process\n");
    }
    return 0;
}