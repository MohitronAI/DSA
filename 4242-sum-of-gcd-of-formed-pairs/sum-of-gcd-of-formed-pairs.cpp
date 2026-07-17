class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        
        int n = nums.size();
        vector<long long> prefixGcd(n);

        long long mx = 0;

        for(int i = 0; i < n; i++) {
            mx = max(mx, (long long)nums[i]);
            prefixGcd[i] = gcd((long long)nums[i], mx);
        }

        sort(prefixGcd.begin(), prefixGcd.end());

        long long ans = 0;
        int left = 0, right = n - 1;

        while(left < right) {
            ans += gcd(prefixGcd[left], prefixGcd[right]);
            left++;
            right--;
        }

        return ans;
    }
};