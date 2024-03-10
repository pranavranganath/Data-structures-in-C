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
void sortLinkedList(struct Node *head) { 
 struct Node *current = head, *index = NULL; 
 int temp; 
 if (head == NULL) { 
 printf("Linked list is empty\n"); 
 return; 
 } 
 while (current != NULL) { 
 index = current->next; 
 while (index != NULL) { 
 if (current->data > index->data) { 
 temp = current->data; 
 current->data = index->data; 
 index->data = temp; 
 } 
 index = index->next; 
 } 
 current = current->next; 
 } 
} 
struct Node* reverseLinkedList(struct Node *head) { 
 struct Node *prev = NULL, *current = head, *next = NULL; 
 while (current != NULL) { 
 next = current->next; 
 current->next = prev; 
 prev = current; 
 current = next; 
 } 
 head = prev; 
 return head; 
} 
struct Node* concatenateLists(struct Node *list1, struct Node *list2) { 
 struct Node *temp = list1; 
 if (list1 == NULL) { 
 return list2; 
 } 
 while (temp->next != NULL) { 
 temp = temp->next; 
 } 
 temp->next = list2; 
 return list1; 
} 
int main() { 
 struct Node *list1 = NULL, *list2 = NULL; 
 list1 = insertAtBeginning(list1, 3); 
 list1 = insertAtBeginning(list1, 2); 
 list1 = insertAtBeginning(list1, 1); 
 printf("Original list 1: "); 
 display(list1); 
 sortLinkedList(list1); 
 printf("Sorted list 1: "); 
 display(list1); 
 list1 = reverseLinkedList(list1); 
 printf("Reversed list 1: "); 
 display(list1); 
 list2 = insertAtBeginning(list2, 6); 
 list2 = insertAtBeginning(list2, 5); 
 list2 = insertAtBeginning(list2, 4); 
 printf("Original list 2: "); 
 display(list2); 
 list1 = concatenateLists(list1, list2); 
 printf("Concatenated list: "); 
 display(list1); 
 
 return 0; 
}
