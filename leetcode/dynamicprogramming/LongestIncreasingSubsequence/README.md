# Problem

[486. Predict the Winner](hhttps://leetcode.com/problems/predict-the-winner/)

주어진 Integer로 이루어진 unsorted array 에서 LIS ( Longest Increasing Subsequence)
를 구하고, 이에 대한 Length 를 Return 하라.

Note:
1개 이상의 LIS 조합이 있을수 있으며 LIS의 Length만 리턴
Target Time Complexity 는 O(n^2) 로 제한

Follow up: O(n log n) 으로 improve 가능한가?

# Idea

DP[i] 는 i번째의 element로 끝나는 array의 LIS 의 Length이다.
i 의 초기 값은 1 번째이며 j의 초기값은 0이다.
각 i번째 마다 j르 0번째 부터 비교하며 max longest값을 구한다.
```
DP(i) = 1 + max( DP(j) )
        where 0 < j < i and nums[j] < nums[i];
    or DP(i) = 1, if no such j exists.

        Index     0  1  2  3  4  5   6  7
        nums[]   10  9  2  5  3  7 101 18
        DP[]      1  1  1  2  2  3   4  4
```

# Implementation

* [c++11 NSQUARE](LIS_NSQUARE.cpp)
```
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
```
# Complexity

```
    Time Complexity - O(N^2)
    Space Complexity - O(N)
```

* [c++11 NLOGN](LIS_NLOGN.cpp)

n log n 방식
Binary Search 를 활용해서 보조 Array(DP)에 LIS List 를 저장
DP(i) 는 현재 element를 활용한 LIS를 저장함.

만약 nums[i+1]의 값이
    DP[n-1] 값보다 크다면, DP 에 push_back. LIS의 Length++
                 작다면, Binary Search로 적절한 DP[index]에 replace

```
   [10, 9, 2, 5, 3, 7, 101, 18]
        10 -> [10]
        9 -> [9] // replace 10 with 9
        2 -> [2] // replace 9 with 2
        5 -> [2, 5]
        3 -> [2, 3] // repace 5 with 3
        7 -> [2, 3, 7]
        101 -> [2, 3, 7, 101]
        18 -> [2, 3, 7, 18] // replace 101 with 3

```

```
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

```

# Complexity

```
    Time Complexity - O(NLOGN)
    Space Complexity - O(N)
```


