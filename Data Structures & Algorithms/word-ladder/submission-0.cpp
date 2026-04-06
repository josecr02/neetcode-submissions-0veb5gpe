class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        /*
        You may transform beginWord to any word within wordList, 
        provided that at exactly one position the words have a different character, 
        and the rest of the positions have the same characters.
        */
        // not optimal solution O(n2 m) time and O(n2) space. Solution 1. BFS.
        if (find(wordList.begin(), wordList.end(), endWord) == wordList.end() || beginWord == endWord){
            return 0;
        }

        int n = wordList.size(); 
        int m = wordList[0].size(); // they all have same length
        vector<vector<int>> adj(n);
        unordered_map<string,int> mp; // mapping word to index of wordList they are
        for (int i = 0; i < n; ++i){
            mp[wordList[i]] = i;
        }

        // now build adjacency list
        for (int i = 0; i < n; ++i){
            for (int j = i + 1; j < n; ++j){
                int count = 0; // count of different characters
                for (int k = 0; k < m; ++k){
                    if (wordList[i][k] != wordList[j][k]){
                        ++count;
                    }
                }

                // now add!
                if (count == 1){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }

        // now add to queue the ones that have directe edge to beginWord
        queue<int> q;
        int res = 1;
        unordered_set<int> visit;

        for (int i = 0; i < m; ++i){ // for every spot in the word
            for (char c = 'a'; c <= 'z'; ++c){
                if (c == beginWord[i]){
                    // char is the same so skip
                    continue;
                }
                // word that we check if it exists
                string word = beginWord.substr(0, i) + c + beginWord.substr(i + 1);
                if (mp.find(word) != mp.end() && visit.find(mp[word]) == visit.end()){
                    // we can add
                    q.push(mp[word]); // push index of word
                    visit.insert(mp[word]);
                }
            }
        }

        // normal bfs
        while (!q.empty()){
            ++res;
            int size = q.size();
            for (int i = 0; i < size; ++i){ // level by level, we try all next possivle in each level
                 int node = q.front();
                q.pop();
                if (wordList[node] == endWord) {
                    return res;
                }
                for (int nei : adj[node]) {
                    if (visit.find(nei) == visit.end()) {
                        visit.insert(nei);
                        q.push(nei);
                    }
                }
            }
        }

        return 0;
    }
};
