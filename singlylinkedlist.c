#include <stdio.h>
#include <stdlib.h>

// Structure of a node
struct Node {
    int data;
    struct Node *next;
};

struct Node *head = NULL;

// Insert at the beginning
void insertBeginning(int value) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));

    newNode->data = value;
    newNode->next = head;
    head = newNode;
}

// Insert at the end
void insertEnd(int value) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));

    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
        return;
    }

    struct Node *temp = head;

    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newNode;
}

// Delete from the beginning
void deleteBeginning() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    struct Node *temp = head;
    head = head->next;

    free(temp);
}

// Delete a node by value
void deleteValue(int value) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    // If first node contains the value
    if (head->data == value) {
        struct Node *temp = head;
        head = head->next;
        free(temp);
        return;
    }

    struct Node *temp = head;

    while (temp->next != NULL &&
           temp->next->data != value) {
        temp = temp->next;
    }

    if (temp->next == NULL) {
        printf("Value not found\n");
        return;
    }

    struct Node *deleteNode = temp->next;
    temp->next = deleteNode->next;

    free(deleteNode);
}

// Traverse and display the list
void traverse() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    struct Node *temp = head;

    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }

    printf("NULL\n");
}

// Main function
int main() {
    insertBeginning(30);
    insertBeginning(20);
    insertBeginning(10);

    printf("After insertion at beginning:\n");
    traverse();

    insertEnd(40);
    insertEnd(50);

    printf("After insertion at end:\n");
    traverse();

    deleteBeginning();

    printf("After deleting first node:\n");
    traverse();

    deleteValue(40);

    printf("After deleting 40:\n");
    traverse();

    return 0;
}

