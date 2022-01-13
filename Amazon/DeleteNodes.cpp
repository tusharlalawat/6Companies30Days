#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

class Solution
{
    public:
    void linkdelete(struct Node *head, int m, int n)
    {
        //Add code here  
        int i=0;
        struct Node* temp = head;
        while(temp != NULL){
            if(i < m-1) {
                while(i < m-1 && temp != NULL) {
                    temp = temp->next;
                    i++;
                }
            }
            else {
                struct Node* t = temp->next;
                int j = 0;
                while(j < n && t != NULL){
                    t = t->next;
                    j++;
                }
                temp->next = t;
                temp = temp->next;
                i=0;
            }
        }
    }
};

int main(){
    int n, M, N;
    cout <<"Enter no. of nodes: ";
    cin >>n;

    Node* head = new Node(0);
    Node* temp = head;
    cout <<"Enter element: ";
    for(int i=0; i<n; i++){
        int x;
        cin >>x;
        Node* t = new Node(x);
        temp->next = t;
        temp = temp->next;
    }
    head = head->next;

    cout <<"Enter M & N: ";
    cin >>M >>N;

    Solution obj;
    obj.linkdelete(head, M, N);

    cout <<"Final List: ";
    while(head){
        cout <<head->data <<" ";
        head = head->next;
    }
    cout <<endl;
}