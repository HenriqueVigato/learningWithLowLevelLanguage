#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

Node *insertAtBegining(Node *head, int data) {
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

Node *insertMiddle(Node *head, int data, int previous) {
  Node *newNode = createNode(data);

  Node *temp = head;
  while (temp->data != previous) {
    temp = temp->next;
  }
  newNode->next = temp->next;
  temp->next = newNode;

  return head;
}

Node *deleteNode(Node *head, int target) {
  Node *temp = head;
  while (temp->next->data != target) {
    temp = temp->next;
  }
  temp->next = temp->next->next;
  return head;
}

void printList(Node *head) {
  Node *temp = head;
  printf("{ ");
  while (temp != NULL) {
    printf("%d  ", temp->data);
    temp = temp->next;
  }
  printf("}");
  printf("\n");
}
void freeMemList(Node *head) {
  Node *temp;
  while (temp != NULL) {
    temp = head;
    head = head->next;
    free(temp);
  }
}

void testLinkedList() {
  Node *head = NULL;
  head = insertAtBegining(head, 10);
  assert(head->data == 10);
  head = insertAtEnd(head, 22);
  assert(head->next->data == 22);
  head = insertMiddle(head, 15, 10);
  assert(head->next->data == 15);
  assert(head->next->next->data == 22);
  printList(head);
  head = deleteNode(head, 15);
  assert(head->next->data == 22);

  printList(head);
  freeMemList(head);
}

//     Sorting the linked list
Node *createATestList() {
  Node *head = NULL;
  int data[17] = {3,  4,  5,   61, 1,  2,  8,   9,  23,
                  11, 24, 576, 75, 45, 33, 221, 256};
  for (int i = 0; i < 17; i++) {
    head = insertAtBegining(head, data[i]);
  }
  return head;
}

int sizeOfList(Node *head) {
  Node *temp = head;
  int sizeOf = 0;
  while (temp != NULL) {
    sizeOf++;
    temp = temp->next;
  }
  return sizeOf;
}

void swap(Node *addr1, Node *addr2) {
  int temp = addr1->data;
  addr1->data = addr2->data;
  addr2->data = temp;
}

void bubblesort(Node *head) {
  int size = sizeOfList(head);
  for (int i = 0; i < size; i++) {
    Node *temp = head;
    while (temp->next != NULL) {
      if (temp->data > temp->next->data) {
        if (temp == head) {
          swap(temp, temp->next);
        } else {
          swap(temp, temp->next);
        }
      } else {
        temp = temp->next;
      }
    }
  }
}

int main() {
  Node *test = createATestList();
  printList(test);

  assert(sizeOfList(test) == 17);

  bubblesort(test);
  printList(test);
}
// main function
// int main() { testLinkedList(); }
