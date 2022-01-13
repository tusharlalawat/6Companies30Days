#include<bits/stdc++.h>
using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) {
        val = x;
        left = NULL;
        right = NULL;
    }
};

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        
        if(!root) return "";
        
        string s;
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty()){
            TreeNode* temp = q.front();
            q.pop();
            
            if(temp == NULL) s += "$,";
            else s += (to_string(temp->val) + ',');
            
            if(temp){
                q.push(temp->left);
                q.push(temp->right);
            }
        }
        cout <<"S: " <<s <<endl;
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        
        if(data.length() == 0) return NULL;
        
        stringstream ss(data);
        string s;
        getline(ss, s, ',');
        
        TreeNode* root = new TreeNode(stoi(s));
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty()){
            TreeNode* temp = q.front();
            q.pop();
            
            getline(ss, s, ',');
            if(s == "$") temp->left = NULL;
            else {
                temp->left = new TreeNode(stoi(s));
                q.push(temp->left);
            }
            
            getline(ss, s, ',');
            if(s == "$") temp->right = NULL;
            else {
                temp->right = new TreeNode(stoi(s));
                q.push(temp->right);
            }
        }
        return root;
    }
};

int main() {
    return 0;
}