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

int tranX[]={-2, -2, 
			  2,  2, 
			 -1, -1,
			  1,  1};
int tranY[]={-1,  1, 
			 -1,  1, 
			  2, -2,  
			  2, -2};
struct Board {
	char g[5][5];
	pair<int, int> getPos(){
		for(int i=0; i<5; ++i){
			for(int j=0; j<5; ++j){
				if(g[i][j] == ' ') return make_pair(i, j);
			}
		}
		return make_pair(-1, -1);
	}
	bool isDone(){
		if(g[2][2] != ' ') return 0;
		for(int i=0; i<2; ++i){
			for(int j=i; j < 5; ++j){
				if(g[i][j] != '1') return 0;
			}
		}
		if(g[2][3] != '1' || g[2][4] != '1' || g[3][4] != '1') return 0;
		if(g[1][0] != '0' || g[2][0] != '0' || g[2][1] != '0') return 0;
		for(int i=3; i<5; ++i){
			for(int j=0; j<=i; ++j){
				if(g[i][j] != '0') return 0;
			}
		}
		return 1;
	}

};


int bfs(Board init){
		queue<Board> q;
		q.push(init);
		int sz, x, y, dpth;
		pair<int, int> pos;
		for(sz = 1, dpth = 0; q.size() && dpth < 11; sz = q.size(), dpth++){
			while(sz--){
				Board u = q.front(); q.pop();
				if(u.isDone()){
					return dpth;
				}

				pos = u.getPos();
				for(int i=0; i<8; ++i){
					x = pos.first + tranX[i];
					y = pos.second + tranY[i];
					if(x >= 0 && x < 5 && y >= 0 && y < 5){
						Board v = u;
						swap(v.g[x][y], v.g[pos.first][pos.second]);
						q.push(v);
					}
				}

			}
		}

	return -1;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int tc;
	string s;
	getline(cin, s);
	tc = toInt(s);
	while(tc--){
		Board init;
		for(int i=0;i<5; ++i){
			getline(cin,s);
			for(int j=0; j<5; ++j){
				init.g[i][j] = s[j];
			}
		}
		int resl = bfs(init);
		if(resl == -1){
			cout<<"Unsolvable in less than 11 move(s)."<<'\n';
		}else{
			cout<<"Solvable in "<<resl<<" move(s)."<<'\n';
		}
	}

	return 0;
}
