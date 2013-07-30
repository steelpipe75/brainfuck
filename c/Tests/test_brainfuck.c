#include <PCUnit.h>

#include "brainfuck.h"

void test_init(void)
{
	char buff[1];
	
	buff[0] = 1;
	
	brainfuck_init( buff, sizeof(buff) );
	
	PCU_ASSERT_EQUAL(0, buff[0]);
}

PCU_Suite *init_suite(void)
{
	static PCU_Test tests[] = {
		PCU_TEST(test_init),
	};
	static PCU_Suite suite = { "init-test", tests, ( sizeof(tests) / sizeof(tests[0]) ) };
	return &suite;
}

