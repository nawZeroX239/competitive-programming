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

#define INF 999999999
#define EPS 1e-9
#define N  10000

using namespace std;

template <class T> T gcd(T a, T b) {
	if (b == 0) { return a; }
	return gcd(b, a % b);
}
int toInt(string& s) {
	stringstream ss(s);
	int x;
	ss >> x;
	return x;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	int round, word_map[26], wrong_map[26], already_guessed[26];
	string word, guess;
	while (cin >> round) {
		if (round == -1) {
			break;
		}
		memset(word_map, 0, sizeof word_map);
		memset(wrong_map, 0, sizeof wrong_map);
		cin >> word >> guess;
		for (int i = 0; i < word.length(); ++i){
			word_map[word[i] - 'a'] ++;
		}
		int wrong_cnt = 0;
		memset(already_guessed, 0, sizeof already_guessed);
		for (int i = 0; i < guess.length(); ++i) {
			int ch = guess[i] - 'a';
			int sum = 0;
			for (int j = 0; j < 26; ++j) {
				sum += word_map[j];
			}
			if (sum == 0) break;
			if (already_guessed[ch]) continue;

			if (word_map[ch] == 0) {
				if (wrong_map[ch] == 0) ++wrong_cnt;
				wrong_map[ch]  = 1;
			} else {
				word_map[ch] = 0;
			}

			already_guessed[ch] = 1;
		}

		cout << "Round " << round << '\n';
		// cout <<"wrong_cnt: "<<wrong_cnt << '\n';
		if (wrong_cnt >= 7) {
			cout << "You lose." << '\n';
		} else {
			int sum = 0;
			for (int i = 0; i < 26; ++i) {
				sum += word_map[i];
			}
			if (sum > 0) {
				cout << "You chickened out." << '\n';
			} else {
				cout << "You win." << '\n';
			}
		}
	}
}