#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>

using namespace std;
vector <string> v;

void split(string line) {

	// stringstream class check1 
	stringstream check1(line);

	string intermediate;

	while (getline(check1, intermediate, ' '))
		v.push_back(intermediate);

}

struct node {
	int next;
	int idx;
	int prev;
	node(): idx(-1), next(-1), prev(-1){}
};

void type1(node* stack, int idx) {
	if (stack[idx].prev != -1)
		stack[stack[idx].prev].next = -1;

	while (idx != -1) {
		stack[idx].prev = -1;
		int next = stack[idx].next;
		stack[idx].next = -1;
		idx = next;
	}
}

void type2(node* stack, int idx) {
	while (idx != -1) {
		stack[idx].prev = -1;
		int next = stack[idx].next;
		stack[idx].next = -1;
		idx = next;
	}
}

int getTop(node* stack, int idx) {
	while (stack[idx].next != -1)
		idx = stack[idx].next;

	return idx;
}

int main() {
	int n;
	string s;
	getline(cin, s);
	n = stoi(s);
	node* stack = new node[n];
	for (int i = 0; i < n; i++)
		stack[i].idx = i;

	while (getline(cin, s) && s[0]!='q') {
		if (v.size() > 0)
			v.clear();
		split(s);
		int p = stoi(v[1]);
		int q = stoi(v[3]);
		// cout << p << " " << q << endl;
		if (p == q)
			continue;
		node ptr1 = stack[p];
		node ptr2 = stack[q];

		while (ptr1.prev != -1)
			ptr1 = stack[ptr1.prev];
		while (ptr2.prev != -1)
			ptr2 = stack[ptr2.prev];
		if (ptr1.idx == ptr2.idx)
			continue;

		if (v[0][0]=='m') {
			type1(stack, p);
			if (v[2][1]=='v') {
				// printf("move over\n");
				// reset p+1, p+2, ..., p+n
				// move p over q
				q = getTop(stack, q);
				stack[q].next = p;
				stack[p].prev = q;
			} else {
				// reset p+1, p+2, ..., p+n and q+1, q+2, ..., q+n
				// move p onto q
				// printf("move onto\n");
				type2(stack, stack[q].next);
				stack[q].next = p;
				stack[p].prev = q;
			}
		} else {
			if (stack[p].prev != -1)
				stack[stack[p].prev].next = -1;
			if (v[2][1]=='v') {
				// printf("pile over\n");
				// pile p..p+n over top of stack q
				q = getTop(stack, q);

				stack[p].prev = q;
				stack[q].next = p;
			} else {
				//printf("pile onto\n");
				// reset q+1, ..., q+n 
				// pile p..p+n onto top of stack q
				type2(stack, stack[q].next);
				stack[q].next = p;
				stack[p].prev = q;
			}
		}
	}

	for (int i = 0; i < n; i++) {
		printf("%d:", i);
		if (stack[i].prev == -1) {
			int itr = i;
			while (itr != -1) {
				printf(" %d", itr);
				itr = stack[itr].next;
			}
		}
		printf("\n");
	}

	return 0;
}