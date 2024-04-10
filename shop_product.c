#include <stdio.h>

// Structure to represent a product
struct Product {
    char name[50];
    float price;
    int quantity;
};

// Function prototypes
void displayProductList(const struct Product products[], int size);

int main() {
    // Maximum number of products in the list
    const int MAX_PRODUCTS = 10;

    // Product list
    struct Product productList[MAX_PRODUCTS];

    // Adding sample products to the list
    productList[0] = (struct Product){"Laptop", 999.99, 5};
    productList[1] = (struct Product){"Smartphone", 399.99, 10};
    productList[2] = (struct Product){"Headphones", 49.99, 20};
    // Add more products as needed

    // Display the product list
    printf("Product List:\n");
    displayProductList(productList, MAX_PRODUCTS);

    return 0;
}

// Function to display the product list
void displayProductList(const struct Product products[], int size) {
    printf("%-20s %-10s %-10s\n", "Product Name", "Price ($)", "Quantity");
    printf("----------------------------------------------\n");

    for (int i = 0; i < size; ++i) {
        printf("%-20s %-10.2f %-10d\n", products[i].name, products[i].price, products[i].quantity);
    }
}
