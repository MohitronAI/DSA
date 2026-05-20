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
        
        // invalid case
        if(target < 0)
            return;
        
        for(int i = index; i < candidates.size(); i++) {
            
            current.push_back(candidates[i]);
            
            // same i because element can be reused
            backtrack(candidates, target - candidates[i], current, i);
            
            current.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        
        vector<int> current;
        
        backtrack(candidates, target, current, 0);
        
        return result;
    }
};