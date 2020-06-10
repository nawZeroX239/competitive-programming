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
	string s;
	
	while (cin>>s) {
		list<char> li;
		list<char>::iterator headPtr=li.begin();
		char now = ']';
		for (int i = 0; i < s.length(); ++i) {
			if (s[i] == '[')
				headPtr = li.begin();

			if (s[i] == ']' || s[i] == '[') {
				now = s[i];
				continue;
			}

			if (now == ']') {
				li.push_back(s[i]);
				headPtr = li.begin();
			} else {
				li.insert(headPtr, s[i]);
			}
		}

		for (list<char>::iterator itr = li.begin(); itr != li.end(); ++itr)
			cout << *itr;
		cout << '\n';
	}
	
}