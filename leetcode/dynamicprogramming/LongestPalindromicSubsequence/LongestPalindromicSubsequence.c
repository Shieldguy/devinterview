/*  516. Longest Palindromic Subsequence */
#include <stdio.h>
#include <string.h>

#define max(a,b) (((a)>(b))?(a):(b))

int longestPalindromeSubseq(char * s){
    int n = strlen(s);
    if(n<2)
        return n;

    int dp[n][n];
    memset(dp, 0x0, sizeof(int)*n*n);

    for(int i=0; i<n; i++) {
        dp[i][i] = 1; // 1 character. Increase number of palindrome
    }

    for(int left = n-1; left>=0; left--) {
        for(int right = left+1; right<n; right++) {
            if(s[left] == s[right]) {
                dp[left][right] = 2+dp[left+1][right-1]; // check diagonal
            }
            else {
                dp[left][right] = max(dp[left+1][right], dp[left][right-1]); // Check max of down and below
            }
        }
    }
    return dp[0][n-1];
}

int main(void) {
  printf("LongestPalindromeSubSeq %d\n", longestPalindromeSubseq("abdbca"));
  return 0;
}
