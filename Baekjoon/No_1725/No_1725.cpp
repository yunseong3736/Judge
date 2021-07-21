#include <cstdio>
#include <stack>
using namespace std;
int histogram[100000];
int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &histogram[i]);
    }
    histogram[n] = -1; //Set stopper.
    stack<int> s;
    int ans = 0;
    for (int i = 0; i <= n; i++) {
        while (!s.empty() && histogram[s.top()] > histogram[i]) {
            int height = histogram[s.top()];
            s.pop();
            int width = i;
            if (!s.empty()) {
                width = (i - s.top() - 1);
            }
            if (ans < width * height) {
                ans = width * height;
            }
        }
        s.push(i);
    }
    printf("%d\n", ans);
    return 0;
}