#include "stats.h"
#include "alerter.h"
#include <math.h>

int emailAlertCallCount = 0;
int ledAlertCallCount = 0;

void swapMe(float* first, float* second)
{
    float tempNum = *first;
    *first = *second;
    *second = tempNum;
}

void sortMe(float* inputSet, int setlength)
{
    int small_index;
    for(int i=0; i<setlength-1; i++)
    {
        small_index = i;
        for(int j=i+1; j < setlength; j++)
        {
            if(inputSet[j] < inputSet[small_index])
            {
                small_index = j;
            }
        }
        swapMe(&inputSet[small_index], &inputSet[i]);
    }

}

void check_and_alert(float maxThreshold, alerter_funcptr alerters[], Stats computedStats)
{

    float numMax = computedStats.max;
    emailAlertCallCount = emailAlerter(numMax, maxThreshold);
    ledAlertCallCount = ledAlerter(numMax, maxThreshold);
}

Stats compute_statistics(const float* numberset, int setlength) {
    Stats s;
    s.average = 0;
    s.min = 0;
    s.max = 0;
    
    float total = 0;
    float* sortedSet = (float* ) numberset;
    sortMe(sortedSet, setlength);

    for(int i =0; i<setlength; i++)
    {
        total = total + sortedSet[i];
    }
    s.average = (total/setlength);
    if(!(isnan(s.average)))
    {
        s.min = sortedSet[0];
        s.max = sortedSet[setlength-1];
    }
    return s;
}

