/*

Given a binary tree where node values are digits from 1 to 9. A path in the binary tree is said to be pseudo-palindromic if at least one permutation of the node values in the path is a palindrome.

Return the number of pseudo-palindromic paths going from the root node to leaf nodes.

 

Example 1:



Input: root = [2,3,1,3,1,null,1]
Output: 2 
Explanation: The figure above represents the given binary tree. There are three paths going from the root node to leaf nodes: the red path [2,3,3], the green path [2,1,1], and the path [2,3,1]. Among these paths only red path and green path are pseudo-palindromic paths since the red path [2,3,3] can be rearranged in [3,2,3] (palindrome) and the green path [2,1,1] can be rearranged in [1,2,1] (palindrome).
Example 2:



Input: root = [2,1,1,1,3,null,null,null,null,null,1]
Output: 1 
Explanation: The figure above represents the given binary tree. There are three paths going from the root node to leaf nodes: the green path [2,1,1], the path [2,1,3,1], and the path [2,1]. Among these paths only the green path is pseudo-palindromic since [2,1,1] can be rearranged in [1,2,1] (palindrome).
Example 3:

Input: root = [9]
Output: 1
 

Constraints:

The given binary tree will have between 1 and 10^5 nodes.
Node values are digits from 1 to 9.

*/

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
    int count = 0;
    vector<int> cache;
    
    void leafNode() {
        int n = 0;
        for(int i =0;i<cache.size();++i) {
            if (cache[i] % 2 != 0) ++n;
            if (n > 1) return;
        }
        ++count;
    }
    
    void util(TreeNode *root) {
        if (root == nullptr) return;
        ++cache[root->val];
        if (root->left == nullptr && root->right == nullptr) leafNode();
        else {
            util(root->left);
            util(root->right);
        }
        --cache[root->val];
    }
    
    int pseudoPalindromicPaths (TreeNode* root) {
        cache.assign(10,0);
        util(root);
        return count;
    }
    
    
    /*int pseudoPalindromicPaths (TreeNode* root) {
        unordered_map<int,int> cache;
        //util(root,cache);
        stack<pair<TreeNode*,unordered_map<int,int>>> s;
        s.push(make_pair(root,cache));
        while(!s.empty()) {
            pair<TreeNode *,unordered_map<int,int>> p = s.top();
            s.pop();
            TreeNode *curr = p.first;
            unordered_map<int,int> cachee = p.second;
            ++cachee[curr->val];
            if (curr->left == nullptr && curr->right == nullptr) leafNode(cachee);
            if (curr->right) s.push(make_pair(curr->right,cachee));
            if (curr->left) s.push(make_pair(curr->left,cachee));
        }
        return count;
    }*/
};