#include <iostream>
#include <vector>

class Solution {
  public:
    int helper(std::vector<int>& nums, std::vector<std::vector<int>>& dp, int i, int j) {
        if(i>j)
            return 0;

        if(dp[i][j]!=-1)
            return dp[i][j];

        dp[i][j] = std::max((nums[i]+std::min(helper(nums, dp, i+2, j), helper(nums, dp, i+1, j-1))),
                        (nums[j]+std::min(helper(nums, dp, i+1, j-1), helper(nums, dp, i, j-2))));

        return dp[i][j];
    }

    bool PredictTheWinner(std::vector<int>& nums) {
        int n = nums.size();
        int result = 0;
        // get total sum
        int total = 0;
        for(auto x: nums)
            total += x;

        std::vector< std::vector<int> > dp (n, std::vector<int>(n, -1));

        result = helper(nums, dp, 0, n-1);

        return (result >= total-result);
    }
};
//Driver code
int main()
{
  Solution s;
  std::vector<int> input = {1,5,2};
  std::cout<<((s.PredictTheWinner(input))?"WIN":"LOST")<<std::endl;
}
