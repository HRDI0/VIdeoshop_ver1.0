#include "videoshop.h"										//기본 논리와 구성은 비디오 관리 함수와 같습니다. 
															//다른 방식으로 작동되거나 새롭게 작성된 코드만 주석을 달겠습니다.

string video_List[3];										//대여 비디오 목록이 옮겨지는 것을 보조하는 문자열 배열
string overdue_List[3];										//연체 기간 데이터가 옮겨지는 것을 보조하는 문자열 배열

Member::Member() {											//기본 생성자
	m_head = NULL;
	m_next = NULL;
}
void Member::m_add(string name, string data) {				//회원 추가 함수
	
	Member* temp = m_head;
	Member* new_member = new Member(name, data, NULL);
	for (int i = 0; i < 3; i++)
		new_member->m_video_List[i] = video_List[i];		//생성된 노드에 비디오 목록 입력
	for (int i = 0; i < 3; i++)
		new_member->m_Overdue[i] = atoi(overdue_List[i].c_str());		//생성된 노드에 연체기간 목록 입력
	if (m_head == NULL) m_head = new_member;
	else {
		while (true) {
			if (temp->m_next == NULL) {
				temp->m_next = new_member;
				break;
			}
			temp = temp->m_next;
		}
	}
	m_size++;												//회원 목록 전체 크기
}

void Member::m_rental(video* list, string member_name, string video_name) {
															//비디오 대여 함수
	list = list->v_head;									//인자로 전달 받은 비디오 목록 활용
	int i = 0;
	Member* m_temp = m_head;
	if (m_head == NULL) {									//회원 목록이 비었을 때 예외 처리
		cout << "회원 목록이 비어있습니다." << endl;
		return;
	}
	if (list == NULL) {										//비디오 목록이 비었을 때 예외 처리
		cout << "비디오 목록이 비어있습니다." << endl;
		return;
	}
	while (m_temp != NULL) {

		if (m_temp->m_name == member_name) {				//입력받은 이름을 가진 회원 노드 탐색
			while (list != NULL) {
				if (list->v_name == video_name) {			//입력받은 이름을 가진 비디오 노드 탐색
					for (i = 2; i >= 0; i--) {				//데이터 관리의 편의성을 위해 배열의 뒤(마지막 배열)부터 앞(첫번째 배열)으로 탐색
						if (m_temp->m_video_List[i] == "") {
							m_temp->m_video_List[i] = video_name;	//비디오 목록 배열에 비디오 이름 입력
							m_temp->m_Overdue[i] = overdue_time();	//연체 기간 배열에 대여시각 입력
							list->v_name = "대출중" + member_name + video_name;	//대여한 비디오의 이름 변경
							cout << "대출되었습니다." << endl;
							return;
						}
					}
				}
				list = list->v_next;
				if (list == NULL) {							//없는 비디오 요청시 예외 처리
					cout << "해당 비디오가 목록에 없습니다." << endl;
					return;
				}

			} 
		}
		m_temp = m_temp->m_next;
		if (m_temp == NULL) {								//없는 회원 요청시 예외 처리
		cout << "해당 회원이 목록에 없습니다." << endl;
		return;
		}

	}
	
}
void Member::m_return(video *list,string member_name, string video_name) {
	int i = 0;												//비디오 반납 함수
	list = list->v_head;
	Member* m_temp = m_head;
	if (m_head == NULL) {
		cout << "회원 목록이 비어있습니다." << endl;
		return;
	}
	if (list == NULL) {
		cout << "비디오 목록이 비어있습니다." << endl;
		return;
	}
	while (m_temp != NULL) {
															//비디오 목록이 비어있는 경우 예외처리
		if (m_temp->m_video_List[0] != "" && m_temp->m_video_List[1] != "" && m_temp->m_video_List[2] != "") {
			cout << "대여한 비디오가 없습니다." << endl;
			return;
		}
		if (m_temp->m_name == member_name) {
			while (list != NULL) {
				if (list->v_name == "대출중" + member_name + video_name) {	//대여한 비디오는 이름을 변경했기 때문에 변경한 이름을 기준으로 탐색
					for (i = 0; i < 3; i++) {								//반납 할때 목록 탐색은 앞 뒤 상관 없기때문에 첫번째 배열부터 탐색
						if (m_temp->m_video_List[i] == video_name) {
							m_temp->m_video_List[i] = "";					//반납 할 비디오 발견시 대여 목록에서 해당 비디오 이름 삭제
							list->v_name = video_name;						//변경했던 비디오 이름 재설정
							cout << "반납되었습니다." << endl;	
							if (overdue_time() - m_temp->m_Overdue[i] >= 7)	//대여할때 입력했던 시각 - 반납 시각 을 기준으로 연체료 계산
								cout << "연체료는 " << ((overdue_time() - m_temp->m_Overdue[i])-6) *1000<<"원 입니다."<<endl;
							else cout << "연체료는 0원 입니다." << endl;
							return;
						}
					}
				}
				list = list->v_next;
				if (list == NULL) {											//없는 비디오 요청시 예외처리
					cout << "해당 비디오가 대여 목록에 없습니다." << endl;
					return;
				}
			}
		}
		m_temp = m_temp->m_next;
		if (m_temp == NULL) {												//없는 회원 요청시 예외처리
			cout << "해당 회원이 목록에 없습니다." << endl;
			return;
		}
	}
}
void Member::m_search(string name) {										//회원 검색 함수
	Member* temp = m_head;
	if (m_head == NULL) {
		cout << "회원 목록이 비어있습니다." << endl;
		return;
	}
	while (temp != NULL) {

		if (temp->m_name == name) {											//작동 방식은 비디오 검색기능과 동일하다.
			cout << temp->m_name << " " << temp->m_number << endl;
			for(int i =0; i<3;i++)
			cout << temp->m_video_List[i]<< endl;
			return;
		}
		temp = temp->m_next;
	}
	cout << "해당 회원이 목록에 없습니다." << endl;
}
void Member::m_print() {													//회원 목록 출력 함수
	Member* temp = m_head;
	while (true) {
		if (m_head == NULL) break;
		cout << temp->m_name << " " << temp->m_number << endl;
		for (int i = 0; i < 3; i++) {										//비디오 목록 출력과 작동방식은 동일하다.
			cout << temp->m_video_List[i] <<  " ";		
																			//반복문을 활용해 비디오 대역 목록출력
		}
		cout << endl;
		temp = temp->m_next;
		if (temp == NULL) break;
	}
}
void Member::m_remove(string name) {										//회원 삭제 함수
	Member* temp = m_head;
	Member* r_temp = NULL;
	if (m_head == NULL) {
		cout << "회원 목록이 비어있습니다." << endl;
		return;
	}
	while (temp != NULL) {													//비디오 삭제 기능과 작동방식은 동일하다.
		if (temp->m_name == name) {
			for (int i = 0; i < 3; i++) {									//비디오 대여목록에 데이터가 존재하면 삭제 되지 않는다.
				if (temp->m_video_List[i] != "") {
					cout << "반납되지 않은 비디오가 있습니다." << endl;
					return;
				}
			}
			if (temp == m_head) {
				m_head = temp->m_next;
				delete(temp);
			}
			else {
				r_temp->m_next = temp->m_next;
				delete(temp);
			}
			cout << "해당 회원을 삭제했습니다." << endl;
			return;
		}
		r_temp = temp;
		temp = temp->m_next;
	}
	cout << "없는 회원입니다." << endl;
}
void Member::m_change(string name) {										//회원 수정 함수
	string c_name;															//
	string c_number;															//수정할 데이터가 들어갈 문자열
	Member* temp = m_head;
	if (m_head == NULL) {
		cout << "회원 목록이 비어있습니다." << endl;
		return;
	}
	while (temp != NULL) {													//비디오 수정기능과 작동방식은 동일하다.

		if (temp->m_name == name) {
			cout << temp->m_name << " " << temp->m_number << endl;
			cout << "수정할 이름 : ";
			getline(cin, c_name);
			if (m_name_check(c_name) == false) {
				cout << endl;
				break;
			}
			cout << "수정할 번호 : ";
			getline(cin, c_number);
			if (m_number_check(c_number) == false) {
				cout << endl;
				break;
			}
			temp->m_name = c_name;
			temp->m_number = c_number;
			cout << temp->m_name << " " << temp->m_number << endl;
			return;
		}
		temp = temp->m_next;
		if (temp == NULL) {
			cout << "해당 회원은 회원목록에 없습니다." << endl;
			return;
		}
	}
}
void Member::m_sort() {													//회원 정렬 함수
	for (int i = 0; i < m_size; i++) {
		Member* temp = m_head;
		Member* sort = new Member("", "", NULL);
		if (m_head == NULL) {
			cout << "회원 목록이 비어있습니다." << endl;
			return;
		}
		while (m_size) {												//비디오 대여 목록 교환과 연체기간목록 교환을 제외하고 비디오 정렬과 작동방식은 동일하다.
			if (temp->m_next == NULL)break;
			if (temp->m_next->m_name.compare(temp->m_name) < 0) {
				sort->m_name = temp->m_name;
				sort->m_number = temp->m_number;
				for (int i = 0; i < 3; i++) {
					sort->m_video_List[i] = temp->m_video_List[i];
				}
				for (int i = 0; i < 3; i++) {
					sort->m_Overdue[i] = temp->m_Overdue[i];
				}
				temp->m_name = temp->m_next->m_name;
				temp->m_number = temp->m_next->m_number;
				for (int i = 0; i < 3; i++) {
					temp->m_video_List[i] = temp->m_next->m_video_List[i];
				}
				for (int i = 0; i < 3; i++) {
					temp->m_Overdue[i] = temp->m_next->m_Overdue[i];
				}
				temp->m_next->m_name = sort->m_name;
				temp->m_next->m_number = sort->m_number;
				for (int i = 0; i < 3; i++) {
					temp->m_next->m_video_List[i] = sort->m_video_List[i];
				}
				for (int i = 0; i < 3; i++) {
					temp->m_next->m_Overdue[i] = sort->m_Overdue[i];
				}
			}
			temp = temp->m_next;
		}
		delete(sort);
	}
}
void Member::m_save() {													//회원 데이터베이스 저장 함수
	if (m_head == NULL) {
		cout << "회원 목록이 비어있습니다." << endl;
		return;
	}
	Member* temp = m_head;
	ofstream outFile("Member.txt");										//Member.txt 파일 생성 또는 덮어쓰기
	while (temp != NULL) {
		outFile << temp->m_name << "\n" << temp->m_number << "\n";		//데이터 베이스 쓰기
		for (int i = 0; i<3; i++) {										//비디오 대여 목록 쓰기
			outFile << temp->m_video_List[i] << "\n";
		}
		temp = temp->m_next;
	}
	m_overdue_save();													//연체기간 저장 함수 호출
	cout << "Member.txt 파일로 내보냈습니다." << endl;
}
void Member::m_overdue_save() {											//연체 기간 저장 함수
	Member* temp = m_head;
	ofstream outFile("time.txt");										//time.txt 파일 생성 또는 덮어쓰기
	while (temp != NULL) {
		for (int i = 0; i <= 2; i++) {									//반복문 활용 첫번째 데이터부터 입력
			outFile << temp->m_Overdue[i] << "\n";
		}
		temp = temp->m_next;
	}
}
void Member::m_load(Member& m_list) {									//회원 데이터 베이스 열기 함수
	string name;														//
	string data;														//데이터가 입력되고 옮겨질 문자열
	ifstream in("Member.txt");
	if (m_list.m_head != NULL ) {										//이미 파일이 열기 된경우 예외 처리
		cout << "이미 Member.txt 파일이 로드되었습니다." << endl;
		return;
	}
	if (in.is_open()) {
		while (!in.eof()) {												//파일의 끝까지 반복
			getline(in, name, '\n');
			getline(in, data, '\n');
			if (name == "\n" || name == "")break;						//만약 공백이 읽어진다면 반복을 멈춘다.
			for (int i = 0; i < 3; i++) {								//비디오 대여 목록 열기
				getline(in, video_List[i], '\n');
			}
			m_overdue_load(m_list);										//연체기간 열기
			m_list.m_add(name, data);									//입력된 데이터를 회원 추가함수로 추가한다.
		}
		cout << "Member.txt 파일을 불러왔습니다." << endl;
	}
	else {
		cout << "저장된 회원 목록이 없습니다." << endl;
	}
	in.close();
}
void Member::m_overdue_load(Member& m_list){							//연체기간 열기 함수
	ifstream in("time.txt");
	if (in.is_open()) {
			for (int i = 0; i < 3; i++) {
				getline(in, overdue_List[i], '\n');						//보조 연체기간 문자열 배열에 연체기간 데이터베이스 입력
			}
	}
	in.close();
}
bool Member::m_name_check(string name) {								//이름 확인 함수
	Member* temp = m_head;
	if (name == "" || name == " ") {
		cout << "올바른 이름을 입력해주세요." << endl;
		return false;
	}
	while (temp != NULL) {												//동일한 이름을 가진 인물은 이름 뒤에 기호를 추가하도록 유도
		if (temp->m_name == name) {
			cout << "동명이인이 존재합니다. 이름에 구분기호를 넣어주세요." << endl;
			return false;
		}
		temp = temp->m_next;
	}
	return true;
}
bool Member::m_number_check(string number) {							//번호 확인 함수
	if (number == "" || number == " ") {
		cout << "올바른 전화번호를 입력해주세요." << endl;
		return false;
	}
	else if (number.size() == 11) return true;							//공백이거나 11자리가 아니면 예외처리
	else {
		cout << "올바른 전화번호를 입력해주세요." << endl;
		return false;
	}
}

Member::~Member() {														//기본 소멸자
	Member* temp = m_head;
	while (temp != NULL)												//사용이 끝난 노드를 전부 할당 해제한다.
	{
		Member* del = temp;
		temp = temp->m_next;
		delete(del);
	}
	m_head = NULL;
}