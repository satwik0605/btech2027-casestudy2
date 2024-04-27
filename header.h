#ifndef BILLING_SYSTEM_H
#define BILLING_SYSTEM_H

#define GST_RATE 0.18 
#define DISCOUNT_RATE 0.1

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#define MAX_CUSTOMERS 50
#define MAX_PRODUCTS 10

#define MAX_LOGIN_ATTEMPTS 3
#define MAX_USERNAME_LENGTH 20
#define MAX_PASSWORD_LENGTH 20

typedef struct {
    char first_name[50];
    char last_name[50];
    int id;
    char phone_number[15];
    float total_amount;
} Customer;

typedef struct {
    char name[50];
    float price;
    int quantity;
} Product;

// Function prototypes
void addCustomer(Customer *customers, int *num_customers);
void modifyCustomer(Customer *customers, int num_customers);
void generateBill(Customer *customers, int num_customers, Product *products, int num_products);
void displayCustomers(Customer *customers, int num_customers);
void loadCustomersFromFile(Customer *customers, int *num_customers);
void saveCustomersToFile(Customer *customers, int num_customers);
bool login();
void initializeProducts(Product *products);
void removeCustomer(Customer *customers, int *num_customers, int id);
void displayProducts(Product *products, int num_products);
void restockProducts(Product *products, int num_products);
void changePassword();

#endif
