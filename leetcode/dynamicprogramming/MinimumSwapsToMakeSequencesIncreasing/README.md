# 801. Minimum Swaps To Make Sequences Increasing

- source: https://leetcode.com/problems/minimum-swaps-to-make-sequences-increasing/

## Approach
```
    Let swap be array storing min # of total swap at index i if we swap at index i
    Let noSwap be array storing min # of total swap at index i if NO swap at index i

    Initial condition:
        swap[0] = 1;
        noSwap[0] = 0;

    Case 1: A[i-1] >= B[i] || B[i-1] >= A[i]
       - If A[i] and B[i] are swapped, then A[i-1] and B[i-1] should be swapped also.
             swap A[i-1] and B[i-1], swap A[i] and B[i]
       - If A[i] and B[i] are not swapped, A[i-1] and  B[i-1] should not be swapped.
             do not swap swap A[i-1] and B[i-1], swap A[i] and B[i], retrieve noSwap from previous.

    Case 2: A[i-1] >= A[i] || B[i-1] >= B[i]
       - In this case, A[i-1] < B[i] && B[i-1] < A[i].
       - In this case, do not swap A[i-1] and B[i-1], but swap A[i] and B[i];
             swap[i] = noSwap[i-1]+1
       - swap A[i-1] and B[i-1], but do not swap A[i] and B[i].
             noSwap[i] = swap[i-1];

    Case 3: Either swapping/no swapping are okay. Get min swap number.
         swap[i] = min(swap[i-1], noSwap[i-1]) + 1;
         noSwap[i] = min(swap[i-1], noSwap[i-1]);

```

## Complexity
```
    Time Complexity - O(N)
    Space Complexity - O(N)
```
## Explanation
```
     Index               0    1    2    3
     A                   1    3    5    4
     B                   1    2    3    7
     swap                1    1    2    1
     noSwap              0    0    0    2
```

