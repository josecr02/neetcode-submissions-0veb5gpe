class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        
        // more optimal solution O(mlogm).
        // this is an eulerian path (use each edge once and form a connected path start at JFK).
        unordered_map<string, vector<string>> adj;
        for (auto t : tickets){
            if (adj.find(t[0]) == adj.end()){
                adj[t[0]] = {};
            }
            adj[t[0]].push_back(t[1]);
        }
        for (auto& [src, dests] : adj){
            sort(dests.rbegin(), dests.rend());
        }

        vector<string> res;
        dfs("JFK", adj, res);
        reverse(res.begin(), res.end());
        return res;
        
    }

    void dfs(const string& src, unordered_map<string,
             vector<string>>& adj, vector<string>& res) {
        while (!adj[src].empty()) {
            string dst = adj[src].back();
            adj[src].pop_back();
            dfs(dst, adj, res);
        }
        res.push_back(src);
    }
};
