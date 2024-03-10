#include <stdlib.h> int binarySearchLeft(int* nums, int 
numsSize, int target) { int left = 0, right = numsSize - 1; 
while (left <= right) { int mid = left + (right - left) / 2; 
if (nums[mid] < target) { 
left = mid + 1; 
} else { 
right = mid - 1; 
}} 
return left;} 
int binarySearchRight(int* nums, int numsSize, int target) { 
int left = 0, right = numsSize - 1; 
while (left <= right) { int mid = 
left + (right - left) / 2; if 
(nums[mid] <= target) { 
left = mid + 1; 
} else { 
right = mid - 1; 
}} 
return right;} 
int* searchRange(int* nums, int numsSize, int target, int* returnSize) { 
int* result = (int*)malloc(2 * sizeof(int)); result[0] = -1; result[1] = 
-1; 
int leftIndex = binarySearchLeft(nums, numsSize, target); 
int rightIndex = binarySearchRight(nums, numsSize, target); 
if (leftIndex <= rightIndex) { 
result[0] = leftIndex; result[1] 
= rightIndex; 
} 
*returnSize = 2; 
return result; 
} 
