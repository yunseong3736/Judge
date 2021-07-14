#include <stdio.h>

int minindex = 0;
int maxindex = 0;
int minheap[100001];
int maxheap[100001];

void swap(int* a, int* b) {
	int tmp = *a; *a = *b; *b = tmp;
}

void minpush(int value) {
	minheap[++minindex] = value;
	int child = minindex;
	int parent = child / 2;
	while (child > 1 && minheap[parent] > minheap[child]) {
		swap(&minheap[parent], &minheap[child]);
		child = parent;
		parent = child / 2;
	}
}

int minpop() {
	int result = minheap[1];
	swap(&minheap[1], &minheap[minindex]);
	minindex--;

	int parent = 1;
	int child = parent * 2;
	if (child + 1 <= minindex) {
		child = (minheap[child] > minheap[child + 1]) ? child + 1 : child;
	}

	while (child <= minindex && minheap[parent] > minheap[child]) {
		swap(&minheap[parent], &minheap[child]);

		parent = child;
		child = child * 2;
		if (child + 1 <= minindex) {
			child = (minheap[child] > minheap[child + 1]) ? child + 1 : child;
		}
	}

	return result;
}

void maxpush(int value) {
	maxheap[++maxindex] = value;
	int child = maxindex;
	int parent = child / 2;
	while (child > 1 && maxheap[parent] < maxheap[child]) {
		swap(&maxheap[parent], &maxheap[child]);
		child = parent;
		parent = child / 2;
	}
}

int maxpop() {
	int result = maxheap[1];
	swap(&maxheap[1], &maxheap[maxindex]);
	maxindex--;

	int parent = 1;
	int child = parent * 2;
	if (child + 1 <= maxindex) {
		child = (maxheap[child] > maxheap[child + 1]) ? child : child + 1;
	}

	while (child <= maxindex && maxheap[parent] < maxheap[child]) {
		swap(&maxheap[parent], &maxheap[child]);

		parent = child;
		child = child * 2;
		if (child + 1 <= maxindex) {
			child = (maxheap[child] > maxheap[child + 1]) ? child : child + 1;
		}
	}

	return result;
}

int main() {

	int n;
	scanf("%d", &n);

	for (int i = 1; i <= n; i++) {
		int value;
		scanf("%d", &value);
		if (i % 2 == 1) maxpush(value);
		else if (i % 2 == 0) minpush(value);
		if (i != 1 && maxheap[1] > minheap[1]) {
			int a, b;
			a = maxpop();
			b = minpop();
			minpush(a);
			maxpush(b);
		}
		printf("%d\n", maxheap[1]);
	}
	
	return 0;
}