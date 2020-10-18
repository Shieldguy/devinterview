#include <iostream>
#include <vector>
#include <string.h>

class Solution {
public:
    int lengthOfLIS(std::vector<int>& nums) {
        if(nums.size()==0 )
            return 0;
        if(nums.size()==1)
            return 1;

        int dp[nums.size()];
        memset(dp, 0x0, sizeof(int)*nums.size());
        dp[0] = 1;
        int result = 1;
        for(int i= 1; i < nums.size(); i++) {
            int temp =0;
            for(int j=0; j<i; j++) {
                if(nums[j]<nums[i]) {
                    temp = std::max(temp, dp[j]);
                }
            }
            dp[i] = temp +1;
            result = std::max(result, dp[i]);
        }
        return result;
    }
};

int main() {
  Solution s;
  std::vector<int> input = {10,9,2,5,3,7,101,18};
  std::cout<<(s.lengthOfLIS(input))<<std::endl;
}

