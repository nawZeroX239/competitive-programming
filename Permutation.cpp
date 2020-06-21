#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>

using namespace std;
vector<char> vect;

void print(){
  if(vect.size() < 1)
    return;
  auto it = vect.begin();
  cout<<*it;
  for(++it; it != vect.end(); ++it){
    cout<<' '<<*it;
  }
  cout<<'\n';
}

void permute(int k){
  if(k == vect.size())
    print();
  else {
    for(int i = k; i<vect.size(); ++i){
      swap(vect[i], vect[k]);
      permute(k+1);
    }
  }
  
}

int main(){
  vect.push_back('a');
  vect.push_back('b');
  vect.push_back('c');
  permute(0);
}
