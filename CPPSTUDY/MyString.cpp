#include "stdafx.h"
#include "MyString.h"

MyString::MyString(const char * str)
{
	int strCount = 0;
	while (*(str + m_strLength) != '\0')
	{
		*(str + m_strLength);
		++m_strLength;
	}

	//Capacity ����
	m_strCapacity = ((m_strLength / 10) + 1) * 10;
	
	//���ڿ� ����
	m_strString = new char[m_strCapacity];
	memcpy_s(m_strString, m_strLength, str, m_strLength);
	m_strString[5] = '\0';
	//strTest = *str;
	//len = strlen(str) + 1;
	//strt = new char[len];
//	strcpy_s(strt, len, str);
	//int check = 0;
	//int a = 0;
	//while (check == 0)
	//{
	//	if (*(str+a) == '\0') check = 1;
	//	strt[a] = *(str + a);
	//	printf("%c\n", *(strt + a));
	//	a++;
	//}
	//printf("%d", a);
	//*(strt + a) = '\0'; �������� �����Ҵ�


//	printf("�����ڳ�\n");
};

MyString::MyString()
{
	m_strCapacity = ((m_strLength / 10) + 1) * 10;
	m_strString = new char[m_strCapacity];
	m_strString[m_strLength] = '\0';
};

MyString::~MyString()
{
	printf("%p\n", m_strString);
	delete[] m_strString;
}

char* MyString::Show()
{
	return m_strString;
}

int MyString::Length()
{
	return m_strLength;
}

int MyString::Size()
{
	return m_strLength;
}

int MyString::Capacity()
{
	return m_strCapacity;
}

void MyString::Clear()
{
	for (int strCount = 0; strCount < m_strCapacity; ++strCount)
		*(m_strString + strCount) = NULL;

	memset(m_strString, 0, m_strCapacity);

	m_strLength = 0;
	delete[] m_strString;
	m_strCapacity = ((m_strLength / 10) + 1) * 10;
	m_strString = new char[m_strCapacity];
}

bool MyString::operator==(const MyString & str)
{
	if (m_strLength == str.m_strLength)
	{
		for (int strCnt = 0; strCnt < m_strLength; strCnt++)
		{
			if (*(m_strString + strCnt) != *(str.m_strString + strCnt))
				return false;
		}
	}
	else
		return false;
	return true;
}

MyString MyString::operator+(const MyString & Bstr)
{
	int strLenMax = m_strLength + Bstr.m_strLength;
	int strCount;
	char * strTemp = new char[strLenMax];
	
	for (strCount = 0; strCount < m_strLength; ++strCount)
		*(strTemp + strCount) = *(m_strString + strCount);
	
	int strBCount = 0;
	for (strCount = m_strLength; strCount < strLenMax; ++strCount)
	{
		*(strTemp + strCount) = *(Bstr.m_strString + strBCount);
		++strBCount;
	}

	strTemp[strLenMax] = '\0';
	return strTemp;
}
std::ostream & operator<<(std::ostream & os, const MyString & str)
{
	os << str.m_strString;
	return os;
	// TODO: ���⿡ ��ȯ ������ �����մϴ�.
}

bool strcmp(MyString& str1, MyString& str2)
{
	if (str1.Length() == str2.Length())
	{
		for (int strCnt = 0; strCnt < str1.Length(); strCnt++)
		{
			if (*(str1.Show() + strCnt) != *(str2.Show() + strCnt))
			{
				printf("�޶��");
				return true;
			}
				
		}
	}
	else
		return true;
	printf("���ƿ�");
	return false;
}

int main()
{
	//MyString str1("abc");
	//MyString str2("def");
	//MyString str3 = str1 + str2;
	//MyString str4("1234567890");
	//std::cout << str1;

	//printf("%s", str2.Show());
	//	std::cout << std::endl;
	//	std::cout << str3;
	//	str4.Clear();
	//	std::cout << str4;
	//	printf("%d", str4.Length());
		//printf("\n");
	//MyString stra("abcde");
	//MyString strb("abcde");

	MyString stra("abcde");
	MyString strb("abcde");
	{

	strcmp(stra, strb);
	}
	//if (stra == strb)
	//	printf("����");
	//strb.Clear();
	//if (stra == strb)
	//	printf("����");
	//else
	//	printf("�ٸ�");
	return 0;
}
