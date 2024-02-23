#include<bits/stdc++.h>
using namespace std;

void TowerHN (int cot1, int cot2, int cot3, int n)
{
    if(n = 1)
        cout << "Chuyen tư cot 1 " << cot1 << "sang" << cot2 << endl;
    else {
        TowerHN(cot1, cot2, cot3, n)
    }
}