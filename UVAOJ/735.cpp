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

#define N 60
#define EPS 1e-9

vector<int> A;

int main(){
	int n, m;
	A.push_back(0);
	A.push_back(50);
	for (int i = 1; i <= 20; ++i) {
		A.push_back(i * 1);
		A.push_back(i * 2);
		A.push_back(i * 3);
	}
	sort(A.begin(), A.end());
	auto it = unique(A.begin(), A.end());
	A.resize(it - A.begin());
	m = A.size();
	while (cin >> n) {
		if (n < 1) break;
		int cm, pm;
		cm = pm = 0;
		for (int i = 0; i < m; ++i)
			for (int j = i; j < m; ++j)
				for (int k = j; k < m; ++k)
					if (A[i] + A[j] + A[k] == n)
						++cm;
		for (int i = 0; i < m; ++i)
			for (int j = 0; j < m; ++j)
				for (int k = 0; k < m; ++k)
					if (A[i] + A[j] + A[k] == n)
						++pm;
		if (cm) {
			cout << "NUMBER OF COMBINATIONS THAT SCORES "<<n<<" IS "<<cm<<".\n";
			cout << "NUMBER OF PERMUTATIONS THAT SCORES "<<n<<" IS "<<pm<<".\n";
		} else {
			cout << "THE SCORE OF "<<n<<" CANNOT BE MADE WITH THREE DARTS.\n";
		}
		cout << "**********************************************************************\n";
	}
	cout << "END OF OUTPUT" << '\n';
}