) #include <stdio.h> 
#define MAX_SIZE 100 
int queue[MAX_SIZE]; 
int front = -1, rear = -1; 
void insert(int value) { 
 if ((front == 0 && rear == MAX_SIZE - 1) || (rear == (front - 1) % (MAX_SIZE - 1))) 
{ 
 printf("Queue Overflow\n"); 
 return; 
 } else if (front == -1) { 
 front = rear = 0; 
 queue[rear] = value; 
 } else if (rear == MAX_SIZE - 1 && front != 0) { 
 rear = 0; 
 queue[rear] = value; 
 } else { 
 rear++; 
 queue[rear] = value; 
 } 
 printf("%d inserted into the queue\n", value); 
} 
void delete() { 
 if (front == -1) { 
 printf("Queue Underflow\n"); 
 return; 
 } 
 printf("%d deleted from the queue\n", queue[front]); 
 if (front == rear) { 
 front = rear = -1; 
 } else if (front == MAX_SIZE - 1) { 
 front = 0; 
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
 if (rear >= front) { 
 for (int i = front; i <= rear; i++) { 
 printf("%d ", queue[i]); 
 } 
 } else { 
 for (int i = front; i < MAX_SIZE; i++) { 
 printf("%d ", queue[i]); 
 } 
 for (int i = 0; i <= rear; i++) { 
 printf("%d ", queue[i]); 
 } 
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
 insert(4); 
 insert(5); 
 display(); 
 return 0; 
} 
