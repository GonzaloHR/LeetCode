class Solution {
public:
    unordered_set<string> mp;
    vector<string> ans;
    void rec(string &s,int n,int i,int dots,vector<string> &candidate){
        if(i>=n){
            if(dots==4){
                string tmp_ans = "";
                for(auto &ele:candidate){
                    tmp_ans += ele;
                    tmp_ans.push_back('.');
                }
                tmp_ans.pop_back();
                ans.push_back(tmp_ans);
            }
            return;
        }
        for(int j=i;j<n;j++){
            string tmp = s.substr(i,j-i+1);
            if(mp.count(tmp)){ // if string is between 0 to 255
                candidate.push_back(tmp); // try that possibility
                rec(s,n,j+1,dots+1,candidate);
                candidate.pop_back(); // backtrack
            }
        }
    }
    vector<string> restoreIpAddresses(string s){
        int n = s.size();
        mp.clear();
        ans.clear();
        for(int i=0;i<256;i++){
            mp.insert(to_string(i));
        }
        vector<string> candidate;
        rec(s,n,0,0,candidate);
        return ans;
    }
};