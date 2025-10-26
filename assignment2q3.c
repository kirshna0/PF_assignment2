#include <stdio.h>

void updatestatus(int grid[3][3]);
void querystatus (int grid [3][3]);
void rundiagnostic(int grid[3][3]);

int main(){
    int grid [3][3] = {0};
    int choice;
    printf("Welcome to IESCO power grid\n");
    printf(" 1. Update status\n");
    printf(" 2. Inquire stauts\n");
    printf(" 3. Run diagnostic\n");
    printf(" 4. Exit\n");

    scanf("%d", &choice);
    switch (choice){
        case 1:{
            updatestatus(grid);
        }
        break;
        case 2:{
            querystatus(grid);
        }
        break;
        case 3:{
            rundiagnostic(grid);
        }
        break;
        case 4:{
            printf("Exiting");
            return 0;
        }break;
        default:{
            printf("Invalid choice");
        }
    }

    return 0;
}

void updatestatus(int grid[3][3]){
    int row, col, choice, onoff, bit;
    printf("Enter the row you want to update (0-2): ");
    scanf("%d", &row);
    printf("Enter the coulumn you want to update (0-2): ");
    scanf("%d", &col);
    printf("Enter 1. Power, 2. over loading, 3. Maintainance to change: ");
    scanf("%d", &choice);
    if (choice == 1)
    {
       bit = 1;
    }else if (choice == 2){
        bit = 2;
    }else if (choice == 3){
        bit = 4;
    }else {
        printf("Invalid");
    }
    printf ("Enter 1 for ON and 0 for OFF: ");
    scanf ("%d", &onoff);
    if (onoff == 1){
       grid[row][col] |= bit;
    }else {
        grid[row][col] &= ~bit;
    }
    printf("Status updated!");

}

void querystatus(int grid[3][3]){
    int row, col;
    printf("Enter row: ");
    scanf ("%d", &row);
    printf("Enter column: ");
    scanf("%d", &col);
    int status = grid[row][col];
    if (status & 1){
        printf("Power is ON\n");
    }else{
        printf("Power is OFF\n");
    }
    if (status & 2){
        printf("Over loading\n");
    }else{
        printf("Normal\n");
    }
    if (status & 4){
        printf("Maintenance required\n");
    }else{
        printf("Maintenance not required\n");
    }
}

void rundiagnostic(int grid[3][3]){
    int overload = 0, maintanance = 0;
    for(int i = 0; i<3; i++){
        for(int j = 0; j<3; j++){
            if(grid[i][j]&2){
                overload++;
            }
            if (grid[i][j]&4)
            {
                maintanance++;
            }
            
        }
    }
    printf("%d sectors are overloaded and %d sectors require maintenance", overload, maintanance);
}