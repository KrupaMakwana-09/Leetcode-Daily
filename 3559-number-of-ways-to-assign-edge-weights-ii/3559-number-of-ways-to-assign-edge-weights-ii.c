#include <stdlib.h>
#include <string.h>

#define MAXLOG 18
#define MOD 1000000007LL

typedef struct Node {
    int to;
    struct Node *next;
} Node;

Node **adj;
int **up;
int *depth;
long long *pow2;

void addEdge(int u, int v) {
    Node *n1 = (Node *)malloc(sizeof(Node));
    n1->to = v;
    n1->next = adj[u];
    adj[u] = n1;

    Node *n2 = (Node *)malloc(sizeof(Node));
    n2->to = u;
    n2->next = adj[v];
    adj[v] = n2;
}

void dfs(int u, int parent) {
    up[u][0] = parent;

    for (int i = 1; i < MAXLOG; i++) {
        up[u][i] = up[up[u][i - 1]][i - 1];
    }

    Node *cur = adj[u];
    while (cur) {
        int v = cur->to;

        if (v != parent) {
            depth[v] = depth[u] + 1;
            dfs(v, u);
        }

        cur = cur->next;
    }
}

int lca(int a, int b) {
    if (depth[a] < depth[b]) {
        int temp = a;
        a = b;
        b = temp;
    }

    int diff = depth[a] - depth[b];

    for (int i = 0; i < MAXLOG; i++) {
        if (diff & (1 << i))
            a = up[a][i];
    }

    if (a == b)
        return a;

    for (int i = MAXLOG - 1; i >= 0; i--) {
        if (up[a][i] != up[b][i]) {
            a = up[a][i];
            b = up[b][i];
        }
    }

    return up[a][0];
}

/**
 * Note: The returned array must be malloced.
 */
int* assignEdgeWeights(int** edges, int edgesSize, int* edgesColSize,
                       int** queries, int queriesSize, int* queriesColSize,
                       int* returnSize) {

    int n = edgesSize + 1;

    adj = (Node **)calloc(n + 1, sizeof(Node*));

    for (int i = 0; i < edgesSize; i++) {
        addEdge(edges[i][0], edges[i][1]);
    }

    depth = (int *)calloc(n + 1, sizeof(int));

    up = (int **)malloc((n + 1) * sizeof(int *));
    for (int i = 0; i <= n; i++) {
        up[i] = (int *)calloc(MAXLOG, sizeof(int));
    }

    dfs(1, 0);

    pow2 = (long long *)malloc((n + 1) * sizeof(long long));
    pow2[0] = 1;

    for (int i = 1; i <= n; i++) {
        pow2[i] = (pow2[i - 1] * 2) % MOD;
    }

    int *answer = (int *)malloc(queriesSize * sizeof(int));

    for (int i = 0; i < queriesSize; i++) {
        int u = queries[i][0];
        int v = queries[i][1];

        int p = lca(u, v);

        int len = depth[u] + depth[v] - 2 * depth[p];

        if (len == 0)
            answer[i] = 0;
        else
            answer[i] = (int)pow2[len - 1];
    }

    *returnSize = queriesSize;
    return answer;
}