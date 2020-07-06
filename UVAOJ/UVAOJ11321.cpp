#include <algorithm>
#include <array>
#include <bitset>
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

#define EPS 1e-2
#define N 10005
#define ll long long
#define pi pair<ll, ll>

using namespace std;

int arr[N];
int m=1;

bool comparator(int a, int b) {
	int r1 = a % m;
	int r2 = b % m;
	if (r1 != r2)
		return r1 < r2;
	if (a & 1 && b & 1) {
		return a > b;
	} else if (a & 1 ) {
		return true;
	} else if (b & 1) {
		return false;
	} else {
		return a < b;
	}

}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	while (cin >> n >> m) {
		cout << n << ' ' << m << '\n';
		if (m == 0 && n == 0)
			break;
		for (int i = 0; i < n; ++i)
			cin >> arr[i];
		sort(arr, arr + n, comparator);
		
		for (int i = 0; i < n; ++i)
			cout << arr[i] << '\n';

	}
	
}
