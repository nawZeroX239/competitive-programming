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
#define N 8
#define M (long long)1e9
#define pi pair<ll, ll>

using namespace std;
int row[N];
vector<string> board(N);
int solcnt;

bool place(int r, int c){
  for(int i=0; i<c; ++i)
    if(row[i] == r || abs(row[i] - r) == abs(i - c))
      return false;
  return true;
}

void backtrack(int c){
  if(c == N){
    ++solcnt;
    return ;
  }

  for(int r=0; r<N; ++r){
    if(board[r][c] == '.' && place(r, c)){
      row[c] = r;
      backtrack(c+1);
    }
  }
}

int main(){
  for(int i=0; i<N; ++i){
    cin>>board[i];
  }
  backtrack(0);
  cout<<solcnt<<'\n';
}
