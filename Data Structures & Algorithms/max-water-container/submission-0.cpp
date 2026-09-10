class Solution {
public:
    int maxArea(vector<int>& heights) {

        int n = heights.size();

        int start = 0;
        int end = n - 1;

        int area = 0;
        int ans = 0;

        while(start <= end){
            area = (end - start) * min(heights[start],heights[end]);
            ans = max(ans,area);

            if(heights[start] <= heights[end]){
                start = start + 1;
            }else end = end - 1;
        }

        return ans;
        
    }
};
