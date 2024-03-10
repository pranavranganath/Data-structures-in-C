 int getLength(struct ListNode 
*head) { 
int length = 0; while 
(head != NULL) { 
length++; head 
= head->next; 
} 
return length; 
} 
struct ListNode *advanceList(struct ListNode *head, int steps) { 
while (steps > 0) { 
head = head->next; 
steps--; 
} 
return head; 
} 
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode 
*headB) { 
int lengthA = getLength(headA); int lengthB = getLength(headB); if (lengthA > 
lengthB) { headA = advanceList(headA, lengthA - lengthB); 
} else { 
headB = advanceList(headB, lengthB - lengthA); 
} 
while (headA != NULL && headB != NULL) { 
if (headA == headB) { return 
headA; // Intersection found. } 
headA = headA->next; 
headB = headB->next; 
} 
return NULL; 
} 
struct ListNode *createNode(int val) { struct ListNode *newNode = (struct 
ListNode *)malloc(sizeof(struct ListNode)); if (newNode == NULL) { 
printf("Memory allocation failed\n"); 
exit(1); 
} 
newNode->val = val; 
newNode->next = NULL; return 
newNode; 
} 
void freeLinkedList(struct ListNode *head) { 
struct ListNode *temp; while (head != 
NULL) { temp = head; head = 
head->next; free(temp); 
}} 
