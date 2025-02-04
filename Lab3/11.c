/*Given a sequence of n strings, the task is to check if any similar words come together and destroy each other, then print the number of words left in the sequence after this pairwise destruction.

Examples: 
Input : ab aa aa bcd ab
Output : 3
As aa and aa destroy each other, ab bcd ab is the new sequence.

Input:  tom jerry jerry tom
Output : 0
First, both 'Jerry' destroy each other. Then, the sequence will be Tom and Tom, and they will also destroy each other. So, the final sequence doesn't have any words.

Using Stack
1- Start traversing the strings and push into the stack.
    a) Check if the current string is the same as the string
       at the top of the stack
        i) If yes, pop the string from the top.
        ii) Else push the current string.
2- Return stack size if the whole sequence is traversed.

Time Complexity: O(N), where N is the size of the given sequence.
Auxiliary Space: O(N), since we use a stack to store the sequence. */

#include <stdio.h>
#include <string.h>

#define MAX 100

int main() {
    int n;
    int top = -1; 
    char stack[MAX][101]; 
    char word[101]; 

    printf("Enter the number of words: ");
    scanf("%d", &n);
    
    printf("Enter the sequence of words: ");
    for (int i = 0; i < n; i++) {
        scanf("%s", word);
        
        if (top >= 0 && strcmp(word, stack[top]) == 0) {
            top--;
        } else {
            top++;
            strcpy(stack[top], word);
        }
    }
    
    printf("Number of words left: %d\n", top + 1);
    
    return 0;
}