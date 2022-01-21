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
