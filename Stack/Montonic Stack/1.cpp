//PROBLEM LINK: https://leetcode.com/problems/largest-rectangle-in-histogram/description/  (Hard level)

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        stack<int>st;
        vector<int>left(n),right(n);
        //next smaller to left(NSL)
        for(int i=0;i<n;i++){
            while(!st.empty() && heights[st.top()]>=heights[i]){
                st.pop();
            }
            left[i] = st.empty() ? -1: st.top();
            st.push(i);
        }
        while(!st.empty()) st.pop();
        //previous smalleer to NSR 
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && heights[st.top()]>=heights[i]){
                st.pop();
            }
            right[i] = st.empty()? n:st.top();
            st.push(i);
        }

        //Rectangle->width*area
        int maxA=0;
        for(int i=0;i<n;i++){
            int width = right[i]-left[i]-1;
            maxA = max(maxA,heights[i]*width);
        }
        return maxA;
    }
};
