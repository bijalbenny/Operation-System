#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>

int main() {
    key_t key = ftok(".", 65);
    int shmid = shmget(key, 1024, 0666 | IPC_CREAT);
    if (shmid == -1) {
        printf("Error creating shared memory\n");
        return 1;
    }
    
    char* str = (char*)shmat(shmid, NULL, 0);
    if (str == (char*)-1) {
        printf("Error attaching shared memory\n");
        return 1;
    }

    printf("Enter a string to store in shared memory: ");
    fgets(str, 1024, stdin);
    printf("String written to shared memory: %s\n", str);
    
    if (shmdt(str) == -1) {
        printf("Error detaching shared memory\n");
        return 1;
    }
    
    if (shmctl(shmid, IPC_RMID, NULL) == -1) {
        printf("Error removing shared memory\n");
        return 1;
    }

    return 0;
}
