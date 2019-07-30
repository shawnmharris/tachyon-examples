
#include <iostream>
#include <tachyon/component.hpp>
#include <itestcontract.hpp>


using namespace tachyon;


int main()
{
	MasterFactory &mf = MasterFactory::Instance();
	mf.Manage("component1");
	mf.Manage("component2");

	// test 1 is implemented in a shared dll 
	sp<ITestContract> sp1 = mf.Create<ITestContract>("ITestContract.TestComponent1");

	// test 2 is implemented in a shared dll 
	sp<ITestContract> sp2 = mf.Create<ITestContract>("ITestContract.TestComponent2");

	sp<ITestContract> sp3 = sp1;
	sp<ITestContract> sp4 = sp2;

	sp<ITestContract> sp5 = mf.Create<ITestContract>("ITestContract.TestComponent1");

	if (!sp1.isValid() || !sp3.isValid() || !sp5.isValid())
	{
		std::cerr << "Invalid TestComponent1, program abort" << std::endl;
		exit(0);
	}
	
	if (!sp2.isValid() || !sp4.isValid())
	{
		std::cerr << "Invalid TestComponent2, program abort" << std::endl;
		exit(0);
	}
	
	if (!sp1->PostInit() || !sp3->PostInit() || !sp5->PostInit())
	{
		std::cerr << "TestComponent1, PostInit failure, program abort" << std::endl;
		exit(0);
	}

	if (!sp2->PostInit() || !sp4->PostInit())
	{
		std::cerr << "TestComponent2, PostInit failure, program abort" << std::endl;
		exit(0);
	}

	std::cout << std::endl;
	std::cout << "BEGIN TESTS" << std::endl;
	std::cout << std::endl;

	std::cout << "TEST sp1->TestMethod() shows Implementation TestComponent1" << std::endl;
	sp1->TestMethod();
	std::cout << std::endl;

	std::cout << "TEST sp2->TestMethod() shows Implementation TestComponent2" << std::endl;
	sp2->TestMethod();
	std::cout << std::endl;

	std::cout << "TEST sp1 and sp3 have same name" << std::endl;
	std::cout << "sp1 name :" << sp1->GetName() << std::endl;
	std::cout << "sp3 name :" << sp3->GetName() << std::endl;
	std::cout << std::endl;

	std::cout << "TEST sp5 has unique name" << std::endl;
	std::cout << "sp5 name :" << sp5->GetName() << std::endl;
	std::cout << std::endl;

	std::cout << "TEST sp2 and sp4 have same name" << std::endl;
	std::cout << "sp2 name :" << sp2->GetName() << std::endl;
	std::cout << "sp4 name :" << sp4->GetName() << std::endl;
	std::cout << std::endl;
	std::string pattern = "ITestContract\\.(.*)";

	std::cout << "TEST find contracts using Regex pattern: " << pattern << std::endl;
	auto spList = mf.CreateAll<ITestContract>(pattern);

	for (auto itr = spList.begin(); itr != spList.end(); itr++)
	{
		if (itr->isValid())
		{
			std::cout << "PATTERN TEST FOUND : " << (*itr)->GetName() << std::endl;
		}
	}
}

