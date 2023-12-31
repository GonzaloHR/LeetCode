class Solution {
	public:
		vector<TreeNode*> generateTrees(int n, int s = 1) {
			vector<TreeNode*> ans;
			if(n < s) return {nullptr};                              
			 for(int i=s; i<=n; i++) {                	                 // Consider every number in range [s,n] as root  
				for(auto left: generateTrees(i-1, s)) {                  // generate all possible trees in range [s,i)
					for(auto right: generateTrees(n, i+1))               // generate all possible trees in range (i,e]
						ans.push_back(new TreeNode(i, left, right));     // make new trees with i as the root 
				}
			}
			return ans;
		}
	};