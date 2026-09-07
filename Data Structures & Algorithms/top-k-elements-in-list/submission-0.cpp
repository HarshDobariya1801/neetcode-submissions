class Solution {
private:
    struct node{
        int num;
        int freq;

        node(int a, int b){
            num = a;
            freq = b;
        }
    };

    struct comp{
        bool operator()(node a,node b){
            return a.freq < b.freq;
        }
    };


public:
    vector<int> topKFrequent(vector<int>& nums, int k) {

        int n = nums.size();
        map<int,int> mp;

        for(int i = 0; i < n; i++){
            mp[nums[i]]++;
        }

        priority_queue<node,vector<node>, comp> q;

        for(auto it: mp){
            q.push(node(it.first,it.second));
        }

        vector<int> ans;

        while(k--){
            node temp = q.top();
            q.pop();
            ans.push_back(temp.num);
        }

        return ans;
        
    }
};
