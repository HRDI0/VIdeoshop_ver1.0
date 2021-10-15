#ifndef videoshop_h
#define videoshop_h
#include <iostream>
#include <stdlib.h>
#include <string>
#include <fstream>
#include <ctime>
using namespace std;
class video {				// ���� �����ͺ��̽��� �����ϴ� Ŭ����
	friend class Member;	//ȸ���� �뿩, �ݳ��� ���� �����ͺ��̽� ������ ���� ��ġ
private:
	video* v_head;			//ù��° ��带 ����Ű�� ���
	string v_name;			//���� �̸�
	string v_genre;			//���� �帣
	int v_id = 1;			//������ �̸��� ������ �����ϱ� ���� ��ȣ
	int id = 1;				//���� ��ȣ ������ ���� ���� ����
	int v_size = 0;			//�����ͺ��̽� ��ü ũ�⸦ �����ϴ� ����
	video* v_next;			//���� ��带 ����Ű�� �ؽ�Ʈ
public:
	video();
	video(string name, string genre, int id, video* node) {
		v_name = name;
		v_genre = genre;
		v_id = id;
		v_next = node;
	}
	void v_add(string name, string data);	//���� �߰� ���
	void v_search(string name);				//���� �˻� ���
	void v_print();							//���� �����ͺ��̽� ��ü ���
	void v_remove(string name);				//���� ���� ���
	void v_sort();							//���� �����ټ����� �������� ���� ���
	void v_save();							//���� �����ͺ��̽��� �ܺ� ������ġ�� ����
	void v_load(video& v_list);				//���� �����ͺ��̽� ����
	void v_change(string name);				//���� ������ ���� ���
	bool v_name_check(string name);			//�������� ���� ���� �̸� ����ó��
	bool v_genre_check(string genre);		//�������� ���� ���� �帣 ����ó��
	~video();
};

class Member:public video {					//ȸ���� �����ͺ��̽��� �����ϴ� Ŭ����, ����Ŭ������ �Լ��� ����ϱ� ���� video Ŭ���� ���
private: 
	Member* m_head;							//ù��° ��带 ����Ű�� ���
	string m_name;							//ȸ�� �̸�
	string m_number;						//ȸ�� ��ȣ
	string m_video_List[3];					//�뿩 ���� ���
	int m_Overdue[3] = { 0, };				//��ü�Ⱓ ���
	int m_size = 0;							//ȸ�� �����ͺ��̽��� ��ü ũ��
	Member* m_next;							//���� ��带 ����Ű�� �ؽ�Ʈ
public:
	Member();
	Member(string name, string number, Member* node) {
		m_name = name;
		m_number = number;
		m_next = node;
	}
	void m_add(string name, string data);	//ȸ�� �߰� ���
	void m_rental(video* list, string member_name, string video_name);		//���� �뿩 ���
	void m_return(video* list, string member_name, string video_name);		//���� �ݳ� ���
	void m_search(string name);				//ȸ�� �˻� ���
	void m_print();							//ȸ�� ��� ��ü ���
	void m_remove(string name);				//ȸ�� ���� ���
	void m_sort();							//ȸ�� �����ټ����� �������� ����
	void m_save();							//ȸ�� �����ͺ��̽��� �ܺ� ������ġ�� ����
	void m_overdue_save();					//ȸ�� ��ü �����͸� �ܺ� ������ġ�� ����
	void m_load(Member &m_list);			//ȸ�� �����ͺ��̽��� ����
	void m_overdue_load(Member& m_list);	//ȸ�� ��ü ������ ����
	void m_change(string name);				//ȸ�� ���� ���
	bool m_name_check(string name);			//�������� ���� ȸ�� �̸�, �����ι� ����ó��
	bool m_number_check(string number);		//������������ ��ȣ ����ó��
	int overdue_time();						//��ü ������ ������ ���� �ð� ��� �Լ�
	~Member();
};



#endif /* videoshop_hpp */#pragma once