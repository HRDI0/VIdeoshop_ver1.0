#include "videoshop.h"

int Member::overdue_time(){			 //시간 계산 함수
	int o_time = 0;
	o_time = (time(NULL) / 86400);	//1970년 1월 1일 자정부터 지금까지 지난 시간을 1일 단위로 o_time에 입력
	return o_time;					//입력된 시간을 정수형으로 return
}