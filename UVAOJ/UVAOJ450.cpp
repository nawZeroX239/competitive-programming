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


string fields[4] = { "Department:", "Home Phone:", "Work Phone:", "Campus Box:" };

bool comparator(vector<string>&a, vector<string>& b) {
	return a[3] < b[3];
}

void print(vector<string>& vect) {
	cout << "----------------------------------------\n";
	cout << vect[1] << ' ' << vect[2] << ' ' << vect[3] << '\n';
	cout << vect[4] << '\n';
	cout << fields[0] << ' ' << vect[0] << '\n';
	cout << fields[1] << ' ' << vect[5] << '\n';
	cout << fields[2] << ' '<<vect[6]<<'\n';
	cout << fields[3] << ' ' << vect[7] << '\n';;

}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	string r, s, department;
	vector<vector<string>> vv;
	cin >> n; 
	getline(cin, s);
	while (n) {
		getline(cin, department);
		while (getline(cin, s)) {
			if (s.length() == 0)
				break;
			vector<string> vect;
			vect.push_back(department);
			for (auto it = s.begin(); it != s.end(); ++it) {
				if (*it != ',')
					r.push_back(*it);
				else {
					vect.push_back(r);
					r.clear();
				}
			}

			if (r.size()) {
				vect.push_back(r);
				r.clear();
			}
			//for (auto it = vect.begin(); it != vect.end(); ++it)
			//	cout << *it << ' ';
			//cout << '\n';
			vv.push_back(vect);

		}
		--n;
	}

	sort(vv.begin(), vv.end(), comparator);
	for (auto it = vv.begin(); it != vv.end(); ++it)
		print(*it);
}
 