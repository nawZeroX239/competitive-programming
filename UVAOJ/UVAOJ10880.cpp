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
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

#define EPS 1e-2
#define N 1000001
#define ll long long
#define pi pair<ll, ll>
using namespace std;

int arr[N];
void factors(vector<int>& v, int n, int r) {
    for (int i = 1; i <= sqrt(n); i++) {

        if (n % i == 0) {
            int k = n / i;
            if (k == i && k > r)
                v.push_back(i);
            else {
                if(i > r) v.push_back(i);
                if (k > r) v.push_back(n / i);
            }
        }
    }
}


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    int n, amt, r;
	cin >> n;
    for(int t=1; t<=n; ++t) {
        cin >> amt >> r;
        cout << "Case #" << t << ":";
        if (amt == r) {
            cout << " 0\n";
        } else {
            vector<int> ans;
            factors(ans, amt - r, r);
            if (ans.size()) {
                sort(ans.begin(), ans.end());
                auto it = ans.begin();
                cout << ' '<< *it;
                for (++it; it != ans.end(); ++it)
                    cout << " " << *it;
            }
            cout << '\n';
        }

    }
}
