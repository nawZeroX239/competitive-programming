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
#include <chrono>

#define EPS 1e-9
#define INF 999999999
const int N = 10000;
const int cx[] = { -1, 1, 0, 0 }, cy[] = { 0, 0, -1, 1 };  	

using namespace std;

bool vis[26];

int toInt(string& s){
	stringstream ss(s);
	int num;
	ss>>num;
	return num;
}

long long dp[(int)1e6 + 1];
int lim[(int)1e6 + 1];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	auto t1 = chrono::high_resolution_clock::now();

	int n, m=1e9+7, X, c[100];
	cin >> n >> X;
	for (int i = 0; i < n; ++i) cin >> c[i];
	dp[0] = 1;
	sort(c, c + n);
	for(int i=0; i<n; ++i){
		for(int amt=1; amt<=X; ++amt) {
			if(amt >= c[i]){
				dp[amt] = dp[amt] + dp[amt - c[i]];
				dp[amt]%=m;
			}
		}
	}
	
	cout << dp[X] << '\n';

	auto t2=chrono::high_resolution_clock::now();
	double dt = chrono::duration_cast<chrono::milliseconds>(t2 - t1).count()/1000.0;
	//cout<<dt<<"s"<<'\n';
	return 0;
}