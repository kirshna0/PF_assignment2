#include <stdio.h>

void addBook(int isbns[], char titles[][50], float prices[], int quantities[], int count);
void processSale(int isbns[], int quantities[], int count);
void lowStockReport(int isbns[], char titles[][50], float prices[], int quantities[], int count);

int main() {
    int isbns[100];
    char titles[100][50];
    float prices[100];
    int quantities[100];
    int count = 0;
    int choice;
    

    while (1) {
        printf("Liberty Books Inventory System\n");
        printf("1. Add New Book\n");
        printf("2. Process a Sale\n");
        printf("3. Generate Low-Stock Report\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            addBook(isbns, titles, prices, quantities, count);
            count = count + 1;  
        }
        else if (choice == 2) {
            processSale(isbns, quantities, count);
        }
        else if (choice == 3) {
            lowStockReport(isbns, titles, prices, quantities, count);
        }
        else if (choice == 4) {
            printf("Exiting program.\n");
            
        }
        else {
            printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}


void addBook(int isbns[], char titles[][50], float prices[], int quantities[], int count) {
    int isbn, i, duplicate = 0;

    if (count >= 100) {
        printf("Inventory is full!\n");
        return;
    }

    printf("\nEnter ISBN: ");
    scanf("%d", &isbn);

    
    for (i = 0; i < count; i++) {
        if (isbns[i] == isbn) {
            duplicate = 1;
        }
    }

    if (duplicate == 1) {
        printf("Book with this ISBN already exists!\n");
        return;
    }

    isbns[count] = isbn;

    printf("Enter Title (one word only): ");
    scanf("%s", titles[count]);

    printf("Enter Price: ");
    scanf("%f", &prices[count]);

    printf("Enter Quantity: ");
    scanf("%d", &quantities[count]);

    printf("Book added successfully!\n");
}


void processSale(int isbns[], int quantities[], int count) {
    int isbn, sold, i, found = 0;

    if (count == 0) {
        printf("No books available.\n");
        return;
    }

    printf("\nEnter ISBN to sell: ");
    scanf("%d", &isbn);

    for (i = 0; i < count; i++) {
        if (isbns[i] == isbn) {
            found = 1;
            printf("Enter number of copies sold: ");
            scanf("%d", &sold);

            if (sold > quantities[i]) {
                printf("Not enough stock! Only %d available.\n", quantities[i]);
            } else {
                quantities[i] = quantities[i] - sold;
                printf("Sale complete! Remaining stock: %d\n", quantities[i]);
            }
        }
    }

    if (found == 0) {
        printf("Book with ISBN %d not found!\n", isbn);
    }
}


void lowStockReport(int isbns[], char titles[][50], float prices[], int quantities[], int count) {
    int i, found = 0;

    if (count == 0) {
        printf("No books available.\n");
        return;
    }

    printf("Low Stock Report (Less than 5)\n");
    printf("ISBN\tTitle\tPrice\tQuantity\n");

    for (i = 0; i < count; i++) {
        if (quantities[i] < 8) {
            printf("%d\t%s\t%.2f\t%d\n", isbns[i], titles[i], prices[i], quantities[i]);
            found = 1;
        }
    }

    if (found == 0) {
        printf("All books have enough stock.\n");
    }
}
