#include <stdio.h>

#include "mytime.h"
#include "testCommon.h"

void testGetSeconds() {
    int ans;
    testStart("getSeconds");
    ans = getSeconds(2, 34, 56);
    assertEqualsInt(ans, 9296);
    ans = getSeconds(11, 59, 59);
    assertEqualsInt(ans, 43199);
}

void testGetSecondsFromTime() {
    int jikoku1[N] = {2, 34, 56}, jikoku2[N] = {11, 59, 59};
    int ans;
    testStart("getSecondsFromTime");
    ans = getSecondsFromTime(jikoku1);
    assertEqualsInt(ans, 9296);
    ans = getSecondsFromTime(jikoku2);
    assertEqualsInt(ans, 43199);
}

void testMakeTimeFromSeconds() {
    int jikoku[N];
    testStart("makeTimeFromSeconds");
    makeTimeFromSeconds(jikoku, 2 * 3600 + 34 * 60 + 56);
    assertEqualsInt(jikoku[HH], 2);
    assertEqualsInt(jikoku[MM], 34);
    assertEqualsInt(jikoku[SS], 56);
    makeTimeFromSeconds(jikoku, 12 * 3600 - 1);
    assertEqualsInt(jikoku[HH], 11);
    assertEqualsInt(jikoku[MM], 59);
    assertEqualsInt(jikoku[SS], 59);
}

void testTimeCmp() {
    testStart("TimeCmp");
    int jikoku1[N] = {2, 34, 56}, jikoku2[N] = {11, 59, 59};
    assertEqualsInt(timeCmp(jikoku1, jikoku2), -1);
    assertEqualsInt(timeCmp(jikoku2, jikoku1), 1);
    assertEqualsInt(timeCmp(jikoku1, jikoku1), 0);
}

void testaddTime() {
    testStart("addTime");
    int jikoku1[N] = {2, 34, 56}, jikoku2[N] = {11, 59, 59},
        jikoku3[N] = {0, 0, 0};
    addTime(jikoku3, jikoku1, jikoku2);
    assertEqualsInt(jikoku3[HH], 14);
    assertEqualsInt(jikoku3[MM], 34);
    assertEqualsInt(jikoku3[SS], 55);
    addTime(jikoku1, jikoku2, jikoku3);
    assertEqualsInt(jikoku1[HH], 26);
    assertEqualsInt(jikoku1[MM], 34);
    assertEqualsInt(jikoku1[SS], 54);
}

void testmulTime() {
    testStart("mulTime");
    int jikan1[N] = {2, 34, 56}, jikan2[N] = {0, 0, 0};
    mulTime(jikan2, jikan1, 2);
    assertEqualsInt(jikan2[HH], 5);
    assertEqualsInt(jikan2[MM], 9);
    assertEqualsInt(jikan2[SS], 52);
    mulTime(jikan2, jikan1, 3);
    assertEqualsInt(jikan2[HH], 7);
    assertEqualsInt(jikan2[MM], 44);
    assertEqualsInt(jikan2[SS], 48);
}

void testdivTime() {
    testStart("divTime");
    int jikan1[N] = {2, 34, 56}, jikan2[N] = {0, 0, 0};
    divTime(jikan2, jikan1, 2);
    assertEqualsInt(jikan2[HH], 1);
    assertEqualsInt(jikan2[MM], 17);
    assertEqualsInt(jikan2[SS], 28);
    divTime(jikan2, jikan1, 3);
    assertEqualsInt(jikan2[HH], 0);
    assertEqualsInt(jikan2[MM], 51);
    assertEqualsInt(jikan2[SS], 38);
}

void testDivTimeByTime() {
    testStart("divTimeByTime");
    int jikan1[N] = {2, 34, 56}, jikan2[N] = {11, 59, 59};
    assertEqualsInt(divTimeByTime(jikan2, jikan1), 4);
    assertEqualsInt(divTimeByTime(jikan1, jikan2), 0);
}

void testSubTime() {
    testStart("subTime");
    int jikan1[N] = {2, 34, 56}, jikan2[N] = {11, 59, 59},
        jikan3[N] = {0, 0, 0};
    subTime(jikan3, jikan2, jikan1);
    assertEqualsInt(jikan3[HH], 16);
    assertEqualsInt(jikan3[MM], 42);
    assertEqualsInt(jikan3[SS], 30);
    subTime(jikan3, jikan1, jikan2);
    assertEqualsInt(jikan3[HH], 2);
    assertEqualsInt(jikan3[MM], 7);
    assertEqualsInt(jikan3[SS], 35);
    subTime(jikan3, jikan1, jikan1);
    assertEqualsInt(jikan3[HH], 0);
    assertEqualsInt(jikan3[MM], 0);
    assertEqualsInt(jikan3[SS], 0);
}

int main() {
    testGetSeconds();
    testGetSecondsFromTime();
    testMakeTimeFromSeconds();
    testTimeCmp();
    testaddTime();
    testmulTime();
    testdivTime();
    testDivTimeByTime();
    testSubTime();
    testErrorCheck();
    return 0;
}