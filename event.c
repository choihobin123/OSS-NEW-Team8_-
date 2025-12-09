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
    printf("\n======= 엔딩 =======\n");

    if (st->proFlag >= 1) {
        printf("전문하사 엔딩\n");
        return;
    }

    if (st->badFlag >= 3) {
        printf("마음의 편지 엔딩\n");
        return;
    }
}  

void printSpecialEnding(const State* st) {
    printf("\n======= 특수 엔딩 =======\n");

    if (st->proFlag >= 1) {
        printf("[전문하사 엔딩] \"자네, 일 머리가 아주 좋아. 나랑 6개월만 더 하지?\"행보관님의 달콤한 제안, 그리고 내 손에 들린 임관 지원서. 정신을 차렸을 땐 이미 도장은 찍혀 있었다.\n");
        return;
    }

    if (st->badFlag >= 3) {
        printf("[마음의 편지 엔딩] 중대장님 책상 위에 수북이 쌓인 흰 봉투들. \"더 이상은 못 참겠습니다...\" \"악마를 보았습니다...\" 익숙한 내 이름이 보인다. 헌병대 차가 위병소를 통과했다.");
        return;
    }

    if (st->nojobFlag >= 1) { //2학년 0,11 스토리 분기점
        printf("[백수 엔딩] \"학교 공부는 나랑 안 맞아.\" 패기롭게 자체 휴강을 때렸다. 도서관에 간다는 핑계로 PC방을 갔고, 코딩 공부 대신 넷플릭스를 정주행했다. 동기들이 졸업 가운을 입을 때, 나는 재수강 신청 버튼을 누르고 있다.");
        return;
    }

    if (st->blackmoneyFlag >= 1) { //2학년 8,12,13 스토리 분기점
        printf("[횡령 엔딩] \"자, 이거 비밀이다? 맛있는 거나 사 먹어.\" 선배가 건넨 두툼한 봉투. 나는 그날 장부를 덮었고 양심도 함께 팔았다. 얼마 후 학교에 경찰차가 들이닥쳤다. 참고인 조사? 아니, 나도 공범이었다.");
        return;
    }

    if (st->gametrollFlag >= 1) { //2학년 14,15 스토리 분기점
        printf("[트롤 엔딩] \"아니 게임인데 왜 이렇게 진지함? ㅋㅋ\" 나는 강철심장 유미로 협곡을 누볐다. 나만 재밌었다. 게임이 끝나자마자 친구들은 조용히 짐을 싸서 나갔다.");
        return;
    }

    if (st->blameFlag >= 5) { //2학년 14,16 스토리 분기점
        printf("[손절 엔딩] \"야! 이걸 못하냐? 네가 사람이냐?\" 내 고함소리에 PC방이 조용해졌다. 친구의 눈빛이 차갑게 식었다. \"그래... 너 잘났다. 너 혼자 해라.\" 단톡방의 숫자가 하나씩 줄어든다. 이제 아무도 나를 부르지 않는다.");
        return;
    }

    if (st->badgamerFlag >= 1) { //2학년 14,17 스토리 분기점
        printf("[게임중독 엔딩] \"내 피지컬 봤냐? 이건 프로 각이다.\" 착각이었다. 내가 있는 곳은 롤드컵 결승 무대가 아니라 컴컴한 PC방 구석이었다. 쌓여가는 컵라면 용기와 멈춰버린 티어. 현실 로그아웃은 불가능했다.");
        return;
    }
}   