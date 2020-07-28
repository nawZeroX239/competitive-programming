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
#include <climits>
#include <bitset>
using namespace std;

#define N 100000
#define EPS 1e-9
#define PI 3.14159265358979323846264338327950

int h[N];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	
	while (true) {
		c -= b;
		if (c < 1) {
			cout << "Yes" << '\n';
			break;
		}
		a -= d;
		if (a < 1) {
			cout << "No" << '\n';
			break;
		}
	}
}
