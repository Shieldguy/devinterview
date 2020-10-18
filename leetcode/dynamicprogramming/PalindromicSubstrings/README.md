# [647. Palindromic Substrings](https://leetcode.com/problems/palindromic-substrings/)

- source:https://leetcode.com/problems/palindromic-substrings/

## Approach
```
  DP[left][right] is true if s[left..right] is a palindrome
  If s[left] == s[right], and in case DP[left+1][right-1],
  then s[left+1...right-1] is a palindrome.
  Count palindrome substring when we find it.
    - 1 character, 2 adjacent characters, or left+1,right-1 case

                    right >>
                 0 1 2 3 4 5
                 a b d b c a
             0 a 1 0 0 0 0 0
             1 b   1 0 1 0 0
          ^  2 d     1 0 0 0
          ^  3 b       1 0 0
          l  4 c         1 0
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
    DP(left, right) == (s[left] == s[right]) && DP(left+1, right-1)

    Base cases :
        //One character
        DP(left, right) = true;
        //Two Adjacent character
        DP(left, right+1) = s[left] == s[right+1]
            or ( s[left] == s[right] and right - left ==1 )

    Increase Counter whenever find new palindrome substring
```
## Similar Problem
```
[5. Longest Palindromic Substring](https://leetcode.com/problems/longest-palindromic-substring/)
[516. Longest Palindromic Subsequence](https://leetcode.com/problems/longest-palindromic-subsequence/)
```

