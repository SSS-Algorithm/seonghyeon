#include<bits/stdc++.h>
using namespace std;
int N, M, R[60], L;
bool check(int m) {
    int cnt = 0;
    for(int i = 0; i <= N; i++) {
        int dist = R[i + 1] - R[i];
        cnt += dist/m;
        if(dist%m == 0) cnt--;
    }
    return cnt > M;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>M>>L;
    R[0] = 0;
    R[N + 1] = L;
    
    for(int i = 1; i <= N; i++) cin>>R[i];
    
    sort(R, R + N + 1);
    int s = 1, e = L;
    while(s < e) {
        int m  = (s + e)/2;
        if(check(m)) s = m + 1;
        else e = m;
    }
    
    cout<<e;
    return 0;
}