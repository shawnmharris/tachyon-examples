#include <tachyon/component.hpp>
#include <testcomponent2.hpp>

constexpr auto NAME = "ITestContract.TestComponent2";
int count = 0;

TestComponent2::TestComponent2()
{
	char buf[255] = { 0 };
	sprintf(buf, "%s(%d)", NAME, count++);
	m_name = buf;
}

TestComponent2::~TestComponent2()
{
}

const char *TestComponent2::GetName()
{
	return m_name.c_str();
}

void TestComponent2::TestMethod()
{
	std::cout << "TestComponent2::TestMethod()" << std::endl;
}

bool TestComponent2::PostInit()
{
	return true;
}

tachyon::Component *TestComponent2::Create()
{
	return new TestComponent2();
}


EXPORT_API bool InitLibrary(tachyon::MasterFactory *m)
{
	m->Register(NAME, TestComponent2::Create);
	return true;
}