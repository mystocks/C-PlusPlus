// TestBoostDll.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"

//	�˺���붨�壬�������ӵ�boost��̬��汾
//	�����·��ʹ�õ����ұ��صľ���·���������������޸�
//	��������ʱ���Զ���ȥboost\\libĿ¼�½��в��Ҷ�Ӧ��lib�ļ���lib�ļ�����ʹ��auto_link.hpp��̬���õ�
//	ʹ��֮ǰ����Ҫ�ȱ���console_test_runner.exe�������Ŀ¼��\libs\test\tools\console_test_runner
//	����ʱ������Ҫʹ�ö�Ӧ��Dll��dll�ļ���boost����Ķ�̬��Ŀ¼��Debug���ṩ�ұ������ɵ�һ�ݣ������Լ�
//	��������Ҳ����
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