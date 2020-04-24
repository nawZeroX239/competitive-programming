#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>

using namespace std;

int main() {
	int a[100001];
	int N, T;
	int b;
	scanf("%d", &T);
	for (int t = 1; t <= T; t++) {
		printf("Case %d: ", t);
		scanf("%d", &N);
		for (int i = 1; i <= N; i++) {
			scanf("%d", &a[i]);
		}
		for (int i = 1; i <= N; i++) {
			scanf("%d", &b);
			a[i]=a[i]-b;
		}

//		for (int i = 1; i <= N; i++)
//				printf(" res[%d]:%d ", i, a[i]);

		int idx = -1;
		for (int i = 1; i <= N && idx<0; i++) {
			if (a[i] >= 0) {
				int sum =0;
				int j = i;
				while (j <= N && sum >= 0)
					sum=sum+a[j++];
//				printf(" [bsum:%d] ", sum);
				if (sum >= 0) {
					int k = 1;
					while (k < i && sum>=0)
						sum = sum + a[k++];
					if (sum >= 0)
						idx = i;
				}

//				printf(" [asum:%d] ", sum);
				i = j-1;
			}
		}
//		for (int i = 1; i <= N; i++)
//			printf(" a[%d]:%d ", i, a[i]);

		if (idx > -1)
			printf("Possible from station %d\n", idx);
		else
			printf("Not possible\n");

	}
	return 0;
}
