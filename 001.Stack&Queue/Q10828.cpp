//
//  main.cpp
//  001.Stack&Queue
//
//  Created by Kong Nayeon  on 2022/03/14.
//

#include <iostream>
#include <string.h>
using namespace std;

#define MAX_STACK_SIZE 10001

//스택 클래스 정의
class Stack{
public:
    int stack[MAX_STACK_SIZE];
    int top;
    
    //생성자
    Stack(){
        top = -1;
    }
    
    //공백 확인
    int is_empty(){
        if (top < 0) return 1;
        else return 0;
    }
    
    int is_full(){
        if(top == MAX_STACK_SIZE-1) return 1;
        else return 0;
    }
    
    //스택에 값을 넣어줌
    void push(int e){
        if(!is_full()) stack[++top] = e;
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
    string a;
    for(int i = 0; i<num; i++){
        cin >> a;
        if (a== "push"){
            int element;
            if(!s.is_full()){
                cin >> element;
                s.push(element);
            }
        }
        else if(a == "pop")
            cout << s.pop()<<endl;
        else if(a == "top")
            cout<<s.getTop()<<endl;
        else if (a == "size")
            cout << s.getSize()<<endl;
        else if (a == "empty")
            cout << s.is_empty()<<endl;
    }
    return 0;
}
