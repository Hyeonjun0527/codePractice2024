#include <bits/stdc++.h>
using namespace std;
/*
1~N에서 N과 서로소인 자연수 K의 개수
서로소 = 공통 소인수가 없는 것(1제외) = 최대공약수가 1인것 => `GCD(N,K) = 1` 인 거 찾으면 댐.
서로소가 없는 것 =  공통 소인수가 있는 것 = 최대공약수 1이 아닌것.= `GCD(N,K) = 1이 아닌것`
N의 소인수와 소인수의 배수들을 모두 제거
총 개수에서 소인수와 소인수의 배수의 개수를 차감.

result -= result/k k는 소인수
result 는 서로소인 수의 총 개수
*/
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long N;
    cin >> N;
    long result = N;
    // for문이 언제나 1개를 제외한 모든 소인수를 제거한다는
    for (long k = 2; k <= sqrt(N); ++k) {
        if (N % k == 0) {//소인수라면...
            result -= result / k;
            while (N % k == 0) {//중복되는 것도 나눠야 함.
                //36 = 2 x 2 x 3 x 3이야.
                //36 2 라고하면 18 = 2 x 3 x 3이 돼.
                //18 2 라고하면 그리고 9 = 3 x 3이 되겠지
                //그리고 k=3이 되고, 9 % 3을 하겠지. 마지막에 N은 1이 되겠지.
                //35 = 7 x 5야. 그리고 7은 안나누어져서 N=7로 남겠지.
                N /= k;
            }
        }
    }
    //여기서 N은 언제나 남아있는게 7과 같은 소수이거나 1이다.
    //왜냐? 먼저 어떤 합성수 N은 최소 하나의 소인수를 sqrt(N)이하에서 갖는다.
    //둘다 sqrt(N)보다 큰 건 말이 안되기 때문이야.
    //합성수 N이 있다고 하자.
    // N = a x b라고 하자. a와 b 각각은 sqrt(N)이하의 소인수, sqrt(N) 이상의 소인수
    // N = sqrt(N) x sqrt(N)
    // N = a x b x c x ...라고 하자. a,b,c, ...각각은 sqrt(N)이하의 소인수
    //N이 sqrt(N)
    //남은 N이 합성수라면 앞서 설명한대로 최소 하나의 sqrt(N) 이하의 소인수를 가져야한다.
    //하지만 이는 이미 제거되었다.
    if (N > 1) {
        result-=result/N;
    }
    cout << result << "\n";
}
