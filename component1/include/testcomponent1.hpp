#pragma once

#include <tachyon/component.hpp>
#include <itestcontract.hpp>


class TestComponent1 : public ITestContract
{
public:
	virtual ~TestComponent1();

	virtual const char *GetName();
	virtual void TestMethod();
	virtual bool PostInit();

	static tachyon::Component *Create();

protected:
	TestComponent1();

	std::string m_name;
};


extern "C"
{
	EXPORT_API bool InitLibrary(tachyon::MasterFactory *m);
}
