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
    
    int nojobFlag;
    int blackmoneyFlag;
    int gametrollFlag;
    int blameFlag;
    int badgamerFlag;
} State;

void printStatus(const State* st);
int printOpeningMenu();
void printSpecialEnding(const State* st);
int ask_fixed_question(int idx, State* st, const Event* event);
void ask_random_question(int pool_size, State* st, const Event* event);

#endif