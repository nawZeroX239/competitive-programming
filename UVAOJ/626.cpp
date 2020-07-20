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

#define N 100
#define EPS 1e-9

int arr[N][N];

int main() {
  int n;
  while (cin >> n) {
    for (int i = 0; i < n; ++i)
      for (int j = 0; j < n; ++j)
        cin >> arr[i][j];
    int total = 0;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        if (i == j) continue;
        if (arr[i][j]) {
          // i eats j
          for (int k = 0; k < n; ++k) {
            if (k == i || k == j) continue;
            if (arr[j][k] && arr[k][i])
              // j eats k & if k eats i then its a cyclic
              if ((i > j && j > k) || (i < j && j < k)) {
                cout << i + 1 << ' ' << j + 1 << ' ' << k + 1 << '\n';
                ++total;
              }
          }
        }
      }
    }

    cout << "total:" << total << "\n\n";
  }
}