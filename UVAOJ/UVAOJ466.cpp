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
template<typename T> void get_num(T&);

int pattern[10][10];
int prime[10][10];
int temp[10][10];
int x[10][10];

int n;

int copy(int a[][10], int b[][10]) {
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			b[i][j] = a[i][j];
	return 1;
}

int check(int a[][10], int b[][10]) {
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			if (a[i][j] != b[i][j])
				return 0;
	return 1;
}

int vert(int z[][10]) {
	copy(z, x);
	for (int q = 0; q < n; ++q)
		for (int a = 0, b = n - 1; a < n; ++a, --b)
			z[a][q] = x[b][q];
	return 1;
}

int rotate(int z[][10]) {
	copy(z, x);
	for (int r = 0; r < n; ++r)
		for (int a = 0, b = n - 1; a < n; ++a, --b) {
			z[r][a] = x[b][r];
		}
	return 1;
}

int comb() {
	rotate(temp); // 90
	if (check(temp, prime))
		return 90;
	rotate(temp);//180
	if (check(temp, prime))
		return 180;
	rotate(temp); // 270
	if (check(temp, prime))
		return 270;

	return 0;
}

int main() {
	string s;
	string t;
	int count = 1, type;
	while (cin >> n) {
		for (int r = 0; r < n; ++r) {
			cin >> s >> t;
			// cout << s << " | " << t << '\n';
			for (int c = 0; c < n; ++c) {
				if (s[c] == '.')
					pattern[r][c] = 1;
				else
					pattern[r][c] = 0;
				if (t[c] == '.')
					prime[r][c] = 1;
				else
					prime[r][c] = 0;
			}

		}

		copy(pattern, temp);
		if (check(pattern, prime)) {
			printf("Pattern %d was preserved.\n", count);
		} else if (rotate(temp) && check(temp, prime)) {
			printf("Pattern %d was rotated 90 degrees.\n", count);
		} else if (rotate(temp) && check(temp, prime)) {
			printf("Pattern %d was rotated 180 degrees.\n", count);
		} else if (rotate(temp) && check(temp, prime)) {
			printf("Pattern %d was rotated 270 degrees.\n", count);
		} else if (copy(pattern, temp) && vert(temp) && check(temp, prime)) {
			printf("Pattern %d was reflected vertically.\n", count);
		} else if ((type=comb())) {
			printf("Pattern %d was reflected vertically and rotated %d degrees.\n", count, type);

		} else {
			printf("Pattern %d was improperly transformed.\n", count);
		}

		//for (int i = 0; i < n; ++i) {
		//	for (int j = 0; j < n; ++j)
		//		if (temp[i][j])
		//			putchar('.');
		//		else
		//			putchar('X');

		//	printf("\n");
		//}

		++count;
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