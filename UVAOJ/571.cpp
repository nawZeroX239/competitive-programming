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

#define EPS 1e-9
#define N 1005
using namespace std;
vector<string> S;
int n, cA, cB, overflow;
int k;
bool flag[N][N];

bool backtrack(int a, int b) {
	if (b == n) {
		for (int i = 0; i < S.size(); ++i)
			cout << S[i] << '\n';
		cout << "success\n";
		return true;
	}

	if (flag[a][b]) return false;
	flag[a][b] = true;
	if (a != cA) {
		S.push_back("fill A");
		if (backtrack(cA, b))
			return true;
		S.pop_back();
	}

	if (b != cB) {
		S.push_back("fill B"); 
		if (backtrack(a, cB)) 
			return true; 
		S.pop_back();
	}


	if (a > 0) {
		S.push_back("empty A");
		if (backtrack(0, b))
			return true;
		S.pop_back();

		overflow = (a + b > cB ? abs(a + b - cB) : 0);
		S.push_back("pour A B");
		if (backtrack(overflow, min(a + b, cB)))
			return true;
		S.pop_back();
	}

	if (b > 0) {
		S.push_back("empty B"); 
		if (backtrack(a, 0)) 
			return true; 
		S.pop_back();

		overflow = (a + b > cA ? abs(a + b - cA) : 0);
		S.push_back("pour B A");
		if (backtrack(min(a + b, cA), overflow)) 
			return true; 
		S.pop_back();
	}


	return false;
}

int main() {
	int tc = 1;
	while (cin >> cA >> cB >> n) {
		memset(flag, 0, sizeof flag);
		backtrack(0, 0);
		S.clear();
	}
}