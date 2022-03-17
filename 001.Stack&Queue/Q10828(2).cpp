//
//  Q10828(2).cpp
//  001.Stack&Queue
//
//  Created by Kong Nayeon  on 2022/03/17.
//

#include <iostream>
#include <string.h>
using namespace std;

#define MAX_STACK_SIZE 100

int stack[MAX_STACK_SIZE],top = -1;


void push(int e){
    stack[++top] = e;
}

int empty() {
    if (top < 0)return 1;
    else return 0;
}
void pop() {
    if (empty() == 1)cout << "-1"<<endl;
    else {
        cout << stack[top--] << endl;
    }
}


int main(){
    int num =0 , element = 0;
    cin >> num;
    char str[10];
    
    for(int i = 0; i<num; i++){
        cin >> str;
        if (!strcmp(str, "push")){
              cin >> element;
              push(element);
            }
        else if (!strcmp(str, "pop"))
            pop();
        else if (!strcmp(str, "top")){
            if (empty()==1) cout << -1 <<endl;
            else cout<<stack[top]<<endl;
        }
        else if (!strcmp(str, "empty"))
            cout <<empty()<<endl;
        else
            cout <<top+1<<endl;
    }
    return 0;
}
