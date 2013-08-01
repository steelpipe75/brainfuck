#include <PCUnit/PCUnit.h>

#include "brainfuck.h"

void test_new(void)
{
	BFI *bfi;
	
	bfi = brainfuck_new(0);
	
	PCU_ASSERT_PTR_EQUAL(NULL, bfi);
}

void test_delete(void)
{
	int bfi_ret;
	
	bfi_ret = brainfuck_delete(NULL);
	
	PCU_ASSERT_EQUAL(BFI_ERROR, bfi_ret);
}

PCU_Suite *NewDeleteTest_suite(void)
{
	static PCU_Test tests[] = {
		PCU_TEST(test_new),
		PCU_TEST(test_delete),
	};
	static PCU_Suite suite = { "NewDeleteTest", tests, ( sizeof(tests) / sizeof(tests[0]) ) };
	return &suite;
}

