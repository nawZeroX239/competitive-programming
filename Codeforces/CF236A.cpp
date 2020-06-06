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
int a, b, c, d, e, f, i, j, k, l, m, n, o, q, r, s, t, u, v, w, x, y, z;
 
 
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	string S;
	int ans = 0;
	int A['z' - 'a' + 1] = {};
	cin >> S;
	for (i = 0; i < S.length(); ++i)
		++A[tolower(S[i]) - 'a'];
	for (i = 0; i <= 'z' - 'a'; ++i)
		if (A[i])
			++ans;
	if (ans & 1)
		printf("IGNORE HIM!\n");
	else
		printf("CHAT WITH HER!\n");
 
	return 0;
}