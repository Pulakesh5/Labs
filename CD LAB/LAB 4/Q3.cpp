

#include <iostream>
#include <stdlib.h>
#include<bits/stdc++.h>
using namespace std;
/*
E->-E|E+T|E-T|T
T->T*F|T/F|F
F->(E)|id

left recursion removed
E->-EE'|TE'
E'->+TE'|-TE'|#
T->FT'
T'->*FT'|/FT'|#
F->(E)|id
*/
int cnt = 0;
void E();
void Ed();
void T();
void Td();
void F();

string expr;

int main() {
  cin >> expr;
  int l = expr.length();
  expr += "$";
  E();
  if (l == cnt)
    cout << "Accepted" << endl;
  else
    cout << "Rejected" << endl;
}

void E() {
    //E->-EE'|TE'
    if(expr[cnt]=='-'){
        cnt++;
        cout<<"E->-EE'"<<endl;
        E();
        Ed();
    }
    else{
        cout<<"E->TE'"<<endl;
        T();
        Ed();
    }
}

void Ed() {
    //E'->+TE'|-TE'|#
    if(expr[cnt] == '+'){
        cnt++;
        cout<<"E'->+TE'"<<endl;
        T();
        Ed();
    }
    else if(expr[cnt] == '-'){
        cnt++;
        cout<<"E'->-TE'"<<endl;
        T();
        Ed();
    }
    else{
        cout<<"E'->null"<<endl;
    }
}

void T() {
    //T->FT'
    cout << "T->FT'" << endl;
    F();
    Td();
}

void Td() {
    //T'->*FT'|/FT'|#
    if (expr[cnt] == '*') {
      cnt++;
      cout << "T'->*FT'" << endl;
      F();
      Td();
    }

    else if (expr[cnt] == '/') {
      cnt++;
      cout << "T'->/FT'" << endl;
      F();
      Td();
    }

    else {
      cout << "T'->null" << endl;
    }
}

void F() {
    //F->(E)|id
    if (isalpha(expr[cnt])) {
      if(isalpha(expr[cnt+1])){
          cout<<"Operator op missing at position "<<cnt<<endl;
          cout<<"Rejected"<<endl;
          exit(0);
      }
      else if(expr[cnt+1] == '(' ){
          cout<<"Operator op missing at position "<<cnt+1<<endl;
          cout<<"Rejected"<<endl;
          exit(0);
      }
      else if(expr[cnt-1] == ')'){
          cout<<"Operator op missing at position "<<cnt-1<<endl;
          cout<<"Rejected"<<endl;
          exit(0);
      }
      cnt++;
      cout << "F->id" << endl;
    } else if (expr[cnt] == '(') {
      cnt++;
      cout << "F->(E)" << endl;
      E();
      if (expr[cnt] != ')') {
          cout<<"Paranthesis missing at position "<<cnt<<endl;
        cout << "Rejected" << endl;
        exit(0);
      }
      cnt++;
    } else if(expr[cnt] == ')'){
        cnt++;
        cout<<"Rejected";
        exit(0);
    }
    else {
        cout<<"Operand var missing at position "<<cnt+1<<endl;
      cout << "Rejected" << endl;
      exit(0);
    }
}
