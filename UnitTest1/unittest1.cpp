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
			wstring str = L"鲍子涵,福建省12345678911福州市鼓楼区鼓西街道湖滨路110号湖滨大厦一层.";
			People s(str);
			s.doit(v);
			wstring name = L"鲍子涵";
			Assert::AreEqual(name, s.name);
		}

	};
}