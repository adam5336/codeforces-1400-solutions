#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>
#include <map>
#include <utility>
using namespace std;

int main(){
    long long k,n,b,f;
    cin>>k;
    while(k--){
        cin>>n;
        vector <long long> b;
        vector <long long> a(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        map<vector<long long>,vector<long long>> mp;
        map<pair<long long,vector<long long>>,long long>mp1;
        pair<long long,vector<long long>>x;
        for(long long i=1;i<n-1;i++){ 
            mp[{0,a[i],a[i+1]}].push_back(a[i-1]);
            x.first = a[i-1];
            x.second = {0,a[i],a[i+1]};
            mp1[x]+=1;
            mp[{a[i-1],0,a[i+1]}].push_back(a[i]);
            x.first = a[i];
            x.second = {a[i-1],0,a[i+1]};
            mp1[x]+=1;
            mp[{a[i-1],a[i],0}].push_back(a[i+1]);
            x.first = a[i+1];
            x.second = {a[i-1],a[i],0};
            mp1[x]+=1;
        }
        long long res=0,d;
        for(auto i=mp.begin(); i!=mp.end();i++){
            d = 0;
            if(i->second.size()>1){
                for(long long j=0;j<i->second.size();j++){
                    x.first = i->second[j];
                    x.second = i->first;
                    if(mp1[x]>1){
                        d+=(mp1[x]*(mp1[x]-1))/2;
                        mp1[x]=0;
                    }
                }
                res+=((i->second.size()*(i->second.size()-1))/2)-d;
            }
        }
        if(res<0)
        cout<<"0"<<"\n";
        else
        cout<<res<<"\n";

    }
}