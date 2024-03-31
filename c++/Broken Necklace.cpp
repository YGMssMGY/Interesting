#include<bits/stdc++.h>
using namespace std;

const int NR = 400;
int n, ans;
char s[NR];
int main()
{
    cin>>n>>s;
    for(int i = 0; i <n; i++){
        int blue = 0;
        for(int j = 0; j< n; j++){
            if(s[(i-j+n)%n] == 'r'){
                break;
            }
            else blue++;
        }
        int red = 0; 
        for(int j = 0; j < n; j++){
            if(s[(i-j+n)%n] == 'b') break;
            else red++;
        }
        int leftCnt = max(blue, red);
        blue = 0;
        for(int j = 1; j <= n; j++){
            if(s[(i+j)%n] == 'r') break;
            else blue++;
        }
        red = 0;
        for(int j = 1; j <= n; j++){
            if(s[(i+j)%n] == 'b') break;
            else red++;
        }
        int rightCnt = max(blue, red);
        ans = max(ans, leftCnt + rightCnt);
    }
    cout<<min(ans, n)<<endl;
    return 0;
}
