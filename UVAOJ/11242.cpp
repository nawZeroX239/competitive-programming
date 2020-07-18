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
#define N 10
#define EPS 1e-9

int front[N];
int rear[N];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int f, r;
	while (scanf("%d", &f) == 1) {
		if (f == 0) break;
		scanf("%d", &r);
		for (int i = 0; i < f; ++i)
			scanf("%d", &front[i]);
		for (int j = 0; j < r; ++j)
			scanf("%d", &rear[j]);
		vector<double> ratio;
		for (int i = 0; i < f; ++i)
			for (int j = 0; j < r; ++j)
				ratio.push_back((double)rear[j] / front[i]);
		sort(ratio.begin(), ratio.end());
		double ans = 0;
		for (int i = 0; i < ratio.size() - 1; ++i)
			ans = max(ratio[i + 1] / ratio[i], ans);
		printf("%.2lf\n", ans);
	}
}