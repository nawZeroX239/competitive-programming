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

#define N 4
#define EPS 1e-9

bool solve(string a, string b) {
	//cout << "a:" << a << " b:" << b << '\n';
	char ch;
	for (int x = 0; x < N; ++x) {
		if (a == b) return true;
		string p = a;

		for (int y = 0; y < N; ++y) {
			ch = a[1]; a[1] = a[3]; a[3] = a[4]; a[4] = a[2]; a[2] = ch;
			if (a == b) return true;
		}

		for (int z = 0; z < N; ++z) {
			ch = a[0]; a[0] = a[1]; a[1] = a[5]; a[5] = a[4]; a[4] = ch;
			if (a == b) return true;
		}
		a = p;
		ch = a[0]; a[0] = a[2]; a[2] = a[5]; a[5] = a[3]; a[3] = ch;
	}
	return false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	string ins;
	while (cin >> ins) {
		if (solve(ins.substr(0, 6), ins.substr(6, 6))) cout << "TRUE" << '\n';
		else cout << "FALSE" << '\n';
	}

}