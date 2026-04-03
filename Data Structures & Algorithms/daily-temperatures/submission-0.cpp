class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        // in other words, how many elements until next element is strictly increasing.
        // idea: add to a stack, if the element is bigger than the top, then pop from the stack until its empty or the top is bigger,
        // whichever comes first. we also keep track of the index and calculate the number of days when popping.
        stack<int> s;
        vector<int> res(temperatures.size(), 0);

        for (int i = 0; i < temperatures.size(); ++i){
            if (s.empty()){
                s.push(i);
                continue;
            }

            while (!s.empty() && temperatures[s.top()]< temperatures[i]){
                // need to pop!
                int j = s.top();
                s.pop();
                res[j] = (i - j);
            }

            // we add it to the stack
            s.push(i);
        }

        // if the stack is not empty, then default values of 0 is ok.
        return res;
    }
};
