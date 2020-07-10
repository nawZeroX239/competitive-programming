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

#define N 8

using namespace std;
int digit[N];
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	long long res, sum, l, r;
	while (scanf("%d", &n) == 1) {
		int hi = sqrt(pow(10, n));
		for (int lo = 0; lo < hi; ++lo) {
			res = (long long)lo * lo;
			for (int i = 0; i < n; ++i) {
				digit[i] = res % 10;
				res /= 10;
			}
			l = r = 0;
			for (int i = 0, j=n/2; i < n / 2; ++i, ++j) {
				r += pow(10, i) *digit[i];
				l += pow(10, i) *digit[j];
			}
			res = (long long)lo * lo;
			sum = l+r;
			if (sum * sum == res) {
				for(int i=n-1; i>=0; --i)
					printf("%d", digit[i]);
				puts("");
			}
			
		}

	}

}