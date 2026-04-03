class Solution {
public:
    bool isValid(string s) {
        std::stack<char> openingBrackets;
        // std::stack closingBrackets;
        std::unordered_map<char, char> mapping {{'(', ')'}, {'{', '}'}, {'[', ']'}};

        if (s.length() <= 1) return false;

        for (auto c : s){
            if (c == '(' || c == '{' || c == '['){
                openingBrackets.push(c);
            } else {
                if (openingBrackets.empty()) return false;
                char correspondingBracket = openingBrackets.top(); // (
                openingBrackets.pop();
                if ((mapping.find(correspondingBracket))->second != c){
                    return false;
                }
            }
        }

        if (!openingBrackets.empty()) return false;

        return true;
    }
};
