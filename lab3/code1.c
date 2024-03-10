) #include <stdio.h> 
#define MAX_SIZE 100 
int queue[MAX_SIZE]; 
int front = -1, rear = -1; 
void insert(int value) { 
 if (rear == MAX_SIZE - 1) { 
 printf("Queue Overflow\n"); 
 return; 
 } 
 if (front == -1) 
 front = 0; 
 rear++; 
 queue[rear] = value; 
 printf("%d inserted into the queue\n", value); 
} 
void delete() { 
 if (front == -1) { 
 printf("Queue Underflow\n"); 
 return; 
 } 
 printf("%d deleted from the queue\n", queue[front]); 
 if (front == rear) { 
 front = -1; 
 rear = -1; 
 } else { 
 front++; 
 } 
} 
void display() { 
 if (front == -1) { 
 printf("Queue is empty\n"); 
 return; 
 } 
 printf("Queue elements: "); 
 for (int i = front; i <= rear; i++) { 
 printf("%d ", queue[i]); 
 } 
 printf("\n"); 
} 
int main() { 
 insert(1); 
 insert(2); 
 insert(3); 
 display(); 
 delete(); 
 display(); 
 return 0; 
} 
