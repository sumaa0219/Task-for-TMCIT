#include "mytime.h"

int getSeconds(int h, int m, int s) { return h * 3600 + m * 60 + s; }

int getSecondsFromTime(int *tp) { return getSeconds(tp[HH], tp[MM], tp[SS]); }

void makeTimeFromSeconds(int *ansp, int seconds) {
    ansp[HH] = seconds / 3600;
    ansp[MM] = (seconds / 60) % 60;
    ansp[SS] = seconds % 60;
}

void makeTime(int *ansp, int h, int m, int s) {
    makeTimeFromSeconds(ansp, getSeconds(h, m, s));
}

int timeCmp(int *t1p, int *t2p) {
    int time1, time2;
    time1 = getSecondsFromTime(t1p);
    time2 = getSecondsFromTime(t2p);
    return time1 > time2 ? 1 : time1 < time2 ? -1 : 0;
}

void addTime(int *ansp, int *t1p, int *t2p) {
    makeTimeFromSeconds(ansp,
                        getSecondsFromTime(t1p) + getSecondsFromTime(t2p));
}

void mulTime(int *ansp, int *tp, int n) {
    makeTimeFromSeconds(ansp, getSecondsFromTime(tp) * n);
}

void divTime(int *ansp, int *tp, int n) {
    makeTimeFromSeconds(ansp, getSecondsFromTime(tp) / n);
}

int divTimeByTime(int *t1p, int *t2p) {
    return (getSecondsFromTime(t1p) / getSecondsFromTime(t2p));
}

void subTime(int *ansp, int *t1p, int *t2p) {
    makeTimeFromSeconds(
        ansp, (((getSecondsFromTime(t1p) - getSecondsFromTime(t2p)) / 2) +
               getSecondsFromTime(t1p)) *
                  timeCmp(t1p, t2p));
}