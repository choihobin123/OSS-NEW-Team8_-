#include <stdio.h>
#include "gamefunc.h"
#include <windows.h>
#include <time.h>

#include "militaryEvent.h"
#include "1StGradeStory.h"
#include "2ndGradeStory.h" 
#include "3rdGradeStory.h" 
#include "4ndGradeStory.h" 

#define _CRT_SECURE_NO_WARNINGS

int main() {
    SetConsoleOutputCP(CP_UTF8);
    srand((unsigned int)time(NULL));
    State myState = { 0, 0, 0, 0, 0 };  // stress, skill, gf, badFlag, proFlag
    printOpeningMenu();
    printf("==== 대학교 생활 시뮬레이션 시작 ====\n\n\n");
    printf("=== 1학년 게임 시작 (Direct Control Ver.) ===\n");
    int current_idx = 0;
    while (current_idx != -1) {
        system("cls");

        // 1. 고정 질문 먼저 던지기
        // (함수가 다음 갈 번호를 알려줌 -> current_idx 업데이트)
        current_idx = ask_fixed_question(current_idx, &myState, events_y1_fixed);

        // 2. 아직 게임이 안 끝났다면, 50% 확률로 무작위 질문 던지기
        if (current_idx != -1) {
            system("cls");
            int dice = rand() % 2; // 0 아니면 1
            if (dice == 0) {
                // 무작위 질문 함수 호출 (총 5개 중 랜덤)
                ask_random_question(5, &myState, events_y1_random);
            }
        }

        // 여기에 "스트레스 너무 높으면 강제로 휴식 질문 던지기" 같은 것도
        // if (myState.stress > 80) { ... } 처럼 직접 넣을 수 있음!
    }
    system("cls");
    printf("\n=== 1학년 종료 최종 상태 ===\n");
    printf("스트레스: %d\n", myState.stress);
    printf("실력: %d\n", myState.skill);
    printf("연애: %s\n", myState.gf ? "성공" : "실패");
    
    printf("\n");
    printSpecialEnding(&myState);

    return 0;
}
