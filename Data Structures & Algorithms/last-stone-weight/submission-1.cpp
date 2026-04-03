class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        // max heap
        priority_queue<int> maxHeap;
        for (int s : stones){
            maxHeap.push(s);
        }
        // maxHeap now contains biggest to lowest values
        // operations are logn
        while (maxHeap.size() > 1){
            int first = maxHeap.top();
            maxHeap.pop();
            int second = maxHeap.top();
            maxHeap.pop();
            if (second < first){
                // x > y
                maxHeap.push(first - second);
            }
        }
        // could be that the last 2 elements destroy each other
        maxHeap.push(0);

        return maxHeap.top();
    }
};
