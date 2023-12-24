class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<int> diff(prices.size()-1,0);
        int n = prices.size();
        int ans = 0;

        for (int i = 1; i < n; i++)
        {
            diff [i-1] = prices[i] - prices[i-1];

            if (diff[i-1] > 0)
            {
                ans += diff[i-1];
            }
        }

        return ans;        
    }
};