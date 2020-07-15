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

#define N 9876543
#define X 10
using namespace std;

#define EPS 1e-9
int sols[N+1];
int arr[X];

int main() {
	ios_base::sync_with_stdio(0);
	for (int i = N; i > 9; --i) {
		int used = 1;
		int n = log(i)/log(10) + 1;
		int m = i;
		bool rep = false;
		while (m > 0) {
			int mod = m % 10;
			arr[--n] = mod;
			if (used & (1 << mod) || mod == 0) {
				rep = true;
				break;
			}
			used |= 1 << mod;
			m /= 10;
		}
		sols[i] = sols[i + 1];
		if (rep) continue;
		n = log(i) / log(10) + 1;
		
		int j = 0;
		int vis = 0;
		while (true) {
			j = (j + arr[j]) % n;
			if (vis & (1 << j)) break;
			vis |= 1 << j;
			if (j == 0) break;

		}
		if (vis == (1<<n)-1) 
			sols[i] = i;
	}
	int n, tc = 1;
	while (cin >> n) {
		if (n == 0) break;
		cout << "Case "<<tc<<": "<<sols[n] << '\n';

		++tc;

	}

}