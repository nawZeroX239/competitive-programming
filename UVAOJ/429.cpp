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

bool can(string &a, string &b){
	int k = 0;
	for(int i=0; i<a.length(); ++i){
		if(a[i] != b[i]) ++k;
	}

	return k <= 1;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T, n, dist[200];
	string s, t;
	getline(cin, s);
	T = toInt(s);
	getline(cin, s);
	while(T--) {
		unordered_map<int, vector<string>> mp;
		unordered_map<int, vector<vector<int>> > graph;
		unordered_map<string, int> ind;
		while(getline(cin, s)){
			if(s[0] == '*') break;
			int sz = s.length();
			if(mp.find(sz) == mp.end()){
				vector<string> w;
				mp[sz] = w;
			}
			mp[sz].push_back(s);
		}

		for(auto it = mp.begin(); it != mp.end(); ++it){
			vector<string> w = it->second;
			vector<vector<int>> adj(w.size());
			for(int i=0; i<w.size(); ++i) ind[w[i]] = i;
			for(int i=0; i<w.size() - 1; ++i){
				for(int j = i + 1; j<w.size(); ++j){
					if(can(w[i], w[j])){
						int u = ind[w[i]], v = ind[w[j]];
						adj[u].push_back(v);
						adj[v].push_back(u);
						//cout<<w[i]<<" <-> "<<w[j]<<'\n';
					}
				}
			}
			graph[it->first] = adj;
		}

		while(getline(cin, s)) {
			if(s.length() == 0) break;
			stringstream ss(s);
			ss>>s>>t;
			int sz = s.length();
			vector<vector<int>> adj = graph[sz];
			for(int i =0; i<adj.size(); ++i) dist[i] = INF;
			queue<int> q;
			q.push(ind[s]);
			dist[ind[s]] = 0;
			while(q.size()){
				int u = q.front(); q.pop();
				for(int i=0; i<adj[u].size(); ++i){
					int v = adj[u][i];
					if(dist[v] == INF) {
						dist[v] = dist[u] + 1;
						q.push(v);
					}
				}
			}
			cout<<s<<' '<<t<<' '<<dist[ind[t]]<<'\n';
		}

		if(T) cout<<'\n';
	}
}
