#include <bits/stdc++.h>
using namespace std;
#define MAX 30005
int make, coin[] = {1, 5, 10, 25, 50};
long long dp[6][MAX];
long long call(int i, int amnt){
    if(i >= 5){
        if(amnt == 0) return 1;
        else return 0;
    }
    if(dp[i][amnt] != -1) return dp[i][amnt];
    long long ret1 = 0, ret2 = 0;
    if(amnt - coin[i] >= 0)
        ret1 = call(i, amnt - coin[i]);
    ret2 = call(i + 1, amnt);
    return dp[i][amnt] = ret1 + ret2;
}
int main(){
    long long ans;
    memset(dp, - 1, sizeof(dp));
    while(scanf("%d", &make) == 1){
        ans = call(0, make);
        if(ans > 1)
            printf("There are %lld ways to produce %d cents change.\n", ans, make);
        else
            printf("There is only 1 way to produce %d cents change.\n", make);
    }
    return 0;
}
