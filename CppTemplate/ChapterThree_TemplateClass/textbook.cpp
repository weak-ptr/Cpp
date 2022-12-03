#include <iostream>
using namespace std;

namespace ImplicitDefinitionWithClassName
{
	template <typename T>
	class MyClass {
	private:
		T m_data;

	public:
		MyClass()
			: m_data()
		{
			cout << "implicit definition with class name\n";
		}

		virtual ~MyClass()
		{
			cout << "Bye~\n";
		}

		void other(void);
	};

	template <typename T>
	void MyClass<T>::other(void)
	{
		cout << "other in implicit definition with class name\n";
	}
}

namespace ExplicitDefinitionWithTypeName
{
	template <typename T>
	class MyClass {
	private:
		T m_data;
	
	public:
		MyClass<T>();
		~MyClass<T>();
		void other(void);
	};

	template <typename T>
	MyClass<T>::MyClass()
		: m_data()
	{
		cout << "explicit definition with type name\n";
	}

	template <typename T>
	MyClass<T>::~MyClass<T>()
	{
		cout << "Bye~\n";
	}

	template <typename T>
	void MyClass<T>::other()
	{
		cout << "other in explicit definition with type name\n";
	}
}

namespace WhatTimeCompilingTemplate
{
	template <typename T>
	class CompilingTest {
	public:
		CompilingTest()
		{

		}

		virtual ~CompilingTest()
		{

		}

		void call(void)
		{
			if (HelloWorld)
				;
		}

		bool HelloWorld(void)
		{
			return true;
		}
	};
}

namespace PartialSpecilization
{
	template <typename T1, typename T2, typename T3>
	class Hello {

	};

	template <typename T>
	class Hello<T, T, T> {

	};

	template <typename T1, typename T2>
	class Hello<T1, T2, int> {

	};
}

int main()
{
#if 0
	ImplicitDefinitionWithClassName::MyClass<int> c1;
	c1.other();

	ExplicitDefinitionWithTypeName::MyClass<int> c2;
	c2.other();

	WhatTimeCompilingTemplate::CompilingTest<int> c3;
#endif

	PartialSpecilization::Hello<float, float, float> f1;//	ok
	PartialSpecilization::Hello<float, float, int> f2;	//	ok
	PartialSpecilization::Hello<int, int, int> f3; 		//	error -- ambiguous

	return 0;
}