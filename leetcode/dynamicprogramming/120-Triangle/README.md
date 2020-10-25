# [120. Triangle](https://leetcode.com/problems/triangle/)

## Problem
- 다음과 같은 트라이앵글 형태의 어레이가 주어짐
```
[
     [2],
    [3,4],
   [6,5,7],
  [4,1,8,3]
]
```
- 트라이앵글 어레이에서 맨위에서 맨 아래까지 합한수가 가장 작은 값을 구하는 것임.
- 2 -> 3 -> 5 -> 1 이 가장 작은 값을 가지는 루트이며 합은 11이 됨
- 알고리즘 연산시 O(n) 의 메모리만 사용할 것. n 는 행의 갯수

## Basic idea
- top down 방식
  - 상위 로우의 (x, y-1) 과 (x+1, y-1) 중에 작은 값을 (x, y) 에 합산하는 형태로 처리
  - 최종 연산된 로우에서 가장 작은 값이 답
- bottom up 방식
  - 하위 로우의 (x, y+1) 과 (x+1, y+1) 중에 작은 겂을 (x, y)에 합산하는 형태로 처리
  - 최종 연산된 0번째 인덱스의 값이 최종 답

## Code
```java
public class Solution {
    public int minimumTotal(List<List<Integer>> triangle) {
        int n = triangle.size();
        int[] tmp = new int[n];   // it is same as last row count;
        for(int i = 0; i < n; i++)
            tmp[i] = triangle.get(n-1).get(i);
        for(int i = n-2; i >= 0; i--) {
            for(int j = 0; j < triangle.get(i).size(); j++) {
                tmp[j] = Math.min(tmp[j], tmp[j+1]) + triangle.get(i).get(j);
            }
        }
        return tmp[0];
    }
}
```
