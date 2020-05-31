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
template<typename T> void get_num(T&);



struct pilot {
	int score;
};

int gp[100][100];
int sys[100][100];
int l[100];
int r[100];

int comp(const void* p, const void* q) {
	return  ((pilot*)q)->score - ((pilot*)p)->score;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int G, Q, S;
	int x, ptr;
	while (scanf("%d%d", &G, &Q)) {
		if (G == 0 && Q == 0)
			break;

		for (int i = 0; i < G; ++i)
			for (int j = 0; j < Q; ++j) {
				scanf("%d", &gp[i][j]);
				--gp[i][j];
			}

		//for (int i = 0; i < G; ++i) {
		//	for (int j = 0; j < Q; ++j) {
		//		printf("%d ", gp[i][j]);
		//	}
		//	puts("");
		//}

		scanf("%d", &S);
		for (int i = 0; i < S; ++i) {
			scanf("%d", &l[i]);
			for (int j = 0; j < l[i]; ++j)
				scanf("%d", &sys[i][j]);
		}

		//for (int i = 0; i < S; ++i) {
		//	for (int j = 0; j < l[i]; ++j)
		//		printf("%d ", sys[i][j]);
		//	puts("");
		//}

		for (int k = 0; k < S; k++) {
			x = -1;
			for (int i = 0; i < G; ++i) {
				for (int j = 0; j < Q; ++j)
					if (gp[i][j] < l[k]) {
						r[j] = r[j] + sys[k][gp[i][j]];
						x = max(x, r[j]);
					}
			}
			//printf("ans: ");
			for (ptr = 0; ptr < Q && r[ptr] != x; ++ptr);
			
			printf("%d", ptr+1);
			for (int i = ptr+1; i < Q; i++)
				if(r[i]==x)
					printf(" %d", i + 1);
			puts("");
			for (int i = 0; i < Q; ++i)
				r[i] = 0;
		}

	}
	return 0;
}



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


	for (; c >= '0' && c <= '9'; c = getchar())
		num = num * 10 + c - 48;

	num = num * sign;
}