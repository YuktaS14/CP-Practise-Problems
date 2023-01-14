#include<bits/stdc++.h>
using namespace std;
#define ll long long

const int N = 1e5+2, MOD = 1e9+7;

vector<ll>powers(N);

ll hashing(string s){
    ll hashValue = 0;
    for(int i = 0; i<s.length();i++)
    {
        hashValue += powers[i]*(s[i]-'a'+1);
    }
    return hashValue;
}
int main(){
    powers[0] = 1;
    for(int i =0 ; i<N; i++){
        powers[i] = (powers[i-1]*31)%MOD;
    }
    int n; cin>>n;
    vector<string>strings(n);
    for(int i = 0; i<strings.size(); i++)
        cin>>strings[i];
    
    vector<ll>hashedString;
    for(auto word: strings){
        hashedString.push_back(hashing(word));
    }
    sort(hashedString.begin(), hashedString.end());
    int distStrings = 0;

    for(int i = 0; i<hashedString.size();i++){
        if(i == 0 or hashedString[i] != hashedString[i-1])
            distStrings++;
    }

    cout<<distStrings;
    return 0;
}