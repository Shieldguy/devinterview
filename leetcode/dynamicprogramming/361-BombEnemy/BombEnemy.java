
import java.util.Arrays;

public class Solution {

	public static void main(String[] args) {
		BombEnemy b = new BombEnemy();
		char[][] grid = new char[][] { { '0', 'E', '0', '0' }, { 'E', '0', 'W', 'E' }, { '0', 'E', '0', '0' } };
		b.maxKilledEnemies(grid);
	}

	public int maxKilledEnemies(char[][] grid) {
		if (grid.length == 0)
			return 0;

		int Y = grid.length;
		int X = grid[0].length;

		int[][] dp = new int[Y][X];
		int[] cols = new int[X];
		for (int i = 0; i < Y; i++) {
			int row = 0;
			for (int j = 0; j < X; j++) {
				if (grid[i][j] == 'W') {
					cols[j] = 0;
					row = 0;
				} else if (grid[i][j] == 'E') {
					cols[j]++;
					row++;
				} else {
					dp[i][j] = row + cols[j];
				}
			}
		}
		Arrays.fill(cols, 0);
		int ans = 0;
		for (int i = Y - 1; i >= 0; i--) {
			int row = 0;
			for (int j = X - 1; j >= 0; j--) {
				if (grid[i][j] == 'W') {
					cols[j] = 0;
					row = 0;
				} else if (grid[i][j] == 'E') {
					cols[j]++;
					row++;
				} else {
					dp[i][j] += row + cols[j];
					ans = Math.max(ans, dp[i][j]);
				}
			}
		}
		return ans;
	}
}
