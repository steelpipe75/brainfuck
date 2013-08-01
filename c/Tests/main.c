#include <PCUnit/PCUnit.h>
#include <stdio.h>

PCU_Suite *init_suite(void);

int main()
{
	const PCU_SuiteMethod suites[] = {
		init_suite,
	};
	
	PCU_set_putchar(putchar);
	
	return PCU_run( suites, ( sizeof(suites) / sizeof(suites[0]) ) );
}
