#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

int mutex = 1, empty = 3, full = 0;

int wait(int s) {
    return --s;                             //s++;return s;
}

int signal(int s) {
    return ++s;                             //s--;return s;
}

void producer() {
    printf("Producer is called\n");
    mutex = wait(mutex);
    full = signal(full);
    empty = wait(empty);
    mutex = signal(mutex);
}

void consumer() {
    printf("Consumer is called\n");
    mutex = wait(mutex);
    empty = signal(empty);
    full = wait(full);
    mutex = signal(mutex);
}

int main() {
    int choice;
    while(true) {
        printf("Enter choice :\n 1.Producer\t 2.Consumer\t 3.Exit\n");
        scanf("%d", &choice);
        switch(choice) {
            case 1: {
                if(mutex == 1 && empty != 0)
                    producer();
                else
                    printf("Buffer is full\n");
                break;
            }
            case 2: {
                if(mutex == 1 && full != 0)
                    consumer();
                else
                    printf("Buffer is empty\n");
                break;
            }
            case 3:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}
