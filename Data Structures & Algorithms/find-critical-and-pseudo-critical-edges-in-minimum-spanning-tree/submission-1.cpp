class UnionFind {
public:
    vector<int> par, rank;

    UnionFind(int n) : par(n), rank(n, 1) {
        for (int i = 0; i < n; ++i) par[i] = i;
    }

    int find(int v) {
        if (v != par[v]) {
            par[v] = find(par[v]);
        }
        return par[v];
    }

    bool unionSets(int v1, int v2) {
        int p1 = find(v1), p2 = find(v2);
        if (p1 == p2) return false;
        if (rank[p1] > rank[p2]) {
            par[p2] = p1;
            rank[p1] += rank[p2];
        } else {
            par[p1] = p2;
            rank[p2] += rank[p1];
        }
        return true;
    }
};
class Solution {
public:
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
        // Build the standard MST using Kruskal's algorithm to get mstWeight.
        // Build an MST excluding this edge. If the graph becomes disconnected or the weight increases, the edge is critical.
        // Otherwise, build an MST that includes this edge first. If the total weight equals mstWeight, the edge is pseudo-critical.
        vector<array<int,4>> edgeList;
        // {a, b, w, i}
        for (int i = 0; i < edges.size(); ++i){
            edgeList.push_back({edges[i][0], edges[i][1], edges[i][2], i});
        }

        // increasing order of weights
        sort(edgeList.begin(), edgeList.end(), [](auto& a, auto& b){
            return a[2] < b[2];
        });

        int mstWeight = 0;
        // Kruskal algorithm lets us get MST.
        UnionFind uf(n);
        for (auto& edge : edgeList){
            if (uf.unionSets(edge[0], edge[1])){
                // we start taking weights in ascending order while valid (not in same set).
                mstWeight += edge[2];
            }
        }

        vector<int> critical, pseudo;
        for (auto& edge : edgeList){
            // try without current edge building an MST
            UnionFind ufWithout(n);
            int weight = 0;
            for (auto& other : edgeList){
                // try all other edges
                if (other[3] != edge[3] && ufWithout.unionSets(other[0], other[1])){
                    weight += other[2];
                }
            }
            // if we cannot build a connected tree or weight is bigger, it is critical.
            if (*max_element(ufWithout.rank.begin(), ufWithout.rank.end()) != n || weight > mstWeight) {
                critical.push_back(edge[3]);
                continue;
            }

            // Try with current edge, to see if its pseudo critical (mst valid).
            UnionFind ufWith(n);
            ufWith.unionSets(edge[0], edge[1]);
            weight = edge[2];
            for (auto& other : edgeList){
                // no need to check because unionSets already checks if in same set
                if (ufWith.unionSets(other[0], other[1])) {
                    weight += other[2];
                }
            }
            if (weight == mstWeight){
                pseudo.push_back(edge[3]);
            }
        }

        return {critical, pseudo};
    }
};