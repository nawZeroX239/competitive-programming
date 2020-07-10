#include <iostream>
#include <cstdio>
#include <climits>
#include <unordered_map>


#define N 9

using namespace std;

int arr[N];
const char* P[] = { "BCG", "BGC", "CBG", "CGB", "GBC", "GCB" };

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int b, g, c, ans, idx, x;
	int total;
	unordered_map<char, int> table;
	table['B'] = 0;
	table['G'] = 1;
	table['C'] = 2;

	while (scanf("%d", &arr[0]) == 1) {
		total = arr[0];
		for (int i = 1; i < N; ++i) {
			scanf("%d", &arr[i]);
			total += arr[i];
		}
		ans = INT_MAX;
		idx = 0;
		for (int i = 0; i < 6; ++i) {
			x = total - arr[ table[P[i][0]] ] - arr[3 + table[P[i][1]] ] - arr[6 + table[P[i][2]] ];
			if (x < ans) {
				ans = x;
				idx = i;
			}
		}
		printf("%s %d\n", P[idx], ans);
	}
}