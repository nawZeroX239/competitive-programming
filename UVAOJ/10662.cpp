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

#define N 20
#define EPS 1e-9

int T[N][N + 1], R[N][N + 1], H[N][N + 1];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int t, r, h;
	while (cin >> t>>r>>h) {
		for (int i = 0; i < t; ++i)
			for (int j = 0; j < r + 1; ++j)
				cin >> T[i][j];
	
		for (int i = 0; i < r; ++i)
			for (int j = 0; j < h + 1; ++j)
				cin >> R[i][j];

		for (int i = 0; i < h; ++i)
			for (int j = 0; j < t + 1; ++j)
				cin >> H[i][j];
		int ans = INT_MAX;
		int I, J, K;
		I = J = K = -1;
		for(int i=0; i<t; ++i)
			for(int j=0;j<r; ++j)
				for (int k = 0; k < h; ++k)
					if (T[i][j + 1] + R[j][k + 1] + H[k][i + 1] == 0 && T[i][0] + R[j][0] + H[k][0] < ans) {
						I = i; J = j; K = k;
						ans = T[i][0] + R[j][0] + H[k][0];
					}
	
		if (ans != INT_MAX) {
			cout << I<<' '<<J<<' '<<K<<':'<<ans << '\n';
		} else {
			cout << "Don't get married!" << '\n';
		}
	}

}