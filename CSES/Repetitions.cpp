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
//#define N 10000
#define ll long long
#define pi pair<ll, ll>

using namespace std;

int main(){
  unordered_set<int> S;
  int best, cnt;
  string s;
  cin>>s;
  cnt = best =1;
  for(int i=1; i<s.length(); ++i){
    if(s[i] == s[i-1])++cnt;
    else{
      best =max(best, cnt);
      cnt = 1;
    }
  }
  best = max(best, cnt);
  cout<<best<<'\n';
}
