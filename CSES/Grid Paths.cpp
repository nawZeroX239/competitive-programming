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
#define N 7
#define M (long long)1e9
#define pi pair<ll, ll>

using namespace std;
bool grid[N][N];
int prune[N][N];
string paths;
int solcnt;
void backtrack(int i, int j, int k){
  if(i == N-1 && j ==0 && k != paths.length()) return ;
  if(k == paths.length()){
    if(i==N-1 && j == 0)
      ++solcnt;
    
  }
  
  bool sol =false;
  bool flag = paths[k] == '?';
  if((paths[k] == 'U' || flag) && (i-1>=0 && !grid[i-1][j])) {
    grid[i-1][j] = true;
    backtrack(i-1, j, k+1);
    grid[i-1][j] = false;
  }

  if((paths[k] == 'D' || flag) && (i+1<N && !grid[i+1][j])) {
    grid[i+1][j] = true;
    backtrack(i+1, j, k+1);
    grid[i+1][j] = false;
  }

  if((paths[k] == 'L' || flag) && (j-1>=0 && !grid[i][j-1])) {
    grid[i][j-1] = true;
    backtrack(i, j-1, k+1);
    grid[i][j-1] = false;
  }

  if((paths[k] == 'R' || flag) && (j+1<N && !grid[i][j+1])){
    grid[i][j+1] = true;
    backtrack(i, j+1, k+1);
    grid[i][j+1] = false;
  }
}

int main(){
  cin>>paths;
  cout<<paths<<'\n';
  grid[0][0] = true;
  backtrack(0, 0, 0);
  cout<<solcnt<<'\n';
}
