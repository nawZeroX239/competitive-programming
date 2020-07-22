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
#define EPS 1e-9

int arr[N][N];
bool vis[N][N];

bool isDraw(int i, int j) {
	return arr[i][j] == 0 && arr[j][i] == 0;
}

bool isWinner(int i, int j) {
	return arr[i][j] && arr[j][i] == 0;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n;
	while (cin >> n) {
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n; ++j)
				cin >> arr[i][j];
		vector<tuple<int, int, int>> sol;
		
		for (int i = 0; i < n; ++i)
			for (int j = i + 1; j < n; ++j)
				for (int k = j+1; k < n; ++k)
					if (isWinner(k, j) && isWinner(j, i) && isWinner(i, k)) {
						sol.push_back(make_tuple(k + 1, j + 1, i + 1));
					}else if ((isDraw(i, j) && isDraw(i, k) && isDraw(j, k)) ||
						(isWinner(i, j) && isWinner(j, k) && isWinner(k, i))) {
						sol.push_back(make_tuple(i + 1, j + 1, k + 1));
					}
		cout << sol.size() << '\n';
		if (sol.size() > 1) sort(sol.begin(), sol.end());
		for (auto it = sol.begin(); it != sol.end(); ++it)
			cout << get<0>(*it) << ' '<<get<1>(*it) <<' '<<get<2>(*it) << '\n';
	}

}