#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int m, n;
    cin >> m >> n;
    vector<int> A(n+1);//자동 0으로 초기화

    for (int i = 2; i <= n; ++i) {
        A[i] = i;
    }
    for (int i = 2; i <= sqrt(n); ++i) {
        if (A[i] == 0) {
            continue;
        }
        //2면 2 4 6 8 10 12 14 16 18 20
        // j는 2 4 6 8이고 i는 2 공차 2이고 i*2부터 시작이네.
        // j는 배수들이야. A는 값과 인덱스가 같아.
        for (int j = i*2 ; j <= n; j = j + i) {
            A[j] = 0;
        }
    }
    while( m <= n) {
        if ( A[m] != 0) {
            cout << A[m] << "\n";
        }
        m++;
    }



}

/*
M부터 N 소수 구해라. 소수구하기 > 에라토스테네스의 체 NloglogN
1. 먼저 2~N까지 배열을 만들어
2. 2부터 시작해서 2의 배수들을 모두 지워. 구간은 sqrt(n)보다 작은거 까지.
105면 10.xxx전까지만 돌려보면대.
3. 배수지워. 어케하냐면, 0으로 만들어. 0이면 넘겨.
4. 배수지울때 중요한거 2, 3, 5, 7,이건 다 소수야. 2*(2~n) 3*(2~n) 이렇게 지워야해.
2 30
*/
