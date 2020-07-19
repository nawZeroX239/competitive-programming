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
#define N 100
#define M 5
#define EPS 1e-9

char city[N][M];
int table[128];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	table['r'] = 0;
	table['o'] = 1;
	table['y'] = 2;
	table['g'] = 3;
	table['b'] = 4;
	char s[32];
	while (true) {
		int n = 0;
		while (scanf("%s", s)) {
			if (s[0] == 'e' || s[0] == '#') break;
			city[n][table[s[0]]] = s[2];
			city[n][table[s[4]]] = s[6];
			city[n][table[s[8]]] = s[10];
			city[n][table[s[12]]] = s[14];
			city[n][table[s[16]]] = s[18];
			++n;
		}
		if (s[0] == '#') break;
		pair<int, int> sol;
		sol.first = -1;
		sol.second = INT_MAX;
		for (int i = 0; i < n; ++i) {
			int cost = 0;
			for (int j = 0; j < n; ++j) {
				if (i == j) continue;
				cost += (city[i][0] != city[j][0]);
				cost += (city[i][1] != city[j][1]);
				cost += (city[i][2] != city[j][2]);
				cost += (city[i][3] != city[j][3]);
				cost += (city[i][4] != city[j][4]);
			}

			if (cost < sol.second) {
				sol.first = i;
				sol.second = cost;
			}
		}
		printf("%d\n", sol.first + 1);
	}
}