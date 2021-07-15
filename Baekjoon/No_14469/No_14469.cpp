#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;

int main() {

	int n;
	scanf("%d", &n);

	vector<pair<int, int>> cow;

	for (int i = 0; i < n; i++) {
		int start, end;
		scanf("%d%d", &start, &end);
		cow.push_back(pair<int, int>(start, end));
	}

	sort(cow.begin(), cow.end());

	int result = 0;
	for (const auto& i : cow) {
		if (result > i.first) {
			result += i.second;
		}
		else {
			result = i.first + i.second;
		}
	}

	printf("%d", result);

	return 0;
}