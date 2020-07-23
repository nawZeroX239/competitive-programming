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

#define N 1000
#define EPS 1e-9


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n;
	string ins;
	string verdicts[] = { "AC", "WA", "TLE", "RE" };
	map<string, int> table;
	for (int i = 0; i < 4; ++i)
		table[verdicts[i]] = 0;

	cin >> n;
	while (n--) {
		cin >> ins;
		++table[ins];
	}
	for (int i = 0; i < 4; ++i)
		cout << verdicts[i] << " x " << table[verdicts[i]] << '\n';
}