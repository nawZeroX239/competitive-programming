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

int main() {
	int x, y, z;
	int a, b, c;
	cin >> x >> y >> z;
	a = sqrt(x * y / z);
	c = y / a;
	b = z / c;
	cout << 4 * (a + b + c) << '\n';

}