#include<iostream>
#include<vector>


using namespace std;
int N, M, answer[500'505];
vector<int> A[500'505];
//각 과목은 선수 과목이 있을 수도 있고 없을 수도 있음. 이때 선수되야 하는 과목을 대상으로 하면?
//각 과목의 선수 과목들의 선수 과목 수의 최대를 고르면 된다.


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>M;
    
    for(int i=0;i < M; i++) {
        int a, b;cin>>a>>b;
        A[b].push_back(a);
    }
    
    for(int i = 1; i < N + 1; i++) {
        answer[i] = 1;
        for(int j = 0; j < A[i].size(); j++) {
            if(answer[i] < answer[A[i][j]] + 1) answer[i] = answer[A[i][j]] + 1;
        }
    }
    
    for(int i = 1; i < N + 1; i++) cout<<answer[i]<< ' ';
    
    return 0;
    
}
