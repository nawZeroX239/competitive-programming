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
#define pi pair<ll, ll>

using namespace std;
bool any(int l, int r){
  return l == 0 && r > 0;
}

// TLE ;) O(2^n) and at best O(n)
bool backtrack(int left, int right){
  if(left < 0 || right < 0 || any(left, right) || any(right, left))
    return false;
  if(left == 0 && right == 0)
    return true;
  if(backtrack(left - 1, right - 2))
    return true;

  if(backtrack(left-2, right - 1))
    return true;
  return false;
}

bool pred(int left, int right){
  if(left < 0 || right < 0) return false;
  return (left%2==0 && left/2 == right) || (right%2 == 0 && right/2 == left);
}
int main(){
  int tc, l, r;
  cin>>tc;

  for(; tc; --tc){
    cin>>l>>r;

    // O(n) still TLE
    // while(l > 0 && r > 0){
    //   sol = pred(l, r);
    //   sol = sol | pred(ll, rr);
    //   if(sol) break;
    //   --l; r-=2;
    //   ll-=2; --rr;
    // }
    if(l>2*r || r>2*l){
      cout<<"NO\n";
    }else {
      int modL = l%3;
      int modR = r%3;
      if((modL+modR == 0) || (modL+modR== 3)){
        cout<<"YES\n";
      }else {
        cout<<"NO\n";
      }
    }

  }
 }
