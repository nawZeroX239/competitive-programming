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

int main() {
	long long i1, i2, j1, j2, pos, n, z;
	long long x;
	int ok;
	while (scanf("%lld%lld", &n, &pos)) {
		if (n == 0 && pos == 0)
			break;
		z = 1;
		i1 =i2= n / 2+1;
		j1 =j2= n / 2+1;
		ok = pos == 1;
		while (!ok) {
			++i2;
			++j2;
			
			x = 2 * (i2 - i1) + 1;
			z =x*x;
			// printf("i2 %lld j2 %lld x %lld z %lld \n", i2, j2, x, z);
			if (pos <= z && pos >= z - x + 1) {
				//printf("1\n");
				i2 = i2- (z - pos);
				ok = 1;
			} else if (pos <= z - x + 1 && pos >= z - 2 * (x - 1)) {
				//printf("2\n");
				i2 = i2 - (x - 1);
				j2 = j2 + pos - (z - x + 1);
				ok = 1;
			} else if (pos <= z - 2 * (x - 1) && pos >= z - 3 * (x - 1)) {
				//printf("3\n");
				j2 = j2 - (x - 1);
				i2 = i2 - (pos - (z - 3 * (x - 1)));
				ok = 1;
			} else if (pos <= z - 3 * (x - 1) && pos >= z - 4*(x - 1) + 1) {
				//printf("4\n");
				j2 = j2 - 1 + z -pos-4 * (x - 1) + 1;

				ok = 1;
			}
		}

		printf("Line = %lld, column = %lld.\n", i2, j2);

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