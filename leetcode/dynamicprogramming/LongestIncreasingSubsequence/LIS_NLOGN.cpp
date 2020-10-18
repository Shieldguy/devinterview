#include <iostream>
#include <vector>
#include <string.h>

class Solution {
public:
    int lengthOfLIS(std::vector<int>& nums) {
       std::vector<int> dp;

        for (int i = 0; i < nums.size(); i++) {
            if (i==0 || dp[dp.size() - 1] < nums[i]) {
                dp.push_back(nums[i]);
            }
            else {
                int l = 0, r = dp.size() - 1;
                while (l <= r) {
                    int m = l + (r-l) / 2;
                    if(dp[m] == nums[i]) {
                       l = m;
                       break;
                    }
                    if (dp[m] > nums[i]) {
                        r = m - 1;
                    }
                    else {
                        l = m + 1;
                    }
                }
                dp[l] = nums[i];
            }
        }
        return dp.size();
    }
};

//Driver code
int main() {
  Solution s;
  std::vector<int> input = {10,9,2,5,3,7,101,18};
  std::cout<<(s.lengthOfLIS(input))<<std::endl;
}

