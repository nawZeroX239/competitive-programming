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
#include <iostream>
#include <iterator>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	while (cin >> n) {
		if (n == 0)
			break;
		bitset<32> foo(n), odd, even;
		for (int i = 0, j = 1; i < 32; ++i) {
			if (foo[i]) {
				if (j&1) {
					odd.set(i);
				} else {
					even.set(i);
				}
				++j;
			}

		}

		cout << odd.to_ulong() << ' ' << even.to_ulong()<< '\n';
	}
}