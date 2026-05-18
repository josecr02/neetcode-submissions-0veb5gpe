class PrefixTree {
    // same but modern C++
    class TrieNode{
    public:
        vector<TrieNode*> children;
        bool endOfWord;

        TrieNode() : children(26, nullptr), endOfWord(false) {
        }
    };
    TrieNode* root;
public:
    PrefixTree() : root{new TrieNode()} {}
    
    void insert(string word) {
        TrieNode* cur = root;
        for (char c : word){
            int i = c - 'a'; // index
            if (cur->children[i] == nullptr){
                cur->children[i] = new TrieNode();
            }
            cur = cur->children[i];
        }
        cur->endOfWord = true;
    }
    
    bool search(string word) {
        TrieNode* cur = root;
        for (char c : word){
            int i = c - 'a';
            if (cur->children[i] == nullptr){
                return false;
            }
            cur = cur->children[i];
        }
        return cur->endOfWord;
    }
    
    bool startsWith(string prefix) {
        TrieNode* cur = root;
        for (char c : prefix){
            int i = c - 'a';
            if (cur->children[i] == nullptr){
                return false;
            }
            cur = cur->children[i];
        }
        return true;
    }
};
