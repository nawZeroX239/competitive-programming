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

#define N 30001
#define ll long long
#define pi pair<ll, ll>

using namespace std;


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t, n;
	string str, key;
	cin >> t;
	getline(cin, str);
	getline(cin, str);
	while (t) {
		vector<string> vect;
		unordered_map<string, int> bucket;
		while (getline(cin, str) && str.length())
			vect.push_back(str);
		for(int i=0; i<vect.size()-1; ++i)
			for (int j = i + 1; j < vect.size(); ++j) {
				++bucket[vect[i] + vect[j]];
				++bucket[vect[j] + vect[i]];
			}
		auto ans = bucket.begin();
		for (auto itr = bucket.begin(); itr != bucket.end(); ++itr) {
			if (itr->second > ans->second)
				ans = itr;
		}

		cout << ans->first << '\n';
		--t;
		if (t)
			cout << '\n';
	}
}
