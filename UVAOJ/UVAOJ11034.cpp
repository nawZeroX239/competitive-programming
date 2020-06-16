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
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

#define EPS 1e-2
#define N 30001
#define ll long long
#define pi pair<ll, ll>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int CASE, size, m, n, sum;
	string s;
	cin >> CASE;
	while (CASE) {
		cin >> size >> m;
		size = size * 100;
		queue<int> left;
		queue<int> right;
		while (m) {
			cin >> n >> s;
			if (s[0] == 'r')
				right.push(n);
			else
				left.push(n);
			--m;
		}

		int ans = 0;
		while (true) {
			sum = 0;
			++ans;
			while (left.size() && (sum + left.front()) <= size) {
				sum = sum + left.front();
				left.pop();
			}
			
			
			sum = 0;
			++ans;
			if (right.size() == 0 && left.size() == 0)
				--ans;
			while (right.size() && (sum + right.front()) <= size) {
				sum = sum + right.front();
				right.pop();
			}

			if (right.size() == 0 && left.size() == 0)
				break;
		}
		cout << ans << '\n';

		--CASE;
	}

}
