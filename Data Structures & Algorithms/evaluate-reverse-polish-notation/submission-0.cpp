class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        // the key is to put the elements into a stack.
        stack<int> res;
        for (const string& c : tokens){
            if (c == "+"){
                int a = res.top();
                res.pop();
                int b = res.top();
                res.pop();
                res.push(a + b);
            }
            else if (c == "*"){
                int a = res.top();
                res.pop();
                int b = res.top();
                res.pop();
                res.push(a*b);
            }
            else if (c == "-"){
                int a = res.top();
                res.pop();
                int b = res.top();
                res.pop();
                res.push(b - a);
            }
            else if (c == "/"){
                int a = res.top();
                res.pop();
                int b = res.top();
                res.pop();
                res.push(b / a);
            } else {
                res.push(stoi(c));
            }
        }
        return res.top();
    }   
};
