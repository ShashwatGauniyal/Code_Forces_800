#include<iostream>
#include<vector>
#include<string>

using namespace std;
using ll = long long;
ll generateCombinations(string & S)
{
int n = S.length();
    long long total_sum = 0;

    for (int i = 0; i < (1 << (n - 1)); i++) {
        long long current_sum = 0;
        long long current_num = S[0] - '0';

        for (int j = 0; j < n - 1; j++) {
            if (i & (1 << j)) {  
                current_sum += current_num;  
                current_num = 0; 
            }
            current_num = current_num * 10 + (S[j + 1] - '0');  
        }
        current_sum += current_num;  
        total_sum += current_sum;
    }

    return total_sum;
}
int main()
{
    int t;
    cin>>t;
    while (t--)
    {
        string s;
        cin>>s;
        ll ans=generateCombinations(s);
        cout<<ans<<endl;
        
    }
    
}