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
#define INF 999999999
#define  EPS 1e-9
#define N  10000

// translation
int tx[] = { 0, 0, 1,  1, 1, -1, -1, -1 };
int ty[] = {-1, 1, 0, -1, 1,  0, -1,  1 };
using namespace std;

template <class T> T gcd(T a, T b) {
	if (b == 0) { return a; }
	return gcd(b, a % b);
}
int toInt(string& s) {
	stringstream ss(s);
	int x;
	ss >> x;
	return x;
}

vector<int> vi;
int ans[26];
bool g[26][26], vis[26], hasSol;

void backtrack(int k) {
	if (k == vi.size()) {
		cout << (char)(ans[0] + 'A');
		for (int i = 1; i < k; ++i) {
			cout << ' ' << (char)(ans[i] + 'A');
		}
		cout << '\n';
		hasSol = true;
		return;
	}
	
	for (int i = 0; i < vi.size(); ++i) {
		if (!vis[vi[i]]) {
			int j;
			for (j = 0; j < k; ++j) {
				if (g[vi[i]][ans[j]]) {
					break;
				}
			}

			if (j == k) {
				ans[k] = vi[i];
				vis[vi[i]] = true;
				backtrack(k + 1);
				vis[vi[i]] = false;
			}

		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int tc;
	string s;
	getline(cin, s);
	tc = toInt(s);
	while (tc--) {
		getline(cin, s);
		getline(cin, s);
		stringstream vars(s);
		char ch;
		vi.clear();
		while (vars >> ch) {
			vi.push_back(ch - 'A');
		}
		sort(vi.begin(), vi.end());
		for (int i = 0; i < vi.size(); ++i) {
			for (int j = 0; j < vi.size(); ++j) {
				g[i][j] = 0;
			}
		}

		getline(cin, s);
		for (int i = 0; i < s.length(); i += 4) {
			// u < v
			int u = s[i] - 'A';
			int v = s[i + 2] - 'A';
			g[u][v] = 1;
			//cout << s[i] << '<' << s[i + 2] << '\n';
		}

		hasSol = false;
		backtrack(0);
		if (!hasSol){
			cout << "NO" << '\n';
		}
		if (tc) cout << '\n';
	}

}