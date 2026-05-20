class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        // Dijkstr'as algorithm. compute shortest distances from k to nodes.
        // first build graph
        // adjacency list
        // dijkstra works with a minheap, keyed by distances
        // we take the minimum distance and add the neighbours to minHeap.
        // we can save the result of time in a vector (distance), and return the max element
        vector<vector<pair<int, int>>> adj(n+1);
        for (auto t : times){
            adj[t[0]].push_back({t[1], t[2]}); // so that we have a :{{b, X}, ...}
        } // vector where each entry is a vector of pairs!

        // {distToNode, node};
        priority_queue<vector<int>, vector<vector<int>>, greater<>> minHeap;

        minHeap.push({0, k}); // starting
        set<int> visited;

        int maxTime = 0;

        while (!minHeap.empty()){
            vector<int> nextClosestNode = minHeap.top();
            minHeap.pop();
            
            if (visited.count(nextClosestNode[1])) continue;
            visited.insert(nextClosestNode[1]);
            
            maxTime = max(maxTime, nextClosestNode[0]);
            // iterate through neighbours to add
            for (auto neighbor : adj[nextClosestNode[1]]){
                if (visited.find(neighbor.first) != visited.end()){
                    continue;
                }
                // else add
                // push curDist + distEdge
                minHeap.push({nextClosestNode[0] + neighbor.second, neighbor.first});
            }
        }  

        return visited.size() == n ? maxTime : -1;
    }
};
