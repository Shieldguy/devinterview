/*  5. Longest Palindromic Substring */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char * longestPalindrome(char * s){
    int n = strlen(s);
    if(n<2)
        return s;

    int dp[n][n];
    memset(dp,0x0, sizeof(int)*n*n);
    int startIdx = 0, maxLen = 1;

    for(int i=0; i<n; i++)
        dp[i][i] = 1; // diagonal, 1 character

    for(int left = n-2; left>=0; left--) {
        for(int right = left+1; right<n; right++) {
            if(s[left] == s[right]) {
                if((right-left ==1) // 2 adjacent characters
                  || dp[left+1][right-1]) {
                    dp[left][right] = 1;
                    if(maxLen<(right-left+1)) {
                        maxLen = right-left+1;
                        startIdx = left;
                    }
                }
            }
        }
    }

    char *res = (char *)malloc(maxLen*sizeof(char)+1);
    memcpy(res, &s[startIdx], maxLen);
    res[maxLen] = '\0';
    return res;
}

int main(void) {
  printf("Longest Palindrome Substring: %s\n", longestPalindrome("abdbca"));
  return 0;
}
