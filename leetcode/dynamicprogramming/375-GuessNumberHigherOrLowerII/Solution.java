
public class Solution {

// 1) MinMax Algo : https://www.youtube.com/watch?v=ZPtqO-d8eXg
//   public int getMoneyAmount(int n) {
//     return helper(0, n);
//   }
//   int helper(int l, int r) {
//     if (l >= r) return 0;
//     int ans = Integer.MAX_VALUE;
//     for(int i=l;i<=r;i++) {
//       ans = Math.min(ans, i + Math.max(helper(l, i-1), helper(i+1, r)));
//     }
//     return ans;
//   }

    // // 2) DP
    // public int getMoneyAmount(int n) {
    //   int[][] dp = new int[n + 1][n + 1];
    //   return miniMax(1, n, dp);
    // }
    // int helper(int l, int r, int[][] dp){
    //   if (l >= r) return 0;
    //   if (dp[l][r] != 0)
    //     return dp[l][r];
    //   dp[l][r] = Integer.MAX_VALUE;
    //   for(int i=l; i <= r; i++)
    //     dp[l][r] = Math.min(dp[l][r], i + Math.max(helper(l, i-1, dp), helper(i+1, r, dp)));
    //   return dp[l][r];
    // }

  // // 3) Optimize
  public int getMoneyAmount(int n) {
    int[][] dp = new int[n + 1][n + 1];
    return helper(1, n, dp);
  }
  int helper(int l, int r, int[][] dp) {
    if (l >= r) return 0;
    if (dp[l][r] != 0)
      return dp[l][r];
    int ans = Integer.MAX_VALUE;
    int m = l + (r - l) / 2; // mid point
    for (int i=m; i <= r; i++) {
        ans = Math.min(ans, i + Math.max(helper(l, i-1, dp), helper(i+1, r, dp)));
    }
    dp[l][r] = ans;
    return ans;
  }

}
