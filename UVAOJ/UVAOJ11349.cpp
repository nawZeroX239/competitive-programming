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

long long int matrix[100][100];

template<typename T> void get_num(T& num) {
	int sign = 1;
	register int c;
	num = 0;

	while (true) {
		c = getchar();
		if (c >= '0' && c <= '9')
			break;

		if (c == '-') {
			c = getchar();
			if (c >= '0' && c <= '9') {
				sign = -1;
				break;
			}
		}

	}


	for (;c>='0' && c <='9'; c = getchar())
		num = num * 10 + c - 48;

	num = num * sign;
}

int main() {
	int t, n, k=1;
	int good;
	char a, b;
	get_num(t);
	while (t) {
		get_num(n);
		good = 1;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++) {
				get_num(matrix[i][j]);
				if(matrix[i][j]<0)
					good=0;
			}

		//for (int i = 0; i < n; i++) {
		//	for (int j = 0; j < n; j++)
		//		printf("%d ", matrix[i][j]);
		//	printf("\n");
		//}
		if (good)
		for(int r1=0, r2=n-1; r1<n/2 && good; ++r1, --r2)
			for(int c1=0, c2=n-1; c1<n && good; ++c1, --c2)
				if (matrix[r1][c1] != matrix[r2][c2]) {
					good = 0;
				}
		if(good && n&1)
			for(int r=n/2, c1=0, c2=n-1; c1<c2; ++c1, --c2)
				if (matrix[r][c1] != matrix[r][c2]) {
					good = 0;
					break;
				}

		if (good)
			printf("Test #%d: Symmetric.\n", k);
		else
			printf("Test #%d: Non-symmetric.\n", k);

		++k;
		--t;
	}
	return 0;
}
