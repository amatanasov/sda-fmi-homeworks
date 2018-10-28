#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;


int main()
{
    char wordA[1001], wordB[1001], wordsIntersection[1001];
    int countA[26] = {0}, countB[26] = {0};

    cin>>wordA;
    cin>>wordB;

    int lenA = strlen(wordA);
    int lenB = strlen(wordB);

    for(size_t i=0; i<lenA; i++)
    {
        int idx = (wordA[i] - 'a') % 26;
        countA[idx]++;
    }
    for(size_t i=0;i<lenB;i++)
    {
        int idx = (wordB[i] - 'a') % 26;
        countB[idx]++;
    }

    int id = 0;
    for(int i=0; i<26; i++)
    {
        int minOccurrence = min(countA[i], countB[i]);
        for(size_t j=0; j<minOccurrence; j++)
        {
            wordsIntersection[id++] = char(i + 'a');
        }
    }
    for(size_t i=0; i<id; i++)
    {
        cout<<wordsIntersection[i];
    }
    cout<<endl;
}
