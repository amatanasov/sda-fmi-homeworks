#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    
    char S[501];
    int counter[26] = {0};
    
    cin>>S;

    int len = strlen(S);

    for(size_t i=0;i<len;i++)
    {
        int id = (S[i] - 'a');
        counter[id]++;
    }
    
    int maxOccurrenceSoFar = 0;
    for(size_t i=0;i<26;i++)
    {
        maxOccurrenceSoFar = max(maxOccurrenceSoFar, counter[i]);
    }

    if(len % 2 == 0)
    {
        if(maxOccurrenceSoFar > len / 2) cout<<"No" << endl;
        else cout<<"Yes"<<endl;
    }
    else 
    {
        if(maxOccurrenceSoFar > len / 2  + 1) cout<<"No"<<endl;
        else cout<<"Yes"<<endl;
    }
}
