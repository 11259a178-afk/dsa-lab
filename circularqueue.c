#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *rear = NULL;

// Enqueue: Insert an element
void enqueue(int value) {
    struct Node *newNode =
        (struct Node *)malloc(sizeof(struct Node));

    newNode->data = value;

    // Queue is empty
    if (rear == NULL) {
        rear = newNode;
        newNode->next = rear;
    }
    else {
        newNode->next = rear->next;
        rear->next = newNode;
        rear = newNode;
    }

    printf("%d inserted\n", value);
}

// Dequeue: Delete an element
void dequeue() {
    if (rear == NULL) {
        printf("Queue is empty\n");
        return;
    }

    struct Node *front = rear->next;

    // Only one node
    if (front == rear) {
        printf("%d deleted\n", front->data);
        rear = NULL;
    }
    else {
        rear->next = front->next;
        printf("%d deleted\n", front->data);
    }

    free(front);
}

// Display the queue
void display() {
    if (rear == NULL) {
        printf("Queue is empty\n");
        return;
    }

    struct Node *front = rear->next;
    struct Node *temp = front;

    printf("Queue: ");

    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != front);

    printf("\n");
}

// Main function
int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);

    display();

    dequeue();
    display();

    enqueue(40);
    display();

    dequeue();
    dequeue();
    display();

    return 0;
}

