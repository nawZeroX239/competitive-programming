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
	while (cin >> n) {
		queue<int> q;
		vector<int> vect;
		if (n == 0)
			break;
		for (int i=1; i<n+1; i++)
			q.push(i);
		while (q.size() > 1) {
			vect.push_back(q.front());
			q.pop();
			temp = q.front();
			q.pop();
			q.push(temp);
		}

		if (vect.size()) {
			printf("Discarded cards: %d", vect[0]);
			for (int i = 1; i < vect.size(); i++)
				printf(", %d", vect[i]);
			printf("\n");
		} else
			printf("Discarded cards:\n");

		printf("Remaining card: %d\n", q.front());

	}

	return 0;
}
