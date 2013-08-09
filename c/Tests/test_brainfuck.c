#include <PCUnit/PCUnit.h>

#include "brainfuck.h"

void test_NewDelete_error(void)
{
	BFI *bfi;
	int bfi_ret;
	
	bfi = brainfuck_new(0);
	
	PCU_ASSERT_PTR_EQUAL(NULL, bfi);
	
	bfi_ret = brainfuck_delete(bfi);
	
	PCU_ASSERT_EQUAL(BFI_ERROR, bfi_ret);
}

void test_NewDelete(void)
{
	BFI *bfi;
	int bfi_ret;
	
	bfi = brainfuck_new(256);
	
	PCU_ASSERT_PTR_NOT_EQUAL(NULL, bfi);
	
	bfi_ret = brainfuck_delete(bfi);
	
	PCU_ASSERT_EQUAL(BFI_SUCCESS, bfi_ret);
}

PCU_Suite *NewDeleteTest_suite(void)
{
	static PCU_Test tests[] = {
		PCU_TEST(test_NewDelete_error),
		PCU_TEST(test_NewDelete),
	};
	static PCU_Suite suite = { "NewDeleteTest", tests, ( sizeof(tests) / sizeof(tests[0]) ) };
	return &suite;
}

void test_GetTapesize_error(void)
{
	BFI *bfi;
	int bfi_ret;
	int tapesize;
	
	bfi = brainfuck_new(0);
	
	tapesize = 0;
	
	bfi_ret = brainfuck_get_tapesize(bfi, &tapesize);
	
	PCU_ASSERT_EQUAL(BFI_ERROR, bfi_ret);
	PCU_ASSERT_EQUAL(0, tapesize);
	
	tapesize = 256;
	
	bfi_ret = brainfuck_get_tapesize(bfi, &tapesize);
	
	PCU_ASSERT_EQUAL(BFI_ERROR, bfi_ret);
	PCU_ASSERT_EQUAL(256, tapesize);
	
	bfi_ret = brainfuck_delete(bfi);
}

void test_GetTapesize(void)
{
	BFI *bfi;
	int bfi_ret;
	int tapesize;
	int test_tapesize;
	
	test_tapesize = 256;
	
	bfi = brainfuck_new(test_tapesize);
	
	bfi_ret = brainfuck_get_tapesize(bfi, &tapesize);
	
	PCU_ASSERT_EQUAL(BFI_SUCCESS, bfi_ret);
	PCU_ASSERT_EQUAL(test_tapesize, tapesize);
	
	bfi_ret = brainfuck_delete(bfi);
}

PCU_Suite *GetTapesizeTest_suite(void)
{
	static PCU_Test tests[] = {
		PCU_TEST(test_GetTapesize_error),
		PCU_TEST(test_GetTapesize),
	};
	static PCU_Suite suite = { "GetTapesizeTest", tests, ( sizeof(tests) / sizeof(tests[0]) ) };
	return &suite;
}

