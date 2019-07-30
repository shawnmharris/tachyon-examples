#include <testcomponent1.hpp>

constexpr auto NAME = "ITestContract.TestComponent1";
int count = 0;

TestComponent1::TestComponent1() 
{
	char buf[255] = { 0 };
	sprintf(buf, "%s(%d)", NAME, count++);
	m_name = buf;
}

TestComponent1::~TestComponent1()
{
}

const char *TestComponent1::GetName()
{
	return m_name.c_str();
}

void TestComponent1::TestMethod()
{
	std::cout << "TestComponent1::TestMethod()" << std::endl;
}

bool TestComponent1::PostInit()
{
	return true;
}

tachyon::Component *TestComponent1::Create()
{
	return new TestComponent1();
}


EXPORT_API bool InitLibrary(tachyon::MasterFactory *m)
{
	m->Register(NAME, TestComponent1::Create);
	return true;
}


