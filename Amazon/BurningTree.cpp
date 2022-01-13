#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;

    Node(){
        this->data = 0;
        this->left = NULL;
        this->right = NULL;
    }
};

class Solution {
  public:
    int minTime(Node* root, int target) 
    {
        // Your code goes here
        queue<Node*> q;
        map<Node*, Node*> mp;  // To map all the node's parent nodes
        q.push(root);
        Node* t = NULL;
        
        while(!q.empty()){
            Node* temp = q.front();
            q.pop();
            
            if(temp->data == target) t = temp;
            if(temp->left){
                mp[temp->left] = temp;
                q.push(temp->left);
            }
            if(temp->right){
                mp[temp->right] = temp;
                q.push(temp->right);
            }
        }
        
        map<Node*, int> visited;  // To check weather the node is visited previos;y or not
        int ans = 0;
        q.push(t);
        
        while(!q.empty()){
            int n = q.size();
            for(int i=0; i<n; i++){
                Node* temp = q.front();
                q.pop();
                
                visited[temp] = 1;
                if(temp->left && visited[temp->left] == 0) q.push(temp->left);
                if(temp->right && visited[temp->right] == 0) q.push(temp->right);
                if(mp.find(temp) != mp.end() && visited[mp[temp]] == 0) q.push(mp[temp]);
            }
            ans++;
        }
        return ans-1;    
    }
};

int main(){
    return 0;
}