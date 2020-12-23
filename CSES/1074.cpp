
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
	// IO();
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

bool lbComp(const pii & a, const int& val){
	return a.f < val;
}
bool ubComp(const int&val, const pii& a){
	return val < a.f;
}


int median(vector<ll> &a){
	if(a.size()%2 == 0){
		return a[a.size()/2];
	}

	return (a[(a.size() - 1) / 2] + a[a.size() / 2]) / 2;
}

void solve() {
	int n;
	ll ans;

	cin>>n;
	vector<ll> arr(n);
	for(ll & x : arr){
		cin>>x;
	}

	sort(arr.begin(), arr.end());
	int m = median(arr);
	ans = 0;
	for(int x : arr){
		ans += abs(m - x);
	}
	cout<<ans<<'\n';
}
