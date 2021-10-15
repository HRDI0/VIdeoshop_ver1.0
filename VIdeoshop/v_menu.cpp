#include "videoshop.h"

void v_menu(video v_DB)
{
	string name;		//�̸��� �Է��� ���ڿ�
	string genre;		//�帣�� �Է��� ���ڿ�
	system("cls");
	v_DB.v_load(v_DB);	//����� ���� �����ͺ��̽� ����
	while (true) {
		int choice = 0;
		cout << endl;
		cout << "���� �뿩�� ver 1.0" << endl;
		cout << endl;
		cout << "���� �޴� \n 1. ����  2. �˻�  3. ����  \n 4. ����  5. ���  6. ��������  \n 7. �ҷ�����  8. ���� " << endl;
		cout << endl;
		cin >> choice;
		cin.clear();
		cin.ignore(INT_MAX, '\n');		//cin �� �ܷ� ���� ó��
		switch (choice)
		{
		case 1: {						//���� �߰�
			cout << "�̸� : ";
			getline(cin,name);
			if (v_DB.v_name_check(name) == false) {
				cout << endl;
				break;
			}

			cout << "�帣 : ";
			getline(cin,genre);
			if (v_DB.v_genre_check(genre) == false) {
				cout << endl;
				break;
			}
			v_DB.v_add(name, genre);
			cout << endl;
			cout << "���� ���" << endl;
			cout << endl;
			v_DB.v_sort();
			v_DB.v_print();
			cout << endl;
			break;
		}
		case 2: {						//���� �˻�
			cout << endl;
			cout << "�˻��� �������� �Է��ϼ���. : ";
			getline(cin, name);
			v_DB.v_search(name);
			cout << endl;
			break;
		}
		case 3: {						//���� ����
			cout << "������ �������� �Է��ϼ���. :  " << endl;
			cout << endl;
			getline(cin, name);
			v_DB.v_change(name);
			v_DB.v_sort();
			cout << endl;
			break;
		}
		case 4: {						//���� ����
			v_DB.v_print();
			cout << endl;
			cout << "������ �������� �Է��ϼ���. : ";
			getline(cin, name);
			v_DB.v_remove(name);
			cout << endl;
			break;
		}
		case 5: {						//���� ��� ���
			v_DB.v_sort();
			cout << endl;
			cout << "���� ���" << endl;
			cout << endl;
			v_DB.v_print();
			break;
		}
		case 6: {						//���� ������ ���̽��� �ܺ� ������ġ�� ����
			v_DB.v_sort();
			v_DB.v_save();
			cout << endl;
			break;
		}
		case 7: {						//�ܺ� ������ġ�� ���� ������ ���̽� ����
			v_DB.v_load(v_DB);
			cout << endl;
			v_DB.v_sort();
			break;
		}
		case 8: {						//���α׷� ����
			v_DB.v_save();
			cout << "���α׷��� �����մϴ�." << endl;
			cout << endl;
			return;
		}
		default:						//�߸��� �Է� ���� ó��
		{
			cout << "�߸��� �Է��Դϴ�." << endl;
			cout << endl;
			break;
		}
		}
	}
}