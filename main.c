#include <stdio.h>
#include "gamefunc.h"
#include "militaryEvent.h"
#include "1StGradeStory.h"

int main() {
    State st = { 0, 0, 0, 0, 0 };  // stress, skill, gf, badFlag, proFlag
    int current = 100;  

    while (current >= 0) {
        current = runEvent(&eventList[current], &st);
    }

    printEnding(&st);

    return 0;
}