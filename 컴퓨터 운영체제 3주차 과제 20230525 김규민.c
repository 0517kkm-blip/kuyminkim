/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
    pid_t pid = fork();

    if (pid == 0) {
        // 자식 프로세스 영역
        printf("[자식] 원래 부모 PID: %d\n", getppid());
        printf("[자식] 부모가 종료되길 잠시 기다립니다...\n");
        sleep(2); // 5초는 너무 기니 2초만 기다릴게요
        
        // 부모가 죽은 후 (고아 상태) 부모 ID 확인
        printf("[자식] 입양된 후 새로운 부모 PID = %d (성공!)\n", getppid());
    } else {
        // 부모 프로세스 영역
        sleep(1); // 자식이 첫 메시지를 찍을 시간을 줍니다
        printf("[부모] 자식을 남겨두고 먼저 종료합니다. (PID = %d)\n", getpid());
        exit(0); 
    }
    return 0;
}