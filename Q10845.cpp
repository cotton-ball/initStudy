//
//  Q10845.cpp
//  001.Stack&Queue
//  Queue 를 사용한 문제풀이
//  Created by Kong Nayeon  on 2022/03/14.
//

#include <iostream>
#include <string.h>
using namespace std;

#define MAX_QUEUE_SIZE 10001

int queue[MAX_QUEUE_SIZE]={};
int front = -1, rear =-1;


void push(int e){
    if(front==-1){
            front = 0;
        }
        queue[++rear] = e;
    }

int empty() {
    if(front==-1 || front>rear) return 1;
    else return 0;
}
void pop() {
    cout<<queue[front]<<endl;
    front++;
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
        else if (!strcmp(str, "pop")){
            if (empty()==1) cout << -1 <<endl;
            else pop();
                
            }
        else if (!strcmp(str, "front")){
            if (empty()==1) cout << -1 <<endl;
            else cout<<queue[front]<<endl;
        }
        else if (!strcmp(str, "back")){
            if (empty()==1) cout << -1 <<endl;
            else cout<<queue[rear]<<endl;
        }
        else if (!strcmp(str, "empty"))
            cout <<empty()<<endl;
        else
            if (empty()==1) cout << "0" <<endl;
            else cout <<rear-front+1<<endl;
    }
    return 0;
}
