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

#define N 1e5
#define EPS 1e-9
#define PI 3.14159265358979323846264338327950

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	double a, b, h, m;
	scanf("%lf%lf%lf%lf", &a, &b, &h, &m);
	double rh = 2.0 * PI / 12.0;
	double rm = 2.0 * PI / 60.0;
	double rad = abs(rh * h + m * rh / 60.0 - rm * m);
	//rad = min(rad, abs(rad - 2.0 * PI));
	//cout << rad<<' '<< abs(rad - 2 * PI) << '\n';
	if (rad < EPS) {
		printf("%d\n", 0);
	} else {
		printf("%.20lf\n", sqrt(a * a + b * b - 2.0 * a * b * cos(rad)));
	}
}
