#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;
    vector<int> A(N, 0);
    vector<char> resultV;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    stack <int> myStack;
    int num = 1; // 오름차순 수
    bool result = true;


    for (int su : A) {
        // 현재 수열의 수
        if (su >= num) { //현재 수열 값 >= 오름차순 자연수 : 값이 같아 질 때까지 push()수행
            while (su >= num) { // push()
                myStack.push(num++);
                resultV.push_back('+');
            }
            myStack.pop();
            resultV.push_back('-');
        }
        else {  //현재 수열 값 < 오름차순 자연수: pop()을 수행하여 수열 원소를 꺼냅니다
            int n = myStack.top();

            // 스택의 가장 위의 수가 만들어야 하는 수열의 수 보다 크다면 수열 출력 불가능
            if (n > su) {
                cout << "NO";
                result = false;
                break;
            }else {
                myStack.pop();
                resultV.push_back('-');
            }
        }
    }
    if (result) {
        for (char i : resultV)
        {
            cout << i << '\n';
        }
    }
}


/*
자연수 1부터 증가시키면서 입력으로 주어진 숫자와 비교하여 증가시킨 자연수를 스택에 추가하거나 빼면 된다.
입력배열의 현재값 >= 루프자연수
num을 스택에 push해 push가 끝나면 수열을 출력하기 위해 마지막 1회만 pop해
현재값이 4면 스택에는  1 2 3 4푸시
num이 입력배열의 현재값보다 커버린다면. 무조건 pop을 해야대.
그런데 만약 top이 입력배열의 현재값보다 커버린다면 NO를 출력하고 끝이야.
그게 아니라면 하나씩 빼고 -출력

입력배열에 8이 있으면 8을 넣어줘야해. 그리고 8을 꺼내야해.


N 수열개수 A 입력배열 result 결과배열
A 배열 초기화
S 스택 선언
for (N만큼반복) {
    if(A의현재값 >= num(1,2,3,...) { // 처음에만 숭숭숭숭 넣어야대서?
        while(A의 현재값 == num까지){
            스택 push
            num++
            result에 + 저장
        }
        스택 pop();
        result에 - 저장
    }else{ // 예를들어 3이나왓는디, num은 5야 그러면 pop을 수행해.
        if(스택의 top > 현재값){
            NO출력
        }else{
            스택 pop
            result에 - 저장
        }
    }
}
result출력
 */