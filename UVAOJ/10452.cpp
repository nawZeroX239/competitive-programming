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
#define N 10
#define PIXEL 1024
#define ll long long
#define pi pair<ll, ll>

using namespace std;

inline void newline() { cout << '\n'; }
inline void split(vector<string>& vect, string& str, char delim) {
	string each;
	for (auto it = str.begin(); it != str.end(); ++it) {
		if (*it != delim)
			each.push_back(*it);
		else {
			vect.push_back(each);
			each.clear();
		}
	}
	if (each.size()) vect.push_back(each);
}

inline bool sort_pred(const pair<int, int>& left, const pair<int, int>& right) {
	return left.first < right.first;
}

inline bool lb_pred(const pair<int, int>& left, int right) {
	return left.first < right;
}


int R, C;
char grid[N][N];
string word = "IEHOVA#";

void backtrack(int k, int i, int j) {
	if (k == word.length()) {
		puts("");
		return;
	}

	if (k > 0) printf(" ");

	if (i-1 >=0 && grid[i - 1][j] == word[k]) {
		printf("forth");
		backtrack(k + 1, i - 1, j);
	}else if (j - 1 >= 0 && grid[i][j - 1] == word[k]) {
		printf("left");
		backtrack(k + 1, i, j - 1);
	}else {
		printf("right");
		backtrack(k + 1, i, j + 1);
	}

}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int tc;
	cin >> tc;
	for (; tc; --tc) {
		cin >> R >> C;

		for (int i = 0; i < R; ++i) {
			string s;
			cin >> s;
			for (int j = 0; j < C; ++j)
				grid[i][j] = s[j];
			
		}
		int startI=R-1, startJ;
		startJ = -1;
		for(int j=0; j<C; ++j)
			if (grid[startI][j] == '@') {
				startJ = j;
				break;
			}
		backtrack(0, startI, startJ);
	}
}