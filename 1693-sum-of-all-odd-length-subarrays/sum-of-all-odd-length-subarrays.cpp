class Solution {
public:
      int sumOddLengthSubarrays(vector<int>& arr) {
        int ans{};
        int n = arr.size();

        for(int i = 0; i < n; i++) {
            int start = i;
            int end = n - i;
            int total = (start + 1) * (end);
            int odd = total / 2;

            if(total % 2 != 0) {
                odd++;
            }
			
            ans += arr[i] * odd;
        }
		
        return ans;
    }
};