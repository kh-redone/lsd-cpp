#include<iostream>

using namespace std;

struct node
{
    int element;
    struct node *next;
};
using stack = node*;


void push(int x, stack *S)
{
    stack A = new node;
    A->element=x;
    A->next=*S;
    *S=A;
    return;
}
void pop(stack *S)
{
    stack temp = *S;
    *S=(*S)->next;
    delete temp;
}

void print_stack(stack S)
{
    while (S!=NULL)
    {
        cout << S->element << "   ";
        S=S->next;
    }
}


// this add an integer to the last of the stack.
void Add_at_end_stack(int x, stack * S)
{
    stack new_node = new node{ x, nullptr };
    if (*S == nullptr) {
        *S = new_node;
        return;
    }
    stack temp = *S;
    while(temp->next != nullptr)
        temp = temp->next;
    temp->next = new_node;
}

stack unique(stack *S)
{
    stack U = nullptr;
    stack temp = *S;
    int k;
    while (temp != nullptr) {
        k = 0;
        stack U_temp = U;
        while (U_temp != nullptr) {
            if (temp->element == U_temp->element) {
                k = 1;
            }
            U_temp = U_temp->next;
        }
        if (k == 0) {
            Add_at_end_stack(temp->element, &U);
        }
        temp = temp->next;
    }
    return U;
}

int main()
{

  stack test=NULL;
  push(8 , &test);
  push(7 , &test);
  push(6 , &test);
  push(5 , &test);
  push(4 , &test);
  push(3 , &test);
  push(3 , &test);
  push(2 , &test);
  push(1 , &test);
  print_stack(test);cout << endl; // the result : 1 2 3 3 4 5 6 7 8
  stack N = unique(&test);
  print_stack(N);cout << endl;   // teh result  : 1 2 3 4 5 6 7 8
  return 0;
}
