#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  int data;
  struct Node *next;
} Node;

Node *createNode(int data) {
  Node *newNode = (Node *)malloc(sizeof(Node));
  newNode->data = data;
  newNode->next = NULL;

  return newNode;
}

Node *insertAtBeginnig(Node *head, int data) {
  Node *newNode = createNode(data);

  newNode->next = head;
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

  return head;
}

void printList(Node *head) {
  Node *temp = head;

  while (temp != NULL) {
    printf("%d\n", temp->data);
    temp = temp->next;
  }

  printf("\n");
}

void freeList(Node *head) {
  Node *temp;

  while (temp != NULL) {
    temp = head;
    head = head-> next;
    free(temp);
  }
}

int main() {
  Node *head = NULL;

  head = insertAtBeginnig(head, 44);
  head = insertAtBeginnig(head, 54);
  head = insertAtBeginnig(head, 36);

  printf("Lista apos isnercaoes no inicio:\n");
  printList(head);

  head = insertAtEnd(head, 55);
  head = insertAtEnd(head, 78);

  printf("Lista apos insercao no final: \n");
  printList(head);

  return 0;
}
