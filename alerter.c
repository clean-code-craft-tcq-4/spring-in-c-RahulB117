#include "alerter.h"

int emailAlerter(float numMax, float maxThreshold)
{
    int emailCount = 0;
    if(numMax > maxThreshold) 
    {
        emailCount = 1;
    }
    return emailCount;
}

int ledAlerter(float numMax, float maxThreshold)
{
    int ledCount = 0;
    if(numMax > maxThreshold) 
    {
        ledCount = 1;
    }
    return ledCount;
}
