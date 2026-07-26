class Solution {
public:
    vector<string> ans;

    bool isValid(string s) {

        if(s.empty() || s.size() > 3)
            return false;

        if(s.size() > 1 && s[0] == '0')
            return false;

        int num = stoi(s);
        return num >= 0 && num <= 255;
    }

    void backtrack(string &s, int index, int parts, string path) {

        if(parts == 4 && index == s.size()) {
            path.pop_back(); // remove last '.'
            ans.push_back(path);
            return;
        }

        if(parts == 4 || index == s.size())
            return;

        for(int len = 1; len <= 3 && index + len <= s.size(); len++) {

            string part = s.substr(index, len);

            if(isValid(part)) {
                backtrack(s, index + len, parts + 1, path + part + ".");
            }
        }
    }

    vector<string> restoreIpAddresses(string s) {

        backtrack(s, 0, 0, "");

        return ans;
    }
};