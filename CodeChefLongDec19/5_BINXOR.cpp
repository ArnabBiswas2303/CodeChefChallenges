// Problem link: https://www.codechef.com/DEC19B/problems/BINXOR

#include <bits/stdc++.h> 
using namespace std; 
  
long long fact[100001];
int MOD=1000000007;

int fast_pow(long long base, long long n,long long M)
{
    if(n==0)
       return 1;
    if(n==1)
    return base;
    long long halfn=fast_pow(base,n/2,M);
    if(n%2==0)
        return ( halfn * halfn ) % M;
    else
        return ( ( ( halfn * halfn ) % M ) * base ) % M;
}

int findMMI_fermat(int n,int M)
{
    return fast_pow(n,M-2,M);
}

long long nCr(int n, int r){
    long long numerator,denominator,mmi_denominator;
    numerator=fact[n];
    denominator=(fact[r]*fact[n-r])%MOD;
    mmi_denominator=findMMI_fermat(denominator,MOD);
    return (numerator*mmi_denominator)%MOD;
}

string makeString(int n, int one){
    string s(n,'0');
    for(int i=0; i<one; i++){        
        s[i]='1';
    }
    return s;
}

int xorOne(string a, string b, int& count, int n){
    int one = 0;
    string xr(n,'0');
    for(int i=0; i<n; i++){
        if(a[i] == '1' && b[i] == '1'){
            xr[i] = '0';
            count--;
        }else if(a[i] == '0' && b[i] == '0'){
            xr[i] = '0';
        }else{
            xr[i] = '1';
        }
    }
    for(int i=0; i<n; i++){
        if(xr[i] == '1')
            one++;
    }
    return one;
}

int main()
{
    
    fact[0]=1;
    int j=1;
    while(j<=100000)
    {
        fact[j]=(fact[j-1]*j)%MOD;
        j++;
    }
    int t;
    cin>>t;
    while(t--){
        int n;
        string a,b;
        cin>>n;
        cin>>a>>b;
        int aOne=0,bOne=0;
        for(int i=0; i<n; i++){
            if(a[i] == '1')
                aOne++;
        }
        for(int i=0; i<n; i++){
            if(b[i] == '1')
                bOne++;
        }
        int count = min(aOne,bOne);
        count++;
        a = makeString(n,aOne);
        b = makeString(n,bOne);
        reverse(b.begin(),b.end());
        int ones = xorOne(a,b,count,n);
        long long ans = 0;
        while(count-- && ones > -1){
            ans = (ans + nCr(n,ones)) % MOD;
            ones -= 2;
        }
        cout<<ans<<endl;
    }
    return 0;
}