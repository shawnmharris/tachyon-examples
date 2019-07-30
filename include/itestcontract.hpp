#pragma once

#include <tachyon/component.hpp>

class ITestContract : public tachyon::Component
{
public:
	virtual ~ITestContract() {}
	// all important setup and resource
	// allocation should happen in post init
	// rather than constructor because of the
	// factory instantiation code path
	virtual bool PostInit() = 0;
	virtual void TestMethod() = 0;
	virtual const char *GetName() = 0;
};