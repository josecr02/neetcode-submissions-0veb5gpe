/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        // we do bfs starting with the given node, we keep queue and pop and add neighbours to queue.
        // The new change is that we have a map to map old node to new node.
        // time is o(n + m), space is o(n).
        if (!node) return nullptr;
        unordered_map<Node*, Node*> oldToNew;
        queue<Node*> q;
        q.push(node); // start with node
        // and create deep copy of it
        oldToNew[node] = new Node(node->val);

        while (!q.empty()){
            Node* cur = q.front();
            q.pop();
            for (Node* nei : cur->neighbors){
                if (oldToNew.find(nei) == oldToNew.end()){
                    // create copy of neighbour and add.
                    oldToNew[nei] = new Node(nei->val);
                    q.push(nei); // add to queue
                }
                // if it already exists or new, then just add neighbour
                oldToNew[cur]->neighbors.push_back(oldToNew[nei]);
            }
        }

        return oldToNew[node];
    }
};
