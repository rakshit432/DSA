class Solution {
public:
    bool ispossible(int node, int col,
                    vector<vector<int>>& graph,
                    vector<int>& color)   // ✅ by reference
    {
        color[node] = col;

        for (auto &it : graph[node]) {
            if (color[it] == -1) {
                if (!ispossible(it, !col, graph, color))
                    return false;
            }
            else if (color[it] == col) {
                return false;  // same color on adjacent nodes
            }
        }
        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        int V = graph.size();
        vector<int> color(V, -1);

        for (int i = 0; i < V; i++) {
            if (color[i] == -1) {
                if (!ispossible(i, 0, graph, color))
                    return false;
            }
        }
        return true;
    }
};
