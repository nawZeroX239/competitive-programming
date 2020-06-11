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

bool comp(string& a, string& b) {
	if (a.length() == b.length())
		return a < b;
	return a.length() < b.length();
}

// its easier to solve the problem with queue
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	vector<string> vect;
	unordered_map<string, int> dp;
	string s;
	for (int a = 'a'; a <= 'z'; ++a) {		
		s.push_back(a);
		vect.push_back(s);
		for (int b = a + 1; b <= 'z'; ++b) {
			s.push_back(b);
			vect.push_back(s);
			for (int c = b +1; c <= 'z'; ++c) {
				s.push_back(c);
				vect.push_back(s);
				for (int d = c+1; d <= 'z'; ++d) {
					s.push_back(d);
					vect.push_back(s);
					for (int e = d + 1; e <= 'z'; ++e) {
						s.push_back(e);
						vect.push_back(s);
						s.pop_back();
					}
					s.pop_back();
				}
				s.pop_back();
			}
			s.pop_back();
		}
		s.pop_back();
	}


	sort(vect.begin(), vect.end(), comp);
	int k = 1;
	for (vector<string>::iterator itr = vect.begin(); itr != vect.end(); ++itr, ++k)
		dp[*itr] = k;
	
	while (cin >> s) {
		if (dp.find(s) == dp.end())
			cout << 0 << '\n';
		else
			cout << dp.find(s)->second << '\n';
	}
}