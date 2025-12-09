#ifndef EVENTS_Y4_H
#define EVENTS_Y4_H

#include "gamefunc.h"

static const Event events_y4[13] = {

    // 0~9번 이벤트는 그대로 사용 가능

    {   // 0. 대기업 공채 지원
        .question = "대기업 공채가 시작됐다. 어떻게 할까?",
        .choice1 = "바로 지원서를 제출한다.",
        .choice2 = "지원하지 않는다.",
        .choice3 = "기업 분석부터 해보고 다음에 해본다.",
        .stateChange1 = { +10, +20, 0 },
        .stateChange2 = { -5,  -10, 0 },
        .stateChange3 = { +5,  +5,  0 },
        .next1 = 10, .next2 = 1, .next3 = 1
    },

    // ... (중간 이벤트 1~9번 생략, 내용은 동일하게 유지)

    {   // 9. 졸업 유예
        .question = "졸업을 바로 할지 고민된다.",
        .choice1 = "졸업 유예한다.",
        .choice2 = "바로 졸업한다.",
        .choice3 = "교수님 상담 후 결정한다.",
        .stateChange1 = { +5,  +10, 0 },
        .stateChange2 = { -10, +5,  0 },
        .stateChange3 = { 0,   +10, 0 },
        .next1 = -1, .next2 = -1, .next3 = -1   // 엔딩 구간
    },

    // 🌟 면접 분기점 수정 (따옴표 이스케이프)

    {   // 10. 면접 – 1차 실무면접
        // 따옴표를 \"로 이스케이프하고 줄 바꿈 \n 추가
        .question = "실무면접이 시작됐다. 면접관이 질문한다:\n\"가장 기억에 남는 프로젝트 경험을 소개해주세요.\"",
        .choice1 = "목표-역할-성과를 구조적으로 설명한다.",
        .choice2 = "긴장해서 장황하게 답한다.",
        .choice3 = "에피소드 중심으로 대충 말한다.",
        .stateChange1 = { 0, 0, 0 },
        .stateChange2 = { 0, 0, 0 },
        .stateChange3 = { 0, 0, 0 },
        .next1 = 11, .next2 = -1, .next3 = -1
    },

    {   // 11. 면접 – 꼬리질문
        // 따옴표를 \"로 이스케이프하고 줄 바꿈 \n 추가
        .question = "면접관이 이어서 질문한다:\n\"그 과정에서 가장 어려웠던 점은 무엇이었나요?\"",
        .choice1 = "기술적 문제와 해결 과정을 말한다.",
        .choice2 = "문제를 돌려서 대답한다.",
        .choice3 = "팀 갈등을 심각하게 얘기한다.",
        .stateChange1 = { 0, 0, 0 },
        .stateChange2 = { 0, 0, 0 },
        .stateChange3 = { 0, 0, 0 },
        .next1 = 12, .next2 = -1, .next3 = -1
    },

    {   // 12. 면접 – 마지막 한마디
        // 따옴표를 \"로 이스케이프하고 줄 바꿈 \n 추가
        .question = "면접관이 마지막으로 묻는다:\n\"마지막으로 하고 싶은 말이 있나요?\"",
        .choice1 = "지원 동기와 포부를 간결하게 어필한다.",
        .choice2 = "준비한 문장을 길게 읽듯 말한다.",
        .choice3 = "감사 인사만 하고 마무리한다.",
        .stateChange1 = { 0, 0, 0 },
        .stateChange2 = { 0, 0, 0 },
        .stateChange3 = { 0, 0, 0 },
        .next1 = 13, .next2 = -1, .next3 = -1    // 면접 끝
    },

};

#endif