#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>

class Solution {
public:
    int minSwap(std::vector<int>& A, std::vector<int>& B) {
        int n = A.size();

        std::vector<int> noSwap(n,0); // min # of total swap at index i if NO swap at index i
        std::vector<int> swap(n,0); // min # of total swap at index i if we swap at index i
        // Initial Condition
        noSwap[0] = 0;
        swap[0] = 1;

        for (int i = 1; i < n; i++) {
            if (A[i-1] >= B[i] || B[i-1] >= A[i]) { // Should not swap
                swap[i] = swap[i-1] + 1;
                noSwap[i] = noSwap[i-1];
            } else if (A[i-1] >= A[i] || B[i-1] >= B[i]) { // should swap
                swap[i] = noSwap[i-1] + 1;
                noSwap[i] = swap[i-1];
            } else { // Either swap or no swap are okay. Get min value
                swap[i] = std::min(swap[i-1], noSwap[i-1]) + 1;
                noSwap[i] = std::min(swap[i-1], noSwap[i-1]);
            }
        }
        return std::min(swap[n-1], noSwap[n-1]);
    }
};
// Driver code
int main() {
  Solution s;
  int arrA[] = {1,3,5,4};
  int arrB[] = {1,2,3,7};
  std::vector<int> A(arrA, arrA+4);
  std::vector<int> B(arrB, arrB+4);
  std::cout<<"minSwap: "<<s.minSwap(A,B)<<std::endl;
  return 0;
}
