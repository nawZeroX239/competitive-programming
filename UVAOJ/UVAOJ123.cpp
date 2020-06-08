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
	int n;
	string temp, s;
	vector<string> line[2001];
	map<string, vector<int>> dp;
	unordered_set<string> ignore;
	while (getline(cin, s)) {
		if (s[0] == ':')
			break;
		ignore.insert(s);
	}

	for (n = 0; getline(cin, s); ++n) {
		if (s.length() < 1)
			continue;
		for (int i = 0; i < s.length() + 1; ++i) {
			if(i<s.length()) 
				s[i] = tolower(s[i]);
			if ((i < s.length() && s[i] == ' ') || i == s.length()) {
				if (ignore.find(temp) == ignore.end()) {
					if (dp.find(temp) == dp.end()) {
						vector<int> vect;
						dp[temp] = vect;
					}
					dp[temp].push_back(n);
				}
				line[n].push_back(temp);
				temp.clear();
			} else {
				temp.push_back(s[i]);
			}
		}
	}

	for (map<string, vector<int>>::iterator itr = dp.begin(); itr != dp.end(); ++itr) {
		int last, c;
		last = -1;
		c = 1;
		for (int i = 0; i < itr->second.size(); ++i) {
			int k = itr->second[i];
			if (k == last)
				++c;
			else
				c = 1;
			int x = c;
			for (int j = 0; j < line[k].size(); ++j) {
				if (j > 0 && j < line[k].size())
					cout << ' ';
				if (itr->first == line[k][j]) {
					if(x == 1)
						for (int l = 0; l < itr->first.length(); ++l)
							cout << (char)toupper(itr->first[l]);
					else
						cout << line[k][j];
					--x;
				} else {
					cout << line[k][j];
				}
			}
			cout << '\n';
			last = k;
		}
		
	}

	
	return 0;
}
