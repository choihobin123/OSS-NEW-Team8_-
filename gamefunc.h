#ifndef GAMEFUNC_H
#define GAMEFUNC_H

typedef struct {
    const char* question;
    const char* choice1;
    const char* choice2;
    const char* choice3;

    const char* result1; // 1번 선택 결과 멘트
    const char* result2; // 2번 선택 결과 멘트
    const char* result3; // 3번 선택 결과 멘트
    
    int stateChange1[3];   // stress, skill, 여친
    int stateChange2[3];
    int stateChange3[3];
    int next1;
    int next2;
    int next3;

    //엔딩플레그 ++ 하는 변수


    //==엔딩플레그 ++ 하는 변수==

    int badFlagTrigger;
    int proFlagTrigger;

    int addictionFlagTrigger;
    int healthFlagTrigger;

    int nojobFlagTrigger;
    int blackmoneyFlagTrigger;
    int gametrollFlagTrigger;
    int blameFlagTrigger;
    int blame2FlagTrigger;
    int badgamerFlagTrigger;

    int byegirlfriendFlagTrigger;
    int overworkFlagTrigger;
    int noPortfolioFlagTrigger;
    int slaveFlagTrigger;

    int quitFlagTrigger;
    int graduateFlagTrigger;

} Event;

typedef struct {
    int stress;
    int skill;
    int gf;

    //==엔딩 플레그==
    //군대
    int badFlag; // 마음픠 편지
    int proFlag; // 전문하사

    //1학년
    int addictionFlag; // 코인중독
	int healthFlag; // 건강악화
    // badgamerFlag 사용
    
    //2학년
    int nojobFlag; // 백수
    int blackmoneyFlag; // 횡령
    int gametrollFlag; // 트롤
    int blameFlag; // 손절
    int blame2Flag; // 손절
    int badgamerFlag; // 게임중독
   
    //3학년
    int byegirlfriendFlag; // 이별
    int overworkFlag; // 과로
    int noPortfolioFlag; // 빈 폴더
    int slaveFlag; //대학원 엔딩1

    //4학년
    int quitFlag; // 중도포기
    int graduateFlag; //대학원 엔딩2

} State;

void printStatus(const State* st);
int printOpeningMenu();
void printSpecialEnding(const State* st);
int ask_fixed_question(int idx, State* st, const Event* event);
void typingPrint(const char* text);
void Opening();
void printEnding(const State* st);
int printOpeningMenu();
void runGradeLoop(const char* title, State* st, const Event* fixedEvents, const Event* randomEvents, int poolSize);
void printSpecialEnding(const State* st);
void ask_random_question(int pool_size, State* st, const Event* event);
int isGameEnd(const State* st);

#endif;