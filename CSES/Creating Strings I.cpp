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
#define N 26
#define M (long long)1e9
#define pi pair<ll, ll>

using namespace std;


int main(){
  string s;
  cin>>s;
  sort(s.begin(), s.end());
  set<string> K;
  do {
    K.insert(s);
  } while(next_permutation(s.begin(), s.end()));
  cout<<K.size()<<'\n';
  for(string str : K)
    cout<<str<<'\n';
 }
