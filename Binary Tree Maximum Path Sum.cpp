//https://leetcode.com/problems/binary-tree-maximum-path-sum/
class Solution {
public:
    
    int maxPathSum(TreeNode * root, int & res){
    if(root == NULL){
        return 0;
    }
    int l = maxPathSum(root -> left, res);
    int r = maxPathSum(root -> right, res);
    int temp = max(max(l,r) + root -> val, root->val);
    int ans = max(temp, l+r+root->val);
    res = max(ans, res);
    return temp;
    }
    
    int maxPathSum(TreeNode* root) {
        int res = INT_MIN;
        maxPathSum(root, res);
        return res;
    }
};