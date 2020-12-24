
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
	int n, x, R, ans;
	cin>>n;
	map<int, vector<int>> mp;
	vector<int> arr(n);
	for(int i=0; i<n; ++i){
		cin>>x;
		arr[i] = x;
		mp[x].push_back(i);
	}

	for(auto it = mp.begin(); it!=mp.end(); ++it){
		it->s.push_back(INF);
	}
	
	R=n-1,ans=0;
	for(int i=n-1; i>=0; --i){
		x = arr[i];
		int temp = mp[x].back();
		mp[x].pop_back();
		if(temp != INF){
			R = min(R, temp-1);
		}
		ans = max(ans, R-i + 1);

		// cout<<"x: "<<x<<" R: "<<R<<'\n';
	}
	cout<<ans<<'\n';
}
