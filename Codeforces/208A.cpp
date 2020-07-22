#include <algorithm>
#include <array>
#include <bitset>
#include <climits>
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

#define N 12

#define EPS 1e-9
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string wub = "WUB";
	string s;
	cin >> s;
	bool space = false;
	for (int i = 0; i < s.length(); ++i) {
		if (s.substr(i, wub.length()) == wub) {
			i += 2;
			if(i+1 < s.length()) if (space)cout << ' ';
		} else {
			
			cout << s[i];
			
			space = true;
		}
	}
	cout << '\n';
}