#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>
using namespace std;
int is_check(vector<long long> a){
    for(int i=0;i<a.size()-2;i++){
        if(__gcd(a[i],a[i+1])>__gcd(a[i+1],a[i+2])){
            return i+1;
        }
    }
    return -1;
}

int main(){
    int k,n,i,pos;
    cin>>k;
    while(k--){
        cin>>n;
        vector<long long> a(n);
        vector<long long> b;
        int d=0;
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        if(n==3 || is_check(a)==-1){
            cout<<"yes\n";
        }
        else{
            bool test=false;
            for(int i=is_check(a)-1;i<=is_check(a)+1;i++){
                b = a;
                b.erase(b.begin()+i);
                if(is_check(b)==-1){
                    test=true;
                }
            }
            if(test==true){
                cout<<"yes\n";
            }
            else{
                cout<<"no\n";
            }
        }

    }
    return 0;
} 