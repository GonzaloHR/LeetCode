class Solution {
public:
    void solve(vector<int>& nums, int i, vector<vector<int>>& ans, vector<int>& output){
        //base case
        if(i >= nums.size()){
            ans.push_back(output);
            return;
        }


        //include wala case
        output.push_back(nums[i]);
        solve(nums, i+1, ans, output);
        output.pop_back();

        //exclude wala case
        solve(nums, i+1, ans, output);
    }


    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        vector<int> output;
        int i = 0;
        solve(nums, i, ans, output);
        map<vector<int>, int> mp;
        for(auto it : ans){
            mp[it]++;
        }

        vector<vector<int>> finalAnswer;
        for(auto it : mp){
            finalAnswer.push_back(it.first);
        }
        return finalAnswer;
    }
};