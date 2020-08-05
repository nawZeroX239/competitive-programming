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
const long long N = 100;

template <class T> T gcd(T a, T b) {
	if (b == 0) { return a; }
	return gcd(b, a % b);
}

template <class T> bool isPrime(T x) {
	for (T d = 2; d * d <= x; d++) { if (x % d == 0) return false; }
	return true;
}

int arr[N];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int even, odd, n;
	cin >> n;
	even = odd = 0;
	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
		if (arr[i]%2) ++odd;
		else even++;
	}
	bool flag = odd > even;
	for (int i = 0; i < n; ++i) {
		if (!flag && arr[i]%2) {
			cout << i+1 << '\n';
			break;
		} else if(flag && arr[i]%2 == 0){
			cout << i+1 << '\n';
			break;
		}
	}
}