// 1StGradeStory.h
#ifndef EVENTS_Y1_H
#define EVENTS_Y1_H

#include "gamefunc.h"

// [무작위 질문지] : 순서 상관없이 뽑아 쓸 질문들 (5개)
static const Event events_y1_random[5] = {
    {
        .question = "[돌발] 학교 앞 편의점에서 1+1 행사를 한다.",
        .choice1 = "친구 몫까지 사서 나눠준다.",
        .choice2 = "나 혼자 다 먹는다.",
        .choice3 = "돈 아끼게 그냥 안 산다.",
        .stateChange1 = { -5, 0, 0 },
        .stateChange2 = { -2, 0, 0 },
        .stateChange3 = { +2, 0, 0 },
        .next1 = 0, .next2 = 0, .next3 = 0 // 무작위는 next 안 씀
    },
    {
        .question = "[돌발] 선배가 족보를 판다고 한다.",
        .choice1 = "거금을 들여 산다.",
        .choice2 = "실력으로 승부한다.",
        .choice3 = "친구랑 공구한다.",
        .stateChange1 = { +10, +15, 0 },
        .stateChange2 = { 0, +5, 0 },
        .stateChange3 = { +5, +15, 0 },
        .next1 = 0, .next2 = 0, .next3 = 0
    },
    {
        .question = "[돌발] 수강신청 정정 기간이다.",
        .choice1 = "꿀강의를 줍는다.",
        .choice2 = "망한 시간표 그대로 간다.",
        .choice3 = "공강을 만들기 위해 전공을 뺀다.",
        .stateChange1 = { -10, 0, 0 },
        .stateChange2 = { +10, 0, 0 },
        .stateChange3 = { -5, -5, 0 },
        .next1 = 0, .next2 = 0, .next3 = 0
    },
    {
        .question = "[돌발] 과방에 피자가 배달왔다.",
        .choice1 = "가장 먼저 달려가서 먹는다.",
        .choice2 = "눈치 보며 한 조각만 먹는다.",
        .choice3 = "안 먹는다.",
        .stateChange1 = { -5, 0, 0 },
        .stateChange2 = { 0, 0, 0 },
        .stateChange3 = { +5, 0, 0 },
        .next1 = 0, .next2 = 0, .next3 = 0
    },
    {
        .question = "[돌발] 갑작스러운 휴강 문자가 왔다!",
        .choice1 = "PC방으로 달려간다.",
        .choice2 = "기숙사에서 잔다.",
        .choice3 = "도서관에 간다.",
        .stateChange1 = { -10, -5, 0 },
        .stateChange2 = { -15, 0, 0 },
        .stateChange3 = { +5, +5, 0 },
        .next1 = 0, .next2 = 0, .next3 = 0
    }
};

// [고정 질문지] : 순서대로 진행될 메인 스토리 (5개)
static const Event events_y1_fixed[5] = {
    {   // 0번
        .question = "1학년 1학기 개강! 캠퍼스에 벚꽃이 만발했다.",
        .choice1 = "동기들과 사진을 찍으러 간다.",
        .choice2 = "도서관 자리부터 맡는다.",
        .choice3 = "수업 째고 낮술한다.",
        .stateChange1 = { -5, 0, 1 },
        .stateChange2 = { +5, +10, 0 },
        .stateChange3 = { -10, -5, 0 },
        .next1 = 1, .next2 = 1, .next3 = 1 // 다음은 1번으로
    },
    {   // 1번
        .question = "교양 수업에서 조별과제 조가 짜여졌다.",
        .choice1 = "조장을 맡아 하드캐리한다.",
        .choice2 = "묻어가기를 시전한다.",
        .choice3 = "자료조사만 맡는다.",
        .stateChange1 = { +20, +20, 0 },
        .stateChange2 = { -5, -5, 0 },
        .stateChange3 = { +5, +5, 0 },
        .next1 = 2, .next2 = 2, .next3 = 2
    },
    {   // 2번
        .question = "대학 축제 기간! 주점이 열렸다.",
        .choice1 = "주점 알바를 한다.",
        .choice2 = "손님으로 가서 논다.",
        .choice3 = "집에 가서 잔다.",
        .stateChange1 = { +15, +5, 0 },
        .stateChange2 = { -10, -5, 0 },
        .stateChange3 = { -15, 0, 0 },
        .next1 = 3, .next2 = 3, .next3 = 3
    },
    {   // 3번
        .question = "기말고사가 코앞이다. 공부 어떻게 할까?",
        .choice1 = "밤새 에너지드링크 마시며 공부.",
        .choice2 = "중요한 것만 본다.",
        .choice3 = "이번 학기는 포기한다.",
        .stateChange1 = { +20, +20, 0 },
        .stateChange2 = { +5, +10, 0 },
        .stateChange3 = { -10, -20, 0 },
        .next1 = 4, .next2 = 4, .next3 = 4
    },
    {   // 4번 (마지막)
        .question = "드디어 종강! 여름방학 계획은?",
        .choice1 = "알바를 한다.",
        .choice2 = "여행을 간다.",
        .choice3 = "학원에 다닌다.",
        .stateChange1 = { +10, 0, 0 },
        .stateChange2 = { -20, 0, 0 },
        .stateChange3 = { +10, +10, 0 },
        .next1 = -1, .next2 = -1, .next3 = -1 // -1은 종료 신호
    }
};

#endif