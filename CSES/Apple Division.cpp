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
#define N 20
#define M (long long)1e9
#define pi pair<ll, ll>

using namespace std;
long long arr[N];
int n;
long long backtrack(int k, long long P, long long Q){
  if(k == n) return abs(P-Q);
  return min(backtrack(k+1, P+arr[k], Q), backtrack(k+1, P, arr[k] + Q));

}

int main(){
  cin>>n;
  for(int i=0; i<n; ++i)
    cin>>arr[i];
  cout<<backtrack(0, 0, 0)<<'\n';
}
