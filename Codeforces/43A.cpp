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
	int n, best;
	map<string, int> table;
	cin >> n;
	string s, winner;
	best = INT_MIN;
	while (n--) {
		cin >> s;
		++table[s];
		if (table[s] > best) {
			winner = s;
			best = table[s];
		}
	}
	cout << winner << '\n';
}