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


int main()
{

  stack test=NULL;
  push(1 , &test);
  push(2 , &test);
  push(3 , &test);
  push(4 , &test);
  push(5 , &test);
  push(6 , &test);
  print_stack(test);cout << endl; //result: 6   5   4   3   2   1  
  pop(&test);
  print_stack(test);cout <<endl;  //result: 5   4   3   2   1
  return 0;
}
