#include<iostream>
#include <cstdlib>
using namespace std;

struct node {
   int data;
   struct node *left;
   struct node *right;
};
struct Stack {
   struct node *link;
   struct Stack *next;
};
class BST{
private:
    struct node* left=NULL;
    struct node* right=NULL;
    struct Stack* head = NULL;
public:
    struct node *createNode(int n) {
        //function to create new node
        struct node *temp = (struct node *)malloc(sizeof(struct node));
        temp->data = n;
        temp->left = temp->right = NULL;
        return temp;
    }
    struct node* insertNode(struct node* node, int n) {
        if (node == NULL) return createNode(n);
        if (n < node->data)
            node->left = insertNode(node->left, n);
        else if (n > node->data)
            node->right = insertNode(node->right, n);
        return node;
    }
    void preorder(struct node *root) {
        //fucntion to print the preorder recursively
       if (root != NULL) {
          cout<<root->data<<" ";
          preorder(root->left);
          preorder(root->right);
       }
    }
    struct Stack* createStack(){
        head=NULL;
        return head;
    }
    struct node* top(struct Stack *head){
        return head->link;
    }
    int isempty(struct Stack *head){
        if (head==NULL)
            return 0;
        else
            return 1;
    }
    struct Stack* pop(struct Stack *head){
        if (head->next!=NULL){
            struct Stack* temp=head->next;
            head=temp;
            return head;
        }
    }
    struct Stack* push(struct node *link,struct Stack *head){
        struct Stack* new_node = (struct Stack*) malloc(sizeof(struct Stack));
        new_node->link = link;
        new_node->next = head;
        head = new_node;
        return head;
    }
    void preorderIterative(struct node *root){
        //non recursive way to preorder
        //cout<<"entering function";
        if (root == NULL){
            cout<<"null";
            return;
        }
        //cout<<"after if";
        head=createStack();
        head=push(root,head);
        //cout<<head->link->data;
        //struct node* ab=top(head);
        //cout<<ab->data;
        while (isempty(head))
        {

            struct node* curr = top(head);
            head=pop(head);
            //cout<<"inside loop";
            cout<<curr->data;
            cout<<" ";
            if (curr->right) {
                head=push(curr->right,head);
            }
            if (curr->left) {
                head=push(curr->left,head);
            }
        }
    //cout<<"no loop";
    }
};
int main() {
    BST a;
    struct node *root = NULL;
    char c;
    cout<<"press Y to enter data ";
    cin>>c;
    while((c=='Y' || c=='y')){
        int data;
        cout<<"enter data: ";
        cin>>data;
        root = a.insertNode(root,data);
        cout<<"press Y to enter more data ";
        cin>>c;
    }

    cout<<"Pre-order traversal of the binary search tree is: ";
    a.preorderIterative(root);
    //a.preorder(root);
    return 0;
}
