class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {

        int n = heights.size();

        stack<int> st1,st2;
        st1.push(-1);
        st2.push(-1);

        vector<int> nextSmallerElement(n);
        vector<int> previousSmallerElement(n);

        for(int i = n - 1; i >=0; i--){
            while(st1.top() != -1 and heights[i] <= heights[st1.top()]){
                st1.pop();
            }
            nextSmallerElement[i] = st1.top();
            st1.push(i);
        }

        //st.clear();

        for(int i = 0; i < n; i++){
             while(st2.top() != -1 and heights[i] <= heights[st2.top()]){
                st2.pop();
            }
            previousSmallerElement[i] = st2.top();
            st2.push(i);
        }

        int ans = INT_MIN;

        for(int i = 0; i < n; i++){
            int l = heights[i];
            if(nextSmallerElement[i] == -1) nextSmallerElement[i] = n;
            int b = nextSmallerElement[i] - previousSmallerElement[i] - 1;
            int area = l * b;
            ans = max(ans,area);
        }

        return ans;
        
    }
};
