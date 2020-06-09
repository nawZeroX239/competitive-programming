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

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, l, r, c, k;
	string s;
	while (cin >> n) {
		vector<string> vect;
		l = -1;
		for (int i = 0; i < n; ++i) {
			cin >> s;
			vect.push_back(s);
			l = max(l, (int)s.length());
		}
		sort(vect.begin(), vect.end());
		c = 60/(l+2);
		if (60 % (l+2) >= l)
			++c;
		r = n / c;
		if (n % c)
			++r;

		cout << "------------------------------------------------------------" << '\n';

		for (int i = 0; i < r; ++i) {
			k = 0;
			for (int j = 0;  j < c; ++j) {
				int idx = r * j + i;
				if (idx < n) {
					cout << vect[idx];
					k = k + vect[idx].length();
					if(r*(j+1)+i<n)
					for (int pass = vect[idx].length()-1; pass < l + 1; ++pass, ++k)
						cout << ' ';
					else 
						for (int pass = vect[idx].length(); pass < l; ++pass, ++k)
							cout << ' ';
				} else {

				}
			}

			cout << '\n';
		}
	}
	
	
	return 0;
}
