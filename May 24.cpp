Return the root node of a binary search tree that matches the given preorder traversal.

(Recall that a binary search tree is a binary tree where for every node, any descendant of node.left has a value < node.val, and any descendant of node.right has a value > node.val.  Also recall that a preorder traversal displays the value of the node first, then traverses node.left, then traverses node.right.)

It's guaranteed that for the given test cases there is always possible to find a binary search tree with the given requirements.

Example 1:

Input: [8,5,1,7,10,12]
Output: [8,5,10,1,7,null,12]

 

Constraints:

1 <= preorder.length <= 100
1 <= preorder[i] <= 10^8
The values of preorder are distinct.

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    // TreeNode* buildBST(TreeNode* root,int elem){
    //     if(root == NULL)
    //         return new TreeNode(elem);
    //     if(elem<root->val){
    //         root->left = buildBST(root->left,elem);
    //     }
    //     else{
    //         root->right = buildBST(root->right,elem);
    //     }
    //    return root;    
    // }
    int buildBST(vector<int>& preorder,int n,int pos,TreeNode* curr,int min,int max){
        if(pos == n || preorder[pos]<min || preorder[pos]>max){
            return pos;
        }
        if( preorder[pos]<curr->val){
            curr->left = new TreeNode(preorder[pos]);
            pos = buildBST(preorder,n,pos+1,curr->left,min,curr->val-1);
        }
        if(pos == n || preorder[pos]<min || preorder[pos]>max){
            return pos;
        }
        if( preorder[pos]>curr->val){
            curr->right = new TreeNode(preorder[pos]);
            pos = buildBST(preorder,n,pos+1,curr->right,curr->val+1,max);
        }
        return pos;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        TreeNode* root = NULL;
        int min = *min_element(preorder.begin(),preorder.end());
        int max = *max_element(preorder.begin(),preorder.end());
        root = new TreeNode(preorder[0]);
        buildBST(preorder,preorder.size(),1,root,min,max);
        return root;
    }
};