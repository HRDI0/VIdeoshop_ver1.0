#include "videoshop.h"

int Member::overdue_time(){			 //�ð� ��� �Լ�
	int o_time = 0;
	o_time = (time(NULL) / 86400);	//1970�� 1�� 1�� �������� ���ݱ��� ���� �ð��� 1�� ������ o_time�� �Է�
	return o_time;					//�Էµ� �ð��� ���������� return
}