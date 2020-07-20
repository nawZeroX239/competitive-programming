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

#define N 1005

#define EPS 1e-9
using namespace std;

// A. Soldier and Bananas

int main() {
	int k, n, w;
	cin >> k >> n >> w;
	int cost = 0;
	for (int i = 1; i <= w; ++i)
		cost += i * k;
	if (n - cost > -1)
		cout << 0 << '\n';
	else
		cout << cost - n << '\n';
}