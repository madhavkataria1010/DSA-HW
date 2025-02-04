/*Question: Remove K Digits to Form the Largest Number
Problem Statement
Given a string num representing a non-negative integer num, and an integer k, remove exactly k digits from num such that the resulting number is as large as possible. If removing all the digits results in an empty string, return "0".
Example 1
Input: num = "1432219", k = 3
Output: "4329"
Explanation:.
Remove the three digits 1, 2, and 1  to form the new number 4329, which is the largest possible number you can create after 3 removals.
Example 2
Input: num = "10200", k = 1
Output: "2000"
Explanation:
If we remove the 1, we get "0200". After removing leading zeros, the number is "2000".
Notice that removing any other digit (like removing 0 from "10200") would not yield as large a number.
Example 3
Input: num = "10", k = 2
Output: "0"
Explanation:
After removing both digits, you are left with an empty string, which should be interpreted as "0".*/

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

void swapChar(char* a, char* b) {
}

void removeKdigitsToFormLargest(const char* num, int k, char* result) {
    int n = strlen(num);
    int idx = 0;
    for (int i = 0; i < n; i++) {
        while (idx > 0 && k > 0 && result[idx - 1] < num[i]) {
            idx--;
            k--;
        }
        result[idx++] = num[i];
    }
    idx -= k;
    result[idx] = '\0';
    int i = 0;
    while (result[i] == '0' && i < idx - 1) i++;
    memmove(result, result + i, idx - i + 1);
    if (result[0] == '\0')
        strcpy(result, "0");
}

int main() {
    char num[100001];
    int k;
    scanf("%s %d", num, &k);
    char largestNumber[100001];
    removeKdigitsToFormLargest(num, k, largestNumber);
    printf("%s\n", largestNumber);
    return 0;
}