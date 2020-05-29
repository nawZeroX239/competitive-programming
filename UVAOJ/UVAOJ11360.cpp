#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>

using namespace std;
template<typename T> void get_num(T&);

int m[10][10];
int aux[10][10];
int temp;
int n;

void row(int a, int b) {
	for (int i = 0; i < n; ++i) {
		temp = m[a][i];
		m[a][i] = m[b][i];
		m[b][i] = temp;

	}
}

void col(int a, int b) {
	for (int i = 0; i < n; ++i) {
		temp = m[i][a];
		m[i][a] = m[i][b];
		m[i][b] = temp;
	}
}

void inc(int step) {
	for(int i=0; i<n; ++i)
		for (int j = 0; j < n; ++j) {
			m[i][j] += step;
			if (m[i][j] > 9)
				m[i][j] = 0;
			if (m[i][j] < 0)
				m[i][j] = 9;
		}
}

void trans() {
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			aux[i][j] = m[i][j];
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			m[j][i] = aux[i][j];
}

int main() {
	int t, a, b, x, q;
	cin >> t;
	string s;
	for (int tt = 1; tt <= t; ++tt) {
		cin >> n;
		for (int i = 0; i < n; ++i) {
			cin >> x;
			for (int j = n - 1; j >= 0; --j) {
				m[i][j] = x % 10;
				x /= 10;
			}
		}

		cin >> q;
		while (q) {
			cin >> s;
			if (s[0] == 't')
				trans();
			else if (s[0] == 'i')
				inc(1);
			else if (s[0] == 'd')
				inc(-1);
			else if (s[0] == 'r' || s[0] == 'c') {
					cin >> a >> b;
					--a, --b;

					if (s[0] == 'r')
						row(a, b);
					else
						col(a, b);

			 }
			--q;
		}

		printf("Case #%d\n", tt);
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j)
				printf("%d", m[i][j]);
			printf("\n");
		}
		printf("\n");
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