class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        // we want minimum time to reach all nodes starting from node k.
        // i.e. minimum distance from k to all other nodes.
        // i.e. shortest paths
        // since the weights are non-negative,
        // we can use Dijkstra to get shortest paths from k.
        // we use min heap to get closest nodes.
        // time is O(mlognn), O(m + n).
        unordered_map<int, vector<pair<int,int>>> edges; // adjacency list
        for (const auto& time : times){
            edges[time[0]].emplace_back(time[1], time[2]); // time[2] is the weight.
        }

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> minHeap;
        minHeap.push({0, k}); // our min heap has pairs DISTANCE, NODE, ordered by ascending distance.

        set<int> visited;
        int t = 0; // distance
        while (!minHeap.empty()){
            auto curr = minHeap.top();
            minHeap.pop();
            int distance = curr.first, node = curr.second;
            if (visited.count(node)){
                continue; // node already seen with shorter distance.
            }
            visited.insert(node);
            t = distance;
            if (edges.count(node)){
                // if the node has any edge
                for (const auto& neighbour : edges[node]){
                    // add to heap the neighbours
                    // they are saved us NODE,WEIGHT
                    int node2 = neighbour.first, distance2 = neighbour.second;
                    if (!visited.count(node2)){
                        minHeap.push({distance2 + distance, node2}); // add new distance to current distance.
                    }
                }
            }
        }

        return visited.size() == n ? t : -1; // t holds the final necessary shortest distance.
    }
};
