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
#define N 10000
#define PIXEL 1024
#define ll long long
#define pi pair<ll, ll>

using namespace std;

inline void newline() { cout << '\n'; }
inline void split(vector<string>& vect, string& str, char delim) {
    string each;
    for (auto it = str.begin(); it != str.end(); ++it) {
        if (*it != delim)
            each.push_back(*it);
        else {
            vect.push_back(each);
            each.clear();
        }
    }
    if (each.size()) vect.push_back(each);
}

inline bool sort_pred(const pair<int, int>& left, const pair<int, int>& right) {
    return left.first<right.first;
}

inline bool lb_pred(const pair<int, int>& left, int right) {
    return left.first < right;
}

struct node {
    struct node* adj[4];
    int state;
};

int assign(char c) {
    if (c == 'p') return -1;
    return (c == 'e' ? 1 : 0);
}

node* build(string s, int &i) {
    if (i >= s.length()) return NULL;
    node* _node = new node();
    _node->state = assign(s[i]);
    if (s[i] == 'p') {
        for (int j = 0; j < 4; ++j) {
            i = i + 1;
            _node->adj[j] = build(s, i);
        }
    }
    return _node;
}

int compute(node* left, node* right, int i) {
    if (left == NULL && right == NULL) return 0;
    int pixel = 0;
    if (left != NULL && right != NULL) {
        if (left->state == 0 || right->state == 0)
            pixel += PIXEL / pow(4, i);
        else
            for (int j = 0; j < 4; ++j)
                pixel += compute(left->adj[j], right->adj[j], i + 1);
    } else if (left == NULL) {
        if (right->state == 0)
            pixel += PIXEL / pow(4, i);
        else if(right->state == -1)
            for (int j = 0; j < 4; ++j)
                pixel += compute(NULL, right->adj[j], i + 1);
    } else {
        if (left->state == 0)
            pixel += PIXEL / pow(4, i);
        else if (left->state == -1)
            for (int j = 0; j < 4; ++j)
                pixel += compute(left->adj[j], NULL, i + 1);
    }

    
   return pixel;
}

void visit(node* root) {
    if (root == NULL) return;
    printf(" %d ", root->state);
    for (int i = 0; i < 4; ++i)
        visit(root->adj[i]);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, dummy[2];
    string tree1, tree2;
    cin >> n;
    for (; n; --n) {
        dummy[0] = dummy[1] = 0;
        cin >> tree1 >> tree2;
        node* right = build(tree1, dummy[0]);
        node* left = build(tree2, dummy[1]);
        printf("There are %d black pixels.\n", compute(left, right, 0));
    }

}