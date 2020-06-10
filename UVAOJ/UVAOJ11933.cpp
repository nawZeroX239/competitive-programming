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
	while (scanf("%d", &n) == 1) {
		if (n == 0)
			break;
		int even, odd;
		even = odd = 0;
		for (int i = 0, j=0; i < 31; ++i) {
			if (n & (1 << i)) {
				if (j & 1) {
					even = even | (1 << i);
				} else {
					odd = odd | (1 << i);
				}
				++j;
			}
		}

		printf("%d %d\n", odd, even);
	}
}