#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
};

int solve(Node* root, int target, int& count) {
    if(!root) return 0;
    
    int left = solve(root->left, target, count);
    int right = solve(root->right, target, count);
    int sum = root->data + left + right;
    
    if(sum == target) count++;
    
    return sum;
}
int countSubtreesWithSumX(Node* root, int target)
{
	// Code here
	int count = 0;
	solve(root, target, count);
	return count;
}

int main(){
    return 0;
}