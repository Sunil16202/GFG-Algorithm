//https://leetcode.com/problems/diameter-of-binary-tree/submissions/

class Solution {
public:
    
    int diameter(TreeNode * root, int & res){
    if(root == NULL){
        return 0;
    }
    int l = diameter(root -> left, res);
    int r = diameter(root -> right, res);
    
    //if root not included
    int temp = max(l,r)+1 ;
    
    //if root included
    int ans = max(temp, l+r+1);
    
    res = max(res, ans);
    return temp;
}
    
    int diameterOfBinaryTree(TreeNode* root) {
        int res = 1;
        int a = diameter(root,res);
        return res-1;
    }
};