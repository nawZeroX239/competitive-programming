#include <algorithm>
#include <array>
#include <bitset>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <forward_list>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

const long double EPS = 1e-9;
const int N = 105;

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m, an, sum;
	while (cin >> n) {
		if (n == 0) break;
		sum = an = 0;
		
		for (int i = 0; i < n; ++i) {
			cin >> m;
			sum += m;
			an = max(an, sum);
			sum = max(sum, 0);
		}
		if (an <= 0) {
			cout << "Losing streak." << '\n';
		} else {
			cout << "The maximum winning streak is " << an << '.' << '\n';
		}
	}
}