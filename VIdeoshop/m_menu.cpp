#include "videoshop.h"
void m_menu(video v_DB) {
	string name;						//이름을 입력할 문자열
	string number;						//번호를 입력할 문자열
	string video_name;					//대여할 비디오 이름을 입력할 문자열
	Member m_DB;						//회원 관리 클래스 생성
	v_DB.v_load(v_DB);					//비디오 데이터베이스 활용을 위해 비디오 데이터베이스 열기
	system("cls");
	m_DB.m_load(m_DB);					//저장된 회원 데이터베이스 열기
	while (true) {
		int choice = 0;
		cout << endl;
		cout << "비디오 대여점 ver 1.0" << endl;
		cout << endl;
		cout << "회원 메뉴 \n 1. 저장  2. 검색  3. 수정  \n 4. 삭제  5. 목록  6. 대여  \n 7. 반납  8. 내보내기  9. 불러오기\n10. 종료 " << endl;
		cout << endl;
		cin >> choice;
		cin.clear();
		cin.ignore(INT_MAX, '\n');		//cin의 잔류 버퍼 처리
		switch (choice)
		{
		case 1: {						//회원 추가
			cout << "이름 : ";
			getline(cin, name);
			if (m_DB.m_name_check(name) == false) {
				cout<< endl;
				break;
			}
			cout << "번호 : ";
			cin >> number;
			cin.clear();
			cin.ignore(INT_MAX, '\n');
			if (m_DB.m_number_check(number) == false) {
				cout << endl;
				break;
			}
			m_DB.m_add(name, number);
			cout << endl;
			cout << "회원 목록" << endl;
			cout << endl;
			m_DB.m_sort();
			m_DB.m_print();
			cout << endl;
			break;
		}
		case 2: {						//회원 검색
			cout << endl;
			cout << "검색할 이름을 입력하세요. : ";
			getline(cin, name);
			m_DB.m_search(name);
			cout << endl;
			break;
		}
		case 3: {						//회원 수정
			cout << "수정할 이름을 입력하세요. :  " << endl;
			cout << endl;
			getline(cin, name);
			m_DB.m_change(name);
			m_DB.m_sort();
			cout << endl;
			break;
		}
		case 4: {						//회원 삭제
			m_DB.m_print();
			cout << endl;
			cout << "삭제할 이름을 입력하세요. : ";
			getline(cin, name);
			m_DB.m_remove(name);
			cout << endl;
			break;
		}
		case 5: {						//회원 목록 출력
			m_DB.m_sort();
			cout << endl;
			cout << "회원 목록" << endl;
			cout << endl;
			m_DB.m_print();
			break;
		}
		case 6: {						//비디오 대여
			v_DB.v_print();
			cout << endl;
			cout << "회원이름 : " << endl;
			getline(cin, name);
			cout << endl;
			cout << "대출 비디오명 : " << endl;
			getline(cin, video_name);
			cout << endl;
			m_DB.m_rental(&v_DB,name, video_name);
			v_DB.v_save();
			break;
		}
		case 7: {						//비디오 반납
			cout << endl;
			cout <<"회원이름 : "<< endl;
			getline(cin, name);
			cout << endl;
			cout <<"반납 비디오명 : "<< endl;
			getline(cin, video_name);
			cout << endl;
			m_DB.m_return(&v_DB,name, video_name);
			v_DB.v_save();
			break;
		}
		case 8: {						//회원 데이터베이스 외부 저장장치에 저장
			m_DB.m_sort();
			m_DB.m_save();
			cout << endl;
			break;
		}
		case 9: {						//저장된 회원 데이터베이스 열기	
			m_DB.m_load(m_DB);
			cout << endl;
			m_DB.m_sort();
			break;
		}
		case 10: {						//프로그램 종료
			m_DB.m_save();
			v_DB.v_save();
			cout << "프로그램을 종료합니다." << endl;
			cout << endl;
			return;
		}
		default:{						//잘못된 입력 예외처리
			cout << "잘못된 입력입니다." << endl;
			cout << endl;
			break;
		}
		}
	}
}