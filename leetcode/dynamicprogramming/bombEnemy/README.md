# 361. Bomb Enemy

- source: https://leetcode.com/problems/bomb-enemy/

## Approach
```
    get the maximum count to kill enemy between starting left and staring right.
```

## Complexity
```
    O(n*n)
```

## Explanation
```
		// from left to right
		for (int i = 0; i < Y; i++) {
			int row = 0;
			for (int j = 0; j < X; j++) {
		...

		// from right to left
		for (int i = 0; i < Y; i++) {
			int row = 0;
			for (int j = 0; j < X; j++) {
		...
		
					ans = Math.max(ans, dp[i][j]);
		
```
