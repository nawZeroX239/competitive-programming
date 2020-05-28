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

int main() {
	int N, n;
	int ans[4];
	int flag;
	while (scanf("%d%d", &N, &n)){
		getchar();
		if (N == 0 && n == 0)
			break;
		char** a = (char**)malloc(sizeof(char*) * N);
		char** b = (char**)malloc(sizeof(char*) * n);
		for (int i = 0; i < N; i++)
			a[i] = (char*)malloc(sizeof(char) * N);
		for (int i = 0; i < n; i++)
			b[i] = (char*)malloc(sizeof(char) * n);
		
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				a[i][j] = getchar();
			}
			getchar();
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				b[i][j] = getchar();
			}
			getchar();
		}

		//for (int i = 0; i < N; i++) {
		//	for (int j = 0; j < N; j++) {
		//		printf("%c ", a[i][j]);
		//	}
		//	printf("%\n");
		//}
		ans[0] = ans[1] = ans[2] = ans[3]=0;
		for(int i=0; i<N-n+1; i++)
			for (int j = 0; j < N - n + 1; j++) {
				// 0*
				flag=1;
				for(int x=0; x<n && flag; x++)
					for (int y = 0; y < n && flag; y++)
						if (b[x][y] != a[i + x][j + y])
							flag = 0;
				
				ans[0] += flag;
				// 90*
				flag = 1;
				for (int x = 0; x < n && flag; x++)
					for (int y1 = n - 1, y2 = 0; y1 >= 0 && flag; y1--, y2++)
						if (b[y1][x] != a[i + x][j + y2])
							flag = 0;
				ans[1] += flag;
				flag = 1;
				// 180*
				for (int x1 = n - 1, x2 = 0; x1 >= 0 && flag; x1--, x2++)
					for (int y1 = n - 1, y2 = 0; y1 >= 0 && flag; y1--, y2++)
						if (b[x1][y1] != a[i + x2][j + y2])
							flag = 0;
				ans[2] += flag;
				flag = 1;
				// 360*
				for (int x1 = n - 1, x2 = 0; x1 >= 0 && flag; x1--, x2++)
					for (int y = 0; y < n && flag; y++)
						if (b[y][x1] != a[i + x2][j + y])
							flag = 0;
				ans[3] += flag;
			}

		printf("%d %d %d %d\n", ans[0], ans[1], ans[2], ans[3]);
	}

	return 0;
}
