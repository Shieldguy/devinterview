#include <iostream>
#include <vector>

class Solution {
  public:
   /*
	1	5	2
1	i	ii	iii
5		i	ii
2			i


	1	5	2
1	1
5		5
2			2


	1	5	2
1	1	5
5		5	5
2			2

	1	5	2
1	1	5	3
5		5	5
2			2
*/
    bool PredictTheWinner(std::vector<int>& nums) {
        int n = nums.size();
        int result = 0;
        // get total sum
        int total = 0;
        for(auto x: nums)
            total += x;
        std::vector< std::vector<int> > dp (n, std::vector<int>(n, 0));


        for(int len = 1; len<=n; len++) {
            for(int i =0; i<=n-len; i++) {
                int j = i+len-1;

                int a = (i+1<n && j-1>=0)?dp[i+1][j-1]:0;
                int b = (i+2<n)?dp[i+2][j]:0;
                int c = (j-2>=0)?dp[i][j-2]:0;

                dp[i][j] = std::max(nums[i]+std::min(a,b), nums[j]+std::min(a,c));
            }
        }

        result = dp[0][n-1];
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
