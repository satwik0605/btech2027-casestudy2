#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "header.h"
#include "functions.c"
int main() {
    int customer_id;
    if (!login()) {
        printf("Login failed. Exiting...\n");
        return 1;
    }
    Customer *customers = malloc(MAX_CUSTOMERS * sizeof(Customer));
    if (customers == NULL) {
        printf("Memory allocation failed. Exiting...\n");
        return 1;
    }
    Product *products = calloc(MAX_PRODUCTS, sizeof(Product));
    if (products == NULL) {
        printf("Memory allocation failed. Exiting...\n");
        free(customers);
        return 1;
    }
    initializeProducts(products);
    int num_customers = 0;
    int choice;
    loadCustomersFromFile(customers, &num_customers);
    do {
        printf("\n===== Customer Billing System =====\n");
        printf("1. Add Customer\n");
        printf("2. Modify Customer Details\n");
        printf("3. Remove Customer\n");
        printf("4. Generate Bill\n");
        printf("5. Display Customers\n");
        printf("6. Display Available Products\n");
        printf("7. Restock Products\n");
        printf("8. Change Password\n");
        printf("9. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                addCustomer(customers, &num_customers);
                break;
            case 2:
                modifyCustomer(customers, num_customers);
                break;
            case 3:
               printf("Enter customer ID to remove: ");
                scanf("%d", &customer_id);
                removeCustomer(customers, &num_customers, customer_id);
                break;
                break;
            case 4:
                generateBill(customers, num_customers, products, MAX_PRODUCTS);
                break;
            case 5:
                displayCustomers(customers, num_customers);
                break;
            case 6:
                displayProducts(products, MAX_PRODUCTS);
                break;
            case 7:
                restockProducts(products, MAX_PRODUCTS);
                break;
            case 8:
                changePassword();
                break;
            case 9:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 9);
    saveCustomersToFile(customers, num_customers);
    free(customers);
    free(products);
    return 0;
}
