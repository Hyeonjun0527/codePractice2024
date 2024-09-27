#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    //A~B
    //A~루트B까지의 소수를 구해.
    //소수의 제곱을 구해서 그것이 B보다 작은지 확인하면 답나와.
    //2,4,8,16,32,64....다 거의 소수야.
    long Min, Max;
    cin >> Min >> Max;
    // vector<long> arr(B_2 - A + 2);//1,2,3,4,5....remain
    vector<long> arr(10'000'001);//1,2,3,4,5....remain
    // vector<int> PrimePow()
    //초기화
    for (int i = 2; i <= 10'000'001; ++i) {
        arr[i] = i;
    }

    //2,3,4,5,...로 All을 싹 돌려볼거야. 배수를 거를거야. 그렇게 소수를 구할거야.
    // i=2라면 그 All배열을
    for(int i = 2; i <= sqrt(10'000'001); i++) {
        if (arr[i] == 0) {
            continue;
        }
        for (int j = i*2; j <= 10'000'001; j = j + i) {//2 2x3 2x4 2x5다 걸러.
            arr[j] = 0;
        }
    }
    // cout << "A : " << A << " B : " << B << "\n";
    // for (int i = 0; i < arr.size(); ++i) {
    //     cout << arr[i] << ", ";
    // }
    //2,4,8,16,32,64....다 거의 소수야 이거의 개수 출력하는거야.
    //0이면 배수야.
    //각각의 소수에 관해, 소수를 N제곱한 값이 B보다 커질때까지 반복한다.
    //All의 요소를 반복하는데 소수면(0이아니면) 그 소수의 제곱부터 시작해서 N제곱한 값이 B보다 작을때까지 반복한다.
    //그때마다 카운트를 증가시킨다.
    // 소수의 거듭제곱이 주어진 범위 내에 있는지 확인
    // 소수야. 소수야 근데 소수의 제곱이 Max보다
    // 2야 2야 근데 2의 제곱(4)이 Max보다 작아?
    // 그럼 2의 세제곱이 Max보다 작아? 그럼 2의 세제곱이 Max보다 작아?
    int count = 0;
    for (long i = 2; i < 10'000'001; i++) {
        if (arr[i] != 0) {  // 소수인 경우
            long temp = arr[i];  // 소수 값을 temp에 저장
            while ((double)temp <= (double)Max / (double)arr[i]) {
                if ((double)temp >= (double)Min / (double)arr[i]) {
                    count++;
                }
                // if (temp > Max / arr[i]) break;  // 오버플로우 없이 거듭제곱을 계산
                temp = temp * arr[i];  // 소수의 거듭제곱 계산
            }
        }
    }

    cout << count << "\n";

}
