//
//  Q14888.cpp
//  init
//
//  Created by Kong Nayeon  on 2022/05/15.
//

#include <iostream>
#include <stdio.h>
using namespace std;

static int n, a[11], opr[10];
static int maxvalue = INT_MIN, minvalue = INT_MAX;
static bool visited[10];

void dfs(int v, int idx, int num, int len);

int main(){
    int index = 0;
    
    cin >>n;
    
    for(int i=0; i<n; i++)
        cin>>a[i];
    
    for(int i = 0; i<4; i++){
        int cnt ;
        cin >> cnt;
        for(int j = 0; j < cnt; j++)
            opr[index++] = i + 1;
    }
    dfs(0, 1, a[0], 0);
    cout <<maxvalue<<"\n"<<minvalue;
    
    return 0;

}


void dfs(int v, int idx, int num, int len){
    int result = 0;
    if(len == n-1){
        if (num > maxvalue) maxvalue=num;
        if (num < minvalue) minvalue = num;
    }
    else{
        for(int i = 0; i< n-1; i++){
            if(!visited[i]){
                switch (opr[i]) {
                    case 1:
                        result = num + a[idx];
                        break;
                    case 2:
                        result = num - a[idx];
                        break;
                    case 3:
                        result = num * a[idx];
                        break;
                    case 4:
                        result = num / a[idx];
                        break;
                }
                visited[i] = true;
                dfs(i, idx+1, result, len+1);
            }
        }
    }
    visited[v] = false;
}


