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

#define TSIZE (int)1e6+1
#define ll long long
#define pi pair<ll, ll>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t, m, n;
	string s, word;
	char ch;
	set<string> bucket;
	set<string>::iterator itr;
	while(getline(cin, s)) {
		int L = s.length();
		if (L< 1)
			continue;
		for (int i = 0; i < L-1; ++i) {
			ch = tolower(s[i]);
			if (ch >= 'a' && ch <= 'z' || ch == '-') {
				word.push_back(ch);
			} else {
				if (word.length()) {
					bucket.insert(word);
					word.clear();
				}
			}

		}

		ch = tolower(s[L - 1]);
		if (ch >= 'a' && ch <= 'z')
			word.push_back(ch);

		if (ch != '-' && word.length()) {
			
			bucket.insert(word);
			word.clear();
		}
		
	}

	for (itr = bucket.begin(); itr != bucket.end(); ++itr)
		cout << *itr << '\n';

}
