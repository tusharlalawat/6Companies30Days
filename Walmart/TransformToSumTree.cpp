#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* left, * right;
}; 

class Solution {
  public:
    int createSumTree(Node *node) {
        
        if(node == NULL) return 0;
        
        int left = createSumTree(node->left);
        int right = createSumTree(node->right);
        int temp = node->data;
        node->data = left + right;
        
        return (left + right + temp);
    }
    
    void toSumTree(Node *node)
    {
       createSumTree(node);
    }
};

int main() {
    return 0;
}