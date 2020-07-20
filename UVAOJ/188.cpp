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
#define N 13

using namespace std;

int arr[N];
int main(){
  string s, w;
  int n, C;
  while(getline(cin, s)){
    stringstream ss(s);
    n=0;
    C = INT_MAX;
    while(ss>>w){
      int sum=0;
      for(int i=0; i<w.length(); ++i){
        sum += (w[i] - 'a' + 1) * pow(32, w.length()-1-i);
      }
      arr[n++] = sum;
      C=min(C, sum);
    }
    // sort(arr, arr+n);    

  while(true){
    bool isOk=true;
    for(int i=0; i<n-1; ++i) {
    for(int j=i+1; j<n; ++j)
      if((C/arr[i])%n == (C/arr[j])%n){
        // choose next C
        C = min((C/arr[i] + 1) * arr[i],
                (C/arr[j] + 1) * arr[j]);
        isOk=false;
        break;
      }
    if(!isOk) break;
    }
    if(isOk) break;
  }


  cout<<s<<'\n';
  cout<<C<<'\n';
  cout<<'\n';
  }

}
