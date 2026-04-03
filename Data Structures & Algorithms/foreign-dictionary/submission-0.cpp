class Solution {
public:
    string foreignDictionary(vector<string>& words) {
        // We perform topological sort with BFS (Kahn's Algorithm)
        unordered_map<char, unordered_set<char>> adj; // adjacency list map
        unordered_map<char, int> indegree; // map node to their indegree

        for (string w : words){
            for (char c : w){
                adj[c] = unordered_set<char>(); // initialize each character to have no neighbours
                indegree[c] = 0;
            }
        }

        // still graph construction
        for (int i = 0; i < words.size() - 1; ++i){
            string w1 = words[i], w2 = words[i+1];
            int minLen = min (w1.size(), w2.size());
            if (w1.size() > w2.size() && w1.substr(0, minLen) == w2.substr(0, minLen)){
                return "";
            }

            for (int j = 0; j < minLen; ++j){
                if (w1[j] != w2[j]){
                    if (!adj[w1[j]].count(w2[j])){
                        // add dependency: w2 char gets dependency w1 char
                        adj[w1[j]].insert(w2[j]);
                        indegree[w2[j]]++;
                    }
                    break;
                }
            }
        }

        // now do top sort.

        queue<char> q;
        for (auto &[c, deg] : indegree){
            if (deg == 0){
                q.push(c); // we start with all that dont have dependencies
            }
        }

        string res;
        while (!q.empty()){
            char char_ = q.front();
            q.pop();
            res += char_;
            for (char neighbour : adj[char_]){
                indegree[neighbour]--; // remove dependency
                if (indegree[neighbour] == 0){
                    q.push(neighbour);
                }
            }
        }

        return res.size() == indegree.size() ? res : ""; // because the size of res must contain all the characters.


    }
};
