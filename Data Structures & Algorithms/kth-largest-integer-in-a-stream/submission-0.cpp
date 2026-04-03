class KthLargest {
public:
// MIN HEAP!
// we only need to keep track of the k largest elements seen so far.
// If the heap contains the k largest elements,
//then the smallest among them is exactly the k-th largest overall.
    priority_queue<int,vector<int>, greater<int>> minHeap;
    int k;

    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        for (int num : nums){
            minHeap.push(num);
            if (minHeap.size() > k){
                minHeap.pop();
            }
        }
    }
    
    // each call is O(logk)
    int add(int val) {
        minHeap.push(val);
        if (minHeap.size() > k){
            minHeap.pop();
        }
        return minHeap.top();
    }
};
