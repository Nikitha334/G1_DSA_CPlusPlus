#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* next;
    
    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

void loopHere(Node* head, Node* tail, int position)
{
    if(position==0) return;
    
    Node* walk = head;
    for(int i=1; i<position; i++)
        walk = walk->next;
    tail->next = walk;
}

bool isLoop(Node* head)
{
    if(!head) return false;
    
    Node* fast = head->next;
    Node* slow = head;
    
    while( fast != slow)
    {
        if( !fast || !fast->next ) return false;
        fast=fast->next->next;
        slow=slow->next;
    }
    
    return true;
}

int length(Node* head)
{
    int ret = 0;
    while(head)
    {
        ret++;
        head = head->next;
    }
    return ret;
}

bool notOriginal(Node *head, unordered_map<Node *, int>&myMap){
    
    while(head){
        if(myMap.find(head)==myMap.end()) return true;
        if(myMap[head] != (head->data)) return true;
        
        head=head->next;
    }
}


class Solution
{
    public:
    
    bool isLoop(Node *head){
        if(head == NULL)
            return false;
        if(head->next == NULL)
            return false;
            
        Node *slow = head;
        Node *fast = head;
        
        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast)
                return true;
        }
        
        return false;
    }
    
    Node *findStart(Node* head){
        Node *slow = head;
        Node *fast = head;
        
        while(true){
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast)
                break;
        }
        
        slow = head;
        while(slow != fast){
            slow = slow->next;
            fast = fast->next;
        }
        
        return slow;
    }
    
    //Function to remove a loop in the linked list.
    void removeLoop(Node* head)
    {
        // code here
        // just remove the loop without losing any nodes
        bool check = isLoop(head);
        if(check == false)
            return;
            
        Node *start = findStart(head);
        Node* cur = start;
        while(cur->next != start)
            cur = cur->next;
        cur->next = NULL;
        return;
    }
};
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        unordered_map<Node *, int>myMap;
        
        int n, num;
        cin>>n;
        
        Node *head, *tail;
        cin>> num;
        head = tail = new Node(num);
        
        myMap[head]=num;
        
        for(int i=0 ; i<n-1 ; i++)
        {
            cin>> num;
            tail->next = new Node(num);
            tail = tail->next;
            myMap[tail]=num;
        }
        
        int pos;
        cin>> pos;
        loopHere(head,tail,pos);
        
        Solution ob;
        ob.removeLoop(head);
        
        if( isLoop(head) || length(head)!=n || notOriginal(head, myMap))
            cout<<"0\n";
        else
            cout<<"1\n";
    }
	return 0;
}

