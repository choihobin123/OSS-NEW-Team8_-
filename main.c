#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include "gamefunc.h"

// 헤더 파일 포함
#include "1StGradeStory.h"
#include "2ndGradeStory.h" 
#include "3rdGradeStory.h" 
#include "4ndGradeStory.h" // 파일명 (4th / 4nd) 확인
#include "militaryEvent.h"

// event.c 함수 선언
int printOpeningMenu();
void runGradeLoop(const char* title, State* st, const Event* fixedEvents, const Event* randomEvents, int poolSize);
void printSpecialEnding(const State* st);
void ask_random_question(int pool_size, State* st, const Event* event);
int isGameEnd(const State* st);

int main() {
    SetConsoleOutputCP(65001); // 한글 설정
    srand((unsigned int)time(NULL));

    State st = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

    Opening();

    // ================== 오프닝 ==================

    if (printOpeningMenu() == 3) return 0;

    // ================== 1학년 ==================
    
    runGradeLoop("1학년", &st, events_y1_fixed, events_y1_random, 5);
    if (isGameEnd(&st)) { printSpecialEnding(&st); return 0; }

    // ================== 2학년 ==================

    runGradeLoop("2학년", &st, events_y2_fixed, events_y2_random, 2);
    if (isGameEnd(&st)) { printSpecialEnding(&st); return 0; }

    if (st.nojobFlag >= 1 || st.blackmoneyFlag >= 1 || st.gametrollFlag >= 1 || st.blameFlag >= 1 || st.badgamerFlag >= 1) {
        printSpecialEnding(&st);
        return 0;
    }

    // ================== 군대 ==================

    runGradeLoop("군대", &st, eventList_military, NULL, 0);

    if (st.proFlag >= 1 || st.badFlag >= 3) {
        printSpecialEnding(&st);
        return 0;
    }

    // ================== 3학년 ==================

    runGradeLoop("3학년", &st, events_y3_fixed, events_y3_random, 0);
    
    if (st.byegirlfriendFlag >= 1 || st.overworkFlag >= 1 || st.noPortfolioFlag >= 1 || st.slaveFlag >= 1) {
        printSpecialEnding(&st);
        return 0;
    }

    // ================== 4학년 ==================

    runGradeLoop("4학년", &st, events_y4_fixed, events_y4_random, 0);
    if (isGameEnd(&st)) { printSpecialEnding(&st); return 0; }
    // ================== 엔딩 ==================

    printEnding(&st);

    return 0;
}