class MinStack {
    // when we pu
    long min;
    stack<long> s;
public:
    MinStack() {
        
    }
    
    void push(int val) {
        if (s.empty()){
            s.push(0);
            min = val;
        } else {
            s.push(val - min); // negative if val < min. So all pushed that are negative means that they were the min.
            if (val < min) min = val;
        }
    }
    
    void pop() {
        if (s.empty()) return;
        long pop = s.top();
        s.pop();
        if (pop < 0) min = min - pop; // if removed the minimum element then readd to minimum the popped.
    }
    
    int top() {
        long top = s.top();
        return (top > 0) ? (top + min) : (int)min;
    }
    
    int getMin() {
        return (int) min;
    }
};
