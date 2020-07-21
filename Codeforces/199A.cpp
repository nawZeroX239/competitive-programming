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

#define N (int)1e5
#define EPS 1e-9
vector<int> fib;
int n, i, j, k;

bool solve() {
	for (i = 0; i < fib.size(); ++i)
		for (j = i; j < fib.size(); ++j)
			for (k = j; k < fib.size(); ++k)
				if (fib[i] + fib[j] + fib[k] == n)
					return true;
	return false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	fib.push_back(0);
	fib.push_back(1);
	for (i = 2; true; ++i) {
		if (fib[i - 1] + fib[i - 2] >= n)
			break;
		fib.push_back(fib[i - 1] + fib[i - 2]);
	}
	//cout << "fib.size(): " << fib.size() << '\n';
	if (solve())
		cout << fib[i] << ' ' << fib[j] << ' ' << fib[k] << '\n';
	else
		cout << "I'm too stupid to solve this problem" << '\n';
}