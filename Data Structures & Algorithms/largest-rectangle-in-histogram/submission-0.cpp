class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> leftMost(n, -1);
        vector<int> rightMost(n, n);
        stack<int> stack;

        //  for each index i, the nearest smaller bar on the left:
        for (int i = 0; i < n; i++) {
            while (!stack.empty() && heights[stack.top()] >= heights[i]) {
                stack.pop();
            }
            // The top of the stack becomes the left boundary, it is now the biggest
            if (!stack.empty()) {
                leftMost[i] = stack.top();
            }
            stack.push(i);
        }

        while (!stack.empty()) stack.pop();

        for (int i = n - 1; i >= 0; i--) {
            // If the current bar is shorter than the bar on top of the stack, pop until this is no longer true.
            // we want the current bar to be the biggest
            while (!stack.empty() && heights[stack.top()] >= heights[i]) {
                stack.pop();
            }
            if (!stack.empty()) {
                rightMost[i] = stack.top();
            }
            stack.push(i);
        }

        int maxArea = 0;
        for (int i = 0; i < n; i++) {
            leftMost[i] += 1;
            rightMost[i] -= 1;
            maxArea = max(maxArea, heights[i] * (rightMost[i] - leftMost[i] + 1));
        }

        return maxArea;
    }
};