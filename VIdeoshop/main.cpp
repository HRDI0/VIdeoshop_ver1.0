#include "videoshop.h"
void v_menu(video v_DB);	//비디오 관리 메뉴
void m_menu(video v_DB);	//회원 관리 메뉴
int main()
{
	video v_DB = video();	//비디오 데이터베이스 활용을 위한 기반
	while (true) {
		int choice = 0;
		cout << endl;
		cout << "비디오 대여점 ver 1.0" << endl;
		cout << endl;
		cout << "1. 비디오 관리메뉴 \t 2. 회원 관리메뉴\t3. 프로그램 종료" << endl;
		cin >> choice;
		cin.clear();
		cin.ignore(INT_MAX, '\n');		//cin의 잔류 버퍼 처리
		switch (choice){

		case 1: {				//비디오 관리 메뉴 진입
			system("cls");
			v_menu(v_DB);
			break;
		}
		case 2: {				//회원 관리 메뉴 진입
			system("cls");
			m_menu(v_DB);
			break;
		}
		case 3: {				//프로그램 종료
			system("cls");
			cout << "프로그램을 종료합니다." << endl;
			return 0;
		}
		default:				//정해진 숫자 외의 입력 예외 처리
			system("cls");
			cout << "잘못된 입력입니다." << endl;
			cout << endl;
			break;
		}
	}
}

