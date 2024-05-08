#include <stdio.h>

#define MAX_SIZE 100

// Function prototypes
void initializeList(int list[], int *size);
void displayList(const int list[], int size);
void insertElement(int list[], int *size, int element, int position);
void deleteElement(int list[], int *size, int position);

int main() {
    int myList[MAX_SIZE];
    int size = 0;

    initializeList(myList, &size);

    // Example: Insert elements
    insertElement(myList, &size, 10, 0);
    insertElement(myList, &size, 20, 1);
    insertElement(myList, &size, 30, 2);

    // Display the list
    printf("List after insertion:\n");
    displayList(myList, size);

    // Example: Delete element at position 1
    deleteElement(myList, &size, 1);

    // Display the list after deletion
    printf("List after deletion:\n");
    displayList(myList, size);

    return 0;
}

// Function to initialize the list
void initializeList(int list[], int *size) {
    *size = 0;
}

// Function to display the list
void displayList(const int list[], int size) {
    for (int i = 0; i < size; ++i) {
        printf("%d ", list[i]);
    }
    printf("\n");
}

// Function to insert an element at a specific position in the list
void insertElement(int list[], int *size, int element, int position) {
    if (*size >= MAX_SIZE) {
        printf("List is full. Cannot insert element.\n");
        return;
    }

    if (position < 0 || position > *size) {
        printf("Invalid position for insertion.\n");
        return;
    }

    // Shift elements to make space for the new element
    for (int i = *size; i > position; --i) {
        list[i] = list[i - 1];
    }

    // Insert the new element
    list[position] = element;
    *size += 1;
}

// Function to delete an element at a specific position in the list
void deleteElement(int list[], int *size, int position) {
    if (*size <= 0) {
        printf("List is empty. Cannot delete element.\n");
        return;
    }

    if (position < 0 || position >= *size) {
        printf("Invalid position for deletion.\n");
        return;
    }

    // Shift elements to fill the gap left by the deleted element
    for (int i = position; i < *size - 1; ++i) {
        list[i] = list[i + 1];
    }

    *size -= 1;
}
