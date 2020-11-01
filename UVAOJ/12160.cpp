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
#define INF 999999999
const int N = 10000;
const int cx[] = { -1, 1, 0, 0 }, cy[] = { 0, 0, -1, 1 };  	

using namespace std;

vector<vector<int>> adj;
bool vis[26];

int toInt(string& s){
	stringstream ss(s);
	int num;
	ss>>num;
	return num;
}


int main(){
	// ios_base::sync_with_stdio(false);
	// cin.tie(NULL);
	// cout.tie(NULL);

	int l, u, r, v, w, b[10], tc=1;
	while(cin>>l>>u>>r){
		if(l==0 && u==0 && r==0) break;
		for(int i=0; i<r; ++i){ 
			cin>>b[i];
		}
		int dist[10000] = {};
		queue<int> q;
		q.push(l);
		dist[l] = 1;
		while(q.size()){
			v = q.front(); q.pop();
			for(int i=0; i<r; ++i){
				w = (v + b[i])%N;
				if(dist[w] == 0){
					dist[w] = dist[v] + 1;
					q.push(w);
				}
				if(w == u) break;
			}
		}
		
		if(dist[u] == 0) cout<<"Case "<<tc++<<": Permanently Locked"<<'\n';
		else	cout<<"Case "<<tc++<<": "<<dist[u] - 1<<'\n';
	}

}
