#include <iostream>

using namespace std;
//---------------------������� � ���������---------------------------------------

int lengthString(char* ch);                      // ������ ������
char* reverseString(char* ch);                   // �������� ������
int balanceBrackets(char* ch);                   // �������� ������� ������
int occurenceSubstring(char* ch, char* p_ch);    // ����� ���������
char* insertnString(char* ch, char* v_ch, int num);  // ������������
char* �utString(char* ch, int length, int num_p);    // �����������

//------------------------MAIN----------------------------------------------------
int main() {
	setlocale(LC_ALL, "RU");
	srand(time(NULL));
	//-------------------------------���� �����-------------------------------------

	char ch[100];

	//------------------������ ������--------------------------------

	cout << "������� ������ ��� ����������� � ������: ";
	cin >> ch;

	cout << "������ ������: " << lengthString(ch) << endl << endl;
	
	for (int i = 0; i < 100; i++) ch[i] = '\0';

	//-------------------��������--------------------------------------
	
	cout << "������� ������, ������� ���������� �������������: ";
	cin >> ch;
	cout << "���������������� ������: ";
	for (int i = 0; i < lengthString(ch); i++)
	{
		cout << reverseString(ch)[i];
	}
	cout << endl << endl;

	for (int i = 0; i < 100; i++) ch[i] = '\0';

	//---------------������ ������----------------------------------------

	cout << "������� ������ ��� �������� ������� ������: ";
	cin >> ch;
	if (balanceBrackets(ch) == 1)
	{
		cout << "������ ������ ��������." << endl << endl;
	}
	else if (balanceBrackets(ch) == 0)
	{
		cout << "������ ������ �� ��������." << endl << endl;
	}
	else if (balanceBrackets(ch) == -1)
	{
		cout << "� ������ ���� ������." << endl << endl;
	}

	for (int i = 0; i < 100; i++) ch[i] = '\0';

	//----------------�����-------------------------------------------------

	char p_ch[100];                   // ���������

	cout << "������� ������ ��� ��������� ������� ���������: ";
	cin >> ch;

	cout << "������� ���������: ";
	cin >> p_ch;

	cout << "����� ������� = " << occurenceSubstring(ch, p_ch) << endl << endl;

	for (int i = 0; i < 100; i++) ch[i] = '\0';

	//----------------������������------------------------------------------

	char v_ch[100];
	int num;

	cout << "������� ������ ������ ��� ������������:";
	cin >> ch;

	cout << "������� ������ ������ ��� ������������:";
	cin >> v_ch;

	cout << "������� ������� ��� ����������� ������:";
	cin >> num;


	cout << "��������� ����������� = ";

	for (int i = 0; i < lengthString(insertnString(ch, v_ch, num)); i++)
	{
		cout << insertnString(ch, v_ch, num)[i];
	}

	cout << endl << endl;

	for (int i = 0; i < 100; i++) ch[i] = '\0';

	//----------------�����������-------------------------------------------

	int length;
	int num_p;

	cout << "������� ������ �� ������� ���������� ����������� n ��������:";
	cin >> ch;

	cout << "������� ����� ���������� ������:";
	cin >> length;

	cout << "������� ����� �������, ������� � ������� ���������� ����������� ������:";
	cin >> num_p;

	cout << "������������� ������ = ";

	for (int i = 0; i < lengthString(�utString(ch, length, num_p)); i++)
	{
		cout << �utString(ch, length, num_p)[i];
	}

	cout << endl << endl;
	//----------------------------------------------------------------------

	system("pause");
	return 0;
}


int lengthString(char* ch)                       // ������ ������
{
	int i = 0;
	while (ch[i] != '\0')
	{
		i++;
	}
	return i;
}

char* reverseString(char* ch)                     // �������� ������
{
	char t_ch[100]{};
	int len = lengthString(ch);
	for (int i = 0; i < len; i++)
	{
		t_ch[len - 1 - i] = ch[i];
	}
	return t_ch;
}

int balanceBrackets(char* ch)                     // �������� ������� ������
{
	bool y = false;               // ������� ������
	bool x = true;                // ������ ������ ����������
	int fg = 0;                   // ������ ������ {}
	int kr = 0;                   // ������ ������ ()
	int kv = 0;                   // ������ ������ []


	int len = lengthString(ch);
	for (int i = 0; i < len; i++)
	{
		//------------{
		if (ch[i] == '{')
		{
			fg++;
			y = true;
		}
		if (ch[i] == '}')
		{
			fg--;
			y = true;
			if (fg < 0)
			{
				x = false;
			}
		}
		//-----------(
		if (ch[i] == '(')
		{
			kr++;
			y = true;
		}
		if (ch[i] == ')')
		{
			kr--;
			y = true;
			if (kr < 0)
			{
				x = false;
			}
		}
		//-------------[
		if (ch[i] == '[')
		{
			kv++;
			y = true;
		}
		if (ch[i] == ']')
		{
			kv--;
			y = true;
			if (kv < 0)
			{
				x = false;
			}
		}
	}

	if (x != false && fg == 0 && kr == 0 && kv == 0)
	{
		x = true;
	}
	else
	{
		x = false;
	}

	if (y == true)
	{
		if (x == true)
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
	else
	{
		return -1;
	}
}

int occurenceSubstring(char* ch, char* p_ch)               // ����� ��������� (p_ch - ��������� )
{

	bool x = false;
	int len = lengthString(ch);
	for (int i = 0; i < len; i++)
	{
		if (ch[i] == p_ch[0])
		{
			x = true;
			for (int j = 0; j < lengthString(p_ch); j++)
			{
				if (ch[i + j] != p_ch[j])
				{
					x = false;
				}
			}
			if (x == true)
			{
				return i + 1;
			}
		}
	}
	return 0;

}

char* insertnString(char* ch, char* v_ch, int num)            // ������������ �� ��������� �������
{
	int len = lengthString(ch);      // ������ ������
	int len_v = lengthString(v_ch);  // ������ ������ ������
	char r_ch[100]{};                // ��������� ������������

	for (int i = 0; i < num - 1; i++)           // �������� ������� �� ������� �� ������ 1
	{
		r_ch[i] = ch[i];
	}

	int j = 0;
	for (int i = num - 1; i < num - 1 + len_v; i++)    // �������� ������� �� ������ 2
	{
		r_ch[i] = v_ch[j];
		j++;
	}

	int k = 0;
	for (int i = num + len_v - 1; i < len + len_v; i++)    // �������� ������� ����� ������� �� ������ 1
	{
		r_ch[i] = ch[num - 1 + k];
		k++;
	}

	return r_ch;

}


char* �utString(char* ch, int length, int num_p)         // ����������� ����� ������
{
	char r_ch[100]{};
	for (int i = 0; i < length; i++)
	{
		r_ch[i] = ch[num_p - 1 + i];
	}

	return r_ch;
}