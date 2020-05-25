#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>

using namespace std;

int a, b, c;
int dp[4001];

int solve(int n) {
	if (n < 0)
		return 0;
	if (n==0)
		return 1;

	if (dp[n] > -1)
		return dp[n];

	dp[n]= max(solve(n - a), max(solve(n - b), solve(n - c)));
	if (dp[n] > 0)
		dp[n]=dp[n] + 1;
	return dp[n];
}

int main() {
	int n;
	cin >> n >> a >> b >> c;
	
	for (int i = 0; i <= n; i++)
		dp[i] = -1;
	cout << solve(n)-1<< endl;

	return 0;
}