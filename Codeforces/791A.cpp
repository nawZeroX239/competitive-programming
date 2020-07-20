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
// A. Bear and Big Brother


int main() {
	int a, b;
	cin >> a >> b;
	int y = 1;
	for (y = 1; true; ++y) {
		a *= 3;
		b *= 2;
		if (a > b) break;
	}
	cout << y << '\n';
}