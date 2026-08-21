#include<bits/stdc++.h>
using namespace std;

int priority(char oparator){
    if(oparator =='^')
        return 100;
    
    else if(oparator =='*' || oparator =='/')
        return 50;
    
    else if(oparator =='+' || oparator =='-')
        return 25;
    
    else
        return -1;  

}

string infix_to_postfix(string infix){

    stack <char> oparators;

    string postfix="";

    for(int i=0;i<infix.length();i++){

        if(infix[i]>='0' && infix[i]<='9' ){

            postfix+=infix[i];
            
        }

        else if(infix[i]=='('){

            oparators.push(infix[i]);

        }else if(infix[i]==')'){

            while(!oparators.empty() && oparators.top() != '('){

                postfix+=oparators.top();
                oparators.pop();

            }
            oparators.pop();
        }else{

            while(!oparators.empty() && priority(oparators.top()) >= priority(infix[i])){

                postfix+=oparators.top();
                oparators.pop();
            }
            oparators.push(infix[i]);
        }
    }

    while(!oparators.empty()){

        postfix+=oparators.top();
        oparators.pop();
    }

    return postfix;
}

double postfix_evaluation(string postfix){

    stack <double> operands;
    

    for(int i=0;i<postfix.length();i++){

        if(postfix[i]>='0' && postfix[i]<='9'){
            
            operands.push(postfix[i]-'0');

        }else if(postfix[i]!=' '){
            if(postfix[i]=='+'){

                double a=operands.top();
                operands.pop();

                double b=operands.top();
                operands.pop();

                operands.push(b+a);
  
                
            }else if(postfix[i]=='-'){

                double a=operands.top();
                operands.pop();

                double b=operands.top();
                operands.pop();

                operands.push(b-a);

            }else if(postfix[i]=='*'){

                double a=operands.top();
                operands.pop();

                double b=operands.top();
                operands.pop();

                operands.push(b*a);

            }else {
                double a=operands.top();
                operands.pop();

                double b=operands.top();
                operands.pop();

                operands.push(b/a);

            }
        }
    }

    return operands.top();
}
int main(){

    string infix="(5+6/2*(8+4)-7)";
    cout<<"Enter infix expression: "<<infix<<endl;

    string postfix = infix_to_postfix(infix);
    cout<<"Postfix expression: "<<postfix<<endl;

    double result = postfix_evaluation(postfix);
    cout<<"Postfix evaluation: "<<result<<endl;
}