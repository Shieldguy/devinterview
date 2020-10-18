class Solution {
    public int countCornerRectangles2(int[][] grid) {
        int ans = 0;
        for(int y1 = 0; y1 < grid.length-1; y1++) {
            for(int y2 = y1+1; y2 < grid.length; y2++) {
                int count = 0;
                for(int x = 0; x < grid[0].length; x++) {
                    if(grid[y1][x] == 1 && grid[y2][x] == 1)
                        count++;
                }
                if(count > 0)
                    ans += count*(count-1)/2;
            }
        }
        return ans;
    }
    
    public int countCornerRectangles(int[][] grid) {
        int[][] dp = new int[grid.length][grid[0].length];
        int res = 0;
        for (int y = 0; y < grid.length; y++) {
            for (int xy = 0; xy < grid[0].length; xy++) {
                if (grid[y][xy] != 1) continue;
                for (int x2 = xy + 1; x2 < grid[0].length; x2++) {
                    if (grid[y][x2] == 1) {
                        res += dp[xy][x2];
                        dp[xy][x2]++;
                    }
                }
            }
        }
        return res; 
    }
}
