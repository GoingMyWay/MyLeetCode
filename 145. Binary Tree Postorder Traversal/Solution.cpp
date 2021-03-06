/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;
        stack<TreeNode*> s;
        TreeNode * p = root;

        while ( !s.empty() || p ) {
            if ( p ) {
                s.push(p);
                p = p->left;
            } else {
                TreeNode * n = s.top();
                if ( n->right == NULL ) {
                    result.push_back(n->val); s.pop();
                    if ( !s.empty() ) p = s.top();
                    else p = NULL;
                    
                    while ( p != NULL && p->right == n ) {
                        result.push_back(p->val); s.pop();
                        n = p;
                        
                        if ( !s.empty() ) p = s.top();
                        else p = NULL;
                    }
                    if ( p != NULL) p = p->right;
                } else p = n->right;
            }
        }
        return result;
    }
};

class Solution2 {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;
        stack<TreeNode*> s;
        TreeNode * p = root;

        while ( !s.empty() || p ) {
            if ( p ) {
                s.push(p);
                result.insert(result.begin(), p->val);
                p = p->right;
            } else {
                p = s.top(); s.pop();
                p = p->left;
            }
        }
        return result;
    }
};
