#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>

using namespace std;


int main() {
	int n;
	int cars[1001];
	long sum = 0;
	int c, s;
	bool b;
	while (scanf("%d", &n) && n > 0) {
		sum = 0;
		b = true;
		for (int i = 1; i <= n; i++)
			cars[i] = -1;
		for (int i = 1; i <= n; i++) {
			scanf("%d%d", &c, &s);
			//printf(" i+s:%d ", i + s);
			sum += s;
			if (!b)
				continue;

			if (s > 0 && i+s<=n) {
				if (cars[i + s] > -1)
					b = false;
				else
					cars[i + s] = c;
			} else if (s < 0 && i+s>0) {
				if (cars[i + s] > -1)
					b = false;
				else
					cars[i + s] = c;
			} else if(s==0){
				cars[i] = c;
			} else {
				//printf(" false ");
				b = false;
			}

			
		}
		//printf(" sum:%d ", sum);
		if (sum != 0 || !b) {
			printf("%d\n", -1);
		} else {
			printf("%d", cars[1]);
			for (int i = 2; i < n + 1; i++)
				printf(" %d", cars[i]);
			printf("\n");
		}
	}
	return 0;
}
