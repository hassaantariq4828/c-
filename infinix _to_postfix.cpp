#include <iostream>
#include <string>
#include <math.h>  // for pow(  ,  )
using namespace std;
typedef double Type;
struct Node{
  Type data ;
  Node * next ;
};
class Stack{
private : Node* head;
public  : Stack( );
      bool Is_Empty();
      Type Top();
      void Push ( Type Data );
      Type  Pop  (          );
      ~Stack( ) ;
};

Stack::Stack( ){ 
  head = NULL;
}
bool Stack::Is_Empty() { 
  return head == NULL;
}
Type Stack::Top() { 
  if ( !Is_Empty() ) 
    return head->data;
  return NULL;
} 
void Stack :: Push ( Type Data ) {
  Node *newNode ;
  newNode = new Node ;
  if ( newNode == NULL ){
    cout << endl << "Stack is full" ;
    return;
  }
  newNode -> data = Data ;
  newNode -> next = head ;
  head = newNode ;
}
Type Stack :: Pop( ) {
  if ( Is_Empty() ){
    cout << "Stack is empty " ;
    return -1 ;
  }
  Node *current ;
  Type Data ;
  current = head ;
  Data = current -> data ;
  head = head -> next ;
  delete current ;
  return Data ;
}
Stack :: ~Stack( ){
  Node *current ;
  while ( head != NULL ){
    current = head ;
    head = head -> next ;
    delete current ;
  }
}
class PF_Solver{
private:
  Stack s;
  string expr;
public:
  PF_Solver(string eq);
  double Calculate();
  double Operation(double N1, char Op, double N2);
}; 
PF_Solver::PF_Solver(string eq) {
  expr = eq;
}

double PF_Solver::Operation(double N1, char Op,double N2)
{    
  switch(Op){
  case '+': return N1 + N2;
  case '-': return N1 - N2;
  case '*': return N1 * N2;
  case '/': return N1 / N2;
  case '^': return pow (N1,N2);
  }
  return 0;
}

double PF_Solver::Calculate(){
  char e; double  n1,n2,n3;

  for ( unsigned int i =0 ; i<expr.size() ; i++){ 
    e = expr[i];
    if ( e == ' ' || e == '\t' )
      continue ;
    if( e >= '0' && e <= '9')
      s.Push( e - '0');
    else {
      n2 = s.Pop();
      n1 = s.Pop();
      n3 = Operation(n1,e,n2);
      s.Push( n3 );
    }
  }
  return s.Pop();
}

int main( ){
  string expression = "6 2 3 + - 3 8 2 / + * 2 ^ 3 +";
  // string expression;
  // cout<<"Enter Postfix Expression:";
  // std::getline(cin,expression);

  cout << "Expression = " << expression.c_str() << endl;
  PF_Solver P(expression);
  cout << "Answer = " 
       << P.Calculate()
    << endl;
  system("PAUSE");
  return 0;
}