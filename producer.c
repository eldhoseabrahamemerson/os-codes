#include<stdio.h>

int main(){
    int buffer, count=0, choice;

    printf("Enter the buffer size: ");
    scanf("%d", &buffer);

    printf("1. Produce\n2. Consume\n3. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    while (choice != 3){
        switch (choice){
            case 1:
                if (count == buffer){
                    printf("Buffer is full. Cannot produce.\n");
                } else{
                    count++;
                    printf("Produced an item. Current count: %d\n", count);
                }
                break;
            case 2:
                if (count == 0){
                    printf("Buffer is empty. Cannot consume.\n");
                } else{
                    count--;
                    printf("Consumed an item. Current count: %d\n", count);
                }
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
        printf("\n1. Produce\n2. Consume\n3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
    }
    return 0;

}