#include <stdio.h>
#include "gamefunc.h"
#include "militaryEvent.h"
#include "1StGradeStory.h"
#include "2ndGradeStory.h" 
#include "3rdGradeStory.h" 
#include "4ndGradeStory.h" 

int main() {

    State st = { 0, 0, 0, 0, 0 };  // stress, skill, gf, badFlag, proFlag
    int current = 100;  

    printf("==== 대학교 생활 시뮬레이션 시작 ====\n");

    // 1학년 스토리 진행 (20개 이벤트)
    int nextId = runYearEvents(events_y1, 20, &st, 0); 

    // 2학년 스토리 진행 (14개 이벤트)
    nextId = runYearEvents(events_y2, 18, &st, 0); 

    // 3학년 스토리 진행 (13개 이벤트)
    nextId = runYearEvents(events_y3, 13, &st, 0); 

    // 4학년 로직은 현재 파일에 없으므로, 3학년 종료 후 바로 엔딩으로 간다고 가정

    // TODO: 군대/졸업/취업/대학원 등 엔딩 분기 로직 필요
    // 현재는 학년 스토리 종료 후 바로 엔딩 출력

    printEnding(&st);

    return 0;
}
