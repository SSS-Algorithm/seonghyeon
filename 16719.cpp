#include<iostream>
#include<string>
#include<algorithm>

using namespace std;
string s;
bool check[100] = {false};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin>>s;

     //문자열 길이만큼 반복
    for(int i = 0; i < s.size(); i++) {
       
        string t_ans =s;
        int idx = 0;
      
        //이미 선택된 문자열 제외 문자 선택
        for(int j = 0; j < s.size(); j++) {
            if(check[j]) continue;
            string t = "";
            
            for(int k = 0; k < s.size(); k++) {
                //선택된 문자열 조합
                if(t.size() < i + 1 && (k == j || check[k])) t += s[k];
            }

            //만들어진 문자열의 순서 판단
            if(t_ans > t) {
                t_ans = t;
                idx = j;
            }
        }
        
        //만들어진 문자열 출력     
        cout<<t_ans<<'\n';
        check[idx] = true;

    }
    
    return 0;
}
