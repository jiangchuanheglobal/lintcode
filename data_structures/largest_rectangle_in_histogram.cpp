class Solution {
public:
    /**
     * @param height: A list of integer
     * @return: The area of largest rectangle in the histogram
     */
    int largestRectangleArea(vector<int> &height) {
        // write your code here
        int max_area = 0;
        stack<int> stk;
        height.insert(height.begin(), 0);
        height.push_back(0);
        for (int i = 0; i < height.size(); i++) {
            while (!stk.empty() && height[stk.top()] > height[i]) {
                int top = stk.top();
                stk.pop();
                int leftbound = stk.top();
                max_area = ::max(max_area, (i - leftbound - 1) * height[top]);
            }
            stk.push(i);
        }
        
        return max_area;
    }
};

// for i = 0 to last

//      if height[i] >= height[stk.top()]
//          stk.push(i)
//      
//          while (height[stk.top()] > height[i])
//              curt = stk.top();
//              stk.pop();
        //         leftbound = stk.top();
        //         max_area = ::max(max_area, (i - leftbound - 1)* height[curt])
                
        // return max_area;
