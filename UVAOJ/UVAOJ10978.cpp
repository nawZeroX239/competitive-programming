#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>

using namespace std;

int main() {
	string str;
	int notOut[52];
	char word[25];
	char* cards[52];
	int n;
	while (scanf("%d", &n) && n > 0) {
		getline(cin, str);
		int idx = 0;
		for (int i = 0; i < n; i++)
			notOut[i] = 0;

		for (int pass = 0; pass < n; pass++) {
			char* card = (char*)malloc(sizeof(char) * 5);
			scanf("%s%s", card, word);
			getline(cin, str);

			int len = strlen(word);
			int x = 0;
			int j = idx;
			while (x<len) {
				if (j >= n)
					j = 0;
				if (notOut[j] == 0)
					x++;
				j++;
			}
			cards[j-1] = card;
			notOut[j-1] = 1;
//			printf("%s %s %d\n", card, word, j);
			idx = j;
		}

		printf("%s", cards[0]);
		for (int i = 1; i < n; i++)
			printf(" %s", cards[i]);
		printf("\n");
	}

	return 0;
}
