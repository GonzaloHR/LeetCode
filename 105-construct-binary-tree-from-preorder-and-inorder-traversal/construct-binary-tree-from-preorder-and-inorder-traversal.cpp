class Solution {
public:
    TreeNode* solve(vector<int>& preorder,int prestart,int preend, vector<int>& inorder,int instart,int inend,map<int,int>&mp)//map was passed by reference to avoid tle got in last 203rd test case
    {
        if(prestart>preend || instart>inend)//base case
            return NULL;
        
        TreeNode* root=new TreeNode(preorder[prestart]);
        //find the index of root in inorder traversal
        int inroot=mp[root->val];
        //find the number of elements on left of root in its inorder traversal
        int numsOnleft=inroot-instart;
        
        //call for left
        root->left=solve(preorder,prestart+1,prestart+numsOnleft,inorder,instart,inroot-1,mp);
        //call for right
        root->right=solve(preorder,prestart+numsOnleft+1,preend,inorder,inroot+1,inend,mp);
        
        return root;
     }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        
        //create the mapping of inorder elements with their index
        map<int,int>mp;
        for(int i=0;i<inorder.size();i++)
            mp[inorder[i]]=i; 
        
     //TreeNode* root=solve(preorder,prestart,preend,in,instart,inend,mp);  
      TreeNode* root=solve(preorder,0,preorder.size()-1,inorder,0,inorder.size()-1,mp);  

        return root;
    }
};