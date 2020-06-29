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

bitset<N+1> taken;
vector<int> ans;
// too slow for large n
bool backtrack(int i, int n){
  if(i > n){
      return true;
  }else {
    for(int j=1; j<=n; ++j){
      if(ans.size() == 0 ||(taken[j] == false && abs(ans[ans.size()-1] - j) > 1)){
        taken[j] = true;
        ans.push_back(j);
        if(backtrack(i+1, n)) return true;
        ans.pop_back();
        taken[j] = false;
      }
    }
  }

  return false;
}

int main(){
  int n;
  cin>>n;
  if(n == 1)
    cout<<n<<'\n';
  else if(n==2 || n==3)
    cout<<"NO SOLUTION\n";
  else if(n == 4)
    cout<<"2 4 1 3\n";
  else if(n == 5){
    cout<<"2 4 1 3 5\n";
  }else{
    bool first=true;
    int i, j;

    if(n&1){ 
      cout<<n<<' ';
    }

    for(i=1, j=n/2+1; i<=n/2; ++j, ++i)
      if(first){
        cout<<i<<' '<<j;
        first = 0;
      }else{
        cout<<' '<<i<<' '<<j;
      }
  
  }
}
