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
const int cx[] = { -1, 1, 0, 0 }, cy[] = { 0, 0, -1, 1 };

using namespace std;

string a = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
// string g[N];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

  int T, tc=1, n, k, x, y;
  bool f;
  cin>>T;

  while(T--){
    // cout<<T<<'\n';
    cin>>n;
    vector<string> g(n);
    for(int i=0; i<n; ++i){
      cin>>g[i];
    }

    for(int i=0; i<n; ++i){
      for(int j=0; j<n; ++j){
        if(g[i][j] != '.') continue;
        for(k = 0; k<a.length(); ++k){
          f = true;
          for(int r=0; r<4; ++r) {
            x = j + cx[r], y = i + cy[r];
            if(x >= 0 && x < n 
            && y >= 0 && y < n&& a[k] == g[y][x]) {
                f = false;
                break;
            }
          }
          if(f){
            g[i][j] = a[k];
            break;
          }
        }
        
      }
    }
    cout<<"Case "<<tc++<<':'<<'\n';
    for(int i=0; i<n; ++i){
      cout<<g[i]<<'\n';
    }

  }

  return 0;
}
