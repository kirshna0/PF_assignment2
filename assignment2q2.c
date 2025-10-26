#include <stdio.h>
#include <string.h>
void customerinfo();
void displayinventory();
void updateinventory(int index, int quantitybought);
void addtocart();
float displaytotalbill();
void showinvoice();

#define NO_OF_PRODUCTS 4

char productcode[4][10] = {"001","002", "003", "004" };
int quantity[NO_OF_PRODUCTS] = {50, 10, 20, 8};
int price[NO_OF_PRODUCTS] = {100,200,300,150 };

char customername[50];
char cnic[20];

float bill = 0, discount = 0;
int cartqty = 0;




int main(){
    int choice;
   while(1){
    printf("Super Market\n");
    printf("Enter\n");
    printf("1. to enter customer information\n");
    printf("2. to display inventory\n");
    printf("3. to add item to cart\n");
    printf("4. to display total bill\n");
    printf("5. to show invoice \n");
    printf("6. to exit\n");
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
        customerinfo();
        break;
    case 2:
       displayinventory();
        break;
    case 3:
        addtocart();
        break;
    case 4:
        displaytotalbill();
        break;
    case 5:
        showinvoice();
        break;
    case 6:
        printf("Exited\n");
        return 0;
    
    default:
        printf("Invalid choice");
        break;
    }

   }
     
}

void customerinfo(){
    printf("Enter customer name: ");
    getchar();
    scanf("%[^\n]", customername);
    printf("Enter CNIC (xxxxx-xxxxxxx-x): ");
    scanf("%s", cnic);
    printf("Customer details saved\n");
}

void displayinventory() {
    printf ("Product code   Quantity in stock   Price per product\n");
    for (int i = 0;i<NO_OF_PRODUCTS; i++){
        printf("%s\t %d\t %d\n", productcode[i],quantity[i],price[i]);
    }
}

void addtocart(){
    char enteredcode[10];
    int  enteredquantity;
    printf("Enter product number\n");
    scanf("%s", enteredcode);
    int found = 0;
    for (int i = 0; i < NO_OF_PRODUCTS; i++)
    {
       if(strcmp(enteredcode, productcode[i])==0){
        found = 1; 
       printf("Enter quantity: ");
       scanf("%d", &enteredquantity);
    if (enteredquantity>quantity[i]){
        printf("Only %d items available!\n", quantity[i]);}
        else
        {
            updateinventory(i, enteredquantity );
            cartqty+=enteredquantity;
            quantity[i] -= enteredquantity;
            bill += enteredquantity * price[i];

        }
       }
    }
    if (!found)
       printf("Invalid product code\n");
        
}

float displaytotalbill(){
    printf("\nYour total bill is: Rs. %.2f\n", bill);
    char promo[10];
    printf("Do you have a promocode? (yes/no): ");
    scanf("%s", promo);

    if (strcmp(promo, "yes") == 0) {
        char code[20];
        printf("Enter promocode: ");
        scanf("%s", code);
        if (strcmp(code, "Eid2025") == 0) {
            discount = bill * 0.25;
            bill -= discount;
            printf("25%% discount applied!\n");
        } else {
            printf("Invalid promocode.\n");
        }
    }
    printf("Final bill: Rs. %.2f\n", bill);
    return bill;
}

void updateinventory(int index, int quantitybought){
    quantity[index] -=quantitybought;
    printf("Inventory updated\n");
}
void showinvoice(){
    printf("\n------ INVOICE ------\n");
    printf("Customer: %s\n", customername);
    printf("CNIC: %s\n", cnic);
    printf("Total items bought: %d\n", cartqty);
    printf("Total bill: Rs. %.2f\n", bill);
    printf("Discount: Rs. %.2f\n", discount);
   
}