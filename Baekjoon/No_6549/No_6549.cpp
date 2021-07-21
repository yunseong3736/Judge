#include <cstdio>
#include <stack>
using namespace std;
int histogram[100000];
int main() {
    while (1) {
        int n;
        scanf("%d", &n);
        if (n == 0) {
            break;
        }
        for (int i = 0; i < n; i++) {
            scanf("%d", &histogram[i]);
        }
        histogram[n] = -1; //Set stopper.
        stack<int> s;
        long long ans = 0;
        for (int i = 0; i <= n; i++) {
            while (!s.empty() && histogram[s.top()] > histogram[i]) {
                long long height = histogram[s.top()];
                s.pop();
                long long width = i;
                if (!s.empty()) {
                    width = (i - s.top() - 1);
                }
                if (ans < width * height) {
                    ans = width * height;
                }
            }
            s.push(i);
        }
        printf("%llu\n", ans);
    }
    return 0;
}