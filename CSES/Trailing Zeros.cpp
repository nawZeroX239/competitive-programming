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
#define N (int)1e5
#define M (long long)1e9
#define ll long long
#define pi pair<ll, ll>

using namespace std;

int main(){
  int n;
  cin>>n;
  int ans = 0;
  long long five=5;
  while(n/five>0){
    ans += n/five;
    five*=5;
  }

  cout<<ans<<'\n';
 }
