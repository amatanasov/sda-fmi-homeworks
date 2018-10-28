#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() 
{
    int maxTimeSoFar = -1;
    int minTimeSoFar = 9999;
    int fullDay = 24 * 60;
    int numberOfCars = 3;
    
    
    int startMinutes, endMinutes, startHours, endHours;
    
    for (size_t i = 0; i < numberOfCars; i++)
    {
        cin >> startHours >> startMinutes >> endHours >> endMinutes;

        int totalStartMinutes = startHours * 60 + startMinutes;
        int totalEndMinutes = endHours * 60 + endMinutes;
        
        if (totalStartMinutes > totalEndMinutes)
            totalEndMinutes += fullDay;

        int totalTime = totalEndMinutes - totalStartMinutes;
        minTimeSoFar = min(minTimeSoFar, totalTime);
        maxTimeSoFar = max(maxTimeSoFar, totalTime);
    }

    
    cout << minTimeSoFar / 60 << ":"; // hours

    minTimeSoFar = minTimeSoFar % 60;
    if (minTimeSoFar < 10) cout << 0;
    
    cout << minTimeSoFar << endl; // minutes

    cout << maxTimeSoFar / 60 << ":"; // hours

    maxTimeSoFar = maxTimeSoFar % 60;
    if (maxTimeSoFar < 10) cout << 0;
    
    cout << maxTimeSoFar << endl; // minutes

    return 0;
}
