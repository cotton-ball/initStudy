//
//  5567(3).cpp
//  init
//
//  Created by Kong Nayeon  on 2022/03/24.
//

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

#define LIST_MAX 10000 //리스트의 최대값
#define FREINDS_MAX 501 //친구 수의 최대깂
bool friends[FREINDS_MAX]; //전역변수는 자동으로 초기화
int list[LIST_MAX][2];



int main(){
    int friendNum, listNum, a, b, temp;
    int weddingFriends = 0;
    cin >> friendNum;
    cin >> listNum;
    
    for(int i = 0; i < listNum; i++){
        cin >> a >> b;
        list[i][0] = a;
        list[i][1] = b;
    }
    
    //1의 인접행렬 체크
    for (int i = 0; i < listNum; i++){
        if(list[i][0]==1){
            temp = list[i][1]; //임시 변수에 1의 친구를 넣어준다
            friends[temp] = true; //친구 리스트에서 체크
            for(int j = 0; j < listNum; j++){
                if(list[j][0] == temp) //1의 친구의 친구 탐색
                    friends[list[j][1]] = true; // 친구 리스트에서 체크
                else if (list[j][1] == temp)
                    friends[list[j][0]] = true; //반대도 마찬가지
            }
        }
        
    }
    
    for (int i = 1; i <= friendNum; i++ )
        if (friends[i]== true)
            weddingFriends++;
    
    cout << weddingFriends-1<<endl;
}

