//
//  Q17298.cpp
//  init
//
//  Created by Kong Nayeon  on 2022/03/18.
//  리스트를 사용해서 다시 해보기

#include <iostream>
#include <string.h>
using namespace std;

#define MAX_STACK_SIZE 100000


//스택에 값을 넣어줌
void push(int e, int stack[],int top){
         stack[++top] = e;
    }
    
    //오큰수 출력
void getNge(int num, int stack[]){
    for(int i = 0; i < num; i++){
        if(i == num-1) cout << "-1";
        else if(stack[i+1]>stack[i])
            cout<< stack[i+1]<<" ";
        else{
            for(int j = i+1; j<num; j++){
                if(stack[j]>stack[i]){
                    cout<<stack[j]<<" "; break;
                }
                else if (j==num-1) cout << "-1 ";
                }
            }
        }
    }


int main(){
    int num= 0,top = -1, input =0;
    cin >> num;
    int s[num];
    for(int i = 0; i<num; i++){
        cin >> input;
        push(input,s,top);
    }
    getNge(num,s);
    return 0;
}
