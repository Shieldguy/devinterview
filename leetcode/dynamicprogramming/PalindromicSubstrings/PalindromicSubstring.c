/*  leetcode - 647. Palindromic Substrings */
#include <stdio.h>
#include <string.h>

int countSubstrings(char * s){
    int n = strlen(s);
    if(n<2)
        return n;

    int dp[n][n];
    memset(dp, 0x0, sizeof(int)*n*n);
    int result = 0;

    for(int i=0; i<n; i++) {
        dp[i][i] = 1; // 1 character. Increase number of palindrome
        result++;
    }

    for(int left = n-1; left>=0; left--) {
        for(int right = left+1; right<n; right++) {
            if(s[left] == s[right]) {
                if((right-left == 1) // 2 adjacent character. Increase number of palindrome
                   || (dp[left+1][right-1])) {
                    dp[left][right] = 1;
                    result++;
                }
            }
        }
    }
    return result;
}

// Driver Code
int main(void) {
  printf("countSubstrings %d\n", countSubstrings("adabca"));
  return 0;
}
