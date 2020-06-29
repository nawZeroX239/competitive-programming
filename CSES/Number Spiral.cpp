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
#define ll long long
#define pi pair<ll, ll>

using namespace std;

int main(){
  int tc;
  long long r, c, x;
  cin>>tc;
  for(; tc; --tc){
    cin>>r>>c;
     x= 0;
    if(r>=c) {
      if(r == 1 && c==1) x=1;
      else {
        if(r&1) x = (r-1)*(r-1)+c;
        else x = r * r - c +1;
      }
    }else {
      if(c&1)x = c * c-r+1;
      else x = (c-1)*(c-1)+r;
    }
    cout<<x<<'\n';
  }
 }
