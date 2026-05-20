class Solution {
public:
    
    vector<vector<int>> result;
    
    void backtrack(vector<int>& candidates, int target,
                   vector<int>& current, int index) {
        
        // base case
        if(target == 0) {
            result.push_back(current);
            return;
        }
        
        for(int i = index; i < candidates.size(); i++) {
            
            // skip duplicates
            if(i > index && candidates[i] == candidates[i - 1])
                continue;
            
            // pruning
            if(candidates[i] > target)
                break;
            
            current.push_back(candidates[i]);
            
            // i + 1 क्योंकि same element reuse नहीं कर सकते
            backtrack(candidates, target - candidates[i],
                      current, i + 1);
            
            current.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        
        sort(candidates.begin(), candidates.end());
        
        vector<int> current;
        
        backtrack(candidates, target, current, 0);
        
        return result;
    }
};