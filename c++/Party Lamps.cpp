#include<bits/stdc++.h>
using namespace std;

const int h[9][7] = {
    {},
    {0,0,0,0,0,0}, 
    {0,0,0,1,1,1}, 
    {1,0,1,0,1,0}, 
    {1,0,1,1,0,1}, 
    {0,1,0,0,1,0}, 
    {0,1,0,1,0,1}, 
    {1,1,1,0,0,0}, 
    {1,1,1,1,1,1}  
};

int n, c, on[101], off[101];

inline void work(int w[9]) {
    bool flag = true;
    for(int k = 1; k <= w[0]; k++) {
        bool tag = false;
        for(int i = 1; i <= on[0]; i++)
            if(!h[w[k]][on[i] % 6]) {
                tag = true;
                break;
            }
        if(tag) continue;
        for(int i = 1; i <= off[0]; i++)
            if(h[w[k]][off[i] % 6]) {
                tag = true;
                break;
            }
        if(tag) continue;
        flag = false;
        for(int i = 1; i <= n; i++)
            printf("%d", h[w[k]][i % 6]);
        printf("\n");
    }
    if(flag) printf("IMPOSSIBLE");
    exit(0);
}

int main() {
    int tmp;
    scanf("%d%d", &n, &c);
    while(1) {
        scanf("%d", &tmp);
        if(tmp == -1) break;
        on[++on[0]] = tmp;
    }
    while(1) {
        scanf("%d", &tmp);
        if(tmp == -1) break;
        off[++off[0]] = tmp;
    }
    if(c == 0) {
        int w[9] = {1, 8};
        work(w);
    }
    if(c == 1) {
        int w[9] = {4, 1, 3, 4, 6};
        work(w);
    }
    if(c == 2) {
        int w[9] = {7, 1, 2, 3, 5, 6, 7, 8};
        work(w);
    }
    if(c > 2) {
        int w[9] = {8, 1, 2, 3, 4, 5, 6, 7, 8};
        work(w);
    }
    return 0;
}