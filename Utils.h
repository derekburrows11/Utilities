
#pragma once

// Clip value between min & max
void limit(float& val, const float vmin, const float vmax);


struct PeriodicTrigger {
    int period = 500, next, prev;
    int dt, dtMax, dtMin;
    long numChecks, numChecksMax, numChecksMin;

    PeriodicTrigger(int per) {
        period = per;
        reset();
    }
    void reset() {
        dtMax = 0;
        dtMin = __INT_MAX__;
        numChecks = 0;
        numChecksMax = 0;
        numChecksMin = __LONG_MAX__;
    }
    bool checkTrigger(int msNow) {
        numChecks++;
        if (msNow - next < 0)
            return 0;
        dt = msNow - prev;
        prev = msNow;
        next += period;
        if (msNow - next >= 0)
            next = msNow + period;       // was behind, and next scan also behind

        if (dt > dtMax)       dtMax = dt;
        else if (dt < dtMin)  dtMin = dt;

        if (numChecks > numChecksMax)       numChecksMax = numChecks;
        else if (numChecks < numChecksMin)  numChecksMin = numChecks;
        numChecks = 0;
        return 1;
    }
};


