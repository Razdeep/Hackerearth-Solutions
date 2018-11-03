// https://www.hackerearth.com/practice/data-structures/stacks/basics-of-stacks/practice-problems/algorithm/sniper-shooting/description/

// More efficient version of the previous code

#include<bits/stdc++.h>
#define MAX 1003
using namespace std;
typedef long long ll;
int main()
{
    ll N,temp;
    vector<ll> line;
    cin>>N;
    vector<ll> freq(MAX,0);
    for(ll i=0;i<N;i++)
    {
        scanf("%lld",&temp);
        freq[temp]++;
    }
    // Killing men
    for(ll i=1;i<MAX;i++)
    {
        ll availBullets=freq[i];
        for(ll j=i-1;j>=1 && availBullets>0;j--)
        {
            ll hereBullets=min(availBullets,freq[j]);
            freq[j]-=hereBullets;
            availBullets-=hereBullets;
        }
    }
    ll sum=0;
    for(ll i=1;i<freq.size();i++)
        sum+=(i*freq[i]);
    cout<<sum<<endl;
    return 0;
}