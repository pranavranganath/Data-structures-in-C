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
struct Node* push(struct Node *top, int data) { 
 struct Node* newNode = createNode(data); 
 newNode->next = top; 
 return newNode; 
} 
struct Node* pop(struct Node *top) { 
 if (top == NULL) { 
 printf("Stack is empty\n"); 
 return NULL; 
 } 
 struct Node* temp = top; 
 top = top->next; 
 free(temp); 
 return top; 
} 
struct Node* enqueue(struct Node *rear, int data) { 
 struct Node* newNode = createNode(data); 
 if (rear == NULL) { 
 return newNode; 
 } 
 rear->next = newNode; 
 return newNode; 
} 
struct Node* dequeue(struct Node *front) { 
 if (front == NULL) { 
 printf("Queue is empty\n"); 
 return NULL; 
 } 
 struct Node* temp = front; 
 front = front->next; 
 free(temp); 
 return front; 
} 
void display(struct Node *head) { 
 struct Node* temp = head; 
 if (temp == NULL) { 
 printf("List is empty\n"); 
 return; 
 } 
 printf("List: "); 
 while (temp != NULL) { 
 printf("%d ", temp->data); 
 temp = temp->next; 
 } 
 printf("\n"); 
} 
int main() { 
 struct Node *stackTop = NULL; // Top of the stack 
 struct Node *queueFront = NULL; // Front of the queue 
 struct Node *queueRear = NULL; // Rear of the queue 
 stackTop = push(stackTop, 1); 
 stackTop = push(stackTop, 2); 
 stackTop = push(stackTop, 3); 
 printf("Stack after pushing elements: "); 
 display(stackTop); 
 stackTop = pop(stackTop); 
 printf("Stack after popping an element: "); 
 display(stackTop); 
 queueRear = enqueue(queueRear, 1); 
 queueRear = enqueue(queueRear, 2); 
 queueRear = enqueue(queueRear, 3); 
 printf("Queue after enqueuing elements: "); 
 display(queueRear); 
 
 queueFront = dequeue(queueFront); 
 printf("Queue after dequeuing an element: "); 
 display(queueFront); 
 
 return 0; 
} 
