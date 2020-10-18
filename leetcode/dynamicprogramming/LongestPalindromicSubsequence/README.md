# [516. Longest Palindromic Subsequence](https://leetcode.com/problems/longest-palindromic-subsequence/)

- source:https://leetcode.com/problems/longest-palindromic-subsequence/

## Approach
```
  DP[left][right] is true if s[left..right] is a palindrome
  If s[left] == s[right], and in case DP[left+1][right-1],
  then s[left+1...right-1] is a palindrome.
  Accumulate value of DP when we find palindrome then increase length to 2
  If we cannot find palindrome, then copy max value of previous left or
  right index's DP value.

                    right >>
                 0 1 2 3 4 5
                 a b d b c a
             0 a 1 1 1 3 3 5
             1 b   1 1 3 3 3
          ^  2 d     1 1 1 1
          ^  3 b       1 1 1
          l  4 c         1 1
          e  5 a           1
          f
          t
```

## Complexity
```
    Time Complexity - O(N^2)
    Space Complexity - O(N^2)
```
## Explanation
```
    IF (s[left] == s[right])
        Increase D(left,right) to 2 + DP(left+1, right-1)
    ELSE
        Get D(left,right) = max(DP(left+1,right), DP(left, right-1))
    Base cases :
        //One character
        DP(left, right) = 1;

    return DP(0, n-1) which contains accumulative value of palindromic sequence
```
## Similar Problem
```
[5. Longest Palindromic Substring](https://leetcode.com/problems/longest-palindromic-substring/)
[647. Palindromic Substrings](https://leetcode.com/problems/palindromic-substrings/)
```

