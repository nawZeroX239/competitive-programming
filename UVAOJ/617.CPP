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
#define N 24
#define EPS 1e-9

struct signal {
	double l;
	int g, y, r;
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	int tc = 1;
	while (cin >> n) {
		if (n == -1) break;
		vector<signal> arr(n);
		for (int i = 0; i < n; ++i)
			cin >> arr[i].l >> arr[i].g >> arr[i].y >> arr[i].r;
		vector<int> sols;
		for (int speed = 30; speed < 61; ++speed) {
			double time = 0;
			//cout << "speed: " << speed;
			int i;
			for (i = 0; i < n; ++i) {
				double res = fmod(arr[i].l / (speed / 3600.0), arr[i].g + arr[i].y + arr[i].r);
				//cout <<' '<<res<< 's';
				if (res > (double)arr[i].g + arr[i].y) break;
				time += arr[i].l / (speed /3600.0);
			}
			if (i == n) {
				sols.push_back(speed);
			}
			//cout << '\n';
		}
		cout << "Case " << tc << ": ";
		if (sols.size() == 0) cout << "No acceptable speeds.\n";
		else {
			cout << sols[0];
			int lastSol = sols[0];
			int start = 0;
			sols.push_back(-1);
			for (int i = 1; i < sols.size(); ++i) {
				if (lastSol + 1 != sols[i] && start != i-1)
					cout <<"-"<<lastSol;
				if (sols[i] > sols[i-1] + 1) {
					cout <<", "<<sols[i];
					start = i;
				}

				lastSol = sols[i];
			}
			cout << '\n';
		}
		++tc;
	}
}