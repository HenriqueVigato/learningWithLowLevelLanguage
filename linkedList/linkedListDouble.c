#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  int data;
  struct Node *next;
  struct Node *previous;
} Node;

Node *createNode(int data) {
  Node *newNode = (Node *)malloc(sizeof(Node));

  newNode->data = data;
  newNode->next = NULL;
  newNode->previous = NULL;

  return newNode;
}

Node *insertAtBeginning(Node *head, int data) {
  Node *newNode = createNode(data);

  if (head == NULL) {
    newNode->next = head;
  } else {
    head->previous = newNode;
    newNode->next = head;
  }

  return newNode;
}

Node *insertAtEnd(Node *head, int data) {
  Node *newNode = createNode(data);

  if (head == NULL) {
    return newNode;
  }

  Node *temp = head;
  while (temp->next != NULL) {
    temp = temp->next;
  }

  temp->next = newNode;
  newNode->previous = temp;

  return head;
}

void printList(Node *head) {
  Node *temp = head;

  while (temp != NULL) {
    printf("%d \n", temp->data);
    temp = temp->next;
  }

  printf(" \n");
}

void freeList(Node *head) {
  Node *temp;

  while (head != NULL) {
    temp = head;
    head = head->next;
    free(temp);
  }
}

// vai ate um ponto da lista e volta ate o comeco
void testReturning(Node *head, int value) {
  Node *temp = head;

  while (temp->data != value) {
    printf("%d \n", temp->data);
    temp = temp->next;
  }

  while (temp != NULL) {
    printf("%d \n", temp->data);
    temp = temp->previous;
  }
  printf(" \n");
}

int main() {
  Node *head = NULL;

  head = insertAtBeginning(head, 100);
  head = insertAtBeginning(head, 200);
  head = insertAtBeginning(head, 300);
  head = insertAtBeginning(head, 400);

  printf("Lista apos insercao no inicio \n");
  printList(head);

  head = insertAtEnd(head, 110);
  head = insertAtEnd(head, 220);
  head = insertAtEnd(head, 330);
  head = insertAtEnd(head, 440);

  printf("Lista apos isnercao no final \n");
  printList(head);

  printf("Testando andar para tras no meio da lista \n");
  testReturning(head, 220);

  freeList(head);
}
