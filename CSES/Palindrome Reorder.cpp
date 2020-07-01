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

char ch[(int)1e6+1];

int main(){
  string s;
  
  int arr[N]={};
  cin>>s;
  ch[s.length()]='\0';
  for(int i=0; i<s.length(); ++i){
    ++arr[s[i] - 'A'];
  }

  int lo=0, hi=s.length()-1;
  int k = 0;
  while(lo<hi && k < N){
    if(arr[k] > 1){
      ch[lo++] = k +'A';
      ch[hi--] = k +'A';
      arr[k]-=2;
    }
    
    if(arr[k]<2) ++k;
  }

  int count=0;
  for(int i=0; i<N; ++i) {
    if(arr[i] == 1) ch[lo] = i+'A';
    count+=arr[i];
  }

  if(count>1) printf("NO SOLUTION\n");
  else printf("%s\n", ch);
 }
