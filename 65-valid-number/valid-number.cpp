class Solution {
public:
    bool isNumber(string s) {
        
        bool digitSeen = false;
        bool dotSeen = false;
        bool eSeen = false;
        bool digitAfterE = true;
        
        for(int i = 0; i < s.size(); i++) {
            
            if(isdigit(s[i])) {
                digitSeen = true;
                
                if(eSeen)
                    digitAfterE = true;
            }
            
            else if(s[i] == '+' || s[i] == '-') {
                
                // sign allowed only at start
                // or immediately after e/E
                if(i > 0 && s[i - 1] != 'e' && s[i - 1] != 'E')
                    return false;
            }
            
            else if(s[i] == '.') {
                
                // only one dot and not after e/E
                if(dotSeen || eSeen)
                    return false;
                
                dotSeen = true;
            }
            
            else if(s[i] == 'e' || s[i] == 'E') {
                
                // only one e/E and must have digit before it
                if(eSeen || !digitSeen)
                    return false;
                
                eSeen = true;
                digitAfterE = false;
            }
            
            else {
                return false;
            }
        }
        
        return digitSeen && digitAfterE;
    }
};