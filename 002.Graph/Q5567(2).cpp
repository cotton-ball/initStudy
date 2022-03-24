//
//  Q5567(2).cpp
//  init
//
//  Created by Kong Nayeon  on 2022/03/24.
//

#include<iostream>
using namespace std;

#define FREINDS_MAX 501

int friendList[FREINDS_MAX][FREINDS_MAX], visited[FREINDS_MAX];
int friendNum,listNum,a,b, weddingFriends;
int main()
{
    cin >> friendNum;
    cin >> listNum;
    for (int i = 0; i < listNum; i++){
        cin >> a;
        cin >> b;
        friendList[a][b] = 1;
        friendList[b][a] = 1;
    }
    for (int i = 2; i <= friendNum; i++){
        if (friendList[1][i]){ //만약 1과 연결되어 있다면 (상근이와 친구)
            visited[i] = 1;
            for (int j = 2; j <= friendNum; j++){
                if (friendList[i][j] == 1) 
                    visited[j] = 1;
            }
        }
    }
    for (int i = 2; i <= friendNum; i++){
        if (visited[i] == 1) //체크 해둔 배열 만큼 weddingFriends ++
            weddingFriends++;
    }
    cout << weddingFriends << endl;
}
