#include <iostream>
#include <bits/stdc++.h>
using namespace std;
struct Node {
   int data;
   struct Node *next;
};
class LinkedList{
private:
struct Node* head = NULL;
public:
void push(int new_data) {
   struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
   new_node->data = new_data;
   new_node->next = head;
   head = new_node;
}
void display() {
   struct Node* temp;
   temp = head;
   while (temp != NULL) {
      cout<< temp->data <<" ";
      temp = temp->next;
   }
}
void deleteNode(int data)
{
    if(head->data == data)
    {
        if(head->next == NULL)
        {
            cout << "There is only one node";
            return;
        }
        head->data = head->next->data;
        head->next = head->next->next;
        return;
    }
    struct Node* prev = head;
    while(prev->next != NULL && prev->next->data != data)
        prev = prev->next;

    if(prev->next == NULL)
    {
        cout << "\nGiven node is not present in Linked List";
        return;
    }
    prev->next = prev->next->next;
    return;
}
};
int main() {
    LinkedList a;
    char c;
    cout<<"press Y to enter data ";
    cin>>c;
    while((c=='Y' || c=='y')){
        int data;
        cout<<"enter data: ";
        cin>>data;
        a.push(data);
        cout<<"press Y to enter more data ";
        cin>>c;

    }
    cout<<"The linked list is: ";
    a.display();
    int data;
    cout<<"\nenter the node to delete:";
    cin>>data;
    a.deleteNode(data);
    cout<<"\nThe linked list is: ";
    a.display();
    return 0;
}
