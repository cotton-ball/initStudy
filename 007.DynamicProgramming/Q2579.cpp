//
//  Q2579.cpp
//  init
//
//  Created by Kong Nayeon  on 2022/05/20.
//

#include <iostream>
using namespace std;

#define MAX 301

int num;
int stair[MAX];
int score[MAX];

int max(int a, int b){
    if(a>b) return a;
    return b;
}

int main(){
    
    cin >> num;
    for(int i = 1; i<=num; i++) cin >> stair[i];
    
    score[1] = stair[1];
    
    score[2] = stair[1]+stair[2];
    for(int i = 3; i <=num; i++){
        score[i] = max(score[i-3]+stair[i]+stair[i-1], score[i-2]+stair[i]);
    }
    cout << score[num] << endl;
    return 0;
}
