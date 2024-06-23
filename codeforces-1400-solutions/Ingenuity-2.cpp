#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>
using namespace std;

int main(){
    int k,n,g,f,b,x1,y1;
    string s,ch;
    cin>>k;
    while(k--){
        int x=0,y=0;
        cin>>n;
        cin>>s;
        for(int i=0;i<n;i++){
            if(s[i]=='N'){x+=1;}
            else if(s[i]=='S'){x-=1;}
            else if(s[i]=='W'){y+=1;}
            else{y-=1;}
        }
        if(abs(x)%2==0 && abs(y)%2==0){
            x=0,y=0,x1=0,y1=0,g=0,f=0;
            for(int i=0;i<n;i++){
                if(s[i]=='N'){
                    if(x%2==0){s[i]='R';g+=1;}
                    else{s[i]='H';f+=1;}
                    x+=1;
                    }
                else if(s[i]=='S'){                    
                    if(x1%2==0){s[i]='R';g+=1;}
                    else{s[i]='H';f+=1;}
                    x1+=1;
                    }
                else if(s[i]=='W'){                    
                    if(y%2==0){s[i]='H';f+=1;}
                    else{s[i]='R';g+=1;}
                    y+=1;}
                else{                    
                    if(y1%2==0){s[i]='H';f+=1;}
                    else{s[i]='R';g+=1;}
                    y1+=1;}
            }
            if(g==n || f==n){
                cout<<"NO\n";
            }else{
            cout<<s<<"\n";
            }
        }
        else{
            cout<<"NO\n";
        }
    }
}