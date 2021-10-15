#ifndef videoshop_h
#define videoshop_h
#include <iostream>
#include <stdlib.h>
#include <string>
#include <fstream>
#include <ctime>
using namespace std;
class video {				// 비디오 데이터베이스를 관리하는 클래스
	friend class Member;	//회원의 대여, 반납시 비디오 데이터베이스 접근을 위한 조치
private:
	video* v_head;			//첫번째 노드를 가리키는 헤드
	string v_name;			//비디오 이름
	string v_genre;			//비디오 장르
	int v_id = 1;			//동일한 이름의 비디오를 구분하기 위한 번호
	int id = 1;				//비디오 번호 조작을 위한 보조 변수
	int v_size = 0;			//데이터베이스 전체 크기를 저장하는 변수
	video* v_next;			//다음 노드를 가리키는 넥스트
public:
	video();
	video(string name, string genre, int id, video* node) {
		v_name = name;
		v_genre = genre;
		v_id = id;
		v_next = node;
	}
	void v_add(string name, string data);	//비디오 추가 기능
	void v_search(string name);				//비디오 검색 기능
	void v_print();							//비디오 데이터베이스 전체 출력
	void v_remove(string name);				//비디오 삭제 기능
	void v_sort();							//비디오 가나다순으로 오름차순 정렬 기능
	void v_save();							//비디오 데이터베이스를 외부 저장장치에 저장
	void v_load(video& v_list);				//비디오 데이터베이스 열기
	void v_change(string name);				//비디오 데이터 수정 기능
	bool v_name_check(string name);			//적절하지 못한 비디오 이름 에외처리
	bool v_genre_check(string genre);		//적절하지 못한 비디오 장르 예외처리
	~video();
};

class Member:public video {					//회원을 데이터베이스를 관리하는 클래스, 비디오클래스의 함수를 사용하기 위해 video 클래스 상속
private: 
	Member* m_head;							//첫번째 노드를 가리키는 헤드
	string m_name;							//회원 이름
	string m_number;						//회원 번호
	string m_video_List[3];					//대여 비디오 목록
	int m_Overdue[3] = { 0, };				//연체기간 목록
	int m_size = 0;							//회원 데이터베이스의 전체 크기
	Member* m_next;							//다음 노드를 가리키는 넥스트
public:
	Member();
	Member(string name, string number, Member* node) {
		m_name = name;
		m_number = number;
		m_next = node;
	}
	void m_add(string name, string data);	//회원 추가 기능
	void m_rental(video* list, string member_name, string video_name);		//비디오 대여 기능
	void m_return(video* list, string member_name, string video_name);		//비디오 반납 기능
	void m_search(string name);				//회원 검색 기능
	void m_print();							//회원 목록 전체 출력
	void m_remove(string name);				//회원 삭제 기능
	void m_sort();							//회원 가나다순으로 오름차순 정렬
	void m_save();							//회원 데이터베이스를 외부 저장장치에 저장
	void m_overdue_save();					//회원 연체 데이터를 외부 저장장치에 저장
	void m_load(Member &m_list);			//회원 데이터베이스를 열기
	void m_overdue_load(Member& m_list);	//회원 연체 데이터 열기
	void m_change(string name);				//회원 수정 기능
	bool m_name_check(string name);			//적절하지 못한 회원 이름, 동일인물 예외처리
	bool m_number_check(string number);		//적절하지못한 번호 예외처리
	int overdue_time();						//연체 데이터 생성을 위한 시간 계산 함수
	~Member();
};



#endif /* videoshop_hpp */#pragma once