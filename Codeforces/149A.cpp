#include <algorithm>
#include <array>
#include <bitset>
#include <climits>
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
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

#define N 12

#define EPS 1e-9
using namespace std;

int arr[N];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int k, ans, h;

	cin >> k;
	for (int i = 0; i < N; ++i)
		cin >> arr[i];
	sort(arr, arr + N);
	ans = 1;
	h = arr[N - 1];
	for (int i = N - 2; i>= 0 && h < k; --i) {
		++ans;
		h += arr[i];
	}

	if (k == 0)
		cout << 0 << '\n';
	else if(h < k)
		cout << -1 << '\n';
	else 
		cout << ans << '\n';

}