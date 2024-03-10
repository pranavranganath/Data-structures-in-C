#include <stdlib.h> #include <stdio.h> 
int leftHeight(struct TreeNode* node) { 
int height = 0; 
while (node) { 
height++; node = 
node->left; 
} 
return height;} 
int countNodes(struct TreeNode* root) { 
if (!root) { 
return 0;} 
int leftHeightVal = leftHeight(root); int 
rightHeightVal = leftHeight(root->right); if 
(leftHeightVal == rightHeightVal) { return 
(1 << leftHeightVal) - 1; 
} else { 
return 1 + countNodes(root->left) + countNodes(root->right); 
}}
