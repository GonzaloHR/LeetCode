class Solution {
   
public: 
 Solution(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}
int minimumTotal(vector<vector<int>> &triangle)
{

    int n = triangle.size();
    for (int i = n-1; i >0 ; i--)
    {
        int m = triangle[i].size();
        for (int j = 0; j < m-1; j++)
        {
            triangle[i-1][j] += min( triangle[i][j] ,  triangle[i][j+1]);
        }
    }
    return triangle[0][0];
}
};