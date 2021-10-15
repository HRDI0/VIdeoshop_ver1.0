#include "videoshop.h"

void v_menu(video v_DB)
{
	string name;		//이름을 입력할 문자열
	string genre;		//장르를 입력할 문자열
	system("cls");
	v_DB.v_load(v_DB);	//저장된 비디오 데이터베이스 열기
	while (true) {
		int choice = 0;
		cout << endl;
		cout << "비디오 대여점 ver 1.0" << endl;
		cout << endl;
		cout << "비디오 메뉴 \n 1. 저장  2. 검색  3. 수정  \n 4. 삭제  5. 목록  6. 내보내기  \n 7. 불러오기  8. 종료 " << endl;
		cout << endl;
		cin >> choice;
		cin.clear();
		cin.ignore(INT_MAX, '\n');		//cin 의 잔류 버퍼 처리
		switch (choice)
		{
		case 1: {						//비디오 추가
			cout << "이름 : ";
			getline(cin,name);
			if (v_DB.v_name_check(name) == false) {
				cout << endl;
				break;
			}

			cout << "장르 : ";
			getline(cin,genre);
			if (v_DB.v_genre_check(genre) == false) {
				cout << endl;
				break;
			}
			v_DB.v_add(name, genre);
			cout << endl;
			cout << "비디오 목록" << endl;
			cout << endl;
			v_DB.v_sort();
			v_DB.v_print();
			cout << endl;
			break;
		}
		case 2: {						//비디오 검색
			cout << endl;
			cout << "검색할 비디오명을 입력하세요. : ";
			getline(cin, name);
			v_DB.v_search(name);
			cout << endl;
			break;
		}
		case 3: {						//비디오 수정
			cout << "수정할 비디오명을 입력하세요. :  " << endl;
			cout << endl;
			getline(cin, name);
			v_DB.v_change(name);
			v_DB.v_sort();
			cout << endl;
			break;
		}
		case 4: {						//비디오 삭제
			v_DB.v_print();
			cout << endl;
			cout << "삭제할 비디오명을 입력하세요. : ";
			getline(cin, name);
			v_DB.v_remove(name);
			cout << endl;
			break;
		}
		case 5: {						//비디오 목록 출력
			v_DB.v_sort();
			cout << endl;
			cout << "비디오 목록" << endl;
			cout << endl;
			v_DB.v_print();
			break;
		}
		case 6: {						//비디오 데이터 베이스를 외부 저장장치에 저장
			v_DB.v_sort();
			v_DB.v_save();
			cout << endl;
			break;
		}
		case 7: {						//외부 저장장치에 비디오 데이터 베이스 열기
			v_DB.v_load(v_DB);
			cout << endl;
			v_DB.v_sort();
			break;
		}
		case 8: {						//프로그램 종료
			v_DB.v_save();
			cout << "프로그램을 종료합니다." << endl;
			cout << endl;
			return;
		}
		default:						//잘못된 입력 예외 처리
		{
			cout << "잘못된 입력입니다." << endl;
			cout << endl;
			break;
		}
		}
	}
}