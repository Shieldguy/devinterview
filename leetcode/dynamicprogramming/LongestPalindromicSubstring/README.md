# [5. Longest Palindromic Substring](https://leetcode.com/problems/longest-palindromic-substring/)

- source: https://leetcode.com/problems/longest-palindromic-substring/

## Approach
```
  DP[left][right] is true if s[left..right] is a palindrome
  If s[left] == s[right], and in case DP[left+1][right-1],
  then s[left+1...right-1] is a palindrome.
  Get start index and max index of longest parindome substring at last.

                    right >>
                 0 1 2 3 4 5
                 a b d b c a
             0 a T F F F F F
             1 b   T F T F F
          ^  2 d     T F F F
          ^  3 b       T F F
          l  4 c         T F
          e  5 a           T
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
    DP(left, right) == (s[left] == s[right]) && DP(left+1, right-1)

    Base cases :
        //One character
        DP(left, right) = true;
        //Two Adjacent character
        DP(left, right+1) = s[left] == s[right+1]
            or ( s[left] == s[right] and right - left ==1 )
```
## Similar Problem
```
[5. Longest Palindromic Substring](https://leetcode.com/problems/longest-palindromic-substring/)
[647. Palindromic Substrings](https://leetcode.com/problems/palindromic-substrings/)
```
