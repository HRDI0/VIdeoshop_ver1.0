#include "videoshop.h"
void v_menu(video v_DB);	//���� ���� �޴�
void m_menu(video v_DB);	//ȸ�� ���� �޴�
int main()
{
	video v_DB = video();	//���� �����ͺ��̽� Ȱ���� ���� ���
	while (true) {
		int choice = 0;
		cout << endl;
		cout << "���� �뿩�� ver 1.0" << endl;
		cout << endl;
		cout << "1. ���� �����޴� \t 2. ȸ�� �����޴�\t3. ���α׷� ����" << endl;
		cin >> choice;
		cin.clear();
		cin.ignore(INT_MAX, '\n');		//cin�� �ܷ� ���� ó��
		switch (choice){

		case 1: {				//���� ���� �޴� ����
			system("cls");
			v_menu(v_DB);
			break;
		}
		case 2: {				//ȸ�� ���� �޴� ����
			system("cls");
			m_menu(v_DB);
			break;
		}
		case 3: {				//���α׷� ����
			system("cls");
			cout << "���α׷��� �����մϴ�." << endl;
			return 0;
		}
		default:				//������ ���� ���� �Է� ���� ó��
			system("cls");
			cout << "�߸��� �Է��Դϴ�." << endl;
			cout << endl;
			break;
		}
	}
}

