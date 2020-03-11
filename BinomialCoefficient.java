
public class BinomialCoefficient {
	
	public int compute(int a, int b) {
		int N = a + 1;
		int[][] dp = new int[N][N];
		dp[0][0] = 1;
		for(int i = 1; i < N; i++) {
			for(int j = 0; j <= i; j++) {
				if((i-1) < 0 || (j-1) < 0) {
					dp[i][j] = 1;
				} else {
					dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
				}
			}
		}
		
		return dp[a][b];
	}
}
