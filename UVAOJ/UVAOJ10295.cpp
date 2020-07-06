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

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n, m;
	string key, str;
	int val;
	unordered_map<string, int> dp;
	unordered_map<string, int>::iterator itr;
	cin >> n >> m;
	while (n) {
		cin >> key >> val;
		dp[key] = val;
		--n;
	}

	while (m) {
		unsigned long long score = 0;
		while (cin >> str) {
			if (str == ".")
				break;
			itr = dp.find(str);
			if (itr != dp.end()) {
				score = score + itr->second;
			}
			
		}
		cout << score << '\n';
		--m;
	}
}