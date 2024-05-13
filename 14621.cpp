#include<bits/stdc++.h>

using namespace std;

int N, M, P[10'010], ans_c = 0;;
bool gender[1010];
vector<tuple<int, int, int>> e;

int Find(int v) {return v == P[v] ? v : P[v] = Find(P[v]);}
bool Union(int u, int v){ return Find(u) != Find(v) && (P[P[u]]=P[v], true); }
long long Kruskal(){
    long long ret = 0;
    for(int i = 1; i <= N; i++) P[i] = i;
    sort(e.begin(), e.end());
    for(auto [w, u, v] : e) if(Union(u, v)) { ret += w;ans_c++; }
    return ret;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>M;
    //남초, 여초 구별
    for(int i = 1; i <= N; i++) {
        char c;cin>>c;
        if(c == 'W') gender[i] = false;
        else gender[i] = true;
    }
    //남초끼리 또는 여초끼리 연결된 간선은 볼 필요 없음
    for(int i = 1; i <= M; i++) {
        int a, b, w;cin>>a>>b>>w;
        if(gender[a] != gender[b]) {
            e.push_back(make_tuple(w, a, b));
        }
    }
    
    int ans = Kruskal();
    cout<<(ans_c < N - 1 ? -1 : ans);
    return 0;
}


/*
#include<bits/stdc++.h>

using namespace std;
using PII = pair<int, int>;

vector<PII> g[10101];
int N, M, C[1010], ans_c = 0;
bool gender[1010];

int Prim(){
    int ret = 0;
    priority_queue<PII, vector<PII>, greater<>> pq;
    C[1] = 1;
    for(auto [i, w]: g[1]) pq.emplace(w, i);
    while(!pq.empty()) {
        auto [c, v] = pq.top(); pq.pop();
        if(C[v]) continue;
        C[v] = 1;ret+=c;ans_c++;
        for(auto [i, w] : g[v]) pq.emplace(w, i);
    }
    
    return ret;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>M;
    //남초, 여초 구별
    for(int i = 1; i <= N; i++) {
        char c;cin>>c;
        if(c == 'W') gender[i] = false;
        else gender[i] = true;
    }
    //남초끼리 또는 여초끼리 연결된 간선은 볼 필요 없음
    for(int i = 1; i <= M; i++) {
        int a, b, w;cin>>a>>b>>w;
        if(gender[a] != gender[b]) {
            g[a].push_back({b, w});
            g[b].push_back({a, w});
        }
    }
    int ans = Prim();
    cout<<(ans_c < N - 1 ? -1 : ans);
    return 0;
}


*/
