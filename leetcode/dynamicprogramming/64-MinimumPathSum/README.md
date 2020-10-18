# Problem
Leetcode : [here](https://leetcode.com/problems/minimum-path-sum/)

음수가 아닌 숫자로 채워진 m x n 그리드에서 왼쪽 상단에서 오른쪽 하단으로 가는 경로 중 경로에 포함된 숫자들의 합이 가장 작은 경로를 찾아라. 경로를 찾을 때는 오른쪽 또는 아래로만 갈 수 있다.

> 예제:
```
  Input:
  [
    [1.3.1],
    [1,5,1],
    [4,2,1]
  ]
  Output: 7
  Explanation: 1 -> 3 -> 1 -> 1 -> 1

```

# Idea
현재 좌표의 다음 좌표(아래, 오른쪽)에서 출발한 경로 중에 최소값을 찾아서 현재 좌표의 값을 더하면 된다. 수식으로 는 아래와 같다.
```
grid(i, j) = grid(i, j) + min(grid(i+1, j), grid(i, j+1))
```
방향성이 아래와 오른쪽만 있다. 그러니 마지막 좌표부터 역순으로 계산하면 왼쪽으로 쭉 계산하고, 위로 올라가서 왼쪽으로 쭉 계산하고 반복하면 된다. 
```
    [1.3.1]    [1.3.1]    [1.3.1]    [1.3.1]    [1.3.1]
    [1,5,1] -> [1,5,1] -> [1,5,1] -> [1,5,2] -> [1,7,2] -> 
    [4,2,1]    [4,3,1]    [7,3,1]    [7,3,1]    [7,3,1]

    [1.3.1]    [1.3.3]    [1.6.3]    [7.6.3]
->  [8,7,2] -> [8,7,2] -> [8,7,2] -> [8,7,2]
    [7,3,1]    [7,3,1]    [7,3,1]    [7,3,1]
```

# Implementation
맨 아랫줄, 맨 오른쪽줄의 경우 바운더리 넘어가지 않게 체크만 잘 해준다.
```golang
func minPathSum(grid [][]int) int {
    m, n := len(grid[0])-1, len(grid)-1

    for i := n; i >= 0; i-- {
        for j := m; j >= 0; j-- {
            // 제일 아래 가로줄
            if i == n && j != m {
                grid[i][j] = grid[i][j] + grid[i][j + 1]
            } else if i != n && j == m { // 제일 오른족 세로줄
                grid[i][j] = grid[i][j] + grid[i+1][j]
            } else if i != n && j != m {
                min := grid[i+1][j]
                if grid[i][j+1] < min {
                    min = grid[i][j+1]
                }
                grid[i][j] = grid[i][j] + min
            }
        }
    }
    return grid[0][0]
}
```
