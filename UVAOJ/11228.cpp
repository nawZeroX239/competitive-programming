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

using namespace std;

typedef tuple<int, int, int> iii;
typedef vector<int> vi;

// translation
int x[] = { 0, 0, 1, -1 };
int y[] = { -1, 1, 0, 0 };

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


// Steven Halim CP3
// UFDS code from ch2/ownlibrary/ufds.cpp
// Union-Find Disjoint Sets Library written in OOP manner, using both path compression and union by rank heuristics
class UnionFind {                                // OOP style
private:
	vi p, rank, setSize;                           // vi p is the key part
	int numSets;
public:
	UnionFind(int N) {
		p.assign(N, 0); for (int i = 0; i < N; ++i) p[i] = i;
		rank.assign(N, 0);                           // optional speedup
		setSize.assign(N, 1);                        // optional feature
		numSets = N;                                 // optional feature
	}
	int findSet(int i) { return (p[i] == i) ? i : (p[i] = findSet(p[i])); }
	bool isSameSet(int i, int j) { return findSet(i) == findSet(j); }
	void unionSet(int i, int j) {
		if (isSameSet(i, j)) return;                 // i and j are in same set
		int x = findSet(i), y = findSet(j);          // find both rep items
		if (rank[x] > rank[y]) swap(x, y);           // keep x 'shorter' than y
		p[x] = y;                                    // set x under y
		if (rank[x] == rank[y]) ++rank[y];           // optional speedup
		setSize[y] += setSize[x];                    // combine set sizes at y
		--numSets;                                   // a union reduces numSets
	}
	int numDisjointSets() { return numSets; }
	int sizeOfSet(int i) { return setSize[findSet(i)]; }
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int T, n, r, tc=1, taken, state;
	double rail, road;

	cin >> T;
	while (T--) {
		cin >> n >> r;
		vector<pair<int, int>> cities(n);
		vector<tuple<double, int, int>> edgeList;
		UnionFind uf(n);
		for (int i = 0; i < n; ++i) {
			cin >> cities[i].first >> cities[i].second;
		}

		for (int i = 0; i < n - 1; ++i) {
			for (int j = i + 1; j < n; ++j) {
				int dx = cities[i].first - cities[j].first, dy = cities[i].second - cities[j].second;
				edgeList.emplace_back(sqrt(dx * dx + dy * dy), i, j);
			}
		}
		sort(edgeList.begin(), edgeList.end());
		road = rail = 0;
		taken = 0;
		state = 1;
		for (int i = 0; i < edgeList.size(); ++i) {
			int u = get<1>(edgeList[i]), v = get<2>(edgeList[i]);
			if (!uf.isSameSet(u, v)) {
				double z = get<0>(edgeList[i]);
				if (islessequal(z, (double)r)) {
					road += z;
				} else {
					rail += z;
					++state;
				}

				uf.unionSet(u, v);
				if (taken == n - 2) break;
				taken++;
			}
		}

		road += 0.5; rail += 0.5;
		cout << "Case #" << tc++ << ": " << state <<' ' << (int)road <<' '<< (int)rail << '\n';
	}
}