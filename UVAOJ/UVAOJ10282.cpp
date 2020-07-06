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
	int i, t;
	string str;
	unordered_map<string, string> dp;
	unordered_map<string, string>::iterator itr;
	while (getline(cin, str) && str.length()) {
		string key, val;
		for (i = 0;str[i] != ' '; ++i)
			val.push_back(str[i]);
		for (i = i + 1; i < str.length(); ++i)
			key.push_back(str[i]);
		dp[key] = val;
	}
	
	while (getline(cin, str)) {
		itr = dp.find(str);
		if (itr == dp.end())
			cout << "eh\n";
		else
			cout << itr->second << '\n';
	}
	
}