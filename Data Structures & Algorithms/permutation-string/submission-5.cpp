class Solution {
public:
    bool checkInclusion(string s1, string s2) {

        int n = s1.size();
        int m = s2.size();

        if(n > m) return false;

        vector<int> v1(26,0),v2(26,0);

        for(int i = 0; i < n; i++){
            v1[s1[i] - 'a']++;
            v2[s2[i] - 'a']++;
        }

        //if(m1 == m2) return true;
        if(v1 == v2) return true;
        int i = 0;

        for(int j = n; j < m; j++){
    
               // m2[s2[i]]--;
                v2[s2[i] - 'a']--;
                // if(m2[s2[i]] == 0){
                //     m2.erase(s2[i]);
                // }
               // m2[s2[j]]++;
                v2[s2[j] - 'a']++;
                i++;

            // if(m1 == m2) return true;
            if(v1 == v2) return true;

        }

        return false;
        
    }
};
