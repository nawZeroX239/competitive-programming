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
const int N = 1005;
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

void dfs(int i){
	vis[i] = true;
	for(int j = 0; j<adj[i].size(); ++j){
		if(!vis[adj[i][j]]){
			dfs(adj[i][j]);
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T, n, ans;
	string s;
	getline(cin, s);
	T = toInt(s);
	getline(cin, s);
	while(T--){
		getline(cin, s);
		n = s[0] - 'A' + 1;
		// cout<<"S : "<<s<<'\n';
		adj.clear();
		adj.resize(n);
		while(getline(cin, s)){
			if(s.length() == 0) break;
			int u =  s[0] - 'A';
			int v = s[1] - 'A';
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		memset(vis, 0, sizeof vis);
		ans = 0;

		for(int i=0; i<n;++i){
			if(!vis[i]){
				dfs(i);
				ans++;
			}
			// cout<<"vis: ";
			// for(int j=0; j<n; ++j){
			// 	cout<<vis[j]<<' ';
			// }
			// cout<<'\n';
		}
		
		cout<<ans<<'\n';
		if(T) cout<<'\n';
	}
}
