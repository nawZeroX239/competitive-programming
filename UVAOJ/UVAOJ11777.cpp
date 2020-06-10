#include <algorithm>
#include <array>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <forward_list>
#include <iostream>
#include <iterator>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

using namespace std;

char grade(int mark) {
	if (mark >= 90)
		return 'A';
	else if (mark >= 80 && mark < 90)
		return 'B';
	else if (mark >= 70 && mark < 80)
		return 'C';
	else if (mark >= 60 && mark < 70)
		return 'D';
	
	return 'F';
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	int t1, t2, f, att, test[3];
	cin >> n;
	for (int t = 1; t <= n; ++t) {
		cin >> t1 >> t2 >> f >> att >> test[0] >> test[1] >> test[2];
		sort(test, test+3);
		int mark = t1 + t2 + f + att + (test[1]+test[2])/ 2;
		printf("Case %d: %c\n", t, grade(mark));
	}
}