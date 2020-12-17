#include <algorithm>
#include <array>
#include <bitset>
#include <chrono>
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

#define INF 1e9
#define  EPS 1e-9
#define N 5005
using namespace std;

typedef tuple<int, int, int> iii;
typedef vector<int> vi;

// translation
int tx[] = { 0, 0, 1, -1 };
int ty[] = { -1, 1, 0, 0 };

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

void solve();

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	auto t1 = chrono::high_resolution_clock::now();
	solve();
	auto t2 = chrono::high_resolution_clock::now();
	double dt = chrono::duration_cast<chrono::milliseconds>(t2 - t1).count() / 1000.0;
	
	//cout << dt << 's' << '\n';
	return 0;
}

int h, w;
pair<int, int> s, e;
char grid[2000][2000];
int dist[20000][2000];
vector < vector<pair<int, int>>> tele(26);
void solve() {
	int x, y;
	cin >> h >> w;

	for (int i = 0; i < h; ++i) {
		for (int j = 0; j < w; ++j) {
			cin >> grid[i][j];
			if (grid[i][j] == 'S') {
				s = make_pair(i, j);
			}
			if (grid[i][j] == 'G') {
				e = make_pair(i, j);
			}
			if (islower(grid[i][j])) {
				tele[grid[i][j] - 'a'].push_back(make_pair(i, j));
			}
		}
	}

	queue<pair<int, int>> q;
	q.push(s);
	dist[s.first][s.second] = 1;
	while (q.size()) {
		pair<int, int> cur = q.front(); q.pop();
		if (grid[cur.first][cur.second] == 'G') break;
		char ch = grid[cur.first][cur.second];
		if (islower(ch)) {
			for (pair<int, int> coord : tele[ch - 'a']) {
				if (dist[coord.first][coord.second] == 0) {
					dist[coord.first][coord.second] = dist[cur.first][cur.second] + 1;
					q.push(coord);
				}
			}
			tele[ch - 'a'].clear();
		}

		for (int i = 0; i < 4; ++i) {
			int x = cur.first + tx[i], y = cur.second + ty[i];
			if (x >= 0 && x < h && y >= 0 && y < w && grid[x][y] != '#') {
				if (dist[x][y] == 0) {
					dist[x][y] = dist[cur.first][cur.second] + 1;
					q.emplace(x, y);
				}
			}
		}

	}

	if (dist[e.first][e.second] == 0) cout << -1 << '\n';
	else
	cout << dist[e.first][e.second] - 1<< '\n';
}