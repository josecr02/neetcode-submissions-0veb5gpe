class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        
        // main loop: get task with shortest processing time 
        // condition: task needs to be available
        // we keep a timer to check current time.at(
        // a min heap for next shortest.
        priority_queue<vector<int>, vector<vector<int>>, greater<>> minHeap; // {proccesingTime, i}.
        priority_queue<vector<int>, vector<vector<int>>, greater<>> minHeapEnqueues; // {enqueueTime, i};
        // put all in the enqueue
        for (int i = 0; i < tasks.size(); ++i){
            minHeapEnqueues.push({tasks[i][0], i});
        }

        long long timer = 0;
        vector<int> res;

        while (!minHeapEnqueues.empty() || !minHeap.empty()){
            if (minHeap.empty() && !minHeapEnqueues.empty() && minHeapEnqueues.top()[0] > timer) {
                timer = minHeapEnqueues.top()[0];
            }
            
            while (!minHeapEnqueues.empty() && minHeapEnqueues.top()[0] <= timer){
                // take
                vector<int> t = minHeapEnqueues.top();   
                minHeapEnqueues.pop();
                minHeap.push({tasks[t[1]][1], t[1]});       
            }
            // now take the shortest
            auto nextTask = minHeap.top();
            minHeap.pop();
            timer += nextTask[0]; // processing time
            res.push_back(nextTask[1]);
        }
        

        return res;
    }
};