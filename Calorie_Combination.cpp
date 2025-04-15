#include<iostream>
#include<vector>
using namespace std;
int solve(vector<int>& arr, int c)
{
    vector<bool>dp(c+1,false);
    dp[0]=true;

    for(int i : arr)
    {
        for(int j=c ;j>=i;j--)
        {
            if(dp[j-c]){
                dp[j]=true;
            }
        }
    }
    return dp[c];
}
int main()
{
    int t;
    cin>>t;
    while (t--)
    {
        int n,c;
        cin>>n>>c;
        vector<int>arr;
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        if(solve(arr,c)) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
    
}