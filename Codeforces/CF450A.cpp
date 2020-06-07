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

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	int pos = 1;
	int a[100];
	cin >> n >> m;
	for (int i = 0; i < n; ++i)
		cin >> a[i];
	while (true) {
		int done = 1;
		for (int i = 0; i < n; ++i) {
			if (a[i] > 0) {
				a[i] -= m;
				pos = i;
				done = 0;
			}
		}
		if (done)
			break;
	}
	
	printf("%d\n", pos+1);
	return 0;
}
