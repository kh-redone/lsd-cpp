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

stack reverse_k(int k,stack *S)
{
    stack R=nullptr;
    stack temp=*S;
    stack final=nullptr;
    int i=0;
    while (temp != nullptr )
    {
        if ( i<k )
        {
            
            push(temp->element,&R);
            temp=temp->next;
        }
        else
        {
            
            while ( R != NULL)
            {
                Add_at_end_stack(R->element,&final);
                R=R->next;
            }
            R=nullptr;
            i=-1;
        }
        i++;
    }
    while ( R != NULL)
        {
            Add_at_end_stack(R->element,&final);
            R=R->next;
        }
    return final;
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
  push(2 , &test);
  push(1 , &test);
  print_stack(test);cout << endl; // the result :1   2   3   4   5   6   7   8
  stack N=reverse_k(2,&test);     // the result :2   1   4   3   6   5   8   7
  print_stack(N);cout <<endl;
  return 0;
}
