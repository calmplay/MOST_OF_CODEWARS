
//#include<stdlib.h>
#include "strlen.h"     //Strlen() ʵ��strlen()
#include <iostream>
using namespace std;
//
//1.ջ��������Щ�ɱ���������Ҫ��ʱ����䣬�ڲ���Ҫ��ʱ���Զ�����ı����Ĵ洢��������ı���ͨ���Ǿֲ����������������ȡ�
//2.�ѣ�������Щ��new������ڴ�飬���ǵ��ͷű�������ȥ�ܣ������ǵ�Ӧ�ó���ȥ���ƣ�һ��һ��new��Ҫ��Ӧһ��delete���������Աû���ͷŵ�����ô�ڳ�������󣬲���ϵͳ���Զ����ա�
//3.���ɴ洢����������Щ��malloc�ȷ�����ڴ�飬���Ͷ���ʮ�����Ƶģ�����������free�������Լ��������ġ�
//4.ȫ�� / ��̬�洢����ȫ�ֱ����;�̬���������䵽ͬһ���ڴ��У�����ǰ��C�����У�ȫ�ֱ����ַ�Ϊ��ʼ���ĺ�δ��ʼ���ģ���C++����û����������ˣ����ǹ�ͬռ��ͬһ���ڴ�����
//5.�����洢��������һ��Ƚ�����Ĵ洢�������������ŵ��ǳ������������޸ģ���Ȼ����Ҫͨ���������ֶ�Ҳ�����޸ģ�



//
//��const���ε��ǡ�ֻ�������� ����ʹ����ô���Σ�Ҳ�Ǳ�����Ҳ���������������顣
//c++��ֻ��enum���ͺ�#define������������峣����
//
//
//const ��constant����д�������ǲ���ģ����׸ı����˼��
//
//const ��C++�������������������ͱ������Զ�����󣬳�Ա����������ֵ������������
//
//����ֵ���Ҷ���const���β���������
//A : const ����ָ��ָ������ݣ�������Ϊ���ɱ�����
//	const int *p = 8;  ָ��ָ�������8���ɸı䡣�����ֵ����Ϊconstλ��*�ŵ���ߡ�
//B : const ����ָ�룬��ָ��Ϊ���ɱ�����
//	int* const p = &a; ����constָ��p��ָ����ڴ��ַ���ܹ����ı䣬�������ݿ��Ըı䡣��ƣ��Ҷ�����Ϊconstλ��*�ŵ��ұߡ�
//C : const ����ָ���ָ��ָ������ݣ���ָ���ָ��ָ������ݶ�Ϊ���ɱ�����
//	const int * const  p = &a; const p��ָ������ݺ�ָ����ڴ��ַ���ѹ̶������ɸı䡣

class String
{

	//��Ա�����У�const���Σ���ʾ��������������ĳ�Ա�����κ��޸ġ����������const���Σ���ʾ�ú�������ı����������ֵ��
public:
	String(const char *str = NULL);//ͨ�ù��캯��
	String(const String &str, const char *nm="·�˼�");//дһ���������캯�� cp_no���������¶������ǳ����
	~String();

	String operator+(const String &str) const;//����+��
	String operator-(const String &str) const;//һ������ĳ��ԡ�����
	//String& operator=( String &str);//����=
	String& operator+=(const String & str);//����+=  
	
	bool operator==(const String &str)const;//����==
	char& operator[](int n) const;//����[]

	size_t size() const;//��ȡ����
	const char* c_str() const;//��ȡC�ַ���
	const char* Name() const;

	friend istream& operator>>(istream &is, String &str);//����
	friend ostream& operator<<(ostream &os, String &str);//���

	
	

private:
	char *data;//�ַ���
	char *name;
	int length;//����
};


String::String(const char *str)
{
	if (!str)
	{
		length = 0;
		data = new char[1];
		name = new char[1];
		*data = '\0';//����ֵ�����ǿգ�����ֵ��
		*name = '\0';

	}
	else
	{
		length = Strlen(str);
		data = new char[length + 1];
		name = new char[length + 1];

		strcpy(data, str);
		strcpy(name, str);

	}
}


String::String(const String &str,const char *nm )
{
		//���
		length = Strlen(nm);
		name = new char[length + 1];
		strcpy(name, nm);

		length = str.size();
		data = new char[length + 1];
		strcpy(data, str.data);

		
}

String :: ~String()
{
	cout << name;
	if (Strlen(data)==length)//����д����֪���ײ��� ��ʱ�ǳ��ڷ�ֹǳ�����Ķ��������� ԭ�����ٴ�����������
		delete[] data;
	length = 0;
	cout << "�������" << '\n';
	system("PAUSE");
}

String String::operator+(const String &str) const//+
{
	String newString;
	newString.length = length + str.size();
	newString.data = new char[newString.length + 1];
	strcpy(newString.data, data);//�����ַ���
	strcat(newString.data, str.data);//�����ַ���

	delete[] data;
	return newString;//newString�൱��this.data+str.data
}

String String::operator-(const String &str)const//-
{
	return str;
}

//String& String::operator=(String &str)//=
//{
//	//���str��data
//	/*if (this == &str)
//		return *this;
//
//	delete[] data;//������Ϊ�˱����ڴ�й© ��֤�µ��ַ�������������ڴ��Сһ��
//	length = str.length;
//	data = new char[length + 1];
//	strcpy(data, str.c_str());
//	return *this;*/
//
//	//ǳ����
//
//	delete[] data;//������Ϊ�˱����ڴ�й©
//	
//	&data =&( str.data);
//	this->length = 0;
//	return *this;
//}

String& String::operator+=(const String &str)//+=
{
	length += str.length;
	char *newData = new char[length + 1];
	strcpy(newData, data);
	strcat(newData, str.data);
	delete[] data;
	data = newData;
	return *this;
}

inline bool String::operator==(const String &str) const//==
{
	if (length != str.length)
		return false;
	return strcmp(data, str.data) ? false : true;//strcmp�ַ����ȽϺ��� ǰ��<���� ���ظ�ֵ��= ����0��> ��������
}


inline char& String::operator[](int n) const//[]����
{
	if (n >= length)
		return data[length - 1];
	else
		return data[n];
}



size_t String::size() const
{
	return this->length;

}


inline const char*String::c_str() const//��ȡc�ַ���
{
	return data;
}

inline const char*String::Name() const//��ȡc�ַ���
{
	return name;
}


istream& operator>>(istream &is, String &str)//����
{

	char tem[1000];
	is >> tem;
	str.length = Strlen(tem);//����©д����һ��  һֱ������������ԭ���ǡ����롱�ĳ���>�����ʼ��ʱ���length������ڴ����
	str.data = new char[str.length + 1];
	strcpy(str.data, tem);
	return is;
}

ostream& operator<<(ostream &os, String &str)//���
{
	os << str.data;
	return os;
}

int main()
{
	
	String wxy("wxy");
	//wxy = (String)malloc(sizeof(String));
	String cy("cy");

	cin >> cy;
	String chm(wxy,"chm");
	String zcy("zcy");
	cout << wxy.Name() << ": " << wxy.c_str() << '\n'
		<< chm.Name() << ": " << chm.c_str() << '\n'
		<< zcy.Name() << ": " << zcy.c_str() << '\n' << '\n';

	wxy += cy;
	zcy = wxy;//���=��Ĭ�ϵ�ǳ����������ָ��wxy�������� ����һ�����Ӱ�Ӷ��������� ��ԭ����������ʱ������ͷ��Ѿ��ͷŹ����ڴ�ͻ����
	cout << wxy.Name()<<": "<< wxy << '\n'
		<< chm.Name() << ": " << chm << '\n'
		<< zcy.Name() << ": " << zcy << '\n';

	/*char* ss = "12345678";
	cout << ss << "�ĳ���=" << Strlen(ss) << '\n';*/

	system("PAUSE");
	return 0;

}