#include <iostream>
#include <string>
#include <algorithm>
#include <utility> 
#include <unordered_set>
#include <vector>
#include <list> 
#include <string>
#include <iterator> 
#include <deque>
#include <array>
#include <forward_list>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cmath>
#include <climits>
#include <bitset>
using namespace std;
#define N 10001
#define M 987
#define EPS 1e-9

int arr[N];
bool vis[N];
int n;
bool solve() {
	for (int i = 0; i < n-2; ++i) {
		memset(vis, 0, sizeof vis);
		for (int j = 0; j < i; ++j)
			vis[arr[j]] = true;
		vis[arr[i]] = true;
		for (int j = i + 1; j < n-1; ++j) {
			vis[arr[j]] = true;
			int u =arr[j]-arr[i] + arr[j];
			if (u >= 0 && u < n && !vis[u]) 
				return false;
		}
	}

	return true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string s;
	while (cin>>s) {
		if (s[0] == '0') break;
		s.pop_back();
		n = stoi(s);
		for (int i = 0; i < n; ++i)
			cin >> arr[i];
		if (solve())
			cout << "yes\n";
		else
			cout << "no\n";
	}
}