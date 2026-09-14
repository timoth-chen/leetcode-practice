class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int largest_area = 0;
        int n = heights.size();
        stack<int> stack;
        for (int i = 0; i <= n; i++){
            while(!stack.empty() && (i == n || heights[i] <= heights[stack.top()])){
                int height = heights[stack.top()];
                stack.pop();
                int width = stack.empty() ? i : i - stack.top() - 1;
                largest_area = max(largest_area, height * width);
            }
            stack.push(i);
        }
        return largest_area;
    }
};
