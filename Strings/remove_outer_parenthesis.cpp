class Solution {
public:
    string removeOuterParentheses(string s) {
        string result;
        int n = s.length();

        int depth = 0;
        for(int i=0 ; i<n ; i++){
            if(s[i] == '('){
                if(depth > 0){
                    result.push_back(s[i]);
                }
                depth++;
            }
            else{ //case for '('
                depth--;
                if(depth > 0){
                    result.push_back(s[i]);
                }
            }
        }
        return result;
    }
};