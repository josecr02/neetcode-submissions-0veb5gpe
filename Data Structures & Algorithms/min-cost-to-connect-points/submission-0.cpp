class DSU {
public:
    vector<int> Parent, Size;

    DSU(int n) : Parent(n), Size(n, 1) {
        for (int i = 0; i < n; ++i) Parent[i] = i;
    }

    int find(int node) {
        if (Parent[node] != node) {
            Parent[node] = find(Parent[node]);
        }
        return Parent[node];
    }

    bool unionSets(int u, int v) {
        int pu = find(u), pv = find(v);
        if (pu == pv) return false;
        if (Size[pu] < Size[pv]) swap(pu, pv);
        Size[pu] += Size[pv];
        Parent[pv] = pu;
        return true;
    }
};

class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        DSU dsu(n);
        vector<vector<int>> edges;

        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                int dist = abs(points[i][0] - points[j][0]) +
                           abs(points[i][1] - points[j][1]);
                edges.push_back({dist, i, j});
            }
        }

        sort(edges.begin(), edges.end());
        int res = 0;

        for (auto& edge : edges) {
            if (dsu.unionSets(edge[1], edge[2])) {
                res += edge[0];
            }
        }
        return res;
    }
};