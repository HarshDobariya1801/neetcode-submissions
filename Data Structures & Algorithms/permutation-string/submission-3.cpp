class Solution {
public:
    bool checkInclusion(string s1, string s2) {

        int n = s1.size();
        int m = s2.size();

        unordered_map<char,int> m1,m2;

        for(int i = 0; i < n; i++){
            m1[s1[i]]++;
            m2[s2[i]]++;
        }

        if(m1 == m2) return true;
        
        int i = 0;

        for(int j = n; j < m; j++){
    
                m2[s2[i]]--;
                if(m2[s2[i]] == 0){
                    m2.erase(s2[i]);
                }
                m2[s2[j]]++;
                i++;

             if(m1 == m2) return true;

        }

        return false;
        
    }
};
