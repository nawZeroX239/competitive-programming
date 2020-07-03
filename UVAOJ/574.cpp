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
#define N 12
#define M (long long)1e9
#define pi pair<ll, ll>

using namespace std;
int arr[N];
int n, sum;
vector<int> sol;
vector<vector<int>> lazy;

void backtrack(int i, int total) {
	if (sum == total) {
		if (lazy.size()) {
			for (int j = 0; j < lazy.size(); ++j) 
				if (lazy[j].size() == sol.size()) {
					bool equal = true;
					for (int k = 0; k < lazy[j].size(); ++k)
						if (lazy[j][k] != sol[k]) {
							equal = false;
							break;
						}
					if (equal) return;
				}			
		}

		lazy.push_back(sol);
	}

	for (int j = i; j < n; ++j) {
		if (arr[j] + total <= sum){
			sol.push_back(arr[j]);
			backtrack(j + 1, arr[j] + total);
			sol.pop_back();
		}
	}

}
int main() {
	while (cin >> sum >> n) {
		if (sum == 0 && n == 0) break;
		for (int i = 0; i < n; ++i)
			cin >> arr[i];
		cout << "Sums of " << sum << ":\n";
		backtrack(0, 0);
		if (lazy.size() == 0)
			cout << "NONE\n";
		for (int i = 0; i < lazy.size(); ++i) {
			cout << lazy[i][0];
			for (int j = 1; j < lazy[i].size(); ++j)
				cout << '+' << lazy[i][j];
			cout << '\n';
		}
		lazy.clear();
	}
}
