#include<stdio.h>

int main() {

	int n;
	int stair[301] = { 0 }, score[301] = { 0 };

	scanf("%d", &n);

	for (int i = 1; i <= n; i++) {
		scanf("%d", &stair[i]);
		if (i == 1) score[i] = stair[i];
		else if (i == 2) score[i] = stair[i] + stair[i - 1];
		else score[i] = (stair[i] + score[i - 2]) > (stair[i] + stair[i - 1] + score[i - 3]) ? 
			(stair[i] + score[i - 2]) : (stair[i] + stair[i - 1] + score[i - 3]);
	}
	printf("%d", score[n]);

	return 0;
}