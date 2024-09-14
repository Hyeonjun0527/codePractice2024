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
    vector<int> A(N+1, 0);
    vector<int> ans(N+1, 0);
    for (int i = 1; i < N+1; i++) {
        cin >> A[i];
    }
    stack <int> myStack;
    myStack.push(1);
    for (int i = 2; i < N+1; i++) {
        //스택 비어있지 않고 현재 수열이 스택 TOP인덱스 가르키는 수열보다 크면
        while (!myStack.empty() && A[myStack.top()] < A[i]) {
            ans[myStack.top()] = A[i];  //정답 배열에 오큰수를 현재 수열로 저장하기
            myStack.pop();
        }
        myStack.push(i); //신규데이터 push
    }
    while (!myStack.empty()) {
        // 반복문을 다 돌고 나왔는데 스택이 비어있지 않다면 빌 때 까지
        ans[myStack.top()] = -1;
        myStack.pop();
    };
    for (int i = 1; i < N+1; i++) {   // 출력
        cout << ans[i] << " ";
    }
}


/*

N수열개수 A배열 ans정답배열

A에 데이터 저장
스택에 push(1)
for(i=2~끝까지)반복
    while(스택이 남아있고 A[top] < A[i])반복
        ans[top] = A[i]
        스택 pop
    }
    스택 push
}
while(스택 남아있으면) 반복
    ans[top] = -1;
    스택 pop
}
ans출력

 */