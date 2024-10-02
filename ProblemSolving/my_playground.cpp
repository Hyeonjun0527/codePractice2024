#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int v;
    cin >> v;

    vector<tuple<vector<int>, int, int>> graph(v + 1);// (0 리스트) (1 진입차수) (2 작업시간)

    //리스트에 작업시간, 간선, 진입차수 추가
    for (int i = 1; i < v + 1; ++i) {
        int t;
        cin >> t;
        get<2>(graph[i]) = t;

        while (true) {
            int x;
            cin >> x;
            if (x == -1) break;

            get<0>(graph[x]).push_back(i);
            get<1>(graph[x]) += 1;
        }
    }

    vector<int> result(v + 1, 0);
    queue<int> q;

    //result(강의를 듣기 위한 최소 시간) 초기화 +  진입차수 0이면 전부 큐에 삽입
    for (int i = 1; i < v + 1; ++i) {
        result[i] = get<2>(graph[i]);
        if (get<1>(graph[i]) == 0) {
            q.push(i);
        }
    }

    while(!q.empty()) {
        int now = q.front();
        q.pop();

        for (auto v: get<0>(graph[now])) {// 인접리스트에 연결된 노드 탐색
            result[v] = max(result[v], result[now] + get<2>(graph[v]));
            if (get<1>(graph[v]) == 0) {
                q.push(v);
            }
        }
    }

    for (int i = 1; i < v + 1; ++i) {
        cout << result[i] << endl;
    }




    
}
