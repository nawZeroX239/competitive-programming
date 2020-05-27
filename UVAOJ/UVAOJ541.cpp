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

int matrix[100][100];
int row[100];
int col[100];

int main() {
	int n;
	int corrupt[2];
	int r, c;
	while (scanf("%d", &n) && n > 0) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				scanf("%d", &matrix[i][j]);
			}
		}
		corrupt[0] = corrupt[1] = 0;
		for (int i = 0; i < n; i++) {
			row[i] = col[i] = 0;
			for (int j = 0; j < n; j++) {
				row[i] += matrix[i][j];
				col[i] += matrix[j][i];
			}
			if (row[i] & 1)
				++corrupt[0];
			if (col[i] & 1)
				++corrupt[1];
			// printf("row %d col %d\n", row[i], col[i]);
		}

		// printf("corrupt %d %d\n", corrupt[0], corrupt[1]);
		if (corrupt[0] > 1 || corrupt[1] > 1) {
			printf("Corrupt\n");
			continue;
		}

		if (!corrupt[0] && !corrupt[1]) {
			printf("OK\n");
			continue;
		}

		r = c = 0;
		for (int i = 0; i < n; i++) {
			// check row & col
			if (row[i] & 1) {
				for (int j = 0; j < n; j++) {
					if (col[j] & 1) {
						r = i + 1;
						c = j + 1;
						break;
					}
				}
				break;
			}
		}

		if (r && c) {
			printf("Change bit (%d,%d)\n", r, c);
		}

	}
	return 0;
}
