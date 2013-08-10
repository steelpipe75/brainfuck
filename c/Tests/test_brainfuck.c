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
	int test_tapesize;
	int tapesize;
	const char *tapeptr;
	char c;
	int i;
	
	test_tapesize = 256;
	
	bfi = brainfuck_new(test_tapesize);
	
	PCU_ASSERT_PTR_NOT_EQUAL(NULL, bfi);
	
	bfi_ret = brainfuck_get_tapesize(bfi, &tapesize);
	
	PCU_ASSERT_EQUAL(BFI_SUCCESS, bfi_ret);
	PCU_ASSERT_EQUAL(test_tapesize, tapesize);
	
	bfi_ret = brainfuck_get_tapeptr(bfi, &tapeptr);
	
	PCU_ASSERT_EQUAL(BFI_SUCCESS, bfi_ret);
	PCU_ASSERT_PTR_NOT_EQUAL(&c, tapeptr);
	
	for(i = 0; i < tapesize; i++){
		PCU_ASSERT_EQUAL_MESSAGE(0, tapeptr[i], PCU_format("i=%d",i));
	}
	
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

void test_GetTapeptr_error(void)
{
	BFI *bfi;
	int bfi_ret;
	const char *tapeptr;
	char c;
	
	bfi = brainfuck_new(0);
	
	tapeptr = NULL;
	
	bfi_ret = brainfuck_get_tapeptr(bfi, &tapeptr);
	
	PCU_ASSERT_EQUAL(BFI_ERROR, bfi_ret);
	PCU_ASSERT_PTR_EQUAL(NULL, tapeptr);
	
	tapeptr = &c;
	
	bfi_ret = brainfuck_get_tapeptr(bfi, &tapeptr);
	
	PCU_ASSERT_EQUAL(BFI_ERROR, bfi_ret);
	PCU_ASSERT_PTR_EQUAL(&c, tapeptr);
	
	bfi_ret = brainfuck_delete(bfi);
}

void test_GetTapeptr(void)
{
	BFI *bfi;
	int bfi_ret;
	int tapesize;
	int test_tapesize;
	const char *tapeptr;
	char c;
	
	test_tapesize = 256;
	
	bfi = brainfuck_new(test_tapesize);
	
	tapeptr = &c;
	
	bfi_ret = brainfuck_get_tapeptr(bfi, &tapeptr);
	
	PCU_ASSERT_EQUAL(BFI_SUCCESS, bfi_ret);
	PCU_ASSERT_PTR_NOT_EQUAL(&c, tapeptr);
	
	bfi_ret = brainfuck_delete(bfi);
}

PCU_Suite *GetTapeptrTest_suite(void)
{
	static PCU_Test tests[] = {
		PCU_TEST(test_GetTapeptr_error),
		PCU_TEST(test_GetTapeptr),
	};
	static PCU_Suite suite = { "GetTapeptrTest", tests, ( sizeof(tests) / sizeof(tests[0]) ) };
	return &suite;
}

void test_CheckProgramBracket_error(void)
{
	int bfi_ret;
	static const char program1[] = "[";
	static const char program2[] = "[]]";
	
	bfi_ret = brainfuck_check_programbracket( program1, sizeof(program1)/sizeof(program1[0]) );
	
	PCU_ASSERT_EQUAL(BFI_ERROR, bfi_ret);
	
	bfi_ret = brainfuck_check_programbracket( program2, sizeof(program2)/sizeof(program2[0]) );
	
	PCU_ASSERT_EQUAL(BFI_ERROR, bfi_ret);
}

void test_CheckProgramBracket(void)
{
	int bfi_ret;
	static const char program1[] = "+";
	static const char program2[] = "[]";
	
	bfi_ret = brainfuck_check_programbracket( program1, sizeof(program1)/sizeof(program1[0]) );
	
	PCU_ASSERT_EQUAL(BFI_SUCCESS, bfi_ret);
	
	bfi_ret = brainfuck_check_programbracket( program2, sizeof(program2)/sizeof(program2[0]) );
	
	PCU_ASSERT_EQUAL(BFI_SUCCESS, bfi_ret);
}

PCU_Suite *CheckProgramBracketTest_suite(void)
{
	static PCU_Test tests[] = {
		PCU_TEST(test_CheckProgramBracket_error),
		PCU_TEST(test_CheckProgramBracket),
	};
	static PCU_Suite suite = { "CheckProgramBracketTest", tests, ( sizeof(tests) / sizeof(tests[0]) ) };
	return &suite;
}

