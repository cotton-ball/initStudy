//
//  main.cpp
//  001.Stack&Queue
//
//  Created by Kong Nayeon  on 2022/03/14.
//

#include <iostream>
#include <string.h>
using namespace std;

#define MAX_STACK_SIZE 100

class Stack{
public:
    int stack[MAX_STACK_SIZE];
    int top;
    Stack(){
        top = -1;
    }
    int is_empty(){
        if (top < 0) return 1;
        else return 0;
    }
    void push(int e){
        else stack[++top] = e;
    }
    int pop(){
        if(is_empty()==1){
            return -1;
        }
        else return stack[top--];
    }
    int getSize(){
        return top+1;
    }
    int getTop(){
        if(is_empty()==1) return -1;
        else return stack[top];
    }
};

int main(){
    Stack s;
    int num =0;
    cin >> num;
    char a[10];
    for(int i = 0; i<=num; i++){
        cin >> a;
        if (!strcmp(a, "push")){
            int element;
            if(!s.is_full()){
                cin >> element;
                s.push(element);
            }
        }
        else if(!strcmp(a, "pop"))
            cout << s.pop()<<endl;
        else if(!strcmp(a, "top"))
            cout<<s.getTop()<<endl;
        else if (!strcmp(a, "size"))
            cout << s.getSize()<<endl;
        else if (!strcmp(a, "empty"))
            cout << s.is_empty()<<endl;
    }
    return 0;
}
