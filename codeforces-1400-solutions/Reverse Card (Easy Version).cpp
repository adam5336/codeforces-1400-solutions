#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>
using namespace std;

int main(){
    long long k,n,m,count,y;
    cin>>k;
    while(k--){
        cin>>n>>m;
        count=n;
        for(long long i=2;i<=m;i++){
            y=n/i;
            if(y>=i-1){
                y-=i-1;
                count+=(y/i)+1;
            }
        }
        cout<<count<<"\n";
    }
    return 0;
}