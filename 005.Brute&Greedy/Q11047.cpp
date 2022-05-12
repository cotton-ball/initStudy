//
//  Q11047.cpp
//  init
//
//  Created by Kong Nayeon  on 2022/05/12.
//
#include <iostream>
using namespace std;

int main(){
    
    int num, cash , cnt = 0 ;
    int arr[10];

    cin >> num >> cash;
    
    for(int i = 0; i< num; i++){
        cin >> arr[i];
    }
    
    num--;
    while(num>=0){
        if(cash <= 0) break;
        if(cash >= arr[num]){
            cash -= arr[num];
            cnt++;
            continue;
        }
        num--;
    }
    
    cout << cnt<<endl;

    return 0;
}
