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
	cin >> S;
	int C[4] = {};
	for (n = i = 0; i < S.length(); ++i)
		if (S[i] != '+')
			++C[S[i] - '0'];
	i = 1;
	while (C[i] == 0)
		++i;
	
	printf("%d", i);
	--C[i];
	while (i <= 3) {
		for (j = 0; j < C[i]; ++j)
			printf("+%d", i);
		++i;
	}
}
