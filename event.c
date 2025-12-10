#define _CRT_SECURE_NO_WARNINGS
#include "gamefunc.h"
#include <stdio.h>
#include <stdlib.h>

// [보조 함수] 엔터 대기
void waitEnter() {
    printf("\n(Enter를 누르면 넘어갑니다)");
    int c;
    while ((c = getchar()) != '\n' && c != EOF); 
}

// [보조 함수] 버퍼 비우기
void clearBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void printStatus(const State* st) {
    printf("\n[현재 상태]\n");
    printf("스트레스 : %d\n", st->stress);
    printf("실력     : %d\n", st->skill);
    printf("여친     : %s\n\n", st->gf ? "있음" : "없음");
}

// 오프닝 메뉴
int printOpeningMenu() {
    int choice;
    while (1) {
        system("cls");
        printf("┌──────────────────────────────────────────────┐\n");
        printf("│             인생.exe - 수능 이후             │\n");
        printf("│    당신의 선택이 한 페이지씩 기록되는 게임   │\n");
        printf("└──────────────────────────────────────────────┘\n\n");
        printf(" 1. 새 게임 시작\n");
        printf(" 2. 게임 설명\n");
        printf(" 3. 종료\n\n");
        printf("선택>> ");

        if (scanf("%d", &choice) == 1) {
            clearBuffer(); 
            if (choice == 1) return 1;
            if (choice == 2) {
                printf("\n======== 게임 설명 ========\n\n");
                printf("이 게임은 수능 이후의 공대생 삶을 따라가는 \n텍스트 기반 인터랙티브 픽션입니다.\n\n");
                printf("각 장면에서 제시되는 선택지를 숫자로 입력하면, \n선택에 따라 상태변수가 변화하고 다음 장면으로 이동합니다.\n");
                printf("\n- 입력 방법: 각 선택지의 번호(1~3)를 입력하세요.\n");
                printf("- '종료'는 언제든 메인 메뉴에서 선택 가능합니다.\n");
                printf("\n===========================\n");
                printf("\n설명을 읽으셨으면 Enter를 누르세요...");
                waitEnter();
                continue;
            }
            if (choice == 3) return 3;
        } else {
            clearBuffer();
        }
    }
}


// 게임을 즉시 종료해야 하는 상태인지 검사하는 함수
int isGameEnd(const State* st) {
    if (st->stress >= 100) return 1;        // 과로사
    if (st->badFlag >= 3) return 1;         // 군대 폐급 (영창)
    if (st->proFlag >= 1) return 1;         // 전문하사
    if (st->nojobFlag >= 1) return 1;       // 자퇴
    if (st->blackmoneyFlag >= 1) return 1;  // 횡령
    if (st->gametrollFlag >= 1) return 1;   // 트롤
    if (st->blameFlag >= 1) return 1;       // 손절
    if (st->blame2Flag >= 1) return 1;      // 손절
    if (st->badgamerFlag >= 1) return 1;    // 게임중독
    return 0; // 게임 계속 진행 가능
}

// 핵심 질문 함수 (기존 runEvent의 이름 변경 + 로직 유지)
int ask_fixed_question(int idx, State* st, const Event* event) {
    const Event* ev = &event[idx];
    int choice;

    system("cls");

    // [기존 텍스트 형식 절대 유지]
    printf("\n====================================\n\n");
    printf("%s\n\n", ev->question);
    printf("1) %s\n", ev->choice1);
    printf("2) %s\n", ev->choice2);
    if (ev->choice3 != NULL) printf("3) %s\n", ev->choice3);
    printf("\n====================================\n");

    printStatus(st);

    // scanf 입력 (안전 처리)
    while (1) {
        printf("선택>> ");
        if (scanf("%d", &choice) == 1) {
            clearBuffer(); // 엔터 제거
            
            int max_c = (ev->choice3 != NULL) ? 3 : 2;
            if (choice >= 1 && choice <= max_c) break;
        } else {
            clearBuffer(); // 문자 입력 시 제거
        }
        printf("잘못된 입력입니다.\n");
    }

    const int* chg = NULL;
    const char* resultText = NULL;
    int next_idx = -1;

    // 로직 처리
    if (choice == 1) {
        chg = ev->stateChange1;
        resultText = ev->result1;
        next_idx = ev->next1;
    }
    else if (choice == 2) {
        chg = ev->stateChange2;
        resultText = ev->result2;
        next_idx = ev->next2;
    }
    else if (choice == 3) {
        chg = ev->stateChange3;
        resultText = ev->result3;
        next_idx = ev->next3;
    }

    // ==========================================================
    // 헤더 파일의 설정값(Trigger)으로 플래그 증가
    // ==========================================================
    
    if (ev->badFlagTrigger == choice) st->badFlag++;

    if (ev->proFlagTrigger == choice) st->proFlag++;

    if (ev->blackmoneyFlagTrigger == choice) st->blackmoneyFlag++;

    if (ev->gametrollFlagTrigger == choice) st->gametrollFlag++;

    if (ev->nojobFlagTrigger == choice) st->nojobFlag++;

    if (ev->badgamerFlagTrigger == choice) st->badgamerFlag++;

    if (ev->blameFlagTrigger == choice) st->blameFlag++;

    if (ev->blame2FlagTrigger == choice) st->blame2Flag++;

    // ==========================================================

    st->stress += chg[0];
    st->skill += chg[1];
    if (chg[2] == 1) st->gf = 1;

    printf("\n------------------------------------\n");
    if (resultText != NULL) {
        printf("%s\n", resultText); // 결과 멘트 출력
    }
    printf(">> (상태 변화) 스트레스 %+d, 실력 %+d\n", chg[0], chg[1]);
    printf("------------------------------------\n");
    
    // 결과 확인 대기
    waitEnter(); 

    return next_idx;
}

// 랜덤 질문 처리
void ask_random_question(int pool_size, State* st, const Event* event) {
    int r = rand() % pool_size;
    // 랜덤한 번호로 고정 질문 함수를 호출
    ask_fixed_question(r, st, event);
}

// 학년 루프 (1~4학년 흐름용)
void runGradeLoop(const char* title, State* st, const Event* fixedEvents, const Event* randomEvents, int poolSize) {
    
    int visited[20] = { 0 }; 
    int usedCount = 0; 

    int current = 0;
    
    system("cls");
    printf("=== %s 시작 ===\n", title);
    waitEnter();

    // 메인 스토리 루프
    while (current != -1) {
        
        // 고정 스토리 진행
        current = ask_fixed_question(current, st, fixedEvents);
        
        // 엔딩/게임오버 체크
        if (st->stress >= 100) return;
        if (isGameEnd(st)) return; 


        // 랜덤 스토리 (고정 스토리 사이사이에 끼어들기)
        // 확률: 30%
        if (current != -1 && randomEvents != NULL && poolSize > 0 && (rand() % 10 < 3)) {
            
            // 아직 안 쓴 랜덤 질문이 남아있는 경우에만 실행
            if (usedCount < poolSize) {
                int r_idx;
                
                // 안 쓴 번호 뽑을 때까지 뺑뺑이 (중복 방지)
                do {
                    r_idx = rand() % poolSize;
                } while (visited[r_idx] == 1);

                visited[r_idx] = 1; 
                usedCount++;
                
                ask_fixed_question(r_idx, st, randomEvents);
                
                if (isGameEnd(st)) return;
            }
        }
    }
}

// 엔딩 출력 (기존 텍스트 유지)
void printSpecialEnding(const State* st) {
    system("cls");
    printf("\n====================================\n");
    printf("        [ G A M E   O V E R ]\n");
    printf("====================================\n\n");

    if (st->stress >= 100) {
        printf("[과로사 엔딩] \n\n\"어..? 왜 갑자기 앞이 흐릿해보이지..?\" \n그 뒤로 희미하게 기억나는 것은..\n\n다급한 친구의 목소리와 사이렌 소리뿐이였다.");
    }

    else if (st->proFlag >= 1) {
        printf("[전문하사 엔딩] \n\n\"자네, 일 머리가 아주 좋아. 나랑 6개월만 더 하지? \n\n\"행보관님의 달콤한 제안, 그리고 내 손에 들린 임관 지원서. \n정신을 차렸을 땐 이미 도장은 찍혀 있었다.");
    }
    else if (st->badFlag >= 3) {
        printf("[마음의 편지 엔딩] \n\n중대장님 책상 위에 수북이 쌓인 흰 봉투들. \n\n\"더 이상은 못 참겠습니다...\" \"악마를 보았습니다...\" \n\n익숙한 내 이름이 보인다. 헌병대 차가 위병소를 통과했다.");
    }
    else if (st->nojobFlag >= 1) {
        printf("[백수 엔딩] \n\n\"학교 공부는 나랑 안 맞아.\" \n\n패기롭게 자체 휴강을 때렸다. \n도서관에 간다는 핑계로 PC방을 갔고, 코딩 공부 대신 넷플릭스를 정주행했다. \n동기들이 졸업 가운을 입을 때, 나는 재수강 신청 버튼을 누르고 있다.");
    }
    else if (st->blackmoneyFlag >= 1) {
        printf("[횡령 엔딩] \n\n\"자, 이거 비밀이다? 맛있는 거나 사 먹어.\" \n\n선배가 건넨 두툼한 봉투. \n나는 그날 장부를 덮었고 양심도 함께 팔았다. \n얼마 후 학교에 경찰차가 들이닥쳤다. \n참고인 조사? \n아니. \n나도 공범이었다.");
    }
    else if (st->gametrollFlag >= 1) {
        printf("[트롤 엔딩] \n\n\"아니 게임인데 왜 이렇게 진지함? ㅋㅋ\" \n\n나는 강철심장 유미로 협곡을 누볐다. \n나만 재밌었다. \n게임이 끝나자마자 친구들은 조용히 짐을 싸서 나갔다.");
    }
    else if (st->blameFlag >= 1 || st->blame2Flag >= 1) {
        printf("[손절 엔딩] \n\n\"야! 이걸 못하냐? 네가 사람이냐?\" \n\n내 고함소리에 PC방이 조용해졌다. \n친구의 눈빛이 차갑게 식었다. \n\"그래... 너 잘났다. 너 혼자 해라.\" \n단톡방의 숫자가 하나씩 줄어든다. 이제 아무도 나를 부르지 않는다.");
    }
    else if (st->badgamerFlag >= 1) {
        printf("[게임중독 엔딩] \n\n\"내 피지컬 봤냐? 이건 프로 각이다.\" \n\n착각이었다. \n내가 있는 곳은 롤드컵 결승 무대가 아니라 컴컴한 PC방 구석이었다. \n쌓여가는 컵라면 용기와 멈춰버린 티어. \n현실 로그아웃은 불가능했다.");
    }

    printf("\n\n====================================\n");

    /*
    printf("\n======= 졸업 엔딩 =======\n");
    if (st->stress < 50 && st->skill > 70) printf("[대기업 엔딩] 성공적인 취업!\n");
    else if (st->skill > 90) printf("[대학원 엔딩] 교수가 되었습니다.\n");
    else printf("[일반 엔딩] 무사히 졸업했습니다.\n");
    */

    waitEnter();
}