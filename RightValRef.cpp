#include<iostream>
#include<string.h>
#include<vector>
/*
*C++ 11增加一个新的引用（reference）类型称作右值引用（R-value reference），
*标记为typename &&。他们能够以non-const值的方式传入，允许对象去改动他们
*而右值引用又是为了实现转移语义，避免内存的拷贝
*/
#define null 0

//! 左值 
void PrintVal(int& i)
{
	std::cout<<"Left ref:"<<i<<std::endl;
}
//! 右值
void PrintVal(int&& i)
{
	std::cout<<"Right ref:"<<i<<std::endl;
}
//! 右值引用实现转移语义
class MyString
{
public:
	MyString(const char* str)
	{
		if (str == null)
		{
			data_ = new char[1];
			*data_ = '\0';
		}
		data_ = new char[strlen(str)+1];
		strcpy(data_, str);
	}
	MyString(const MyString& myString)
	{
		std::cout<<"Left val ref:"<<myString.data_<<std::endl;
		data_ = new char[strlen(myString.data_)+1];
		strcpy(data_, myString.data_);
	}
	MyString(MyString&& myString)
	{
		std::cout<<"Right val ref:"<<myString.data_<<std::endl;
		data_ = myString.data_;
		myString.data_ = null;
	}
	const char* c_str() const
	{
		return data_;
	}
	friend std::ostream& operator<<(std::ostream &os, const MyString& myS)	//！在一个加了const限定符的成员函数中，不能够调用 非const成员函数。
	                                                                        //! 因为如果调用了非const成员函数，就违反了const成员函数不改变对象的规定
																			                                    //! 见http://blog.csdn.net/rainkin1993/article/details/8034657
	{
		os<<myS.c_str();
		return os;		
	}
	~MyString()
	{
		if (null != data_)
		{
			delete[] data_;
			data_ = null;
		}
	}
private:
	char* data_;
};



int main(int argc, char const *argv[])
{
	int val = 6;
	/* 左值右值引用函数重载 */
	PrintVal(val);		
	PrintVal(5);
	/* 通过右值引用实现转移语义 */
	MyString str("str");
	MyString str1(str);					//! 左值
	MyString str2(MyString("str2"));	//! 应该是被编译器优化掉了
	std::vector<MyString> v;
	v.push_back(MyString("vec"));		//! 这样不会被优化直接调用了右值引用函数，实现了转移语义
	MyString str3(std::move(str));		//! 使用std::move强行右值

	std::cout<<str1<<str2<<str3<<std::endl;
	return 0;
}
