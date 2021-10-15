#include "videoshop.h"
void m_menu(video v_DB) {
	string name;						//�̸��� �Է��� ���ڿ�
	string number;						//��ȣ�� �Է��� ���ڿ�
	string video_name;					//�뿩�� ���� �̸��� �Է��� ���ڿ�
	Member m_DB;						//ȸ�� ���� Ŭ���� ����
	v_DB.v_load(v_DB);					//���� �����ͺ��̽� Ȱ���� ���� ���� �����ͺ��̽� ����
	system("cls");
	m_DB.m_load(m_DB);					//����� ȸ�� �����ͺ��̽� ����
	while (true) {
		int choice = 0;
		cout << endl;
		cout << "���� �뿩�� ver 1.0" << endl;
		cout << endl;
		cout << "ȸ�� �޴� \n 1. ����  2. �˻�  3. ����  \n 4. ����  5. ���  6. �뿩  \n 7. �ݳ�  8. ��������  9. �ҷ�����\n10. ���� " << endl;
		cout << endl;
		cin >> choice;
		cin.clear();
		cin.ignore(INT_MAX, '\n');		//cin�� �ܷ� ���� ó��
		switch (choice)
		{
		case 1: {						//ȸ�� �߰�
			cout << "�̸� : ";
			getline(cin, name);
			if (m_DB.m_name_check(name) == false) {
				cout<< endl;
				break;
			}
			cout << "��ȣ : ";
			cin >> number;
			cin.clear();
			cin.ignore(INT_MAX, '\n');
			if (m_DB.m_number_check(number) == false) {
				cout << endl;
				break;
			}
			m_DB.m_add(name, number);
			cout << endl;
			cout << "ȸ�� ���" << endl;
			cout << endl;
			m_DB.m_sort();
			m_DB.m_print();
			cout << endl;
			break;
		}
		case 2: {						//ȸ�� �˻�
			cout << endl;
			cout << "�˻��� �̸��� �Է��ϼ���. : ";
			getline(cin, name);
			m_DB.m_search(name);
			cout << endl;
			break;
		}
		case 3: {						//ȸ�� ����
			cout << "������ �̸��� �Է��ϼ���. :  " << endl;
			cout << endl;
			getline(cin, name);
			m_DB.m_change(name);
			m_DB.m_sort();
			cout << endl;
			break;
		}
		case 4: {						//ȸ�� ����
			m_DB.m_print();
			cout << endl;
			cout << "������ �̸��� �Է��ϼ���. : ";
			getline(cin, name);
			m_DB.m_remove(name);
			cout << endl;
			break;
		}
		case 5: {						//ȸ�� ��� ���
			m_DB.m_sort();
			cout << endl;
			cout << "ȸ�� ���" << endl;
			cout << endl;
			m_DB.m_print();
			break;
		}
		case 6: {						//���� �뿩
			v_DB.v_print();
			cout << endl;
			cout << "ȸ���̸� : " << endl;
			getline(cin, name);
			cout << endl;
			cout << "���� ������ : " << endl;
			getline(cin, video_name);
			cout << endl;
			m_DB.m_rental(&v_DB,name, video_name);
			v_DB.v_save();
			break;
		}
		case 7: {						//���� �ݳ�
			cout << endl;
			cout <<"ȸ���̸� : "<< endl;
			getline(cin, name);
			cout << endl;
			cout <<"�ݳ� ������ : "<< endl;
			getline(cin, video_name);
			cout << endl;
			m_DB.m_return(&v_DB,name, video_name);
			v_DB.v_save();
			break;
		}
		case 8: {						//ȸ�� �����ͺ��̽� �ܺ� ������ġ�� ����
			m_DB.m_sort();
			m_DB.m_save();
			cout << endl;
			break;
		}
		case 9: {						//����� ȸ�� �����ͺ��̽� ����	
			m_DB.m_load(m_DB);
			cout << endl;
			m_DB.m_sort();
			break;
		}
		case 10: {						//���α׷� ����
			m_DB.m_save();
			v_DB.v_save();
			cout << "���α׷��� �����մϴ�." << endl;
			cout << endl;
			return;
		}
		default:{						//�߸��� �Է� ����ó��
			cout << "�߸��� �Է��Դϴ�." << endl;
			cout << endl;
			break;
		}
		}
	}
}