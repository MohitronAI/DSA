class Solution {
public:
    vector<vector<int>> ans;
    vector<int> temp;

    void backtrack(vector<int>& nums, int index) {

        ans.push_back(temp);

        for(int i = index; i < nums.size(); i++) {
            temp.push_back(nums[i]);
            backtrack(nums, i + 1);
            temp.pop_back();
        }
    }

    vector<vector<int>> subsets(vector<int>& nums) {

        backtrack(nums, 0);

        return ans;
    }
};