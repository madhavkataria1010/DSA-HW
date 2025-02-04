/*You are given an integer array nums. The range of a subarray of nums is the difference between the largest and smallest element in the subarray.

Return the sum of all subarray ranges of nums.

A subarray is a contiguous non-empty sequence of elements within an array.

Note: You are required to solve this problem using stacks.
Expected Time  Complexity is O(N) . 

Constraints:

1 <= nums.length <= 1000
-109 <= nums[i] <= 109

Input:
The first line contains an integer n, representing the size of the array.
The second line contains n space-separated integers, representing the elements of the array.
Output:
A single integer representing the sum of all subarray ranges.
Sample Input-1
3  
1 2 3  
Sample Output-1
4  */

#include <stdio.h>
#include <stdlib.h>

int main(){
    int n;
    scanf("%d", &n);
    int nums[n];
    for (int i = 0; i < n; i++){
        scanf("%d", &nums[i]);
    }
    
    int leftGreater[n], rightGreater[n];
    int leftLess[n], rightLess[n];
    
    int stack[n], topIndex = -1;
    
    for (int i = 0; i < n; i++){
        while(topIndex != -1 && nums[stack[topIndex]] <= nums[i])
            topIndex--;
        leftGreater[i] = (topIndex == -1) ? -1 : stack[topIndex];
        stack[++topIndex] = i;
    }
    
    topIndex = -1;
    for (int i = n-1; i >= 0; i--){
        while(topIndex != -1 && nums[stack[topIndex]] < nums[i])
            topIndex--;
        rightGreater[i] = (topIndex == -1) ? n : stack[topIndex];
        stack[++topIndex] = i;
    }
    
    topIndex = -1;
    for (int i = 0; i < n; i++){
        while(topIndex != -1 && nums[stack[topIndex]] >= nums[i])
            topIndex--;
        leftLess[i] = (topIndex == -1) ? -1 : stack[topIndex];
        stack[++topIndex] = i;
    }
    
    topIndex = -1;
    for (int i = n-1; i >= 0; i--){
        while(topIndex != -1 && nums[stack[topIndex]] > nums[i])
            topIndex--;
        rightLess[i] = (topIndex == -1) ? n : stack[topIndex];
        stack[++topIndex] = i;
    }
    
    long long sumMax = 0, sumMin = 0;
    for (int i = 0; i < n; i++){
        long long countMax = (long long)(i - leftGreater[i]) * (rightGreater[i] - i);
        long long countMin = (long long)(i - leftLess[i]) * (rightLess[i] - i);
        sumMax += nums[i] * countMax;
        sumMin += nums[i] * countMin;
    }
    
    printf("%lld\n", sumMax - sumMin);
    return 0;
}