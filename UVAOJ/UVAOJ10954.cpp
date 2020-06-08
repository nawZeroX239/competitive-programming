#include <iostream>
#include <string>
#include <algorithm>
#include <utility> 
#include <unordered_set>
#include <vector>
#include <list> 
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

using namespace std;


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, x;
	while (cin >> n) {
		if (n == 0)
			break;
		priority_queue<long long, vector<long long>, greater<long long>> pq;

		for (int i = 0; i < n; ++i) {
			cin >> x;
			pq.push(x);
		}
		
		long long a, b, cost=0;
		while (pq.size()>1) {
			a = pq.top();
			pq.pop();
			b = pq.top();
			pq.pop();
			cost = cost + a + b;
			pq.push(a + b);
		}

		cout << cost << '\n';
	}

	return 0;
}
