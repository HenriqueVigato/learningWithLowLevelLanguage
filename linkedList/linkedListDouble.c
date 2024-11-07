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

Node *insertAtMiddle(Node *head, int data, int previous) {
  Node *newNode = createNode(data);

  if (head == NULL) {
    return NULL;
  }

  Node *temp = head;

  while (temp->data != previous) {
    temp = temp->next;
  }

  newNode->next = temp->next;
  newNode->previous = temp;

  temp->next->previous = newNode;
  temp->next = newNode;

  return head;
}

// TODO: criar uma funcao que delete os itens da lista ligada.
Node *deleteItem(Node *head, int target) {
  Node *temp = head;

  if (head == NULL) {
    return NULL;
  }

  // Caso o item a ser deletado e o primeiro da lista
  if (head->data == target) {
    temp->next->previous = NULL;
    return temp->next;
  }

  while (temp->next->data != target) {
    temp = temp->next;
  }

  Node *to_be_deleted = temp->next;

  // verifica se o item apos oque vai ser deletado e nulo ou nao
  if (temp->next->next == NULL) {
    temp->next = NULL;
    return head;
  }

  temp->next->next->previous = temp;
  temp->next = temp->next->next;

  free(to_be_deleted);

  return head;
}

// TODO: criar um metodo para organizar a lista ligada
// TODO: criar uma metodo para busacar itens da lista ligada
//

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
  printf("Lista apos insercao no final \n");
  printList(head);

  printf("Testando andar para tras no meio da lista \n");
  testReturning(head, 220);

  head = insertAtMiddle(head, 222, 200);
  head = insertAtMiddle(head, 333, 300);
  head = insertAtMiddle(head, 444, 400);
  printf("Testando inserir no meio da lista! \n");
  printList(head);

  head = deleteItem(head, 444);
  head = deleteItem(head, 440);
  head = deleteItem(head, 400);
  printf("Apos excluir algum iten \n");
  printList(head);

  freeList(head);
}
