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
#define INF 999999999
const int N = 1005;
const int cx[] = { -1, 1, 0, 0 }, cy[] = { 0, 0, -1, 1 };  	

using namespace std;
struct foobar {
	int x, y;
};
foobar a[35];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int t, w, d, v, n, Case=1;
	int dp[35][1005];
	vector<int> vi;

	while(cin>>t>>w){
		if(Case > 1) cout<<'\n';
		cin>>n;
		for(int i=0; i<n; ++i){
			cin>>d>>v;
			a[i].x = 3 * d * w;
			a[i].y = v;
		}

		for(int i=0; i<=n; ++i){
			dp[i][0] = 0;
		}
		for(int j = 0 ;j<=t; ++j){
			dp[0][j] = 0;
		}
		for(int i=1; i<=n; ++i){
			for(int j=1; j<= t; ++j){
				if(a[i - 1].x <= j){
					dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - a[i - 1].x] + a[i - 1].y);
				} else {
					dp[i][j] = dp[i - 1][j];
				}
			}
		}
		cout<<dp[n][t]<<'\n';
		vi.clear();
		for(int i=n, j = t; i > 0; --i){
			if(dp[i][j] != dp[i - 1][j]){
				vi.push_back(i - 1);
				j -= a[i - 1].x;
			}
		}
		cout<<vi.size()<<'\n';
		for(int i=vi.size() - 1; i >= 0; i--){
			int pos = vi[i];
			cout<<a[pos].x/(3 * w)<<' '<<a[pos].y<<'\n';
		}

		Case++;
	}
}
