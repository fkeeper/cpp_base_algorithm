#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define maxn 2024
#define eType int
#define inf 1000000000
#define longOrShortPath <

struct EDGE {
    int v;
    eType w;

    EDGE() {}
    EDGE(int _v, eType _w) {
        v = _v;
        w = _w;
    }
};

void initEdges(int n, vector<EDGE> edges[maxn]) {
    for (int i = 0; i <= n; ++i) {
        edges[i].clear();
    }
}

void addEdge(vector<EDGE> edges[maxn], int u, int v, eType w) {
    edges[u].push_back(EDGE(v, w));
}

void SPFAInit(int n, int s, eType dist[maxn], queue<int>& q, bool inqueue[maxn]) {
    for (int i = 0; i <= n; ++i) {
        dist[i] = (i == s) ? 0 : inf;
        inqueue[i] = false;
    }
    inqueue[s] = true;
    q.push(s);
}

void SPFAUpdate(vector<EDGE> edges[maxn], int u, eType dist[maxn], queue<int>& q, bool inqueue[maxn]) {
    for (int i = 0; i < edges[u].size(); ++i) {
        int v = edges[u][i].v;
        eType w = edges[u][i].w;
        if (dist[u] + w longOrShortPath dist[v]) {
            dist[v] = dist[u] + w;
            if (!inqueue[v]) {
                inqueue[v] = true;
                q.push(v);
            }
        }
    }
}

void SPFA(vector<EDGE> edges[maxn], int n, int s, eType dist[maxn]) {
    queue<int> q;
    bool inqueue[maxn];
    SPFAInit(n, s, dist, q, inqueue);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        inqueue[u] = false;
        SPFAUpdate(edges, u, dist, q, inqueue);
    }
}

vector<EDGE> edges[maxn];
eType dist[maxn];

int gcd(int a, int b) {
    return !b ? a : gcd(b, a % b);
}

int lcm(int a, int b) {
    return a / gcd(a, b) * b;//先除再乘，防止溢出
}

int main()
{
    int n = 2021;
    initEdges(n, edges);
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j - i <= 21; ++j) {
            if (i - j > 21) continue;
            if (j > n) break;
            addEdge(edges, i, j, lcm(i, j));
        }
    }
    SPFA(edges, n, 1, dist);
    cout << dist[n] << endl;
    return 0;
}