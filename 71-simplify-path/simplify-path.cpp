class Solution {
public:
    string simplifyPath(string path) {
        
        vector<string> st;
        string dir = "";
        
        for(int i = 0; i <= path.size(); i++) {
            
            if(i == path.size() || path[i] == '/') {
                
                if(dir == "" || dir == ".") {
                    // do nothing
                }
                else if(dir == "..") {
                    if(!st.empty())
                        st.pop_back();
                }
                else {
                    st.push_back(dir);
                }
                
                dir = "";
            }
            else {
                dir += path[i];
            }
        }
        
        if(st.empty())
            return "/";
        
        string result = "";
        
        for(string s : st) {
            result += "/" + s;
        }
        
        return result;
    }
};