#include <iostream>
#include <string>
#include <algorithm>
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

int board[501][501];

int main() {
	int w, h, n;
	int x1, x2, y1, y2;
	int ctr, ans;
	while (scanf("%d%d%d", &w, &h, &n)) {
		if (w == 0 && h == 0 && n == 0)
			break;

		if(n>0)
		for (int i = 1; i <= h; i++)
			for (int j = 1; j <= w; j++)
				board[i][j] = 1;
		
		ctr = 0;
		for (int k = 0; k < n; k++) {
			scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
			
			if (x1 > x2)
				swap(x1, x2);
			if (y1 > y2)
				swap(y1, y2);

			for (int i = y1; i <= y2; i++)
				for (int j = x1; j <= x2; j++)
					if (board[i][j]) {
						board[i][j] = 0;
						++ctr;
					}
		}


		ans = (h * w) - ctr;
		if (ans > 1)
			printf("There are %d empty spots.\n", ans);
		else if (ans==1)
			printf("There is one empty spot.\n");
		else
			printf("There is no empty spots.\n");

	}

	return 0;
}
