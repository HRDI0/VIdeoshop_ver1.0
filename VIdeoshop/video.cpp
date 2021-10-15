#include "videoshop.h"

video::video() {												//기본 생성자
	v_head = NULL;
	v_next = NULL;
}
void video::v_add(string name, string data) {					//비디오 추가 함수
	
	video* temp = v_head;										//temp가 헤드노드를 가리키도록 함
	video* new_video = new video(name, data, v_id, NULL);		//입력받은 문자열을 입력한 비디오 클래스 생성
	if (v_head == NULL) v_head = new_video;						//헤드노드가 비어있다면 생성된 노드가 헤드노드가 된다.
	else {
		while (true) {
			if (temp->v_next == NULL) {							//빈 공간에 노드를 연결
				temp->v_next = new_video;
				break;
			}
			temp = temp->v_next;
		}
	}
	v_size++;													//비디오 전체 크기
	for (id; id <= v_id; id++);									//만약 비디오 번호중 같은 번호나 더 큰 번호가 있다면 보조 번호 증가
	v_id = id;													//비디오 번호를 보조번호로 초기화
}
void video::v_search(string name) {								//비디오 검색 함수
	video* temp = v_head;
	if (v_head == NULL) {										//비디오 목록이 비었는지 확인
		cout << "비디오 목록이 비어있습니다." << endl;
		return;
	}
	while (temp != NULL) {

		if (temp->v_name == name) {								//비디오 목록에서 입력받은 이름 검색
			cout << temp->v_name <<" "<< temp->v_genre << " " << temp->v_id << endl;
			return;
		}
		temp = temp->v_next;
	}
	cout << "해당 비디오가 비디오 목록에 없습니다." << endl;	//없는 비디오 예외처리
}
void video::v_print() {											//비디오 목록 출력 함수
	video* temp = v_head;
	while (true) {
		if (v_head == NULL) break;
		cout << temp->v_name << " " << temp->v_genre << " " << temp->v_id << endl;
		temp = temp->v_next;
		if (temp == NULL) break;
	}
}
void video::v_remove(string name) {								//비디오 삭제
	video* temp = v_head;
	video* r_temp = NULL;
	if (v_head == NULL) {
		cout << "비디오 목록이 비어있습니다." << endl;
		return;
	}
	while (temp != NULL) {

		if (temp->v_name == name) {								//삭제한 노드가 헤드노드일 경우 다음 노드가 헤드노드가 되고 전 헤드노드는 삭제된다.
			if (temp == v_head) {
				v_head = temp->v_next;
				delete(temp);
			}
			else {												//삭제할 노드 발견시 다음 노드가 해당 노드 대신 연결되고 해당 노드는 삭제된다.
				r_temp->v_next = temp->v_next;
				delete(temp);
			}
			cout << "해당 비디오를 삭제했습니다." << endl;
			return;
		}
		r_temp = temp;
		temp = temp->v_next;
	}
	cout << "없는 비디오입니다." << endl;						//없는 비디오 삭제요청시 예외처리
}
void video::v_sort() {											//비디오 정렬 함수
	for (int i = 0; i < v_size; i++) {							//비디오 데이터베이스 전체 크기만큼 반복
		video* temp = v_head;
		video* sort = new video("NULL", "NULL", 0, NULL);
		if (v_head == NULL) {
			cout << "비디오 목록이 비어있습니다." << endl;
			return;
		}
		while (v_size) {										//현재 가리키는 노드의 다음노드와 다음다음 노드를 비교하고 오름차순 정렬
			if (temp->v_next == NULL)break;
			if (temp->v_next->v_name.compare(temp->v_name) < 0) {	//만약 다음다음 노드가 다음노드보다 가나다순으로 앞이라면 두 노드의 데이터를 맞바꾼다.
				sort->v_name = temp->v_name;
				sort->v_genre = temp->v_genre;
				sort->v_id = temp->v_id;
				temp->v_name = temp->v_next->v_name;
				temp->v_genre = temp->v_next->v_genre;
				temp->v_id = temp->v_next->v_id;
				temp->v_next->v_name = sort->v_name;
				temp->v_next->v_genre = sort->v_genre;
				temp->v_next->v_id = sort->v_id;
			}
			temp = temp->v_next;
		}
		delete(sort);
	}
}

void video::v_change(string name) {								//비디오 수정 함수
	string c_name;												//
	string c_genre;												//수정할 데이터가 들어갈 문자열
	video* temp = v_head;
	if (v_head == NULL) {
		cout << "비디오 목록이 비어있습니다." << endl;
		return;
	}
	while (temp != NULL) {

		if (temp->v_name == name) {								//수정할 노드를 찾고 해당 노드의 데이터 변경
			cout << temp->v_name << " " << temp->v_genre<<" "<<temp->v_id << endl;
			cout << "수정할 이름 : ";
			getline(cin, c_name);
			if (v_name_check(c_name) == false) {
				cout << endl;
				break;
			}
			cout << "수정할 장르 : ";
			getline(cin, c_genre);
			if (v_genre_check(c_genre) == false) {
				cout << endl;
				break;
			}
			temp->v_name = c_name;
			temp->v_genre = c_genre;
			cout << temp->v_name << " " << temp->v_genre << " " << temp->v_id << endl;
			return;
		}
		temp = temp->v_next;
		if (temp == NULL) {										//없는 비디오 수정요청시 예외 처리
			cout << "해당 비디오는 비디오목록에 없습니다." << endl;
			return;
		}
	}
}
void video::v_save() {											//비디오 외부 저장장치로 저장 함수
	if (v_head == NULL) {
		cout << "비디오 목록이 비어있습니다." << endl;
		return;
	}
	video* temp = v_head;
	ofstream outFile("video shop.txt");							//실행 폴더에 video shop.txt 파일 생성
	while (temp != NULL) {										//video shop.txt 파일에 데이터베이스 입력
		outFile << temp->v_name <<"\n"<< temp->v_genre<<"\n"<<temp->v_id <<"\n";
		temp = temp->v_next;
	}
	cout << "video shop.txt 파일로 내보냈습니다." << endl;
	outFile.close();
}
void video::v_load(video &v_list) {								//비디오 데이터 베이스 열기 함수
	string name;												//
	string data;												//데이터가 저장될 변수들
	string id;													//
	string v_id;												//
	ifstream in("video shop.txt");
	if (in.is_open()) {
		if (v_list.v_head != NULL) {							//파일이 이미 열기되었을때 예외처리
			cout << "이미 video shop.txt 파일이 로드되었습니다." << endl;
			return;
		}
		while (!in.eof()) {										//파일이 끝날때까지 반복
			
			getline(in, name,'\n');
			getline(in, data,'\n');
			getline(in, id,'\n');
			if (name == "\n" || name == "")break;				//만약 공백이 읽어진다면 반복을 멈춘다.
			v_list.v_id = atoi(id.c_str());						//입력받은 비디오 번호를 노드에 입력
			v_list.v_add(name, data);							//입력받은 데이터를 노드에 추가
			cout << name <<" "<< data << " " << id << endl;		//입력된 데이터 출력
			
		}
		cout << "video shop.txt 파일을 불러왔습니다." << endl;
	}
	else {														//파일일 존재하지 않을때 예외처리
		cout << "저장된 비디오 목록이 없습니다." << endl;
	}
	in.close();
	return;
}
bool video::v_name_check(string name) {							//이름 확인 함수
	if (name == "" || name == " ") {
		cout << "올바른 이름을 입력해주세요." << endl;
		return false;
	}
	else return true;
}
bool video::v_genre_check(string genre) {						//장르 확인 함수
	if (genre == "" || genre == " ") {
		cout << "올바른 장르를 입력해주세요." << endl;
		return false;
	}
	else return true;
}
video::~video() {												//기본 소멸자
	video* temp = v_head;
	while (temp != NULL)
	{
		video* del = temp;
		temp = temp->v_next;
		delete(del);											//사용이 끝난 노드를 전부 할당 해제한다.
	}
	v_head = NULL;
}
