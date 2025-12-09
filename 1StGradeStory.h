#ifndef EVENTS_Y1_H
#define EVENTS_Y1_H

#include "gamefunc.h"

// 0 ~ 19 : 총 20개 이벤트
static const Event events_y1[20] = {
    {   // 0. 수능
        .question = "수능을 어떻게 할까?",
        .choice1  = "계획대로 수능을 본다.",
        .choice2  = "수능을 포기하고 다른 길을 고민한다.",
        .choice3  = NULL,
        .stateChange1 = { +15, +20, 0, 0},   // 긴장↑, 성적↑
        .stateChange2 = { -5,  -20, 0, 0 },   // 스트레스는 잠깐 줄지만 성적↓
        .stateChange3 = { 0, 0, 0, 0 },
        .next1 = 1,
        .next2 = 1,
        .next3 = -1
    },
    {   // 1. OT 참여 여부
        .question = "입학 OT가 있는데, 어떻게 할까?",
        .choice1  = "OT에 간다.",
        .choice2  = "OT에 가지 않는다.",
        .choice3  = NULL,
        .stateChange1 = { +5,  0, 0, 0 },   // 낯가림+긴장
        .stateChange2 = { -5,  0, 0 , 0},   // 마음은 편하지만 인맥 기회↓
        .stateChange3 = { 0, 0, 0, 0 },
        .next1 = 2,
        .next2 = 2,
        .next3 = -1
    },
    {   // 2. OT에서의 태도
        .question = "OT 현장, 어떤 태도로 있을까?",
        .choice1  = "옆 사람에게 먼저 말을 건다.",
        .choice2  = "구석에서 휴대폰만 본다.",
        .choice3  = "스태프를 도우며 열심히 움직인다.",
        .stateChange1 = { +10, 0, 0, 0 },   // 긴장되지만 관계 기회↑
        .stateChange2 = { -5,  0, 0, 0 },   // 편하지만 관계 기회↓
        .stateChange3 = { +8, +2, 0, 0 },   // 약간의 스트레스+경험
        .next1 = 3,
        .next2 = 3,
        .next3 = 3
    },
    {   // 3. 동아리 면접
        .question = "관심 있는 동아리가 있다. 어떻게 할까?",
        .choice1  = "지원해서 면접을 본다.",
        .choice2  = "이번 학기는 쉬고 지원하지 않는다.",
        .choice3  = NULL,
        .stateChange1 = { +10, +5, 0, 0 },  // 준비 스트레스+경험/실력
        .stateChange2 = { -5,  0, 0, 0 },
        .stateChange3 = { 0, 0, 0, 0 },
        .next1 = 4,
        .next2 = 4,
        .next3 = -1
    },
    {   // 4. 동아리 활동 스타일
        .question = "동아리에 들어갔다. 어떤 스타일로 활동할까?",
        .choice1  = "정모와 스터디를 빠지지 않고 나간다.",
        .choice2  = "바쁠 때만 빼고 적당히 나간다.",
        .choice3  = "처음만 나가고 거의 나가지 않는다.",
        .stateChange1 = { +10, +10, 0, 0 },
        .stateChange2 = { +3,  +3, 0, 0 },
        .stateChange3 = { -2,  0,  0, 0 },
        .next1 = 5,
        .next2 = 5,
        .next3 = 5
    },
    {   // 5. MT 참여
        .question = "동아리 MT에 간다고 한다. 어떻게 할까?",
        .choice1  = "MT에 참가해서 사람들과 친해진다.",
        .choice2  = "공부를 이유로 MT를 가지 않는다.",
        .choice3  = NULL,
        .stateChange1 = { -5,  0, 0, 0 },   // 스트레스↓, 대신 피곤은 나중에…
        .stateChange2 = { +5, +5, 0, 0 },   // 스트레스↑지만 공부 시간↑
        .stateChange3 = { 0, 0, 0, 0 },
        .next1 = 6,
        .next2 = 6,
        .next3 = -1
    },
    {   // 6. 새내기 과제
        .question = "첫 과제가 나왔다. 언제 시작할까?",
        .choice1  = "바로 계획을 세우고 미리 시작한다.",
        .choice2  = "마감 직전에 몰아서 한다.",
        .choice3  = NULL,
        .stateChange1 = { -5, +15, 0, 0 },
        .stateChange2 = { +15, -5,  0, 0 },
        .stateChange3 = { 0, 0, 0, 0 },
        .next1 = 7,
        .next2 = 7,
        .next3 = -1
    },
    {   // 7. 첫 공강
        .question = "첫 공강 시간이 생겼다. 어떻게 쓸까?",
        .choice1  = "도서관에서 예습과 복습을 한다.",
        .choice2  = "학생식당이나 휴게실에서 낮잠 잔다.",
        .choice3  = "카페에서 친구와 수다 떨며 쉰다.",
        .stateChange1 = { +3, +10, 0, 0 },
        .stateChange2 = { -5, -3,  0, 0 },
        .stateChange3 = { -3, 0,   0, 0 },
        .next1 = 8,
        .next2 = 8,
        .next3 = 8
    },
    {   // 8. 교양 발표
        .question = "교양 수업에서 발표자를 모집한다.",
        .choice1  = "손을 들고 자발적으로 발표를 맡는다.",
        .choice2  = "눈을 피하며 조용히 있는다.",
        .choice3  = "친한 친구와 함께 팀 발표를 제안한다.",
        .stateChange1 = { +15, +5, 0, 0 },
        .stateChange2 = { -3,  0,  0, 0 },
        .stateChange3 = { +8, +3, 0, 0 },
        .next1 = 9,
        .next2 = 9,
        .next3 = 9
    },
    {   // 9. 친구 모임
        .question = "같은 과 친구들이 모임에 나가자고 한다.",
        .choice1  = "나가서 같이 놀며 친해진다.",
        .choice2  = "과제 핑계를 대고 거절한다.",
        .choice3  = NULL,
        .stateChange1 = { -8,  0, 0, 0 },
        .stateChange2 = { +5, +5, 0, 0 },
        .stateChange3 = { 0, 0, 0, 0 },
        .next1 = 10,
        .next2 = 10,
        .next3 = -1
    },
    {   // 10. 과잠
        .question = "과잠을 맞춘다고 한다. 어떻게 할까?",
        .choice1  = "과잠을 사서 함께 맞춰 입는다.",
        .choice2  = "돈 아낀다고 안 산다.",
        .choice3  = NULL,
        .stateChange1 = { -2, 0, 0, 0 },
        .stateChange2 = { 0,  0, 0, 0 },
        .stateChange3 = { 0, 0, 0, 0 },
        .next1 = 11,
        .next2 = 11,
        .next3 = -1
    },
    {   // 11. CC 고백
        .question = "마음에 드는 동기가 생겼다. 고백할까?",
        .choice1  = "용기내서 직접 고백한다.",
        .choice2  = "친구로만 지내자며 마음을 접는다.",
        .choice3  = NULL,
        .stateChange1 = { +20, 0, +1, 0 },  // 성공했다고 가정하거나, 이후 이벤트에서 판정 가능
        .stateChange2 = { -5,  0,  0, 0 },
        .stateChange3 = { 0, 0, 0, 0 },
        .next1 = 12,
        .next2 = 13,   // 고백 안 하면 바로 13으로(다른 루트)
        .next3 = -1
    },
    {   // 12. CC와 시험기간
        .question = "CC가 된 뒤 시험 기간이 다가온다.",
        .choice1  = "공부 시간 확보하자고 솔직하게 말한다.",
        .choice2  = "눈치 보여서 계속 같이 논다.",
        .choice3  = NULL,
        .stateChange1 = { +5,  +10, 0, 0 },
        .stateChange2 = { +15,  -5, 0, 0 },
        .stateChange3 = { 0, 0, 0, 0 },
        .next1 = 14,
        .next2 = 14,
        .next3 = -1
    },
    {   // 13. 솔로 루트 / 사람 관계
        .question = "솔로인 채로 학기가 흘러간다. 사람들과의 관계는?",
        .choice1  = "친구들과 더 자주 어울리며 지낸다.",
        .choice2  = "혼자가 편해서 대부분 혼자 다닌다.",
        .choice3  = NULL,
        .stateChange1 = { -5,  0, 0, 0 },
        .stateChange2 = { -2, +2, 0, 0 },
        .stateChange3 = { 0, 0, 0, 0 },
        .next1 = 14,
        .next2 = 14,
        .next3 = -1
    },
    {   // 14. 알바 시작
        .question = "생활비가 부족해졌다. 알바를 할까?",
        .choice1  = "카페 알바를 시작한다.",
        .choice2  = "부모님께 지원을 조금 더 부탁한다.",
        .choice3  = NULL,
        .stateChange1 = { +15, -5, 0, 0 },
        .stateChange2 = { +5,  0,  0, 0 },
        .stateChange3 = { 0, 0, 0, 0 },
        .next1 = 15,
        .next2 = 15,
        .next3 = -1
    },
    {   // 15. 시험 기간 알바 스케줄
        .question = "시험 기간인데 사장님이 근무를 늘려달라고 한다.",
        .choice1  = "정중하게 거절하고 공부에 집중한다.",
        .choice2  = "돈이 필요해 어쩔 수 없이 근무를 늘린다.",
        .choice3  = NULL,
        .stateChange1 = { +5,  +15, 0, 0 },
        .stateChange2 = { +20, -10, 0, 0 },
        .stateChange3 = { 0, 0, 0, 0 },
        .next1 = 16,
        .next2 = 16,
        .next3 = -1
    },
    {   // 16. 방학 계획
        .question = "방학이 다가온다. 방학을 어떻게 보낼까?",
        .choice1  = "전공 기초 과목을 선행 학습한다.",
        .choice2  = "쉬면서 취미 위주로 보낸다.",
        .choice3  = "알바를 더 늘려서 돈을 모은다.",
        .stateChange1 = { +5,  +20, 0, 0 },
        .stateChange2 = { -5, -2,  0, 0 },
        .stateChange3 = { +10, -5,  0, 0 },
        .next1 = 17,
        .next2 = 17,
        .next3 = 17
    },
    {   // 17. 컨디션 관리
        .question = "기말 직전, 몸이 살짝 안 좋은 느낌이 든다.",
        .choice1  = "하루 쉬면서 컨디션을 회복한다.",
        .choice2  = "버티면서 공부를 계속한다.",
        .choice3  = NULL,
        .stateChange1 = { -10, +5, 0, 0 },
        .stateChange2 = { +15, +10,0, 0 },
        .stateChange3 = { 0, 0, 0, 0 },
        .next1 = 18,
        .next2 = 18,
        .next3 = -1
    },
    {   // 18. 멘토 상담
        .question = "선배가 멘토링을 해주겠다고 한다. 어떻게 할까?",
        .choice1  = "선배를 만나 진로와 공부법을 물어본다.",
        .choice2  = "귀찮아서 나중으로 미룬다.",
        .choice3  = NULL,
        .stateChange1 = { -5, +10, 0, 0 },
        .stateChange2 = { 0,  -2,  0, 0 },
        .stateChange3 = { 0, 0, 0, 0 },
        .next1 = 19,
        .next2 = 19,
        .next3 = -1
    },
    {   // 19. 한 학기 회고 (엔딩 직전)
        .question = "1학기를 돌아보며, 앞으로의 루틴을 어떻게 정리할까?",
        .choice1  = "공부·관계·휴식을 균형 있게 유지하는 루틴을 만든다.",
        .choice2  = "굳이 정리하지 않고 대충 흘러가는 대로 둔다.",
        .choice3  = NULL,
        .stateChange1 = { -5, +10, 0, 0 },
        .stateChange2 = { 0,   0,  0, 0 },
        .stateChange3 = { 0, 0, 0, 0 },
        .next1 = -1,   // 여기서 엔딩으로
        .next2 = -1,
        .next3 = -1
    },
};

#endif