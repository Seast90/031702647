#include "stdafx.h"
#include "CppUnitTest.h"
#include "../AddressBook/People.h"
#include "../AddressBook/Address.h"
#include "../AddressBook/Area.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			vector <wstring > v;
			wstring str = L"���Ӻ�,����ʡ12345678911�����й�¥�������ֵ�����·110�ź�������һ��.";
			People s(str);
			s.doit(v);
			wstring name = L"���Ӻ�";
			Assert::AreEqual(name, s.name);
		}

	};
}