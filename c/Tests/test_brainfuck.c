#include <PCUnit/PCUnit.h>

#include "brainfuck.h"

typedef struct NEW_DELETE_TEST_DATA{
	const char *ptr_program;
	int programsize;
	int tapesize;
}NEW_DELETE_TEST_DATA;

#define NEW_DELETE_TEST(x,y)	{(x), sizeof(x)/sizeof(x[0]), y}

typedef struct PROG_BRACKET_TEST_DATA{
	const char *ptr_program;
	int programsize;
}PROG_BRACKET_TEST_DATA;

#define PROG_BRACKET_TEST(x)	{(x), sizeof(x)/sizeof(x[0])}

static const char program1[] = "+";
static const char program2[] = "[]";

static const char err_program1[] = "[";
static const char err_program2[] = "[]][";
static const char err_program3[] = "[]]";

void test_NewDelete_error(void)
{
	BFI *bfi;
	int bfi_ret;
	
	int i;
	
	static const NEW_DELETE_TEST_DATA programs[] = {
		NEW_DELETE_TEST(program1,0),
		NEW_DELETE_TEST(err_program1,256),
		NEW_DELETE_TEST(err_program2,256),
		NEW_DELETE_TEST(err_program3,256),
	};
	int program_num = sizeof(programs)/sizeof(programs[0]);
	
	for(i = 0; i < program_num; i++){
		bfi = brainfuck_new(programs[i].ptr_program, programs[i].programsize, programs[i].tapesize);
		
		PCU_ASSERT_PTR_EQUAL_MESSAGE(NULL, bfi, PCU_format("i=%d",i));
		
		bfi_ret = brainfuck_delete(bfi);
		
		PCU_ASSERT_EQUAL_MESSAGE(BFI_ERROR, bfi_ret, PCU_format("i=%d",i));
	}
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
	
	bfi = brainfuck_new(program1, sizeof(program1)/sizeof(program1[0]), test_tapesize);
	
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
	
	bfi = brainfuck_new(program1, sizeof(program1)/sizeof(program1[0]), 0);
	
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
	
	bfi = brainfuck_new(program1, sizeof(program1)/sizeof(program1[0]), test_tapesize);
	
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
	
	bfi = brainfuck_new(program1, sizeof(program1)/sizeof(program1[0]), 0);
	
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
	
	bfi = brainfuck_new(program1, sizeof(program1)/sizeof(program1[0]), test_tapesize);
	
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

void test_GetProgramsize_error(void)
{
	BFI *bfi;
	int bfi_ret;
	int programsize;
	
	bfi = brainfuck_new(program1, sizeof(program1)/sizeof(program1[0]), 0);
	
	programsize = 0;
	
	bfi_ret = brainfuck_get_programsize(bfi, &programsize);
	
	PCU_ASSERT_EQUAL(BFI_ERROR, bfi_ret);
	PCU_ASSERT_EQUAL(0, programsize);
	
	programsize = 256;
	
	bfi_ret = brainfuck_get_programsize(bfi, &programsize);
	
	PCU_ASSERT_EQUAL(BFI_ERROR, bfi_ret);
	PCU_ASSERT_EQUAL(256, programsize);
	
	bfi_ret = brainfuck_delete(bfi);
}

void test_GetProgramsize(void)
{
	BFI *bfi;
	int bfi_ret;
	int programsize;
	int test_tapesize;
	
	test_tapesize = 256;
	
	bfi = brainfuck_new(program1, sizeof(program1)/sizeof(program1[0]), test_tapesize);
	
	bfi_ret = brainfuck_get_programsize(bfi, &programsize);
	
	PCU_ASSERT_EQUAL(BFI_SUCCESS, bfi_ret);
	PCU_ASSERT_EQUAL(sizeof(program1), programsize);
	
	bfi_ret = brainfuck_delete(bfi);
}

PCU_Suite *GetProgramsizeTest_suite(void)
{
	static PCU_Test tests[] = {
		PCU_TEST(test_GetProgramsize_error),
		PCU_TEST(test_GetProgramsize),
	};
	static PCU_Suite suite = { "GetProgramsizeTest", tests, ( sizeof(tests) / sizeof(tests[0]) ) };
	return &suite;
}

void test_GetProgramptr_error(void)
{
	BFI *bfi;
	int bfi_ret;
	const char *programptr;
	char c;
	
	bfi = brainfuck_new(program1, sizeof(program1)/sizeof(program1[0]), 0);
	
	programptr = NULL;
	
	bfi_ret = brainfuck_get_programptr(bfi, &programptr);
	
	PCU_ASSERT_EQUAL(BFI_ERROR, bfi_ret);
	PCU_ASSERT_PTR_EQUAL(NULL, programptr);
	
	programptr = &c;
	
	bfi_ret = brainfuck_get_programptr(bfi, &programptr);
	
	PCU_ASSERT_EQUAL(BFI_ERROR, bfi_ret);
	PCU_ASSERT_PTR_EQUAL(&c, programptr);
	
	bfi_ret = brainfuck_delete(bfi);
}

void test_GetProgramptr(void)
{
	BFI *bfi;
	int bfi_ret;
	int tapesize;
	int test_tapesize;
	const char *programptr;
	char c;
	
	test_tapesize = 256;
	
	bfi = brainfuck_new(program1, sizeof(program1)/sizeof(program1[0]), test_tapesize);
	
	programptr = &c;
	
	bfi_ret = brainfuck_get_programptr(bfi, &programptr);
	
	PCU_ASSERT_EQUAL(BFI_SUCCESS, bfi_ret);
	PCU_ASSERT_PTR_NOT_EQUAL(&c, programptr);
	PCU_ASSERT_PTR_NOT_EQUAL(program1, programptr);
		
	bfi_ret = brainfuck_delete(bfi);
}

PCU_Suite *GetProgramptrTest_suite(void)
{
	static PCU_Test tests[] = {
		PCU_TEST(test_GetProgramptr_error),
		PCU_TEST(test_GetProgramptr),
	};
	static PCU_Suite suite = { "GetProgramptrTest", tests, ( sizeof(tests) / sizeof(tests[0]) ) };
	return &suite;
}

void test_CheckProgramBracket_error(void)
{
	int bfi_ret;
	
	int i;
	
	static const PROG_BRACKET_TEST_DATA programs[] = {
		PROG_BRACKET_TEST(err_program1),
		PROG_BRACKET_TEST(err_program2),
		PROG_BRACKET_TEST(err_program3),
	};
	int program_num = sizeof(programs)/sizeof(programs[0]);
	
	for(i = 0; i < program_num; i++){
		bfi_ret = brainfuck_check_programbracket(programs[i].ptr_program, programs[i].programsize);
		
		PCU_ASSERT_EQUAL_MESSAGE(BFI_ERROR, bfi_ret, PCU_format("i=%d",i));
	}
}

void test_CheckProgramBracket(void)
{
	int bfi_ret;
	
	int i;
	
	static const PROG_BRACKET_TEST_DATA programs[] = {
		PROG_BRACKET_TEST(program1),
		PROG_BRACKET_TEST(program2),
	};
	int program_num = sizeof(programs)/sizeof(programs[0]);
	
	for(i = 0; i < program_num; i++){
		bfi_ret = brainfuck_check_programbracket(programs[i].ptr_program, programs[i].programsize);
		
		PCU_ASSERT_EQUAL_MESSAGE(BFI_SUCCESS, bfi_ret, PCU_format("i=%d",i));
	}
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

