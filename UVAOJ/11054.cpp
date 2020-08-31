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
const int N = 100000;

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
  int n, x, y;
  long long ans;
  while(cin>>n){
    if(n == 0) break;
    cin>>x;
    ans = abs(x);
    for(int i=1; i<n; ++i){
      cin>>y;
      x = x + y;
      ans += abs(x);
    }
    cout<<ans<<'\n';
  }
}