class MedianFinder {
    priority_queue<int, vector<int>, less<int>> smallHeap; // lower half sorted
    priority_queue<int, vector<int>, greater<int>> largeHeap; // upper half
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        smallHeap.push(num);
        // i.e. small heap (top) 6, 4, 2, 1
        // i.e. large heap (top) 8, 9, 10, 11
        if (!largeHeap.empty() && smallHeap.top() > largeHeap.top()){
            // move the bigger one to the upper half heap
            largeHeap.push(smallHeap.top());
            smallHeap.pop();
        }
        // rebalance: If one heap becomes larger than the other by more than 1, move the top element to the other heap.
        if (smallHeap.size() > largeHeap.size() + 1){
            largeHeap.push(smallHeap.top());
            smallHeap.pop();
        }
        if (largeHeap.size() > smallHeap.size() + 1){
            smallHeap.push(largeHeap.top());
            largeHeap.pop();
        }
    }
    
    double findMedian() {
        if (smallHeap.size() == largeHeap.size()){
            return (largeHeap.top() + smallHeap.top()) / 2.0;
        } else if (smallHeap.size() > largeHeap.size()){
            return smallHeap.top();
        } else {
            return largeHeap.top();
        }
    }
};
