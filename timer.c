#include <time.h>
#include "timer.h"

static clock_t startClocks = 0;

// Starts the timer.
void startTimer()
{
    startClocks = clock();
}

// Returns the time in seconds since startTimer() was called.
double stopTimer()
{
    double measuredSeconds = (clock() - (double)startClocks) / CLOCKS_PER_SEC;

    if(startClocks > 0)
        startClocks = 0;
    else
        measuredSeconds = -1;
    
    return measuredSeconds;
}