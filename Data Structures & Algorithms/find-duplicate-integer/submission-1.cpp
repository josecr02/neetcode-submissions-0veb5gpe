class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        // optimal solution not modifying the nums array
        // we follow it as a linked list.
        // Distance from head to cycle entrance = Distance from meeting point to cycle entrance
        int slow = 0, fast = 0;
        while (true){
            slow = nums[slow];
            fast = nums[nums[fast]];
            if (slow == fast){ 
                break;
            }
        }

        int slow2 = 0;
        while (true){
            slow = nums[slow];
            slow2 = nums[slow2];
            if (slow == slow2){
                return slow;
            }
        }
    }
};
