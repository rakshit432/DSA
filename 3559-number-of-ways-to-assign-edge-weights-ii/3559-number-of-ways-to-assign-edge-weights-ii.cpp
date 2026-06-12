constexpr int N = 1e5;
constexpr int LOG = 17;

static int q[N], front = 0, back = 0;
static int adj[N + 1];

struct Edge {
    int to = -1, nxt = -1;
};

static Edge E[2 * N];
static int eCnt = 0;

static inline void addEdge(int u, int v) {
    E[eCnt] = {v, adj[u]};
    adj[u] = eCnt++;
}

static int level[N + 1], parent[N + 1], up[N + 1][LOG];
static constexpr int mod = 1e9 + 7;

class Solution {
public:
    static long long modPow(long long x, int exp) {
        long long y = 1;
        while (exp) {
            if (exp & 1) y = y * x % mod;
            x = x * x % mod;
            exp >>= 1;
        }
        return y;
    }

    static long long pow2(int x) {
        if (x < 30) return 1LL << x;

        long long B = (1LL << 30) % mod;
        auto [q, r] = div(x, 30);

        return modPow(B, q) * pow2(r) % mod;
    }

    static int lca(int u, int v) {
        if (level[u] < level[v]) swap(u, v);

        int diff = level[u] - level[v];

        while (diff) {
            int i = __builtin_ctz(diff);
            u = up[u][i];
            diff &= (diff - 1);
        }

        if (u == v) return u;

        for (int i = LOG - 1; i >= 0; --i) {
            if (up[u][i] != up[v][i]) {
                u = up[u][i];
                v = up[v][i];
            }
        }

        return up[u][0];
    }

    static int distance(int u, int v) {
        int a = lca(u, v);
        return level[u] + level[v] - 2 * level[a];
    }

    vector<int> assignEdgeWeights(vector<vector<int>>& edges,
                                  vector<vector<int>>& queries) {

        int n = edges.size() + 1;

        memset(adj, -1, sizeof(int) * (n + 1));
        memset(level, 0, sizeof(int) * (n + 1));
        memset(parent, 0, sizeof(int) * (n + 1));

        eCnt = 0;

        for (auto& e : edges) {
            int u = e[0];
            int v = e[1];

            addEdge(u, v);
            addEdge(v, u);
        }

        static bitset<N + 1> vis;
        vis.reset();

        front = back = 0;

        q[back++] = 1;
        vis[1] = 1;

        level[1] = 1;
        parent[1] = 0;

        while (front < back) {
            int u = q[front++];

            for (int e = adj[u]; e != -1; e = E[e].nxt) {
                int v = E[e].to;

                if (!vis[v]) {
                    vis[v] = 1;
                    parent[v] = u;
                    level[v] = level[u] + 1;
                    q[back++] = v;
                }
            }
        }

        for (int i = 1; i <= n; i++)
            up[i][0] = parent[i];

        for (int j = 1; j < LOG; j++) {
            for (int i = 0; i <= n; i++) {
                up[i][j] = up[up[i][j - 1]][j - 1];
            }
        }

        vector<int> ans(queries.size());

        for (int i = 0; i < queries.size(); i++) {
            int u = queries[i][0];
            int v = queries[i][1];

            int d = distance(u, v);

            ans[i] = d ? pow2(d - 1) : 0;
        }

        return ans;
    }
};