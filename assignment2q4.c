#include <stdio.h>
int Max;
int stack[100];
int top = -1;
void push ();
void pop ();
void peek ();
void dispaly ();

int main(){
    int choice;
     printf("Enter the Max size of stack: ");
     scanf("%d", &Max);
     while (1){
        printf("Enter\n");
        printf("1. for Push\n");
        printf("2. for Pop\n");
        printf("3. for Peek\n");
        printf("4. for Dispaly\n");
        printf("5. for Exit\n");
        scanf ("%d", &choice);
        if (choice == 1){
        push();}
        else if (choice == 2)
        pop ();
        else if(choice == 3)
        peek();
        else if(choice == 4)
        dispaly();
        else if(choice == 5){
        printf("Exiting");
        break;}
        else {
            printf("Invalid choice!");
        }

     }

    return 0;
}

void push (){
    if (top == Max - 1){
        printf("Overflow! Stack is full\n");
    }else{
        printf("\nEnter the value you want to add to stack: ");
        top++;
        scanf("%d", &stack[top]);
        printf("%d stack pushed!\n", stack[top]);
       
    }
}

void pop (){
    if (top == -1){
        printf("Stack is empty, underflow\n");

    }else{
        printf("%d element popped\n", stack[top]);
        top--;
    }
}
void peek (){
    if(top == -1){
        printf("Stack is empty");
    }else{
    printf("Top element is %d\n",stack[top] );}
}

void dispaly(){
    if (top == -1){
        printf("stack is empty!");
    }else{
    printf("Elemnts in stack are: ");
    for(int i = top; i>=0; i--){
        printf("%d,", stack[i]);
    }
}
}