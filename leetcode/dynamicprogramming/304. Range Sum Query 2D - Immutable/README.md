# [304. Range Sum Query 2D - Immutable](https://leetcode.com/problems/range-sum-query-2d-immutable/)

- source:https://leetcode.com/problems/range-sum-query-2d-immutable/

## Problem
```

```
## Approach
```
    sum[m][n] = matrix[m][n] + sum[m-1][n] + sum[m][n-1] - sum[m-1][n-1]

    suppose the matrix like follow
    matrix[][] = 
    [ 3, 0, 1, 4, 2],
    [ 5, 6, 3, 2, 1],
    [ 1, 2, 0, 1, 5],
    [ 4, 1, 0, 1, 7],
    [ 1, 0, 3, 0, 5]

    create the matrix where each cell represents the cumulative sum up to current cell.
    to caculate generallay, expand matrix n*n into matrx (n+1)*(n+1)
    intialize sum[][] =
    [0, 0, 0, 0, 0, 0],
    [0, 0, 0, 0, 0, 0],
    [0, 0, 0, 0, 0, 0],    
    [0, 0, 0, 0, 0, 0],
    [0, 0, 0, 0, 0, 0],
    [0, 0, 0, 0, 0, 0],    

    sum[m][n] = matrix[m][n] + sum[m-1][n] + sum[m][n-1] - sum[m-1][n-1]
    ==> changed expression 
    sum[m][n] = matrix[m-1][n-1] + sum[m-1][n] + sum[m][n-1] - sum[m-1][n-1]
        
    sum[1][1] = matrix[0][0] + sum[0][1] + sum[1][0] - sum[0][0]
    = 3 + 0 + 0 - 0 = 3
    sum[1][2] = matrix[0][1] + sum[0][2] + sum[1][1] - sum[0][1]
    = 0 + 0 + 3 - 0 = 3
    sum[2][1] = matrix[1][0] + sum[1][1] + sum[2][0] - sum[1][0]
    = 5 + 3 + 0 - 0 = 8
    sum[2][2] = matrix[1][1] + sum[1][2] + sum[2][1] - sum[1][1]
    = 6 + 3 + 8 - 3 = 14

    [0, 0, 0, 0, 0, 0],
    [0, 3, 3, 0, 0, 0],
    [0, 8,14, 0, 0, 0],    
    [0, 0, 0, 0, 0, 0],
    [0, 0, 0, 0, 0, 0],
    [0, 0, 0, 0, 0, 0],    

```
## Implementation
```
    * [c++11](Immutable.cpp)        
```

## Complexity
```
    Time Complexity - O(N)
    Space Complexity - my solution is O(N), optimal might be O(1) with updating directly to the matrix
    
```

