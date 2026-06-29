class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        
        vector<string> result;
        int i = 0;
        int n = words.size();
        
        while(i < n) {
            
            int lineLength = words[i].size();
            int j = i + 1;
            
            // Find how many words fit in current line
            while(j < n && lineLength + 1 + words[j].size() <= maxWidth) {
                lineLength += 1 + words[j].size();
                j++;
            }
            
            int gaps = j - i - 1;
            string line = "";
            
            // Last line or only one word
            if(j == n || gaps == 0) {
                
                for(int k = i; k < j; k++) {
                    line += words[k];
                    if(k != j - 1)
                        line += " ";
                }
                
                line += string(maxWidth - line.size(), ' ');
            }
            else {
                
                int totalChars = 0;
                for(int k = i; k < j; k++)
                    totalChars += words[k].size();
                
                int totalSpaces = maxWidth - totalChars;
                int evenSpaces = totalSpaces / gaps;
                int extraSpaces = totalSpaces % gaps;
                
                for(int k = i; k < j - 1; k++) {
                    line += words[k];
                    line += string(evenSpaces + (extraSpaces > 0 ? 1 : 0), ' ');
                    if(extraSpaces > 0)
                        extraSpaces--;
                }
                
                line += words[j - 1];
            }
            
            result.push_back(line);
            i = j;
        }
        
        return result;
    }
};