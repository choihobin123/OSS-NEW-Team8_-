#define _CRT_SECURE_NO_WARNINGS
#include "gamefunc.h"
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>   // 키 입력 감지(_kbhit, _getch)용
#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_ENTER 13

void typingPrint(const char* text) {
    int i = 0;
    int skip = 0; // 스킵 모드 플래그 (0: 정상 속도, 1: 즉시 출력)

    while (_kbhit()) _getch();

    while (text[i] != '\0') {
        if (!skip && _kbhit()) {
            char ch = _getch();
            if (ch == '\r') { // 엔터('\r')면 스킵
                skip = 1;
            }
        }

        int charLen = 1;
        unsigned char c = (unsigned char)text[i];

        // UTF-8 바이트 길이 계산
        if ((c & 0xF0) == 0xF0) charLen = 4;
        else if ((c & 0xE0) == 0xE0) charLen = 3; // 한글
        else if ((c & 0xC0) == 0xC0) charLen = 2;
        else charLen = 1;

        // 글자 출력
        for (int j = 0; j < charLen; j++) {
            printf("%c", text[i + j]);
        }
        i += charLen;

        if (!skip) {
            Sleep(45);      // 출력 속도
            fflush(stdout); 
        }
        else {
            Sleep(0);       // 스킵 시 딜레이 0 (즉시 출력)
        }
    }
    
    fflush(stdout);
}

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

void setColor(int color) { // [보조 함수] 텍스트 색상 변경
// color: 7=흰색, 10=연두색, 11=하늘색, 12=빨간색, 14=노란색, 8=회색
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void delay(int milliseconds) {
    long pause;
    // 대략적인 루프 횟수 조정 (컴퓨터 성능에 따라 다름)
    pause = (long)milliseconds * 100000;
    while (pause--);
}
void showLoadingBar(const char* taskName) {
    setColor(10); // 연두색 (시스템 느낌)
    printf("\n [SYSTEM] %s...\n", taskName);

    printf(" 0%% [");
    for (int i = 0; i < 30; i++) printf(" ");
    printf("]");

    for (int i = 0; i <= 30; i++) {
        // 커서를 줄 맨 앞으로 이동 (\r)
        printf("\r");

        // 퍼센트 출력
        int percent = (i * 100) / 30;
        setColor(11); // 하늘색
        printf(" %3d%% [", percent);

        // 게이지 채우기
        setColor(10); // 연두색
        for (int j = 0; j < i; j++) printf("=");
        for (int j = i; j < 30; j++) printf(" ");

        setColor(11); // 하늘색
        printf("]");

        // 랜덤 딜레이로 리얼함 추가
        Sleep(rand() % 50 + 20);
    }
    printf("\n");
    Sleep(300);
    setColor(7); // 다시 흰색 복구
}

void Opening() {
    char buf[128];
    system("cls"); // 화면 초기화

    // 1. 시스템 부팅 시퀀스 (매트릭스 느낌)
    setColor(10); // 연두색
    printf("\n Initializing Boot Sequence...\n");
    Sleep(500);
    printf(" Checking Memory... OK\n");
    Sleep(200);
    printf(" Loading User Data... OK\n");
    Sleep(200);

    showLoadingBar("Decrypting Memories");
    showLoadingBar("Syncing Timeline");

    Sleep(1000);
    system("cls");

    // 2. 타이틀 로고 (ASCII ART)
    // 폰트가 깨지지 않게 색상 강조
    setColor(11); // 하늘색 (제목)
    printf("\n\n");
    printf("   ██╗     ██╗███████╗███████╗   ███████╗██╗  ██╗███████╗\n");
    printf("   ██║     ██║██╔════╝██╔════╝   ██╔════╝██║  ██║██╔════╝\n");
    printf("   ██║     ██║█████╗  █████╗     ███████╗  ███║  █████╗  \n");
    printf("   ██║     ██║██╔══╝  ██╔══╝     ██╔═══╝ ██╔══██║██╔══╝  \n");
    printf("   ███████╗██║██║     ███████╗   ███████╗██║  ██║███████╗\n");
    printf("   ╚══════╝╚═╝╚═╝     ╚══════╝   ╚══════╝╚═╝  ╚═╝╚══════╝\n");
    printf("\n");

    setColor(14); // 노란색 (부제)
    printf("            [ 인생.exe : 수능 그 이후 ]\n");
    printf("            - 공대생 대학 생활 시뮬레이션 -\n");
    printf("\n\n");

    setColor(8); // 회색 (안내문구)
    printf("  System Ready. Press [Enter] to Access Diary module...\n");

    // 엔터 대기
    fflush(stdin);
    while (getchar() != '\n');

    // 3. 일기장 감성 진입 (화면 전환)
    system("cls");
    Sleep(1000);

    setColor(7); // 흰색 (기본)
    printf("\n\n");

    // 느리게 타이핑 해주는 함수
    typingPrint(" ...시스템이 종료되고, 낡은 일기장이 화면에 나타납니다.\n\n");
    Sleep(1000);

    typingPrint(" [ 202X년 3월 2일 ]\n");
    Sleep(500);
    typingPrint(" 차가운 새벽 공기. 닳아버린 펜을 듭니다.\n");
    Sleep(1000);
    typingPrint(" 치열했던 수능이 끝나고, 합격 통지서를 받았던 그날의 기억...\n\n");
    Sleep(1000);

    typingPrint(" 이제 당신의 4년이 기록됩니다.\n");
    typingPrint(" 학점, 인간관계, 사랑, 그리고 미래.\n");
    typingPrint(" 이 일기장의 끝에 무엇이 적혀있을지는...\n\n");
    Sleep(1500);

    setColor(12); // 빨간색 (강조)
    typingPrint(" 오직 당신의 선택에 달려있습니다.\n\n");

    setColor(7); // 흰색 복구
    Sleep(1000);

    printf("==================================================\n");
    printf("      첫 페이지를 넘기시려면 [Enter]를 누르세요\n");
    printf("==================================================\n");

    fflush(stdin);
    // 버퍼 비우고 입력 대기
    fgets(buf, sizeof(buf), stdin);
    system("cls");
}

// 오프닝 메뉴
int printOpeningMenu() {
    int cursor = 0; // 현재 선택된 메뉴 위치 (0: 새게임, 1: 설명, 2: 종료)
    int key;

    while (1) {
        system("cls"); // 화면 지우기

        // 1. 메인 타이틀 박스 출력
        setColor(11); // 하늘색
        printf("\n");
        printf("  ╔══════════════════════════════════════════════════╗\n");
        printf("  ║                                                  ║\n");
        printf("  ║            L I F E . E X E   SYSTEM              ║\n");
        printf("  ║                                                  ║\n");
        printf("  ║        [ v1.0 / User: Engineering_Student ]      ║\n");
        printf("  ║                                                  ║\n");
        printf("  ╚══════════════════════════════════════════════════╝\n\n");

        // 2. 메뉴 목록 출력
        const char* menuItems[] = {
            " 새 게임 시작 ",
            " 시스템 설명서 ",
            " 시스템 종료 "
        };

        for (int i = 0; i < 3; i++) {
            if (i == cursor) {
                // 선택된 항목: 노란색 + 화살표
                setColor(14);
                printf("      ▶  [ %s ]\n\n", menuItems[i]);
            }
            else {
                // 선택 안 된 항목: 회색
                setColor(8);
                printf("         %s \n\n", menuItems[i]);
            }
        }

        // 3. 하단 안내 문구
        setColor(7); // 흰색
        printf("\n  ----------------------------------------------------\n");
        printf("   [↑/↓]: 이동   [Enter]: 선택 \n");

        // 4. 키 입력 처리
        key = _getch(); // 키 하나 입력받음

        if (key == 224) { // 특수키(화살표)인 경우
            key = _getch(); // 실제 키 코드 읽기
            if (key == KEY_UP) {
                cursor--;
                if (cursor < 0) cursor = 2; // 맨 위에서 위로 가면 맨 아래로
            }
            else if (key == KEY_DOWN) {
                cursor++;
                if (cursor > 2) cursor = 0; // 맨 아래에서 아래로 가면 맨 위로
            }
        }
        else if (key == KEY_ENTER) { // 엔터키 누름
            // 선택된 커서에 따라 동작 결정
            if (cursor == 0) {
                return 1; // 새 게임
            }
            else if (cursor == 1) {
                // 게임 설명 화면
                system("cls");
                setColor(10); // 연두색
                printf("\n\n [ 시스템 설명서 ]\n\n");

                setColor(7);
                typingPrint(" > 본 시뮬레이션은 '공대생'의 대학 생활을 다룹니다.\n\n");
                typingPrint(" > 매 순간의 선택이 당신의 [스트레스], [학점], [연애]를 결정합니다.\n");
                typingPrint(" > 현명한 선택으로 최고의 엔딩을 수집하십시오.\n\n");

                setColor(8);
                printf(" ----------------------------------------\n");
                printf("  [Enter] 키를 누르면 메인으로 돌아갑니다.\n");

                while (_getch() != 13); // 엔터 칠 때까지 대기
            }
            else if (cursor == 2) {
                return 3; // 종료
            }
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
    if (st->byegirlfriendFlag >= 1) return 1; // 이별
    if (st->overworkFlag >= 1) return 1; // 과로
    if (st->noPortfolioFlag >= 1) return 1; // 빈 폴더
    if (st->slaveFlag >= 1) return 1; // 대학원
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

    if (ev->byegirlfriendFlagTrigger == choice) st->byegirlfriendFlag++;

    if (ev->overworkFlagTrigger == choice) st->overworkFlag++;

    if (ev->noPortfolioFlagTrigger == choice) st->noPortfolioFlag++;

    if (ev->slaveFlagTrigger == choice) st->slaveFlag++;

    // ==========================================================

    st->stress += chg[0];
    st->skill += chg[1];
    if (chg[2] == 1) st->gf = 1;

    printf("\n------------------------------------\n\n");
    if (resultText != NULL) {
        typingPrint(resultText); // 결과 멘트 출력
    }
    printf("\n\n>> (상태 변화) 스트레스 %+d, 실력 %+d\n", chg[0], chg[1]);
    printf("\n------------------------------------\n");
    
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
        typingPrint("[과로사 엔딩] \n\n\"어..? 왜 갑자기 앞이 흐릿해보이지..?\" \n그 뒤로 희미하게 기억나는 것은..\n\n다급한 친구의 목소리와 사이렌 소리뿐이였다.");
    }

    else if (st->proFlag >= 1) {
        typingPrint("[전문하사 엔딩] \n\n\"자네, 일 머리가 아주 좋아. 나랑 6개월만 더 하지? \n\n\"행보관님의 달콤한 제안, 그리고 내 손에 들린 임관 지원서. \n정신을 차렸을 땐 이미 도장은 찍혀 있었다.");
    }
    else if (st->badFlag >= 3) {
        typingPrint("[마음의 편지 엔딩] \n\n중대장님 책상 위에 수북이 쌓인 흰 봉투들. \n\n\"더 이상은 못 참겠습니다...\" \"악마를 보았습니다...\" \n\n익숙한 내 이름이 보인다. 헌병대 차가 위병소를 통과했다.");
    }
    else if (st->nojobFlag >= 1) {
        typingPrint("[백수 엔딩] \n\n\"학교 공부는 나랑 안 맞아.\" \n\n패기롭게 자체 휴강을 때렸다. \n도서관에 간다는 핑계로 PC방을 갔고, 코딩 공부 대신 넷플릭스를 정주행했다. \n동기들이 졸업 가운을 입을 때, 나는 재수강 신청 버튼을 누르고 있다.");
    }
    else if (st->blackmoneyFlag >= 1) {
        typingPrint("[횡령 엔딩] \n\n\"자, 이거 비밀이다? 맛있는 거나 사 먹어.\" \n\n선배가 건넨 두툼한 봉투. \n나는 그날 장부를 덮었고 양심도 함께 팔았다. \n얼마 후 학교에 경찰차가 들이닥쳤다. \n참고인 조사? \n아니. \n나도 공범이었다.");
    }
    else if (st->gametrollFlag >= 1) {
        typingPrint("[트롤 엔딩] \n\n\"아니 게임인데 왜 이렇게 진지함? ㅋㅋ\" \n\n나는 강철심장 유미로 협곡을 누볐다. \n나만 재밌었다. \n게임이 끝나자마자 친구들은 조용히 짐을 싸서 나갔다.");
    }
    else if (st->blameFlag >= 1 || st->blame2Flag >= 1) {
        typingPrint("[손절 엔딩] \n\n\"야! 이걸 못하냐? 네가 사람이냐?\" \n\n내 고함소리에 PC방이 조용해졌다. \n친구의 눈빛이 차갑게 식었다. \n\"그래... 너 잘났다. 너 혼자 해라.\" \n단톡방의 숫자가 하나씩 줄어든다. 이제 아무도 나를 부르지 않는다.");
    }
    else if (st->badgamerFlag >= 1) {
        typingPrint("[게임중독 엔딩] \n\n\"내 피지컬 봤냐? 이건 프로 각이다.\" \n\n착각이었다. \n내가 있는 곳은 롤드컵 결승 무대가 아니라 컴컴한 PC방 구석이었다. \n쌓여가는 컵라면 용기와 멈춰버린 티어. \n현실 로그아웃은 불가능했다.");
    }
    else if(st->byegirlfriendFlag >= 1){
        typingPrint("[이별 엔딩] \n\n\"우리... 그만하자.\" \n\n그 한마디가 내 세상의 전원을 꺼버렸다. \n아무것도 손에 잡히지 않는다. 전공책도, 게임도, 밥 먹는 것조차 귀찮다. \n방 구석에 쌓여가는 술병만큼 내 학점도, 내 인생도 무너져 내렸다. 나는 방 밖으로 나가는 문을 잠가버렸다.");
    }
    else if(st->overworkFlag >= 1){
        typingPrint("[과로 엔딩] \n\n\"어서오세...요...\" \n\n편의점 계산대의 바코드가 2개로 겹쳐 보이기 시작했다.\n새벽 알바가 끝나면 쉴 틈 없이 1교시 수업으로, 그리고 다시 과제로... 카페인으로 억지로 붙잡고 있던 정신줄이 툭 하고 끊어졌다.\n\n\"학생! 학생!! 정신 차려!!\"\n\n눈을 떴을 때 보인 건 하얀 병원 천장뿐이었다. 의사 선생님은 단호한 표정으로 휴학 진단서를 내밀었다. 통장 잔고는 조금 찼을지 몰라도, 내 몸은 완전히 방전되어 버렸다.");
    }
    else if(st->noPortfolioFlag >= 1){
        typingPrint("[빈 폴더 엔딩] \n\n\"지원 마감 10분 전.\"\n바탕화면은 '새 폴더', '최종', '진짜_최종', '진짜_진짜_최종'으로 가득 차 있다.\n하지만 정작 클릭해 보면 정리되지 않은 스크린샷과 의미 없는 메모장 파일뿐.\n\n\"이것도 나중에... 저것도 나중에...\"\n\n미래의 나에게 미뤘던 빚이 쓰나미가 되어 돌아왔다.\n남들은 결과물을 멋진 PDF로 뽐내는데, 내 모니터엔 빈 폴더만 깜빡거린다.\n제출 버튼을 누르지 못하고 창을 닫았다. 내 대학 생활은 '제목 없음'으로 끝났다.");
    }
    else if(st->slaveFlag >=1 ){
        typingPrint("[대학원 엔딩] \n\n\"자네, 연구에 재능이 있어. 대학원 생각 없나?\"\n\n교수님의 달콤한 제안. 그리고 정신을 차려보니 나는 랩실 책상 앞에 앉아 있다.\n친구들이 취업해서 첫 월급을 자랑할 때, 나는 밤새 논문을 읽고 실험 데이터를 정리한다.\n\n\"교수님, 저 졸업은 언제쯤...\"\n\"허허, 자네 아직 멀었네. 이번 학회 준비는 다 됐나?\"\n\n학교의 불은 꺼지지 않고, 나의 청춘도 랩실에 저당 잡혔다.");
    }
    printf("\n\n====================================\n");

    

    waitEnter();
}

void printEnding(const State* st) {
    printf("\n======= 졸업 엔딩 =======\n");
    if (st->stress < 50 && st->skill > 70) printf("[대기업 엔딩] 성공적인 취업!\n");
    else if (st->skill > 90) printf("[대학원 엔딩] 교수가 되었습니다.\n");
    else printf("[일반 엔딩] 무사히 졸업했습니다.\n");
    waitEnter();
}
    