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

const int N = 100;
const long double EPS = 1e-9;

using namespace std;

template <class T>
T gcd(T a, T b) 
{
	if (b == 0) return a;
	return gcd(b, a % b);
}

int a[N], b[N];

int main() 
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m, ans;

	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		cin >> a[i];
	}
	cin >> m;
	for (int i = 0; i < m; ++i)
	{
		cin >> b[i];
	}
	sort(a, a + n);
	sort(b, b + m);

	ans = 0;
	int x = 0;
	int y = 0;
	while (x < n && y < m)
	{
		if (abs(a[x] - b[y]) <= 1)
		{
			++ans;
		}

		if (x >= n || y >= m) continue;
		if(b[y] > a[x] + 1) ++x;
		else 
		if(a[x] > b[y] + 1) ++y;
		else
		{
			++x; ++y;
		}
	}

	cout << ans << '\n';
}