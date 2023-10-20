class Solution {
public:
   int maxSumRangeQuery(vector<int>& nums, vector<vector<int>>& requests) {
    vector<int> cnt(nums.size());
    for (auto &r : requests) {
        cnt[r[0]] += 1;
        if (r[1] + 1 < nums.size())
            cnt[r[1] + 1] -= 1;
    }
    partial_sum(begin(cnt), end(cnt), begin(cnt));
    sort(begin(nums), end(nums));
    sort(begin(cnt), end(cnt));
    return inner_product(begin(nums), end(nums), begin(cnt), 0, 
        [](int res, long long m){ return (res + m) % 1000000007; }, multiplies<long long>());
}
};