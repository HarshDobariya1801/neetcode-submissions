class Solution {
public:
    int maxProfit(vector<int>& prices) {

        int n = prices.size();

        int s = prices[0];

        int ans = 0;

        for(int i = 1; i < n; i++){
            if(prices[i] - s > 0){
                ans = max(ans, prices[i] - s );
               
            }
             s = min(s, prices[i]);
        }

        return ans;
        
    }
};
