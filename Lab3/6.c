/*You are given a string s, which contains hashtags #.
In one operation, you can:
1. Choose a hashtag # in s.
2. Remove the closest non-hashtag character to its left and remove the hashtag itself.
Return the string after all hashtags have been removed.

Note:
The input will be generated such that the operation is always possible.
It can be shown that the resulting string will always be unique.

Input Format:
A string s, consisting of lowercase English letters and hashtags #

Output Format:
A string, representing the final string after performing all the operations.
 
Sample Input 1 :
abc###def#g##

Sample Output 1:
d

Sample Input 2 :
pqr#stu##vw###

Sample Output 2:
pq*/

#include <stdio.h>
#include <string.h>

char* removeHashtags(char* s) {
    int j = 0;
    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] == '#') {
            if (j > 0) {
                j--; // Remove the closest non-hashtag character
            }
        } else {
            s[j++] = s[i]; // Keep the character
        }
    }
    s[j] = '\0';
    return s;
}


int main() {
    char s[1000];
    scanf("%s", s);
    printf("%s", removeHashtags(s));
    return 0;
}

