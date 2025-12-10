#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Product {
    int ID;
    char Name[20];
    int Price;
} Product;

typedef struct Node {
    Product prod;
    struct Node *next;
} Node;

//createEmptyList
Node* createEmptyList() {
    return NULL;
}

//check if the list is empty
int isTheListEmpty(Node *head) {
    return (head == NULL);
}

// add a product at the end of list
Node* add_prod(Node **head, int id, char name[], int price) {
    Node *newNode = (Node*) malloc(sizeof(Node));

    newNode->prod.ID = id;
    strcpy(newNode->prod.Name, name);
    newNode->prod.Price = price;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
        newNode->next = newNode;
        return newNode;
    }

    Node *temp = *head;
    while (temp->next != *head)
        temp = temp->next;

    temp->next = newNode;
    newNode->next = *head;

    return newNode;
}

// add a product at the beginning of list
Node* add_prod_inthebegin(Node **head, int id, char name[], int price) {
    Node *newNode = (Node*) malloc(sizeof(Node));

    newNode->prod.ID = id;
    strcpy(newNode->prod.Name, name);
    newNode->prod.Price = price;

    if (*head == NULL) {
        *head = newNode;
        newNode->next = newNode;
        return newNode;
    }

    Node *temp = *head;
    while (temp->next != *head)
        temp = temp->next;

    newNode->next = *head;
    temp->next = newNode;
    *head = newNode;

    return newNode;
}

//display one node
void display_node(Node *temp) {
    printf("\nID: %d | Product: %s | Price: %d\n",
           temp->prod.ID,
           temp->prod.Name,
           temp->prod.Price);
}

//display all list
void display_list(Node *head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    Node *temp = head;

    do {
        display_node(temp);
        temp = temp->next;
    } while (temp != head);
}


int main() {
    int price, id = 1;
    char name[20];

    Node *head = createEmptyList();

    if (isTheListEmpty(head))
        printf("List is empty.\n");

    

    printf("\nBEGIN // Enter product name and price:\n");
    scanf("%s %d", name, &price);
    add_prod_inthebegin(&head, id++, name, price);
  
    printf("\nEND // Enter product name and price:\n");
    scanf("%s %d", name, &price);
    add_prod(&head, id++, name, price);
    
    printf("\nDisplaying list:\n");
    display_list(head);

    return 0;
}


