class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        // greedy, more optimal.
        vector<int> count(26, 0);
        for (char t : tasks){
            count[t - 'A']++;
        }
        // now we want to get the max frequeuncy
        sort(count.begin(), count.end()); 
        int maxf = *max_element(count.begin(), count.end());
        int idle = (maxf - 1) * n; // n spacing in betweeno for cooldown.
        for (int i = 24; i >= 0; i--) {
            idle -= min(maxf - 1, count[i]); // we use sorting because there might be tasks with same frequency.
        }
        if (idle > 0){
            // we have to fill idle states
            return tasks.size() + idle;
        }
        else{
            // no extra time needed
            return tasks.size();
        }
    }
};
