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
#define N 1000005

using namespace std;

int arr[N][N];
int main(){
  int n;
  while(cin>>n){
    for(int i=0;i<n;++i)
    for(int j=0; j<n; ++j)
      cin>>arr[i][j];
    int total=0;
    map<int, bool> vis;
    for(int i=0; i<n; ++i){
      for(int j=0; j<n; ++j) {
        if(i == j) continue;
        if(arr[i][j]){
          for(int k=0; k<n; ++k) {
            if(k == i || k == j) continue;
            int a=100*(i+1) + 10*(j+1) + k+1;
            int b=100*(j+1) + 10*(k+1) + i+1;
            int c=100*(k+1) + 10*(i+1) + j+1;
            if(arr[j][k] && arr[k][i] && !vis[a]) {
              cout<<i+1<<' '<<j+1<<' '<<k+1<<'\n';
              vis[a] =  vis[b] = vis[c]= true;
              ++total;
            }
          }
        }
      }
    }

    cout<<"total:"<<total<<'\n';
    cout<<'\n';
  }

}