#include <bits/stdc++.h>
using namespace std;

class ListNode{
public:
    int val;
    ListNode *next;
    ListNode(int x){
        val=x;
        next=NULL;
    }
};

class Solution{
public:
    ListNode *moveToFront(ListNode *head){
        ListNode *ptr=head;
        if(head==NULL || head->next==NULL)return head;
        int prev=head->val;
        int data;
        ptr=ptr->next;
        while(ptr!=NULL)
        {   data= ptr->val;
            ptr->val=prev;
            prev=data;
            
            ptr=ptr->next;
        }
        head-> val=data;
        return head;
        
    }
};

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<ListNode*> a(n);
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            a[i]=new ListNode(x);
            if(i!=0){
                a[i-1]->next=a[i];
            }
        }
        ListNode *head=a[0];
        Solution ob;
        head=ob.moveToFront(head);
        while(head!=NULL){
            cout<<head->val;
            if(head->next!=NULL){
                cout<<" ";
            }
            head=head->next;
        }
        cout<<endl;
    }
    return 0;
}
