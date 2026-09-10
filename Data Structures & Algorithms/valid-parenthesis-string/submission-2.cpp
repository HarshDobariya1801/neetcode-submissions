class Solution {
public:
    bool checkValidString(string s) {

        int n = s.size();
       // stack<char> st;

       int minimum = 0;
       int maximum = 0;

       for(int i = 0; i < n; i++){
            if(s[i] == '('){
                minimum += 1;
                maximum += 1;
            }else if(s[i] == ')'){
                minimum -= 1;
                maximum -= 1;
            }else{
                minimum -= 1;
                maximum += 1;
            }

            if(minimum < 0) minimum = 0;
            if(maximum < 0) return false;
       }

       if(minimum == 0) return true;
       return false;

        
    }
};
