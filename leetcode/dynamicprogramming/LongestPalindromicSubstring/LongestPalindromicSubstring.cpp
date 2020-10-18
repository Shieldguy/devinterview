/* Leetcode #5 Longest Palindromic Substring*/
#include <iostream>

class Solution {
    public:
        std::string longestPalindrome(std::string s) {
        int n = s.size();
        if(n<2)
            return s;

        bool dp[n][n];
        memset(dp, 0x0, sizeof(bool)*(n)*(n));

        std::string result ="";
        int startIdx = 0;
        int maxLength = 1;

        for(int i=0; i<n; i++){
            dp[i][i] = true; // 1 character
        }

        for(int l=n-2; l>=0; l--){
            for(int r=l+1; r<n;r++){
                if(s[l] == s[r]){
                    if((r-l == 1) // if there are 2 adjacent character
                        || (dp[l+1][r-1])){
                        dp[l][r] = true;
                        if(maxLength < (r-l+1)){
                            startIdx = l;
                            maxLength = r-l+1;
                        }
                    }
                }
            }
        }
        return s.substr(startIdx, maxLength);
    }
};

// Driver Code
int main() {
    Solution s;
    std::string str = "abdbca";
    std::string result = s.longestPalindrome(str);
    std::cout<<"\n"<<result<<"\nLength is: " <<result.size();
    return 0;
}
