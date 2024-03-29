/*
https://www.codingninjas.com/codestudio/problems/merge-two-sorted-linked-lists_800332?leftPanelTab=0&campaign=YouTube_Lovebabbar31stJan2021&utm_source=youtube&utm_medium=affiliate&utm_campaign=YouTube_Lovebabbar31stJan2021
*/

#include<bits/stdc++.h>
using namespace std;

template <typename T>
    class Node {
        public:
        T data;
        Node* next;

        Node(T data) {
            next = NULL;
            this->data = data;
        }

        ~Node() {
            if (next != NULL) {
                delete next;
            }
        }
};

Node<int>* solve(Node<int>* first, Node<int>* second){

    //if only one element is present in first list
    if(first -> next == NULL){
        first -> next = second;
        return first;
    }

    Node<int>* curr1 = first;
    Node<int>* next1 = curr1 -> next;
    Node<int>* curr2 = second;
    Node<int>* next2 = curr2 -> next;
    
    while(next1 != NULL && curr2 != NULL){
        

        if((curr1 -> data <= curr2 -> data) && 
            (curr2 -> data <= next1 -> data)){
                //add nodes in between the first line
            curr1 -> next = curr2;
            next2 = curr2 -> next;
            curr2 -> next = next1;

            //update pointers
            curr1 = curr2;
            curr2 = next2;
        }
        else{
            // curr1 and next1 ko aage badhana padega
            curr1 = next1;
            next1 = next1 -> next;  

            if(next1 == NULL){
                curr1 -> next = curr2;
                return first;
            }
        }
    }
    return first;
}

Node<int>* sortTwoLists(Node<int>* first, Node<int>* second)
{

    


    if(first == NULL)
        return second;

    if(second == NULL)
        return first;

    if(first -> data <= second -> data){
        return solve(first, second);
    }
    else{
        return solve(second, first);
    }
}