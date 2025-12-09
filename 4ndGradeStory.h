#ifndef EVENTS_Y4_H
#define EVENTS_Y4_H

#include "gamefunc.h"

static const Event events[20] = {

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

    {   // 1. 자기소개서 작성
        .question = "자기소개서를 쓰려고 했지만 집중이 안 된다.",
        .choice1 = "하루에 1개씩 꾸준히 쓴다.",
        .choice2 = "오늘도 미룬다.",
        .choice3 = "친구와 스터디를 만들어본다.",
        .stateChange1 = { +10, +20, 0 },
        .stateChange2 = { -10, -15, 0 },
        .stateChange3 = { +5,  +10, 0 },
        .next1 = 2, .next2 = 2, .next3 = 2
    },

    {   // 2. 취업 멘토링
        .question = "취업 멘토링 안내 메시지가 왔다.",
        .choice1 = "멘토링을 신청한다.",
        .choice2 = "참가하지 않는다.",
        .choice3 = "녹화본만 본다.",
        .stateChange1 = { +5,  +15, 0 },
        .stateChange2 = { -5,  -5,  0 },
        .stateChange3 = { 0,   +5,  0 },
        .next1 = 3, .next2 = 3, .next3 = 3
    },

    {   // 3. 졸업프로젝트 리더
        .question = "졸업 프로젝트 리더를 맡아달라는 요청이 왔다.",
        .choice1 = "리더를 맡는다.",
        .choice2 = "맡지 않는다.",
        .choice3 = "공동 리더를 제안한다.",
        .stateChange1 = { +15, +20, 0 },
        .stateChange2 = { -5,  -5,  0 },
        .stateChange3 = { +5,  +10, 0 },
        .next1 = 4, .next2 = 4, .next3 = 4
    },

    {   // 4. 인턴 제안
        .question = "교수님이 인턴 제안을 주셨다.",
        .choice1 = "수락한다.",
        .choice2 = "거절한다.",
        .choice3 = "면담 후 결정한다.",
        .stateChange1 = { +10, +25, 0 },
        .stateChange2 = { -5,  -10, 0 },
        .stateChange3 = { +5,  +10, 0 },
        .next1 = 5, .next2 = 5, .next3 = 5
    },

    {   // 5. CC 커플 문제
        .question = "오래 사귄 CC 커플 관계가 흔들리고 있다.",
        .choice1 = "계속 만난다.",
        .choice2 = "헤어진다.",
        .choice3 = "잠시 시간을 갖는다.",
        .stateChange1 = { +10, -5,  +1 },
        .stateChange2 = { -10, +5, -1 },
        .stateChange3 = { 0,   0,   0 },
        .next1 = 6, .next2 = 6, .next3 = 6
    },

    {   // 6. 추천서 요청
        .question = "취업을 위해 교수님 추천서가 필요할 것 같다.",
        .choice1 = "직접 찾아가 요청한다.",
        .choice2 = "요청하지 않는다.",
        .choice3 = "조교에게 먼저 물어본다.",
        .stateChange1 = { +5,  +15, 0 },
        .stateChange2 = { -5,  0,   0 },
        .stateChange3 = { 0,   +5,  0 },
        .next1 = 7, .next2 = 7, .next3 = 7
    },

    {   // 7. 면접 스터디
        .question = "친구가 면접 스터디 참여를 제안했다.",
        .choice1 = "바로 참여한다.",
        .choice2 = "참여하지 않는다.",
        .choice3 = "첫 모임만 참석해본다.",
        .stateChange1 = { +10, +20, 0 },
        .stateChange2 = { -5,  -5,  0 },
        .stateChange3 = { +5,  +10, 0 },
        .next1 = 8, .next2 = 8, .next3 = 8
    },

    {   // 8. 자격증 마지막 도전
        .question = "자격증 시험의 마지막 접수 기간이다.",
        .choice1 = "신청한다.",
        .choice2 = "포기한다.",
        .choice3 = "난이도를 분석해본다.",
        .stateChange1 = { +10, +20, 0 },
        .stateChange2 = { -5,  -10, 0 },
        .stateChange3 = { +5,  +5,  0 },
        .next1 = 9, .next2 = 9, .next3 = 9
    },

    {   // 9. 졸업 유예
        .question = "졸업을 바로 할지 고민된다.",
        .choice1 = "졸업 유예한다.",
        .choice2 = "바로 졸업한다.",
        .choice3 = "교수님 상담 후 결정한다.",
        .stateChange1 = { +5,  +10, 0 },
        .stateChange2 = { -10, +5,  0 },
        .stateChange3 = { 0,   +10, 0 },
        .next1 = -1, .next2 = -1, .next3 = -1   // 엔딩 구간
    }

            //면접 분기점(대기업 엔딩과 이어짐)

     {   // 10. 면접 – 1차 실무면접
        .question = "실무면접이 시작됐다. 면접관이 질문한다:\n“가장 기억에 남는 프로젝트 경험을 소개해주세요.”",
        .choice1 = "목표-역할-성과를 구조적으로 설명한다.",
        .choice2 = "긴장해서 장황하게 답한다.",
        .choice3 = "에피소드 중심으로 대충 말한다.",
        .stateChange1 = { 0, 0, 0 },
        .stateChange2 = { 0, 0, 0 },
        .stateChange3 = { 0, 0, 0 },
        .next1 = 11, .next2 = -1, .next3 = -1
    },

    {   // 11. 면접 – 꼬리질문
        .question = "면접관이 이어서 질문한다:\n“그 과정에서 가장 어려웠던 점은 무엇이었나요?”",
        .choice1 = "기술적 문제와 해결 과정을 말한다.",
        .choice2 = "문제를 돌려서 대답한다.",
        .choice3 = "팀 갈등을 심각하게 얘기한다.",
        .stateChange1 =  { 0, 0, 0 },
        .stateChange2 =  { 0, 0, 0 },
        .stateChange3 =  { 0, 0, 0 },
        .next1 = 12, .next2 = -1, .next3 = -1
    },

    {   // 12. 면접 – 마지막 한마디
        .question = "면접관이 마지막으로 묻는다:\n“마지막으로 하고 싶은 말이 있나요?”",
        .choice1 = "지원 동기와 포부를 간결하게 어필한다.",
        .choice2 = "준비한 문장을 길게 읽듯 말한다.",
        .choice3 = "감사 인사만 하고 마무리한다.",
        .stateChange1 =  { 0, 0, 0 }
        .stateChange2 =  { 0, 0, 0 }
        .stateChange3 =  { 0, 0, 0 }
        .next1 = 13, .next2 = -1, .next3 = -1   // 면접 끝 
    },

};


#endif