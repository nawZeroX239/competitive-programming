
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
#define f first
#define s second
#define pii pair<int, int>
#define ll long long

// const int N = 10000;
const int cx[] = { -1, 1, 0, 0 }, cy[] = { 0, 0, -1, 1 };  	

using namespace std;

int strToInt(string& str){
	stringstream ss(str);
	int num;
	ss>>num;
	return num;
}

void IO(){
	//ios_base::sync_with_stdio(false);
	//cin.tie(NULL);
	//cout.tie(NULL);
    freopen("badmilk.in", "r", stdin);
	freopen("badmilk.out", "w", stdout);
}

void solve();

int main() {
#ifndef LOCAL_MACHINE
	IO();
#endif

	auto t1 = chrono::high_resolution_clock::now();

	solve();

#ifdef LOCAL_MACHINE
	auto t2=chrono::high_resolution_clock::now();
	double dt = chrono::duration_cast<chrono::milliseconds>(t2 - t1).count();
	cout<<dt<<"ms"<<'\n';
#endif

	return 0;
}

int L;
ll dp[201][13];
// top down
ll f(int i, int k){
	if(k == 12 && i == L){
		return 1;
	}

	if(k == 12 || i == L) return 0;
	if(dp[i][k] != -1) return dp[i][k];
	return dp[i][k] = f(i + 1, k) + f(i + 1, k + 1);
}

void solve() {
	cin>>L;
	// memset(dp, -1, sizeof dp);
	dp[0][0] = 1;
	// bottom up
	for(int i=1; i<=L; ++i){
		for(int k = 1; k<=12; ++k){
			dp[i][k] += dp[i - 1][k] + dp[i - 1][k - 1];
		}
	}
	cout<<dp[L][12]<<'\n';
}
