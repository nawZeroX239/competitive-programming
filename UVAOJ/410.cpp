#include <iostream>
#include <string>
#include <algorithm>
#include <utility> 
#include <unordered_set>
#include <vector>
#include <list> 
#include <string>
#include <iterator> 
#include <iomanip>
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
const int N = 1000;
template <class T> T gcd(T a, T b) {
	if (b == 0) { return a; }
	return gcd(b, a % b);
}



int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int c, s,  tc = 1;
	double imb, avg;
	while (cin >> c >> s) {
		vector<int> arr;
		arr.assign(2 * c, 0);
		avg = 0;
		for (int i = 0; i < s; ++i) {
			cin >> arr[i];
			avg += arr[i];
		}
		avg /= c;
		sort(arr.begin(), arr.end());
		cout << "Set #" << tc << '\n';
		imb = 0;
		for (int i = 0, j = 2 * c - 1; i < c; ++i, --j) {
			cout <<' '<< i  << ':';
			if (arr[i]) cout << ' '<< arr[i];
			if (arr[j]) cout << ' ' << arr[j];
			imb += abs(arr[i] + arr[j] - avg);
			cout << '\n';
		}
		cout << "IMBALANCE = " <<fixed<<setprecision(5)<<imb<<'\n';
		cout << '\n';
		++tc;
	}
	
}
