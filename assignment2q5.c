#include <stdio.h>
#include <string.h>

void encodemessage(char message[]);
void decodemessage(char message[]);
void reversestring(char str[]);
char toggle(char bit);

int main() {
    char message[100];
    int choice;

    while (1) {
        printf("\nTCS Company\n");
        printf("Enter\n");
        printf("1. If you want to encode message\n");
        printf("2. If you want to decode message\n");
        printf("3. If you want to exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
       

        if (choice == 1) {
            printf("Enter the message you want to encode: ");
            getchar();
            scanf("%[^\n]", message);
            encodemessage(message);
        }
        else if (choice == 2) {
            printf("Enter the message you want to decode: ");
            getchar();
            scanf("%[^\n]", message);
            decodemessage(message);
        }
        else if (choice == 3) {
            printf("Exiting\n");
            break;
        }
        else {
            printf("Invalid choice!\n");
        }
    }

    return 0;
}


void reversestring(char str[]) {
    int length = strlen(str);
    for (int i = 0; i < length / 2; i++) {
        char temp = str[i];
        str[i] = str[length - i - 1];
        str[length - i - 1] = temp;
    }
}


char toggle(char bit) {
    bit ^= (1 << 1);
    bit ^= (1 << 4);
    return bit;
}


void encodemessage(char message[]) {
    reversestring(message);
    int i = 0;
    while (message[i] != '\0') {
        message[i] = toggle(message[i]);
        i++;
    }
    printf("\nEncoded Message: %s\n\n", message);
}


void decodemessage(char message[]) {
    int i = 0;
    while (message[i] != '\0') {
        message[i] = toggle(message[i]);
        i++;
    }
    reversestring(message);
    printf("\nDecoded Message: %s\n\n", message);
}