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

#define EPS 1e-100
#define N 1005
#define ll long long
#define pi pair<ll, ll>

using namespace std;
int arr[N];
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, m;
	int foobar = 0;
	while (cin >> n) {
		if (n == 0)
			break;
		
		while (cin >> m) {
			if (m == 0)
				break;
			queue<int> A;
			stack<int> station;
			arr[0] = m;
			A.push(1);
			for (int i = 1; i < n; ++i) {
				cin >> arr[i];
				A.push(i + 1);
			}
			int possible = 1;
			for (int i = 0; i < n; ++i) {
				if (A.size() && A.front() == arr[i]) {
					A.pop();
				} else if(station.size() && station.top() == arr[i]){
					station.pop();
				} else {
					while (A.size() && A.front() != arr[i]) {
						station.push(A.front());
						A.pop();
					}

					if (A.size() && A.front() == arr[i])
						A.pop();
					else if (station.size() && station.top() == arr[i])
						station.pop();
					else
						possible = 0;
					
				}

				if (possible == 0)
					break;
			}

			if (possible) {
				cout << "Yes" << '\n';
			} else {
				cout << "No" << '\n';
			}
		}
		cout << '\n';
	}
}
