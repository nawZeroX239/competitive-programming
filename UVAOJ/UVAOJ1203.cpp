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
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

#define TSIZE (int)1e6+1
#define ll long long
#define pi pair<ll, ll>

using namespace std;
ll timer[3001];
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	priority_queue<pi, vector<pi>, greater<pi>> order;
	string ins;
	int n, m, k;
	pi p;
	while (cin >> ins) {
		if(ins == "#")
			break;
		cin >> n >> m;
		timer[n] = m;
		order.push(make_pair(m, n));
	}
	cin >> k;
	while(k) {
		p = order.top();
		p.first = p.first + timer[p.second];
		order.pop();
		cout << p.second << '\n';
		order.push(p);
		--k;
	}
}