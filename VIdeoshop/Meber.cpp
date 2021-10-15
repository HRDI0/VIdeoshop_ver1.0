#include "videoshop.h"										//�⺻ ���� ������ ���� ���� �Լ��� �����ϴ�. 
															//�ٸ� ������� �۵��ǰų� ���Ӱ� �ۼ��� �ڵ常 �ּ��� �ްڽ��ϴ�.

string video_List[3];										//�뿩 ���� ����� �Ű����� ���� �����ϴ� ���ڿ� �迭
string overdue_List[3];										//��ü �Ⱓ �����Ͱ� �Ű����� ���� �����ϴ� ���ڿ� �迭

Member::Member() {											//�⺻ ������
	m_head = NULL;
	m_next = NULL;
}
void Member::m_add(string name, string data) {				//ȸ�� �߰� �Լ�
	
	Member* temp = m_head;
	Member* new_member = new Member(name, data, NULL);
	for (int i = 0; i < 3; i++)
		new_member->m_video_List[i] = video_List[i];		//������ ��忡 ���� ��� �Է�
	for (int i = 0; i < 3; i++)
		new_member->m_Overdue[i] = atoi(overdue_List[i].c_str());		//������ ��忡 ��ü�Ⱓ ��� �Է�
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
	m_size++;												//ȸ�� ��� ��ü ũ��
}

void Member::m_rental(video* list, string member_name, string video_name) {
															//���� �뿩 �Լ�
	list = list->v_head;									//���ڷ� ���� ���� ���� ��� Ȱ��
	int i = 0;
	Member* m_temp = m_head;
	if (m_head == NULL) {									//ȸ�� ����� ����� �� ���� ó��
		cout << "ȸ�� ����� ����ֽ��ϴ�." << endl;
		return;
	}
	if (list == NULL) {										//���� ����� ����� �� ���� ó��
		cout << "���� ����� ����ֽ��ϴ�." << endl;
		return;
	}
	while (m_temp != NULL) {

		if (m_temp->m_name == member_name) {				//�Է¹��� �̸��� ���� ȸ�� ��� Ž��
			while (list != NULL) {
				if (list->v_name == video_name) {			//�Է¹��� �̸��� ���� ���� ��� Ž��
					for (i = 2; i >= 0; i--) {				//������ ������ ���Ǽ��� ���� �迭�� ��(������ �迭)���� ��(ù��° �迭)���� Ž��
						if (m_temp->m_video_List[i] == "") {
							m_temp->m_video_List[i] = video_name;	//���� ��� �迭�� ���� �̸� �Է�
							m_temp->m_Overdue[i] = overdue_time();	//��ü �Ⱓ �迭�� �뿩�ð� �Է�
							list->v_name = "������" + member_name + video_name;	//�뿩�� ������ �̸� ����
							cout << "����Ǿ����ϴ�." << endl;
							return;
						}
					}
				}
				list = list->v_next;
				if (list == NULL) {							//���� ���� ��û�� ���� ó��
					cout << "�ش� ������ ��Ͽ� �����ϴ�." << endl;
					return;
				}

			} 
		}
		m_temp = m_temp->m_next;
		if (m_temp == NULL) {								//���� ȸ�� ��û�� ���� ó��
		cout << "�ش� ȸ���� ��Ͽ� �����ϴ�." << endl;
		return;
		}

	}
	
}
void Member::m_return(video *list,string member_name, string video_name) {
	int i = 0;												//���� �ݳ� �Լ�
	list = list->v_head;
	Member* m_temp = m_head;
	if (m_head == NULL) {
		cout << "ȸ�� ����� ����ֽ��ϴ�." << endl;
		return;
	}
	if (list == NULL) {
		cout << "���� ����� ����ֽ��ϴ�." << endl;
		return;
	}
	while (m_temp != NULL) {
															//���� ����� ����ִ� ��� ����ó��
		if (m_temp->m_video_List[0] != "" && m_temp->m_video_List[1] != "" && m_temp->m_video_List[2] != "") {
			cout << "�뿩�� ������ �����ϴ�." << endl;
			return;
		}
		if (m_temp->m_name == member_name) {
			while (list != NULL) {
				if (list->v_name == "������" + member_name + video_name) {	//�뿩�� ������ �̸��� �����߱� ������ ������ �̸��� �������� Ž��
					for (i = 0; i < 3; i++) {								//�ݳ� �Ҷ� ��� Ž���� �� �� ��� ���⶧���� ù��° �迭���� Ž��
						if (m_temp->m_video_List[i] == video_name) {
							m_temp->m_video_List[i] = "";					//�ݳ� �� ���� �߽߰� �뿩 ��Ͽ��� �ش� ���� �̸� ����
							list->v_name = video_name;						//�����ߴ� ���� �̸� �缳��
							cout << "�ݳ��Ǿ����ϴ�." << endl;	
							if (overdue_time() - m_temp->m_Overdue[i] >= 7)	//�뿩�Ҷ� �Է��ߴ� �ð� - �ݳ� �ð� �� �������� ��ü�� ���
								cout << "��ü��� " << ((overdue_time() - m_temp->m_Overdue[i])-6) *1000<<"�� �Դϴ�."<<endl;
							else cout << "��ü��� 0�� �Դϴ�." << endl;
							return;
						}
					}
				}
				list = list->v_next;
				if (list == NULL) {											//���� ���� ��û�� ����ó��
					cout << "�ش� ������ �뿩 ��Ͽ� �����ϴ�." << endl;
					return;
				}
			}
		}
		m_temp = m_temp->m_next;
		if (m_temp == NULL) {												//���� ȸ�� ��û�� ����ó��
			cout << "�ش� ȸ���� ��Ͽ� �����ϴ�." << endl;
			return;
		}
	}
}
void Member::m_search(string name) {										//ȸ�� �˻� �Լ�
	Member* temp = m_head;
	if (m_head == NULL) {
		cout << "ȸ�� ����� ����ֽ��ϴ�." << endl;
		return;
	}
	while (temp != NULL) {

		if (temp->m_name == name) {											//�۵� ����� ���� �˻���ɰ� �����ϴ�.
			cout << temp->m_name << " " << temp->m_number << endl;
			for(int i =0; i<3;i++)
			cout << temp->m_video_List[i]<< endl;
			return;
		}
		temp = temp->m_next;
	}
	cout << "�ش� ȸ���� ��Ͽ� �����ϴ�." << endl;
}
void Member::m_print() {													//ȸ�� ��� ��� �Լ�
	Member* temp = m_head;
	while (true) {
		if (m_head == NULL) break;
		cout << temp->m_name << " " << temp->m_number << endl;
		for (int i = 0; i < 3; i++) {										//���� ��� ��°� �۵������ �����ϴ�.
			cout << temp->m_video_List[i] <<  " ";		
																			//�ݺ����� Ȱ���� ���� �뿪 ������
		}
		cout << endl;
		temp = temp->m_next;
		if (temp == NULL) break;
	}
}
void Member::m_remove(string name) {										//ȸ�� ���� �Լ�
	Member* temp = m_head;
	Member* r_temp = NULL;
	if (m_head == NULL) {
		cout << "ȸ�� ����� ����ֽ��ϴ�." << endl;
		return;
	}
	while (temp != NULL) {													//���� ���� ��ɰ� �۵������ �����ϴ�.
		if (temp->m_name == name) {
			for (int i = 0; i < 3; i++) {									//���� �뿩��Ͽ� �����Ͱ� �����ϸ� ���� ���� �ʴ´�.
				if (temp->m_video_List[i] != "") {
					cout << "�ݳ����� ���� ������ �ֽ��ϴ�." << endl;
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
			cout << "�ش� ȸ���� �����߽��ϴ�." << endl;
			return;
		}
		r_temp = temp;
		temp = temp->m_next;
	}
	cout << "���� ȸ���Դϴ�." << endl;
}
void Member::m_change(string name) {										//ȸ�� ���� �Լ�
	string c_name;															//
	string c_number;															//������ �����Ͱ� �� ���ڿ�
	Member* temp = m_head;
	if (m_head == NULL) {
		cout << "ȸ�� ����� ����ֽ��ϴ�." << endl;
		return;
	}
	while (temp != NULL) {													//���� ������ɰ� �۵������ �����ϴ�.

		if (temp->m_name == name) {
			cout << temp->m_name << " " << temp->m_number << endl;
			cout << "������ �̸� : ";
			getline(cin, c_name);
			if (m_name_check(c_name) == false) {
				cout << endl;
				break;
			}
			cout << "������ ��ȣ : ";
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
			cout << "�ش� ȸ���� ȸ����Ͽ� �����ϴ�." << endl;
			return;
		}
	}
}
void Member::m_sort() {													//ȸ�� ���� �Լ�
	for (int i = 0; i < m_size; i++) {
		Member* temp = m_head;
		Member* sort = new Member("", "", NULL);
		if (m_head == NULL) {
			cout << "ȸ�� ����� ����ֽ��ϴ�." << endl;
			return;
		}
		while (m_size) {												//���� �뿩 ��� ��ȯ�� ��ü�Ⱓ��� ��ȯ�� �����ϰ� ���� ���İ� �۵������ �����ϴ�.
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
void Member::m_save() {													//ȸ�� �����ͺ��̽� ���� �Լ�
	if (m_head == NULL) {
		cout << "ȸ�� ����� ����ֽ��ϴ�." << endl;
		return;
	}
	Member* temp = m_head;
	ofstream outFile("Member.txt");										//Member.txt ���� ���� �Ǵ� �����
	while (temp != NULL) {
		outFile << temp->m_name << "\n" << temp->m_number << "\n";		//������ ���̽� ����
		for (int i = 0; i<3; i++) {										//���� �뿩 ��� ����
			outFile << temp->m_video_List[i] << "\n";
		}
		temp = temp->m_next;
	}
	m_overdue_save();													//��ü�Ⱓ ���� �Լ� ȣ��
	cout << "Member.txt ���Ϸ� �����½��ϴ�." << endl;
}
void Member::m_overdue_save() {											//��ü �Ⱓ ���� �Լ�
	Member* temp = m_head;
	ofstream outFile("time.txt");										//time.txt ���� ���� �Ǵ� �����
	while (temp != NULL) {
		for (int i = 0; i <= 2; i++) {									//�ݺ��� Ȱ�� ù��° �����ͺ��� �Է�
			outFile << temp->m_Overdue[i] << "\n";
		}
		temp = temp->m_next;
	}
}
void Member::m_load(Member& m_list) {									//ȸ�� ������ ���̽� ���� �Լ�
	string name;														//
	string data;														//�����Ͱ� �Էµǰ� �Ű��� ���ڿ�
	ifstream in("Member.txt");
	if (m_list.m_head != NULL ) {										//�̹� ������ ���� �Ȱ�� ���� ó��
		cout << "�̹� Member.txt ������ �ε�Ǿ����ϴ�." << endl;
		return;
	}
	if (in.is_open()) {
		while (!in.eof()) {												//������ ������ �ݺ�
			getline(in, name, '\n');
			getline(in, data, '\n');
			if (name == "\n" || name == "")break;						//���� ������ �о����ٸ� �ݺ��� �����.
			for (int i = 0; i < 3; i++) {								//���� �뿩 ��� ����
				getline(in, video_List[i], '\n');
			}
			m_overdue_load(m_list);										//��ü�Ⱓ ����
			m_list.m_add(name, data);									//�Էµ� �����͸� ȸ�� �߰��Լ��� �߰��Ѵ�.
		}
		cout << "Member.txt ������ �ҷ��Խ��ϴ�." << endl;
	}
	else {
		cout << "����� ȸ�� ����� �����ϴ�." << endl;
	}
	in.close();
}
void Member::m_overdue_load(Member& m_list){							//��ü�Ⱓ ���� �Լ�
	ifstream in("time.txt");
	if (in.is_open()) {
			for (int i = 0; i < 3; i++) {
				getline(in, overdue_List[i], '\n');						//���� ��ü�Ⱓ ���ڿ� �迭�� ��ü�Ⱓ �����ͺ��̽� �Է�
			}
	}
	in.close();
}
bool Member::m_name_check(string name) {								//�̸� Ȯ�� �Լ�
	Member* temp = m_head;
	if (name == "" || name == " ") {
		cout << "�ùٸ� �̸��� �Է����ּ���." << endl;
		return false;
	}
	while (temp != NULL) {												//������ �̸��� ���� �ι��� �̸� �ڿ� ��ȣ�� �߰��ϵ��� ����
		if (temp->m_name == name) {
			cout << "���������� �����մϴ�. �̸��� ���б�ȣ�� �־��ּ���." << endl;
			return false;
		}
		temp = temp->m_next;
	}
	return true;
}
bool Member::m_number_check(string number) {							//��ȣ Ȯ�� �Լ�
	if (number == "" || number == " ") {
		cout << "�ùٸ� ��ȭ��ȣ�� �Է����ּ���." << endl;
		return false;
	}
	else if (number.size() == 11) return true;							//�����̰ų� 11�ڸ��� �ƴϸ� ����ó��
	else {
		cout << "�ùٸ� ��ȭ��ȣ�� �Է����ּ���." << endl;
		return false;
	}
}

Member::~Member() {														//�⺻ �Ҹ���
	Member* temp = m_head;
	while (temp != NULL)												//����� ���� ��带 ���� �Ҵ� �����Ѵ�.
	{
		Member* del = temp;
		temp = temp->m_next;
		delete(del);
	}
	m_head = NULL;
}