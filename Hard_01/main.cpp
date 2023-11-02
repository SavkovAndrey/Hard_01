#include <iostream>

using namespace std;
//---------------------Функции и Прототипы---------------------------------------

int lengthString(char* ch);                      // длинна строки
char* reverseString(char* ch);                   // инверсия строки
int balanceBrackets(char* ch);                   // проверка баланса скобок
int occurenceSubstring(char* ch, char* p_ch);    // поиск вхождения
char* insertnString(char* ch, char* v_ch, int num);  // конкотенация
char* сutString(char* ch, int length, int num_p);    // копирование

//------------------------MAIN----------------------------------------------------
int main() {
	setlocale(LC_ALL, "RU");
	srand(time(NULL));
	//-------------------------------САМА ПРОГА-------------------------------------

	char ch[100];

	//------------------Длинна строки--------------------------------

	cout << "Введите строку для определения её длинны: ";
	cin >> ch;

	cout << "Длинна строки: " << lengthString(ch) << endl << endl;
	
	for (int i = 0; i < 100; i++) ch[i] = '\0';

	//-------------------Инверсия--------------------------------------
	
	cout << "Введите строку, которую необходимо инвертировать: ";
	cin >> ch;
	cout << "Конвертированная строка: ";
	for (int i = 0; i < lengthString(ch); i++)
	{
		cout << reverseString(ch)[i];
	}
	cout << endl << endl;

	for (int i = 0; i < 100; i++) ch[i] = '\0';

	//---------------Баланс скобок----------------------------------------

	cout << "Введите строку для проверки баланса скобок: ";
	cin >> ch;
	if (balanceBrackets(ch) == 1)
	{
		cout << "Баланс скобок выдержан." << endl << endl;
	}
	else if (balanceBrackets(ch) == 0)
	{
		cout << "Баланс скобок не выдержан." << endl << endl;
	}
	else if (balanceBrackets(ch) == -1)
	{
		cout << "В строке нету скобок." << endl << endl;
	}

	for (int i = 0; i < 100; i++) ch[i] = '\0';

	//----------------Поиск-------------------------------------------------

	char p_ch[100];                   // подстрока

	cout << "Введите строку для получения позиции подстроки: ";
	cin >> ch;

	cout << "Введите подстроку: ";
	cin >> p_ch;

	cout << "Номер позиции = " << occurenceSubstring(ch, p_ch) << endl << endl;

	for (int i = 0; i < 100; i++) ch[i] = '\0';

	//----------------Конкотенация------------------------------------------

	char v_ch[100];
	int num;

	cout << "Введите первую строку для конкатенации:";
	cin >> ch;

	cout << "Введите вторую строку для конкатенации:";
	cin >> v_ch;

	cout << "Введите позицию для вставляемой строки:";
	cin >> num;


	cout << "Результат объединения = ";

	for (int i = 0; i < lengthString(insertnString(ch, v_ch, num)); i++)
	{
		cout << insertnString(ch, v_ch, num)[i];
	}

	cout << endl << endl;

	for (int i = 0; i < 100; i++) ch[i] = '\0';

	//----------------Копирование-------------------------------------------

	int length;
	int num_p;

	cout << "Введите строку из которой необходимо скопировать n символов:";
	cin >> ch;

	cout << "Введите длину копируемой строки:";
	cin >> length;

	cout << "Введите номер позиции, начиная с которой необходимо скопировать строку:";
	cin >> num_p;

	cout << "Скопированная строка = ";

	for (int i = 0; i < lengthString(сutString(ch, length, num_p)); i++)
	{
		cout << сutString(ch, length, num_p)[i];
	}

	cout << endl << endl;
	//----------------------------------------------------------------------

	system("pause");
	return 0;
}


int lengthString(char* ch)                       // длинна строки
{
	int i = 0;
	while (ch[i] != '\0')
	{
		i++;
	}
	return i;
}

char* reverseString(char* ch)                     // инверсия строки
{
	char t_ch[100]{};
	int len = lengthString(ch);
	for (int i = 0; i < len; i++)
	{
		t_ch[len - 1 - i] = ch[i];
	}
	return t_ch;
}

int balanceBrackets(char* ch)                     // проверка баланса скобок
{
	bool y = false;               // наличие скобок
	bool x = true;                // баланс скобок глобальный
	int fg = 0;                   // баланс скобок {}
	int kr = 0;                   // баланс скобок ()
	int kv = 0;                   // баланс скобок []


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

int occurenceSubstring(char* ch, char* p_ch)               // поиск подстроки (p_ch - подстрока )
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

char* insertnString(char* ch, char* v_ch, int num)            // конкотенация по указанной позиции
{
	int len = lengthString(ch);      // длинна строки
	int len_v = lengthString(v_ch);  // длинна второй строки
	char r_ch[100]{};                // результат конкотенации

	for (int i = 0; i < num - 1; i++)           // копируем символы до позиции из строки 1
	{
		r_ch[i] = ch[i];
	}

	int j = 0;
	for (int i = num - 1; i < num - 1 + len_v; i++)    // копируем символы из строки 2
	{
		r_ch[i] = v_ch[j];
		j++;
	}

	int k = 0;
	for (int i = num + len_v - 1; i < len + len_v; i++)    // копируем символы после позиции из строки 1
	{
		r_ch[i] = ch[num - 1 + k];
		k++;
	}

	return r_ch;

}


char* сutString(char* ch, int length, int num_p)         // копирование куска строки
{
	char r_ch[100]{};
	for (int i = 0; i < length; i++)
	{
		r_ch[i] = ch[num_p - 1 + i];
	}

	return r_ch;
}