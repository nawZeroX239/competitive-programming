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

const int N = 1048576;
const long double EPS = 1e-9;

using namespace std;

template <class T>
T gcd(T a, T b) 
{
	if (b == 0) return a;
	return gcd(b, a % b);
}

int id;
bool tree[N], vis[20][N];
vector<vector<int>> sol(20);

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int tc, k, r, s;
	bool temp;
	for (int i=0 ; i < 524288; ++i) {
		k = 1;
		for (int depth = 0; depth < 20; ++depth) {
			temp = tree[k];
			tree[k] = !tree[k];
			if (!vis[depth][k]) {
				sol[depth].push_back(k);
				vis[depth][k] = true;
			}
			k = 2*k;
			if (temp) ++k;
		}
	}

	cin >> tc;
	while (tc--) {
		cin >> r >> s;
		cout << sol[r - 1][s - 1] << '\n';
	}
	cin >> tc;

}