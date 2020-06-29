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
  long long n;
  cin>>n;
  while(n != 1){
    cout<<n<<' ';
    if(n&1) n=n*3+1;
    else n=n/2;
  }
  cout<<n<<'\n';
}
