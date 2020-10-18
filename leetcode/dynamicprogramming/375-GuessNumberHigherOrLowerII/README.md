# 375. Guess Number Higher or Lower II

- source: https://leetcode.com/problems/guess-number-higher-or-lower-ii/

## Approach
```
    DP and optimization
```

## Complexity
```
    O(n^2)
```

## Explanation
```
    1) MinMax Algolism : https://www.youtube.com/watch?v=ZPtqO-d8eXg
    체스, 오목, low-high 등 게임 및 AI 알고리즘에서 사용되는 최적 선택 상황에서 사용
    
     for(int i=l; i<=r; i++) {
       ans = Math.min(ans, i + Math.max(helper(low, i-1), helper(i+1, high)));
     }

    2) DP memorization
    3) Optimize
    
        int ans = Integer.MAX_VALUE;    => 변수 사용
        int m = l + (r - l) / 2; // mid point 추가로 iteration 범위 줄임
        for (int i=m; i <= r; i++) {
            ans = Math.min(ans, i + Math.max(helper(l, i-1, dp), helper(i+1, r, dp)));
        }
        dp[l][r] = ans;
        
```
