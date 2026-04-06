class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        // more optimal? O(m2 n) for time and space. SOlution 2.
        unordered_set<string> words(wordList.begin(), wordList.end()); // convert for O(1) lokups
        if (words.find(endWord) == words.end() || beginWord == endWord) return 0;
        int res = 0;
        queue<string> q;
        q.push(beginWord);

        while (!q.empty()) {
            res++;
            int len = q.size();
            for (int i = 0; i < len; i++) { // layer by layer bfs again.
                string node = q.front();
                q.pop();
                if (node == endWord) return res;
                for (int j = 0; j < node.length(); j++) { // go through all chars
                    char original = node[j];
                    for (char c = 'a'; c <= 'z'; c++) { // and then replace each char with every other char
                        if (c == original) continue;
                        node[j] = c;
                        if (words.find(node) != words.end()) { // add edge to visit
                            q.push(node);
                            words.erase(node); // remove, we dont want to reuse.
                        }
                    }
                    node[j] = original; // put back again the og char
                }
            }
        }
        return 0;
    }
};