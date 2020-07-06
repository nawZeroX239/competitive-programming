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

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, cmd, val;
	
	while (cin >> n) {
		
		int x[3] = { -1, -1, -1 };
		stack<int> st;
		queue<int> qu;
		priority_queue<int> pr;
		int var = 1;
		int u, v;
		u = v = 0;
		for (; n; --n) {
			cin >> cmd >> val;
			if (cmd == 1) {
				st.push(val);
				qu.push(val);
				pr.push(val);
				++u;
			} else {
				if (st.size()) {
					if (x[0] == -1 || x[0] == 1)
						x[0] = val == st.top();
					st.pop();
				}
				if (qu.size()) {
					if (x[1] == -1 || x[1] == 1)
						x[1] = val == qu.front();
					qu.pop();
				}
				if (pr.size()) {
					if (x[2] == -1 || x[2] == 1)
						x[2] = val == pr.top();
					pr.pop();
				}
				var = 0;
				++v;
			}
		}

		int ans = max(x[0], 0) + max(x[1], 0) + max(x[2], 0);
		// cout << "var " << var << "ans "<<ans<< '\n';
		if ((ans > 1 && v<=u)|| var) {
			cout << "not sure\n";
		} else if (v <= u && x[0] == 1) {
			cout << "stack\n";
		} else if(v<= u && x[1] == 1) {
			cout << "queue\n";
		} else if (v <= u && x[2] == 1) {
			cout << "priority queue\n";
		} else {
			cout << "impossible\n";
		}
	}
}