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

//cheak if the list is empty
void  isTheListEmpty(Node *head) {
  if  (head == NULL)
  printf("list is empty \n");
  else 
  printf("list isn`t empty \n");
}

// add a product at the end of list
Node* add_prod(Node **head, char name[], int price) {
    Node *newNode = (Node*) malloc(sizeof(Node));

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
// add a product at the begin of list

Node* add_prod_inthebegin(Node **head, char name[], int price) {
    Node *newNode = (Node*) malloc(sizeof(Node));

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
//display the node 
void display_node(Node *temp) {
    printf("\nProduct name: %s * Price: %d *\n",
           temp->prod.Name,
           temp->prod.Price);
}
//display all the list
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
    int price;
    char name[20];
   
    Node *head = createEmptyList();
  isTheListEmpty(head);
    printf("END // Enter product name and price:\n");
    scanf("%s %d", name, price);

    printf("BEGIN // Enter product name and price:\n");
    scanf("%s %d", name, &price);
    add_prod_inthebegin(&head, name, price);


    printf("\nDisplaying list:\n");
    display_list(head);

    return 0;
}

