//
//  14888(3).cpp
//  init
//
//  Created by Kong Nayeon  on 2022/05/18.
//


#include <iostream>
using namespace std;

int n;
int a[12];
int opr[4];
int maxvalue, minvalue;
int visited[11];

void calc() {
    int tmp = a[0];
    for (int i = 1; i < n; i++) {
        switch (visited[i]) {
        case 0: tmp += a[i]; break;
        case 1: tmp -= a[i]; break;
        case 2: tmp *= a[i]; break;
        case 3: tmp /= a[i]; break;
        }
    }
    if (tmp > maxvalue) maxvalue = tmp;
    if (tmp < minvalue)minvalue = tmp;
}
void DFS(int node) {
    if (node == n) {
        calc();
        return;
    }
    for (int i = 0; i < 4; i++) {
        if (opr[i] == 0)continue;
        visited[node] = i;
        opr[i]--;
        DFS(node + 1);
        opr[i]++;
        visited[node] = 0;
    }
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++)
        cin>>a[i];
    for (int i = 0; i < 4; i++)
        cin>>opr[i];

    maxvalue = -0x7fffffff;
    minvalue = 0x7fffffff;

    DFS(1);

    cout << maxvalue<<endl;
    cout << minvalue<<endl;
    return 0;
}
