#include <algorithm>
#include <array>
#include <bitset>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <forward_list>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

#define EPS 1e-9
const int N = 1005;
const int cx[] = { -1, 1, 0, 0 }, cy[] = { 0, 0, -1, 1 };  	

using namespace std;

int cut[55];
int dp[55][55];
int solve(int left, int right){
	if(left + 1 == right) return 0;
	if(dp[left][right] != -1) return dp[left][right];
	int r =999999999;
	for(int i=left + 1; i < right; ++i){
		r = min(r, cut[right] - cut[left] + solve(left, i)  + solve(i, right));
	}

	return dp[left][right] = r;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int l, n;
	while(cin>>l){
		if(l == 0) break;
		cin>>n;
		for(int i=1; i<=n; ++i){
			cin>>cut[i];
		}
		cut[0] = 0;
		cut[n+ 1] = l;
		memset(dp, -1, sizeof dp);
		cout<<"The minimum cutting is "<<solve(0, n+1)<<'.'<<'\n';
	}
}
