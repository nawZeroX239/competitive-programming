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

#define N 1025
#define M 20000
#define EPS 1e-9

int n, sol;
int x, y, z, a, b, c;
bool solve() {
	for (x = -100; x <= 100; ++x)
		for (y = -100; y <= 100; ++y)
			for (z = -100; z <= 100; ++z)
				if (x != y && y != z && x != z &&
					x + y + z == a && x * y * z == b && x * x + y * y + z * z == c)
					return true;
	return false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int tc;
	cin >> tc;
	while (tc--) {
		cin >> a >> b >> c;
		if (solve()) {
			cout << x << ' '<< y << ' ' << z << '\n';
		} else {
			cout << "No solution." << '\n';
		}
	}

}
