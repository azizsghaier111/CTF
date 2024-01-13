#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

void addToLinkedList(struct Node** head, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = *head;
    newNode->prev = NULL;
    if (*head != NULL) {
        (*head)->prev = newNode;
    }
    *head = newNode;
}

void printLinkedList(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    struct Node* head = NULL;

    addToLinkedList(&head, 10);
    addToLinkedList(&head, 20);
    addToLinkedList(&head, 30);

    printf("Original linked list: ");
    printLinkedList(head);

    // Simulating a buffer overflow vulnerability
    char buffer[8];
    gets(buffer); // Unsafe function prone to buffer overflow

    printf("Linked list after potential attack: ");
    printLinkedList(head);

    return 0;
}
