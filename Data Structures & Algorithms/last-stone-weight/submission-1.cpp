class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {

        int n = stones.size();

        // maxHeap
        priority_queue<int> pq;

        for(int i = 0; i < n; i++){
            pq.push(stones[i]);
        }

        while(pq.size() > 1){

            int x = pq.top();
            pq.pop();

            int y = pq.top();
            pq.pop();

            int diff = 0;

            if(x != y){
                if(x < y || y < x){
                    diff = abs(x - y);
                }
                pq.push(diff);
            }
        }

        if(pq.empty()) return 0;
        return pq.top();



        
    }
};
