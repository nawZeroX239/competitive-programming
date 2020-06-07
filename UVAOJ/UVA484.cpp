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


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, temp;
	vector<int> vect;
	unordered_map<int, int> dp;
	while (cin >> n) {
		if (dp.find(n) != dp.end())
			dp[n] = (dp.find(n))->second + 1;
		else {
			dp[n] = 1;
			vect.push_back(n);
		}
	}

	for (int i = 0; i < vect.size(); ++i)
		printf("%d %d\n", vect[i], (dp.find(vect[i]))->second);


	return 0;
}
