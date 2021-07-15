#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;

vector<pair<int, int>> bus[1001];
int root[1001];
bool check[1001];

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) {
        int start, end, cost;
        scanf("%d %d %d", &start, &end, &cost);
        bus[start].push_back(pair<int, int>(end, cost));
    }
    int start, end;
    scanf("%d %d", &start, &end);
    for (int i = 1; i <= n; i++) {
        root[i] = 1e9;
    }
    root[start] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    q.push(make_pair(0, start));
    while (!q.empty()) {
        int node = q.top().second;
        q.pop();
        if (!check[node]) {
            check[node] = true;
            for (int line = 0; line < bus[node].size(); line++) {
                int next = bus[node][line].first;
                if (root[next] > root[node] + bus[node][line].second) {
                    root[next] = root[node] + bus[node][line].second;
                    q.push(pair<int, int>(root[next], next));
                }
            }
        }
    }
    printf("%d", root[end]);
}