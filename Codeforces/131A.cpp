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
#include <climits>
#include <bitset>
#include <numeric>
using namespace std;


const long double PI = 3.14159265358979323846264338327950;
const double EPS = 1e-9;
const long long N = 1e9;

template <class T> T gcd(T a, T b) {
	if (b == 0) { return a; }
	return gcd(b, a % b);
}

template <class T> bool isPrime(T x) {
	for (T d = 2; d * d <= x; d++) { if (x % d == 0) return false; }
	return true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string s;
	cin >> s;
	if (s.length() == 1) {
		cout << (char)(islower(s[0])? toupper(s[0]) : tolower(s[0])) << '\n';
		return 0;
	} else {
		bool first = true;
		for (int i = 1; i < s.length(); ++i)
			first = first && isupper(s[i]);
		if (isupper(s[0]) && first) {
			for (int i = 0; i < s.length(); ++i)
				cout << (char)tolower(s[i]);
		} else if (islower(s[0]) && first){
			cout << (char)toupper(s[0]);
			for (int i = 1; i < s.length(); ++i)
				cout << (char)tolower(s[i]);
		} else {
			cout << s;
		}
		cout << '\n';
	}
}