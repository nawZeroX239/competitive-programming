#include <iostream>
#include <string>
#include <algorithm>
#include <utility> 
#include <unordered_set>
#include <vector>
#include <list> 
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
	int n, c;
	string str;
	set<string> dp;
	while (cin >> str) {
		string temp;
		for (int i = 0; i < str.length(); ++i) {
			c = tolower(str[i]);
			if (c >= 'a' && c <= 'z') {
				temp.push_back(c);
			} else if (temp.length()) {
				dp.insert(temp);
				temp.clear();
			}
		}
		
		if(temp.length())
			dp.insert(temp);
	}

	for (set<string>::iterator itr = dp.begin(); itr != dp.end(); ++itr)
		cout << *itr << '\n';

	return 0;
}
