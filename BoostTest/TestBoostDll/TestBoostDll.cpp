// TestBoostDll.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"

//	此宏必须定义，并且链接的boost动态库版本
//	这里的路径使用的是我本地的绝对路径，其他请自行修改
//	编译链接时，自动会去boost\\lib目录下进行查找对应的lib文件，lib文件名是使用auto_link.hpp动态配置的
//	使用之前，需要先编译console_test_runner.exe，编译的目录在\libs\test\tools\console_test_runner
//	测试时，还需要使用对应的Dll，dll文件在boost编译的动态库目录，Debug已提供我编译生成的一份，或者自己
//	编译生成也可以
#ifndef BOOST_TEST_DYN_LINK 
#define BOOST_TEST_DYN_LINK
#endif

#include "boost/test/unit_test.hpp"
#include <map>
#include <vector>
int MySum(int a, int b)
{
	return a + b;
}

BOOST_AUTO_TEST_SUITE(aaa)
BOOST_AUTO_TEST_CASE(FirstDllTest)
{
	BOOST_CHECK_EQUAL(2, MySum(1,1));
	BOOST_CHECK(3 == MySum(1,3));
	BOOST_CHECK(5 == MySum(3,3));
}
BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE(bbbb)
BOOST_AUTO_TEST_CASE(SecondDllTest)
{
	BOOST_CHECK_EQUAL(3, MySum(2,1));
	BOOST_CHECK(3 == MySum(0,3));
	BOOST_CHECK(5 == MySum(2,3));
}
BOOST_AUTO_TEST_SUITE_END()

extern "C" {

#ifdef BOOST_WINDOWS
	__declspec(dllexport)
#endif
		bool
		init_unit_test()
	{
		printf("Enter init_unit_test\n");
		boost::unit_test::framework::master_test_suite().p_name.value = "Test runner test";

		return true;
	}

}