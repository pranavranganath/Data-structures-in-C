#include <stdio.h> 
#include <stdlib.h> 
struct Node { 
 int data; 
 struct Node *next; 
}; 
struct Node* createNode(int data) { 
 struct Node* newNode = (struct Node*)malloc(sizeof(struct Node)); 
 if (newNode == NULL) { 
 printf("Memory allocation failed\n"); 
 exit(1); 
 } 
 newNode->data = data; 
 newNode->next = NULL; 
 return newNode; 
} 
struct Node* insertAtBeginning(struct Node *head, int data) { 
 struct Node* newNode = createNode(data); 
 newNode->next = head; 
 return newNode; 
} 
void insertAtPosition(struct Node *head, int data, int position) { 
 struct Node* newNode = createNode(data); 
 struct Node* temp = head; 
 for (int i = 1; i < position - 1; i++) { 
 if (temp == NULL) { 
 printf("Position out of range\n"); 
 return; 
 } 
 temp = temp->next; 
 } 
 if (temp == NULL) { 
 printf("Position out of range\n"); 
 return; 
 } 
 newNode->next = temp->next; 
 temp->next = newNode; 
} 
void insertAtEnd(struct Node *head, int data) { 
 struct Node* newNode = createNode(data); 
 struct Node* temp = head; 
 while (temp->next != NULL) { 
 temp = temp->next; 
 } 
 temp->next = newNode; 
} 
void display(struct Node *head) { 
 struct Node* temp = head; 
 if (temp == NULL) { 
 printf("Linked list is empty\n"); 
 return; 
 } 
 printf("Linked list: "); 
 while (temp != NULL) { 
 printf("%d ", temp->data); 
 temp = temp->next; 
 } 
 printf("\n"); 
} 
int main() { 
 struct Node *head = NULL; 
 head = insertAtBeginning(head, 3); 
 head = insertAtBeginning(head, 2); 
 head = insertAtBeginning(head, 1); 
 display(head); 
 
 insertAtPosition(head, 4, 2); 
 display(head); 
 
 insertAtEnd(head, 5); 
 display(head); 
 
 return 0; 
} 
