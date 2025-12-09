#include <stdio.h>
#include "gamefunc.h"
#include "militaryEvent.h"

int main() {
    State st = { 0, 0, 0, 0, 0, 0, 0, 0 };  // stress, skill, gf, badFlag, proFlag, gametrollFlag, blameFlag, badgamerFlag
    int current = 100;  // ���� ���丮 ����

    while (current >= 0) {
        current = runEvent(&eventList[current], &st);
    }

    printEnding(&st);

    return 0;
}