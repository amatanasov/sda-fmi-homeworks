#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

bool comparingInvariant(string a, string b) {
    
    string ab=a+b;
    string ba=b+a;
    
    if(ab.compare(ba)>=0)
        return true;
    else
        return false;
}

int main() {
    int n;
    cin>>n;
    bool allZero = true;
    
    string* numbers = new string[n];
    
    for(size_t i =0; i<n; ++i) {
        cin>>numbers[i];
        if(numbers[i].compare("0")!=0)
            allZero=false;
    }
    
    if(allZero)
        cout<<"0"<<endl;
    else
    {
        for (size_t i = 0; i < n-1; i++) 
        {       
            for (size_t j = 0; j < n-i-1; j++)
            {
                if (comparingInvariant(numbers[j],numbers[j+1])) 
                {
                    string temp = numbers[j]; 
                    numbers[j] = numbers[j+1]; 
                    numbers[j+1] = temp;
                }
            }
        }
        for(int i=n-1; i>=0; i--)
            cout << numbers[i];
        cout<<endl;
    }
    
    return 0;
}
