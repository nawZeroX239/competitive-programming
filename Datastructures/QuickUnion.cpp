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

class QuickUnion{
  vector<int> v, rank;
  int numSet;
public:
  QuickUnion(int n){
    v.assign(n, 0);
    rank.assign(n, 0);
    for(int i=0; i<n; ++i) v[i] = i;
    numSet=n;
  }
  bool same_set(int i, int j){ return find(i) == find(j);}
  int find(int i){ return v[i] == i ? i : v[i]=find(v[i]); }
  void union_set(int i, int j){
    if((i=find(i))==(j=find(j))) return;
    if(rank[i] >= rank[j]){
      v[j] = i;
      if(rank[i] == rank[j]) ++rank[i];
    }else {
      v[i] = j;
    }
    --numSet;
  }
};

int main(){
  int N=10;
  QuickUnion qu(N);
  // for(int i=0; i<N; ++i) qu
  qu.union_set(0, 2);
  qu.union_set(1, 3);
  qu.union_set(0, 1);
  for(int i=0; i<N; ++i)
    printf("find(%d) %d\n", i, qu.find(i));
}
