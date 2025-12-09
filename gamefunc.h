#ifndef GAMEFUNC_H
#define GAMEFUNC_H

typedef struct {
    const char* question;
    const char* choice1;
    const char* choice2;
    const char* choice3;
    int stateChange1[4];   // stress, skill, gf, money
    int stateChange2[4];
    int stateChange3[4];
    int next1;
    int next2;
    int next3;
} Event;

typedef struct {
    int stress;
    int skill;
    int gf;
    int badFlag;
    int proFlag;
    int blameFlag;
    int badgamerFlag;
} State;

// �Լ� ����
int runEvent(const Event* ev, State* st);
void printStatus(const State* st);
void printEnding(const State* st);

#endif