#include <PCUnit/PCUnit.h>
#include <stdio.h>

PCU_Suite *NewDeleteTest_suite(void);
PCU_Suite *GetTapesizeTest_suite(void);

int main()
{
	const PCU_SuiteMethod suites[] = {
		NewDeleteTest_suite,
		GetTapesizeTest_suite,
	};
	
	PCU_set_putchar(putchar);
	PCU_enable_color();
	PCU_set_verbose(1);
	
	return PCU_run( suites, ( sizeof(suites) / sizeof(suites[0]) ) );
}
