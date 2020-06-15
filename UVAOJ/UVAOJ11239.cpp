#include <algorithm>
#include <array>
#include <bitset>
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
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

#define N 30001
#define ll long long
#define pi pair<ll, ll>

using namespace std;

struct project {
	unordered_set<string> students;
	string name;
	project() {};
	project(string bar) {
		name = bar;
	};
};

project new_project(string &s) {
	project p(s);
	return p;
}

bool comp(project& a, project& b) {
	if (a.students.size() == b.students.size())
		return a.name < b.name;
	return a.students.size() > b.students.size();

}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t, n;
	string str, key;
	

	while (getline(cin, str)) {
		if (str[0] == '0')
			break;
		vector<project> vect;
		unordered_map<string, project> proj;
		unordered_map<string, string> table;
		string now;
		proj[str] = new_project(str);
		now = str;
		while (getline(cin, str) && str[0] != '1') {
			if (str[0] >= 'A' && str[0] <= 'Z') {
				proj[str] = new_project(str);
				now = str;
				continue;
			} else {
				auto it = table.find(str);
				if (it != table.end() && it->second != now) {
					auto rm = proj.find(it->second)->second.students.find(str);
					if(rm != proj.find(it->second)->second.students.end())
						proj.find(it->second)->second.students.erase(rm);
					it->second = now;
				} else if(it == table.end()){
					table[str] = now;
					proj.find(now)->second.students.insert(str);
				}
			}

		}
		for (auto it = proj.begin(); it != proj.end(); ++it)
			vect.push_back(it->second);
		sort(vect.begin(), vect.end(), comp);
		for (auto it = vect.begin(); it != vect.end(); ++it)
			cout << it->name << ' ' << it->students.size() << '\n';
	}
}
