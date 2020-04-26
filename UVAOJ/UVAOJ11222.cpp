#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <unordered_set>
#include <vector>

using namespace std;


int main() {
	
	int c[3];
	int t;
	scanf("%d", &t);
	
	vector<int> e, f, g;

	for (int T = 1; T <= t; T++) {
		int p[3][10001] = {};
		int lo = 10001;
		int hi = 0;
		printf("Case #%d:\n", T);
		for (int k = 0; k < 3; k++) {
			int n;
			scanf("%d", &n);

			for (int i = 0; i < n; i++) {
				int x;
				scanf("%d", &x);
				hi = max(x, hi);
				lo = min(x, lo);
				p[k][x] = 1;
			}
		}
		c[0] = c[1] = c[2] = 0;
		for (int i = lo; i <= hi; i++) {
			if (p[0][i] && !p[1][i] && !p[2][i]) {
				e.push_back(i);
				c[0]++;
			} else if (p[1][i] && !p[2][i] && !p[0][i]) {
				f.push_back(i);
				c[1]++;
			} else if (!p[0][i] && !p[1][i] && p[2][i]) {
				g.push_back(i);
				c[2]++;
			}
		}
		//printf(" 0:%d 1:%d 2:%d\n", c[0], c[1], c[2]);
		if (c[0] == c[1] && c[1] == c[2]) {
			printf("1 %d", e.size());
			for (int i = 0; i < e.size(); i++)
				printf(" %d", e[i]);
			printf("\n2 %d", f.size());
			for (int i = 0; i < f.size(); i++)
				printf(" %d", f[i]);
			printf("\n3 %d", g.size());
			for (int i = 0; i < g.size(); i++)
				printf(" %d", g[i]);

		} else if (c[0] > c[2] && c[0] == c[1]) {
			printf("1 %d", e.size());
			for (int i = 0; i < e.size(); i++)
				printf(" %d", e[i]);
			printf("\n2 %d", f.size());
			for (int i = 0; i < f.size(); i++)
				printf(" %d", f[i]);
		} else if (c[1] > c[0] && c[1] == c[2]) {
			printf("2 %d", f.size());
			for (int i = 0; i < f.size(); i++)
				printf(" %d", f[i]);
			printf("\n3 %d", g.size());
			for (int i = 0; i < g.size(); i++)
				printf(" %d", g[i]);
		} else if (c[0] > c[1] && c[0] == c[2]) {
			printf("1 %d", e.size());
			for (int i = 0; i < e.size(); i++)
				printf(" %d", e[i]);
			printf("\n3 %d", g.size());
			for (int i = 0; i < g.size(); i++)
				printf(" %d", g[i]);
		}else if (c[0] > c[1] && c[0] > c[2]) {
			printf("1 %d", e.size());
			for (int i = 0; i < e.size(); i++)
				printf(" %d", e[i]);
		} else if (c[1] > c[0] && c[1] > c[2]) {
			printf("2 %d", f.size());
			for (int i = 0; i < f.size(); i++)
				printf(" %d", f[i]);
		} else if(c[2]>0){
			printf("3 %d", g.size());
			for (int i = 0; i < g.size(); i++)
				printf(" %d", g[i]);
		}
		e.clear();
		f.clear();
		g.clear();
		printf("\n");
	}
	return 0;
}
