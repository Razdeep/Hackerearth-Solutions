// https://www.hackerearth.com/practice/data-structures/stacks/basics-of-stacks/practice-problems/algorithm/sniper-shooting/description/
#include<bits/stdc++.h>
#define MAX 1003
using namespace std;
typedef long long ll;
int main()
{
    ll N,temp;
    vector<ll> line;
    cin>>N;
    for(ll i=0;i<N;i++)
    {
        cin>>temp;
        line.push_back(temp);
    }
    sort(line.begin(),line.end());
    vector<ll> freq(MAX,0);
    // counting the frequencies
    for(ll i=1;i<MAX;i++)
    {
        freq[i]=count(line.begin(),line.end(),i);
    }
    // Killing men
    for(ll i=(*min(line.begin(),line.end()));i<MAX;i++)
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