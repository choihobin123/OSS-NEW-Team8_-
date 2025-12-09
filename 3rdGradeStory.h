#ifndef EVENTS_Y3_H
#define EVENTS_Y3_H

#include "gamefunc.h"

// stateChange: { 스트레스, 학업능력, 연애 여부 }
static const Event events_y3[13] = {

    {   // 0. 취업 스터디 제안
        .question = "선배가 취업 스터디를 같이 하자고 제안한다.",
        .choice1 = "취업 준비 제대로 해보자. 주 3회 빡세게 참여한다.",
        .choice2 = "너무 힘들진 않게 주 1회만 나가본다.",
        .choice3 = "난 혼자 하는 게 편하다. 독학 플랜을 짠다.",
        .stateChange1 = { +15, +15, 0 },
        .stateChange2 = { +5, +7, 0 },
        .stateChange3 = { +5, +10, 0 },
        .next1 = 1,
        .next2 = 1,
        .next3 = 1
    },

    {   // 1. 인턴 모집 공고
        .question = "방학 인턴 모집 공고가 올라왔다. 합격하면 스펙과 경험 둘 다 챙길 수 있다.",
        .choice1 = "제대로 준비해서 도전한다!",
        .choice2 = "소규모 회사라도 상관없다. 일단 지원한다.",
        .choice3 = "아직은 준비가 부족하다. 이번엔 넘긴다.",
        .stateChange1 = { +20, +20, 0 },
        .stateChange2 = { +10, +15, 0 },
        .stateChange3 = { 0, +5, 0 },
        .next1 = 2,
        .next2 = 11, // >> 스타트업 인턴 분기
        .next3 = 2
    },

    {   // 2. 자격증 공부
        .question = "자격증이 취업에 도움이 된다는 말을 듣고 고민에 빠졌다.",
        .choice1 = "학원 등록하고 바로 준비 시작!",
        .choice2 = "인강으로 차근차근 독학한다.",
        .choice3 = "자격증보다 수업 성적이 우선이다.",
        .stateChange1 = { +15, +10, 0 },
        .stateChange2 = { +10, +8, 0 },
        .stateChange3 = { -5, +12, 0 },
        .next1 = 3,
        .next2 = 3,
        .next3 = 3
    },

    {   // 3. 팀 프로젝트
        .question = "발표까지 있는 팀 프로젝트가 시작됐다. 성실이 곧 생존이다.",
        .choice1 = "직접 팀장을 맡아 전체 진행을 책임진다.",
        .choice2 = "핵심 작업을 맡아 결과로 보여준다.",
        .choice3 = "최소한만 맡고 조용히 넘어간다.",
        .stateChange1 = { +20, +20, 0 },
        .stateChange2 = { +10, +15, 0 },
        .stateChange3 = { -5, -5, 0 },
        .next1 = 4,
        .next2 = 4,
        .next3 = 4
    },

    {   // 4. 교환학생 설명회
        .question = "국제처에서 교환학생 설명회를 연다.",
        .choice1 = "어학도 준비하며 정식으로 도전한다.",
        .choice2 = "단기 연수 정도만 생각한다.",
        .choice3 = "해외보단 국내 경험이 더 중요하다.",
        .stateChange1 = { +15, +15, 0 },
        .stateChange2 = { +5, +8, 0 },
        .stateChange3 = { 0, +10, 0 },
        .next1 = 5,
        .next2 = 5, 
        .next3 = 5
    },

    {   // 5. 연애 갈등 (연애중일 때만)
        .question = "연인이 요즘 연락이 줄었다며 서운함을 표현한다.",
        .choice1 = "서로의 시간을 맞춰보며 노력한다.",
        .choice2 = "좋게 이야기하고 이별한다.",
        .choice3 = "정리를 미루고 애매하게 유지한다.",
        .stateChange1 = { +10, 0, 0 },
        .stateChange2 = { +15, 0, -1 },
        .stateChange3 = { +20, 0, 0 },
        .next1 = 6,
        .next2 = 6,
        .next3 = 12 // >> 연애 위기 분기
    },

    {   // 6. 학과 세미나
        .question = "교수님이 진로에 도움이 된다며 세미나 참여를 추천했다.",
        .choice1 = "매주 참석하며 깊게 공부해본다.",
        .choice2 = "관심 있는 주제만 골라서 듣는다.",
        .choice3 = "자료만 받아보고 가볍게 넘긴다.",
        .stateChange1 = { +15, +20, 0 },
        .stateChange2 = { +5, +10, 0 },
        .stateChange3 = { 0, +3, 0 },
        .next1 = 7,
        .next2 = 7,
        .next3 = 7
    },

    {   // 7. 대외활동
        .question = "대외활동 팀원을 모집하고 있다.",
        .choice1 = "장기 프로젝트형 활동에 참여한다.",
        .choice2 = "공모전에 나가 경험을 쌓는다.",
        .choice3 = "개인 포트폴리오에 집중한다.",
        .stateChange1 = { +15, +15, 0 },
        .stateChange2 = { +10, +10, 0 },
        .stateChange3 = { 0, +12, 0 },
        .next1 = 8,
        .next2 = 8,
        .next3 = 8
    },

    {   // 8. 알바 병행
        .question = "과제와 알바를 병행하니 체력이 바닥난다.",
        .choice1 = "일단 학업에 집중하기 위해 알바를 그만둔다.",
        .choice2 = "근무 시간을 줄이고 버텨본다.",
        .choice3 = "돈이 더 급하다. 그대로 유지한다.",
        .stateChange1 = { +5, +20, 0 },
        .stateChange2 = { +10, +10, 0 },
        .stateChange3 = { -10, -10, 0 },
        .next1 = 9,
        .next2 = 9,
        .next3 = 9
    },

    {   // 9. 진로 상담
        .question = "졸업이 다가오며 불안감이 커져간다.",
        .choice1 = "진로 상담 센터를 찾아간다.",
        .choice2 = "졸업한 선배에게 조언을 구한다.",
        .choice3 = "인터넷 후기만 보며 혼자 결정한다.",
        .stateChange1 = { +5, +8, 0 },
        .stateChange2 = { +10, +10, 0 },
        .stateChange3 = { 0, -3, 0 },
        .next1 = 10, 
        .next2 = 10,
        .next3 = 10
    },

    {   // 10. 대학원 고민
        .question = "3학년 말, 교수님이 대학원을 추천하며 연구도 잘할 것 같다고 하신다.",
        .choice1 = "긍정적으로 고민해보기로 한다.",
        .choice2 = "취업 준비에 집중해야 한다고 말씀드린다.",
        .choice3 = "모르겠다. 지금은 판단을 미룬다.",
        .stateChange1 = { +5, +10, 0 },
        .stateChange2 = { +5, +5, 0 },
        .stateChange3 = { +3, 0, 0 },
        .next1 = -1,  //4학년으로?
        .next2 = -1,
        .next3 = -1
    },

    // --- 특수 분기 --- //

    {   // 11. [분기] 스타트업 인턴
        .question = "작지만 바쁜 회사에서 인턴을 시작했다. 야근이 일상이다.",
        .choice1 = "끝까지 버티며 경험을 쌓는다.",
        .choice2 = "무리하지 말고 적당히 마무리한다.",
        .choice3 = NULL,
        .stateChange1 = { +25, +30, 0 },
        .stateChange2 = { 0, +5, 0 },
        .stateChange3 = { 0, 0, 0 },
        .next1 = 2,
        .next2 = 2,
        .next3 = -1
    },

    {   // 12. [분기] 연애 위기
        .question = "연락이 줄며 서로 멀어지고 있다.",
        .choice1 = "만나서 솔직하게 대화하고 관계를 정리한다.",
        .choice2 = "연락을 천천히 줄이며 자연스럽게 정리한다.",
        .choice3 = NULL,
        .stateChange1 = { +10, 0, -1 },
        .stateChange2 = { +5, 0, -1 },
        .stateChange3 = { 0, 0, 0 },
        .next1 = -1, //연애 분기는 추후 수정 필요
        .next2 = -1,
        .next3 = -1
    },
};

#endif