#pragma once

#include <tachyon/component.hpp>
#include <itestcontract.hpp>



class TestComponent2 : public ITestContract
{
public:
	virtual ~TestComponent2();

	virtual const char *GetName();
	virtual void TestMethod();
	virtual bool PostInit();

	static Component *Create();

protected:
	TestComponent2();

	std::string m_name;
};

extern "C"
{
	EXPORT_API bool InitLibrary(tachyon::MasterFactory *m);
}
