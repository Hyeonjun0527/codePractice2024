#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long min, max;
    cin >> min >> max;

    // vector<bool> table(max - min + 1, true);
    vector<bool> table(max - min + 1);
    fill(table.begin(), table.end(), true);

    //2제곱부터 포우까지 4 9 16 25 36 49 64 81 100
    long long number = 2;
    long long power = number * number;
    while (power <= max) {

        long long start = min / power * power;
        //시작을 조정함
        if (min % power != 0) {
            start += power;
        }


        for (long long value_now = start ;  value_now <= max ; value_now += power) {
            table[value_now - min] = false;//value_now - min은 조정.
        }

        number++;
        power = number * number;
    }
    int count = 0;
    for ( bool i : table) {
        if ( i ) {
            count++;
        }
    }
    cout << count << '\n';
}


/*
에라토스테네스의 체
문제를 보고 힌트가 뭘 지 추측해야돼
1. 제곱수의 배수를 찾으려고 하는거야!!! 제외하려는거야!!! 여기까지가 핵심 그 다음엔?
2. min에 가장 가까운 제곱수의 배수를 계산해. 거기서 start하자.
그건 머냐면 start = min / power * power
나누어떨어지지 않으면 start += power
3. 제곱수 배수는 일정한 간격으로 존재해.
4. iteration은 max까지 하면 되겠네 index로는 root(MAX)
5. 제곱수의 배수만 찾으면 되니까
그리고 그 배수부터 max까지 제곱수의 배수를 찾아서 false로 바꾼다.
*/
