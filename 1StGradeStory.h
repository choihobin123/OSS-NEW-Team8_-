// 1StGradeStory.h
#ifndef EVENTS_Y1_H
#define EVENTS_Y1_H

#include "gamefunc.h"

// =============================================================
// [1학년 스토리 컨셉]
// "설렘 반, 절망 반. 공대생의 시작."
// 키워드: 미적분학, 술게임, 첫사랑(CC), 밤샘 과제
// =============================================================

// [무작위 질문지] : 게임 중간중간 등장하는 돌발 상황 (10개)
static const Event events_y1_random[10] = {
    {
        .question = "[돌발] 9시 1교시 수업인데 눈을 뜨니 8시 55분이다!",
        .choice1 = "우사인 볼트 빙의해서 뛰어간다.",
        .choice2 = "에라 모르겠다. 자체 휴강이다.",
        .choice3 = "여유롭게 씻고 2교시부터 간다.",
        .result1 = "심장은 터질 것 같지만 출석은 불렀다. 땀범벅이 되었다.",
        .result2 = "다시 이불 속으로 들어갔다. 세상에서 제일 달콤한 잠이다.",
        .result3 = "지각 체크는 됐지만, 마음만은 여유롭다.",
        .stateChange1 = { +10, +5, 0 },  // 스트레스↑, 실력↑
        .stateChange2 = { -10, -5, 0 },  // 스트레스↓, 실력↓
        .stateChange3 = { -5,  -2, 0 },
        .next1 = 0, .next2 = 0, .next3 = 0
    },
    {
        .question = "[돌발] 팀플 조별모임 시간. 조장이 연락 두절이다.",
        .choice1 = "내가 총대를 메고 캐리한다.",
        .choice2 = "교수님께 이 사실을 고발한다.",
        .choice3 = "나도 잠수 탄다.",
        .result1 = "밤을 새워 PPT를 완성했다. 조원들이 나를 신처럼 떠받든다.",
        .result2 = "정의구현. 조장은 F를 받았고 내 속은 시원하다.",
        .result3 = "결국 조 전체가 공중분해 되었다. 다 같이 망했다.",
        .stateChange1 = { +15, +15, 0 }, // 스트레스 대폭↑, 실력 대폭↑
        .stateChange2 = { +5,   +5, 0 },
        .stateChange3 = { +10, -10, 0 },
        .next1 = 0, .next2 = 0, .next3 = 0
    },
    {
        .question = "[돌발] 도서관 옆자리 그/그녀가 쪽지를 건넸다.",
        .choice1 = "설레는 마음으로 쪽지를 펴본다.",
        .choice2 = "공부에 방해된다. 무시한다.",
        .choice3 = NULL,
        .result1 = "'혹시... 지우개 좀 빌려주실 수 있나요?' 김이 팍 샜다.",
        .result2 = "철벽을 쳤다. 나는 차가운 공대생이다.",
        .result3 = NULL,
        .stateChange1 = { +5, -2, 0 },
        .stateChange2 = { 0, +5, 0 },
        .stateChange3 = { 0, 0, 0 },
        .next1 = 0, .next2 = 0, .next3 = 0
    },
    {
        .question = "[돌발] 동기가 '족보(기출문제)'를 구했다며 은밀히 접근한다.",
        .choice1 = "압도적 감사! 바로 복사한다.",
        .choice2 = "내 실력으로 승부하겠다. 거절한다.",
        .choice3 = NULL,
        .result1 = "시험 문제가 족보와 똑같이 나왔다! 학점의 신이 도왔다.",
        .result2 = "멋진 다짐이었지만, 시험지를 보자마자 후회했다.",
        .result3 = NULL,
        .stateChange1 = { -10, +15, 0 }, // 스트레스↓, 실력(학점)↑
        .stateChange2 = { +10, +5, 0 },
        .stateChange3 = { 0, 0, 0 },
        .next1 = 0, .next2 = 0, .next3 = 0
    },
    {
        .question = "[돌발] 술자리에서 선배가 '마셔라 마셔라' 노래를 부른다.",
        .choice1 = "패기 있게 원샷 때린다.",
        .choice2 = "몰래 물을 섞어 마신다.",
        .choice3 = "취한 척 테이블에 엎드린다.",
        .result1 = "분위기는 띄웠지만 다음 날 내 머리는 깨졌다.",
        .result2 = "들키지 않았다. 이것이 사회생활이다.",
        .result3 = "집에 일찍 갈 수 있었지만, '노잼' 타이틀을 얻었다.",
        .stateChange1 = { +10, 0, 0 },
        .stateChange2 = { -5, 0, 0 },
        .stateChange3 = { -5, -2, 0 },
        .next1 = 0, .next2 = 0, .next3 = 0
    },
    {
        .question = "[돌발] 전공 필수 과목 교수님이 질문을 던진다.",
        .choice1 = "자신 있게 손들고 대답한다.",
        .choice2 = "교수님과 눈을 마주치지 않으려 노력한다.",
        .choice3 = NULL,
        .result1 = "정답이다! 교수님이 흐뭇하게 내 이름을 적어가셨다.",
        .result2 = "위기를 모면했다. 하지만 얻은 것도 없다.",
        .result3 = NULL,
        .stateChange1 = { +5, +10, 0 },
        .stateChange2 = { -2, 0, 0 },
        .stateChange3 = { 0, 0, 0 },
        .next1 = 0, .next2 = 0, .next3 = 0
    },
    {
        .question = "[돌발] 코딩 과제 중 블루스크린이 떴다. 저장 안 했는데.",
        .choice1 = "모니터를 주먹으로 친다.",
        .choice2 = "침착하게 다시 처음부터 짠다.",
        .choice3 = NULL,
        .result1 = "모니터가 부서졌다. 과제도 날리고 돈도 날렸다.",
        .result2 = "각성 상태로 코딩했다. 오히려 코드가 더 깔끔해졌다.",
        .result3 = NULL,
        .stateChange1 = { +30, -10, 0 },
        .stateChange2 = { +20, +20, 0 },
        .stateChange3 = { 0, 0, 0 },
        .next1 = 0, .next2 = 0, .next3 = 0
    },
    {
        .question = "[돌발] 우주 공강 4시간 발생. 무엇을 할까?",
        .choice1 = "도서관에 박혀서 예습 복습.",
        .choice2 = "PC방으로 달려가 롤 한 판.",
        .choice3 = "과방 소파에서 부족한 잠을 보충한다.",
        .result1 = "학구열이 불타오른다. A+에 한 걸음 다가갔다.",
        .result2 = "연승했다! 공부는 안 했지만 기분은 최고다.",
        .result3 = "일어나니 개운하다. 얼굴에 자국이 남았지만.",
        .stateChange1 = { +5, +10, 0 },
        .stateChange2 = { -10, -5, 0 },
        .stateChange3 = { -15, 0, 0 },
        .next1 = 0, .next2 = 0, .next3 = 0
    },
    {
        .question = "[돌발] 학과 행사 뒤풀이 비용이 부족하다. 총무가 쳐다본다.",
        .choice1 = "멋지게 카드를 긁는다. (내가 쏜다!)",
        .choice2 = "화장실 가는 척 도망간다.",
        .choice3 = NULL,
        .result1 = "동기들의 환호를 받았다. 다음 달의 내가 갚겠지.",
        .result2 = "돈은 굳었지만, 인간관계에 금이 갔다.",
        .result3 = NULL,
        .stateChange1 = { -10, 0, 0 }, // 스트레스 해소, 돈은 구현 안함
        .stateChange2 = { +5, 0, 0 },
        .stateChange3 = { 0, 0, 0 },
        .next1 = 0, .next2 = 0, .next3 = 0
    },
    {
        .question = "[돌발] 밤 12시, 갑자기 현타(현실 자각 타임)가 온다.",
        .choice1 = "미래를 위해 전공 책을 편다.",
        .choice2 = "유튜브 알고리즘의 파도에 몸을 맡긴다.",
        .choice3 = "내일의 나를 믿고 그냥 잔다.",
        .result1 = "새벽 감성으로 공부 효율이 200% 올랐다.",
        .result2 = "정신 차려보니 아침 해가 뜨고 있다. 망했다.",
        .result3 = "역시 잠이 보약이다.",
        .stateChange1 = { +10, +10, 0 },
        .stateChange2 = { +10, -5, 0 },
        .stateChange3 = { -10, 0, 0 },
        .next1 = 0, .next2 = 0, .next3 = 0
    }
};

// [고정 질문지] : 1학년 메인 스토리라인 (입학 ~ 종강)
static const Event events_y1_fixed[20] = {
    {   // 0. 입학식
        .question = "3월 2일. 공대생으로서의 첫발을 내디뎠다. 정문 앞의 기분은?",
        .choice1 = "수석 졸업을 목표로 주먹을 꽉 쥔다.",
        .choice2 = "캠퍼스의 낭만을 즐기리라 다짐한다.",
        .choice3 = NULL,
        .result1 = "비장한 각오로 도서관 위치부터 파악했다.",
        .result2 = "설레는 마음으로 술집 위치부터 파악했다.",
        .result3 = NULL,
        .stateChange1 = { +5, +10, 0 },
        .stateChange2 = { -5, 0, 0 },
        .stateChange3 = { 0, 0, 0 },
        .next1 = 1, .next2 = 1, .next3 = -1
    },
    {   // 1. 새내기 배움터 (OT)
        .question = "새내기 배움터(OT) 날이다. 선배들이 술을 짝으로 들고 온다.",
        .choice1 = "분위기에 맞춰 끝까지 마신다.",
        .choice2 = "적당히 마시다가 몰래 빠진다.",
        .choice3 = "술을 못 마신다고 단호하게 거절한다.",
        .result1 = "선배들에게 '에이스'로 찍혔지만, 다음 날 위액을 확인했다.",
        .result2 = "적당히 즐기고 컨디션도 챙겼다. 현명한 선택.",
        .result3 = "분위기가 싸해졌지만, 내 간은 지켜냈다.",
        .stateChange1 = { +20, 0, 0 },
        .stateChange2 = { 0, 0, 0 },
        .stateChange3 = { +10, 0, 0 },
        .next1 = 2, .next2 = 2, .next3 = 2
    },
    {   // 2. 수강신청
        .question = "수강신청 날이다. '일반물리학' 교수님 평점이 극과 극이다.",
        .choice1 = "[학점폭격기] 과제는 많지만 학점은 잘 주는 교수님.",
        .choice2 = "[천사표] 수업은 재밌지만 학점은 짠 교수님.",
        .choice3 = "[패기] 그냥 시간 맞는 아무 강의나 넣는다.",
        .result1 = "한 학기 동안 죽어나겠지만, A+을 노려볼 만하다.",
        .result2 = "수업은 힐링인데 성적표 받을 때 킬링당할 수도 있다.",
        .result3 = "시간표가 테트리스처럼 예쁘게 짜였지만, 내용은 헬게이트다.",
        .stateChange1 = { +15, +20, 0 },
        .stateChange2 = { -10, -5, 0 },
        .stateChange3 = { 0, 0, 0 },
        .next1 = 3, .next2 = 3, .next3 = 3
    },
    {   // 3. 동아리 가입
        .question = "동아리 홍보 기간. 시끄러운 음악 소리가 들린다.",
        .choice1 = "[밴드부] 낭만과 열정의 음악 동아리.",
        .choice2 = "[학술부] 로봇/코딩을 연구하는 학구파.",
        .choice3 = "동아리는 사치다. 집으로 간다.",
        .result1 = "인싸들의 성지에 입성했다. 연습하느라 공부 시간은 뺏길 듯.",
        .result2 = "선배들에게 족보와 코딩 팁을 얻을 수 있다! (너드력 상승)",
        .result3 = "조용하고 평화로운 대학 생활이 예상된다.",
        .stateChange1 = { -5, -10, 0 },
        .stateChange2 = { +5, +15, 0 },
        .stateChange3 = { -5, 0, 0 },
        .next1 = 4, .next2 = 4, .next3 = 4
    },
    {   // 4. 첫 과제
        .question = "미적분학 첫 과제가 나왔다. 문제가 영어로 써있다...",
        .choice1 = "번역기를 돌려가며 밤새 푼다.",
        .choice2 = "동기 거를 베낀다 (Ctrl+C, Ctrl+V).",
        .choice3 = "쿨하게 제출하지 않는다.",
        .result1 = "해 뜨는 걸 보며 완성했다. 뿌듯함과 피로가 동시에 밀려온다.",
        .result2 = "5분 만에 끝냈다. 근데 교수님이 눈치챈 것 같다.",
        .result3 = "F학점의 기운이 스멀스멀 올라온다.",
        .stateChange1 = { +15, +10, 0 },
        .stateChange2 = { -5, -5, 0 },
        .stateChange3 = { 0, -20, 0 },
        .next1 = 5, .next2 = 5, .next3 = 5
    },
    {   // 5. 벚꽃 축제
        .question = "중간고사가 끝난 5월, 축제 기간이다. 캠퍼스가 시끌벅적하다.",
        .choice1 = "주점에서 친구들과 미친 듯이 논다.",
        .choice2 = "축제는 무슨, 도서관 빈자리를 노린다.",
        .choice3 = NULL,
        .result1 = "목이 쉬도록 소리 질렀다. 스트레스가 확 풀린다!",
        .result2 = "축제 소음을 BGM 삼아 공부했다. 독한 놈 소리를 들었다.",
        .result3 = NULL,
        .stateChange1 = { -30, -5, 0 },
        .stateChange2 = { +10, +10, 0 },
        .stateChange3 = { 0, 0, 0 },
        .next1 = 6, .next2 = 6, .next3 = -1
    },
    {   // 6. 썸의 기류 (CC 분기점)
        .question = "자꾸 눈이 마주치는 동기가 있다. 같이 밥 먹자는 연락이 왔다.",
        .choice1 = "이건 그린라이트다. 적극적으로 대시한다.",
        .choice2 = "공대생에게 연애는 사치다. 철벽을 친다.",
        .choice3 = NULL,
        .result1 = "밥 먹고 영화까지 봤다. 핑크빛 기류가 흐른다.",
        .result2 = "상대는 머쓱해하며 떠났다. 나는 고독한 솔로 공학자다.",
        .result3 = NULL,
        .stateChange1 = { -5, 0, 0 }, // 연애 플래그 ON 가능성
        .stateChange2 = { 0, +5, 0 },
        .stateChange3 = { 0, 0, 0 },
        .next1 = 7, .next2 = 8, .next3 = -1 // 7번: 고백이벤트, 8번: 솔로이벤트
    },
    {   // 7. 고백 (연애 루트)
        .question = "늦은 밤, 집 가는 길. 지금이 아니면 기회가 없을 것 같다.",
        .choice1 = "\"나랑... 사귈래?\" 고백한다.",
        .choice2 = "역시 무리다. 친구로 남는다.",
        .choice3 = NULL,
        .result1 = "상대가 웃으며 고개를 끄덕였다! 1일 시작이다. (돈 깨지는 소리)",
        .result2 = "말을 삼켰다. 평생 친구로 남겠지만 가슴은 아리다.",
        .result3 = NULL,
        .stateChange1 = { -10, -10, 1 }, // gf = 1 (커플 달성)
        .stateChange2 = { +5, 0, 0 },
        .stateChange3 = { 0, 0, 0 },
        .next1 = 9, .next2 = 9, .next3 = -1
    },
    {   // 8. 솔로의 다짐 (솔로 루트)
        .question = "커플들이 캠퍼스를 거니는 게 꼴 보기 싫다.",
        .choice1 = "운동이라도 해서 몸을 키운다.",
        .choice2 = "게임으로 현실 도피를 한다.",
        .choice3 = NULL,
        .result1 = "몸이 좋아졌다. 자신감이 조금 붙는다.",
        .result2 = "협곡의 지배자가 되었다. 현실 랭크는 떨어지는 중.",
        .result3 = NULL,
        .stateChange1 = { -5, +2, 0 },
        .stateChange2 = { -10, -5, 0 },
        .stateChange3 = { 0, 0, 0 },
        .next1 = 9, .next2 = 9, .next3 = -1
    },
    {   // 9. 기말고사 기간
        .question = "종강이 코앞이다. 기말고사 범위가 책 전체라고 한다.",
        .choice1 = "카페인 수혈하며 3일 밤샘 벼락치기.",
        .choice2 = "평소 실력대로 본다 (공부 안 함).",
        .choice3 = "선배에게 족보를 구걸한다.",
        .result1 = "시험지 글씨가 춤을 추지만, 답은 다 썼다.",
        .result2 = "시험지를 받자마자 겸허해졌다.",
        .result3 = "족보랑 문제가 완전히 다르다! 교수님이 업그레이드되셨다.",
        .stateChange1 = { +20, +20, 0 },
        .stateChange2 = { -5, -20, 0 },
        .stateChange3 = { +10, -5, 0 },
        .next1 = 10, .next2 = 10, .next3 = 10
    },
    {   // 10. 방학의 시작
        .question = "드디어 종강! 허무하게 지나간 1학기. 방학 계획은?",
        .choice1 = "부족했던 전공 공부를 보충한다.",
        .choice2 = "알바를 해서 용돈을 모은다.",
        .choice3 = "아무것도 안 하고 숨만 쉰다.",
        .result1 = "남들 놀 때 공부했다. 2학기 과탑은 내 거다.",
        .result2 = "통장은 채웠지만 몸은 낡았다.",
        .result3 = "진정한 휴식. 잉여로움이 충전되었다.",
        .stateChange1 = { +5, +20, 0 },
        .stateChange2 = { +10, -5, 0 },
        .stateChange3 = { -20, -5, 0 },
        .next1 = -1, .next2 = -1, .next3 = -1 // 1학년 종료
    },
    // (배열 크기 맞추기용 더미 데이터 - 필요시 추가 가능)
    {.question = NULL, .next1 = -1, .next2 = -1, .next3 = -1 },
    {.question = NULL, .next1 = -1, .next2 = -1, .next3 = -1 },
    {.question = NULL, .next1 = -1, .next2 = -1, .next3 = -1 },
    {.question = NULL, .next1 = -1, .next2 = -1, .next3 = -1 },
    {.question = NULL, .next1 = -1, .next2 = -1, .next3 = -1 },
    {.question = NULL, .next1 = -1, .next2 = -1, .next3 = -1 },
    {.question = NULL, .next1 = -1, .next2 = -1, .next3 = -1 },
    {.question = NULL, .next1 = -1, .next2 = -1, .next3 = -1 },
    {.question = NULL, .next1 = -1, .next2 = -1, .next3 = -1 }
};

#endif