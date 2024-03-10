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
struct Node* deleteFirst(struct Node *head) { 
 if (head == NULL) { 
 printf("Linked list is empty\n"); 
 return NULL; 
 } 
 struct Node* temp = head; 
 head = head->next; 
 free(temp); 
 return head; 
} 
struct Node* deleteLast(struct Node *head) { 
 if (head == NULL) { 
 printf("Linked list is empty\n"); 
 return NULL; 
 } 
 if (head->next == NULL) { 
 free(head); 
 return NULL; 
 } 
 struct Node* temp = head; 
 struct Node* prev = NULL; 
 while (temp->next != NULL) { 
 prev = temp; 
 temp = temp->next; 
 } 
 free(temp); 
 prev->next = NULL; 
 return head; 
} 
struct Node* deleteElement(struct Node *head, int data) { 
 if (head == NULL) { 
 printf("Linked list is empty\n"); 
 return NULL; 
 } 
 struct Node* temp = head; 
 struct Node* prev = NULL; 
 if (temp != NULL && temp->data == data) { 
 head = temp->next; 
 free(temp); 
 return head; 
 } 
 while (temp != NULL && temp->data != data) { 
 prev = temp; 
 temp = temp->next; 
 } 
 if (temp == NULL) { 
 printf("Element not found\n"); 
 return head; 
 } 
 prev->next = temp->next; 
 free(temp); 
 return head; 
} 
int main() { 
 struct Node *head = NULL; 
 head = insertAtBeginning(head, 1); 
 head = insertAtBeginning(head, 2); 
 head = insertAtBeginning(head, 3); 
 display(head); 
 head = deleteFirst(head); 
 display(head); 
 head = deleteElement(head, 2); 
 display(head); 
 head = deleteLast(head); 
 display(head); 
 
 return 0; 
} 
