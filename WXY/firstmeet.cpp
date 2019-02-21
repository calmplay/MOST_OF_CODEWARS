
//#include<stdlib.h>
#include "strlen.h"     //Strlen() 实现strlen()
#include <iostream>
using namespace std;
//
//1.栈，就是那些由编译器在需要的时候分配，在不需要的时候自动清楚的变量的存储区。里面的变量通常是局部变量、函数参数等。
//2.堆，就是那些由new分配的内存块，他们的释放编译器不去管，由我们的应用程序去控制，一般一个new就要对应一个delete。如果程序员没有释放掉，那么在程序结束后，操作系统会自动回收。
//3.自由存储区，就是那些由malloc等分配的内存块，他和堆是十分相似的，不过它是用free来结束自己的生命的。
//4.全局 / 静态存储区，全局变量和静态变量被分配到同一块内存中，在以前的C语言中，全局变量又分为初始化的和未初始化的，在C++里面没有这个区分了，他们共同占用同一块内存区。
//5.常量存储区，这是一块比较特殊的存储区，他们里面存放的是常量，不允许修改（当然，你要通过非正当手段也可以修改）



//
//用const修饰的是“只读变量” ，即使在怎么修饰，也是变量，也不能用来声明数组。
//c++中只有enum类型和#define宏可以用来定义常量。
//
//
//const 是constant的缩写，本意是不变的，不易改变的意思。
//
//const 在C++中是用来修饰内置类型变量，自定义对象，成员函数，返回值，函数参数。
//
//“左定值，右定向，const修饰不变量”。
//A : const 修饰指针指向的内容，则内容为不可变量。
//	const int *p = 8;  指针指向的内容8不可改变。简称左定值，因为const位于*号的左边。
//B : const 修饰指针，则指针为不可变量。
//	int* const p = &a; 对于const指针p其指向的内存地址不能够被改变，但其内容可以改变。简称，右定向。因为const位于*号的右边。
//C : const 修饰指针和指针指向的内容，则指针和指针指向的内容都为不可变量。
//	const int * const  p = &a; const p的指向的内容和指向的内存地址都已固定，不可改变。

class String
{

	//成员函数中，const修饰，表示这个函数不会对类的成员进行任何修改。输入参数的const修饰，表示该函数不会改变这个参数的值。
public:
	String(const char *str = NULL);//通用构造函数
	String(const String &str, const char *nm="路人甲");//写一个拷贝构造函数 cp_no用来决定新对象的深浅拷贝
	~String();

	String operator+(const String &str) const;//重载+号
	String operator-(const String &str) const;//一个好奇的尝试。。。
	//String& operator=( String &str);//重载=
	String& operator+=(const String & str);//重载+=  
	
	bool operator==(const String &str)const;//重载==
	char& operator[](int n) const;//重载[]

	size_t size() const;//获取长度
	const char* c_str() const;//获取C字符串
	const char* Name() const;

	friend istream& operator>>(istream &is, String &str);//输入
	friend ostream& operator<<(ostream &os, String &str);//输出

	
	

private:
	char *data;//字符串
	char *name;
	int length;//长度
};


String::String(const char *str)
{
	if (!str)
	{
		length = 0;
		data = new char[1];
		name = new char[1];
		*data = '\0';//赋空值，并非空（即无值）
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
		//深拷贝
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
	if (Strlen(data)==length)//这种写法不知道妥不妥 暂时是出于防止浅拷贝的对象析构后 原对象再次析构将报错
		delete[] data;
	length = 0;
	cout << "析构完成" << '\n';
	system("PAUSE");
}

String String::operator+(const String &str) const//+
{
	String newString;
	newString.length = length + str.size();
	newString.data = new char[newString.length + 1];
	strcpy(newString.data, data);//拷贝字符串
	strcat(newString.data, str.data);//接连字符串

	delete[] data;
	return newString;//newString相当于this.data+str.data
}

String String::operator-(const String &str)const//-
{
	return str;
}

//String& String::operator=(String &str)//=
//{
//	//深拷贝str的data
//	/*if (this == &str)
//		return *this;
//
//	delete[] data;//这里是为了避免内存泄漏 保证新的字符串和他申请的内存大小一致
//	length = str.length;
//	data = new char[length + 1];
//	strcpy(data, str.c_str());
//	return *this;*/
//
//	//浅拷贝
//
//	delete[] data;//这里是为了避免内存泄漏
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
	return strcmp(data, str.data) ? false : true;//strcmp字符串比较函数 前者<后者 返回负值；= 返回0；> 返回正数
}


inline char& String::operator[](int n) const//[]索引
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


inline const char*String::c_str() const//获取c字符串
{
	return data;
}

inline const char*String::Name() const//获取c字符串
{
	return name;
}


istream& operator>>(istream &is, String &str)//输入
{

	char tem[1000];
	is >> tem;
	str.length = Strlen(tem);//当初漏写了这一句  一直报错！！！！！原因是“输入”的长度>对象初始化时候的length，造成内存溢出
	str.data = new char[str.length + 1];
	strcpy(str.data, tem);
	return is;
}

ostream& operator<<(ostream &os, String &str)//输出
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
	zcy = wxy;//这个=是默认的浅拷贝，可以指向wxy整个对象， 但是一旦这个影子对象析构了 ，原形再析构的时候如果释放已经释放过的内存就会出错
	cout << wxy.Name()<<": "<< wxy << '\n'
		<< chm.Name() << ": " << chm << '\n'
		<< zcy.Name() << ": " << zcy << '\n';

	/*char* ss = "12345678";
	cout << ss << "的长度=" << Strlen(ss) << '\n';*/

	system("PAUSE");
	return 0;

}