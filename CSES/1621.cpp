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
using namespace std;
 
#define N 200000
#define EPS 1e-9
 
int arr[N];
 
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, x, ans;
	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> arr[i];
	sort(arr, arr + n);
	ans = 1;
	for (int i = 1; i < n; ++i)
		if (arr[i] != arr[i - 1])
			++ans;
	cout << ans << '\n';
}