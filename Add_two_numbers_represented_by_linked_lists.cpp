/*
https://practice.geeksforgeeks.org/problems/add-two-numbers-represented-by-linked-lists/1



Given two decimal numbers represented by two linked lists of size N and M respectively. The task is to return a linked list that represents the sum of these two numbers.

For example, the number 190 will be represented by the linked list, 1->9->0->null, similarly 25 by 2->5->null. Sum of these two numbers is 190 + 25 = 215, which will be represented by 2->1->5->null. You are required to return the head of the linked list 2->1->5->null.
*/

//{ Driver Code Starts
// driver

#include <bits/stdc++.h>
using namespace std;

/* Linked list Node */
struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node* buildList(int size)
{
    int val;
    cin>> val;
    
    Node* head = new Node(val);
    Node* tail = head;
    
    for(int i=0; i<size-1; i++)
    {
        cin>> val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

void printList(Node* n)
{
    while(n)
    {
        cout<< n->data << " ";
        n = n->next;
    }
    cout<< endl;
}


// } Driver Code Ends
/* node for linked list:

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
    private:
    Node* reverse(Node* head) {
        Node* curr = head;
        Node* prev = NULL;
        Node* next = NULL;
        
        while(curr != NULL){
            next = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }   
        void insertAtTail(struct Node* &head, struct Node* &tail, int val){
            
            Node* temp = new Node(val);
            //empty list
            if(head == NULL){
                head = temp;
                tail = temp;
                return;
            }
            else{
                tail -> next = temp;
                tail = temp;
            }
        }
        
        struct Node* add(struct Node* first, struct Node* second)
        {
            int carry = 0;
            
            Node* ansHead = NULL;
            Node* ansTail = NULL;
            
            while(first != NULL && second != NULL){
                int sum = carry + first -> data + second -> data;
                int digit = sum % 10;
                
                //create node and add in answer linked list
                insertAtTail(ansHead, ansTail, digit);
                
                carry = sum/10;
                first = first -> next;
                second = second -> next;
            }
        
        while(first != NULL){
            int sum = carry + first -> data;
            int digit = sum % 10;
            
            //create node and add in answer Linked List
            insertAtTail(ansHead, ansTail, digit);
            carry = sum / 10;
            first = first -> next;
        }
        
        while(second != NULL){
            int sum = carry + second -> data;
            int digit = sum % 10;
            
            //create node and add in answer Linked List
            insertAtTail(ansHead, ansTail, digit);
            carry = sum / 10;
            second = second -> next;
        }
        
        while(carry != 0){
            int sum = carry;
            int digit = sum % 10;
            
            //create node and add in answer Linked List
            insertAtTail(ansHead, ansTail, digit);
            carry = sum / 10;
        }
        
        return ansHead;
    }
    public:
    //Function to add two numbers represented by linked list.
    struct Node* addTwoLists(struct Node* first, struct Node* second)
    {
        //step -1   - reverse input LL
        first = reverse(first);
        second = reverse(second);
        
        
        //step -2   - add 2 LL
        Node* ans = add(first, second);
        
        
        //step -3  
        ans = reverse(ans);
        
        return ans;
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, m;
        
        cin>>n;
        Node* first = buildList(n);
        
        cin>>m;
        Node* second = buildList(m);
        Solution ob;
        Node* res = ob.addTwoLists(first,second);
        printList(res);
    }
    return 0;
}

// } Driver Code Ends

