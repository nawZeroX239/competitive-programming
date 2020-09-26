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
#define EPS 1e-9
#define N  10000

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
int x[] = { -1, 1, 0, 0, -1, -1, 1, 1}, y[] = { 0, 0, -1, 1, -1, 1, -1, 1};

string ori[100];
int g[100][100];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int row, col, Case = 1;
	while (cin >> row >> col) {
		if (row == 0 && col == 0) break;
		if (Case > 1) cout << '\n';
		for (int i = 0; i < row; ++i) {
			cin >> ori[i];
		}
		for (int i = 0; i < row; ++i) {
			for (int j = 0; j < col; ++j) {
				g[i][j] = 0;
			}
		}
		for (int i = 0; i < row; ++i) {
			for (int j = 0; j < col; ++j) {
				if (ori[i][j] == '*') {
					for (int k = 0; k < 8; ++k) {
						int ii = i + y[k];
						int jj = j + x[k];
						if (ii > -1 && ii < row && jj > -1 && jj < col) {
							g[ii][jj]++;
						}
					}
				}
			}
		}
		cout << "Field #" << Case++ <<':'<<'\n';
		for (int i = 0; i < row; ++i) {
			for (int j = 0; j < col; ++j) {
				if (ori[i][j] == '*') cout << ori[i][j];
				else cout << g[i][j];
			}
			cout << '\n';
		}

	}
}