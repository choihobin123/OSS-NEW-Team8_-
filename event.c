#define _CRT_SECURE_NO_WARNINGS
#include "gamefunc.h"
#include <stdio.h>


void printStatus(const State* st) {
    printf("\n[현재 상태]\n");
    printf("스트레스 : %d\n", st->stress);
    printf("실력     : %d\n", st->skill);
    printf("여친     : %s\n\n", st->gf ? "있음" : "없음");
}

int runEvent(const Event* ev, State* st) {
    int choice;

    printf("\n====================================\n");
    printf("%s\n", ev->question);
    printf("1) %s\n", ev->choice1);
    printf("2) %s\n", ev->choice2);
    printf("3) %s\n", ev->choice3);
    printf("====================================\n");

    printStatus(st);

    printf("선택>> ");
    scanf("%d", &choice);

    int* chg = NULL;

    if (choice == 1) chg = ev->stateChange1, st->badFlag += (ev->stateChange1[0] >= 2);
    else if (choice == 2) chg = ev->stateChange2;
    else if (choice == 3) chg = ev->stateChange3;
    else return -1;

    st->stress += chg[0];
    st->skill += chg[1];
    if (chg[2] == 1) st->gf = 1;

    // 말뚝 엔딩 플래그
    if (choice == 2 && ev->next2 == -1) st->proFlag++;

    // 다음 이벤트 반환
    if (choice == 1) return ev->next1;
    if (choice == 2) return ev->next2;
    return ev->next3;
}

void printEnding(const State* st) {
    printf("\n====================================\n");
    printf("==== 최종 결과 ====\n");
    printf("====================================\n");
    printf("최종 스트레스: %d\n", st->stress);
    printf("최종 실력: %d\n", st->skill);
    printf("연애 여부: %s\n", st->gf ? "성공" : "실패");

    // 예시 엔딩 로직:
    if (st->skill >= 50 && st->stress < 50) {
        printf("\n🎉 [성공 엔딩] 학업 능력과 스트레스 관리에 모두 성공했습니다! 원하던 직장에 취업하거나 대학원에 진학할 수 있을 것입니다.\n");
    } else if (st->skill >= 50 && st->stress >= 50) {
        printf("\n😥 [번아웃 엔딩] 엄청난 실력을 쌓았지만, 스트레스 관리에 실패했습니다. 잠시 쉬어가는 시간이 필요해 보입니다.\n");
    } else if (st->skill < 50 && st->stress < 50) {
        printf("\n😌 [평화 엔딩] 학업 능력은 조금 부족하지만, 스트레스 없이 편안한 대학 생활을 보냈습니다.\n");
    } else {
        printf("\n😭 [재앙 엔딩] 스트레스는 높고 실력은 부족합니다. 재수강과 휴학을 고민해야 할 수도 있습니다.\n");
    }

    printf("====================================\n");
}
