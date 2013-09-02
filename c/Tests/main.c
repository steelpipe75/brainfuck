#include <PCUnit/PCUnit.h>
#include <stdio.h>

PCU_Suite *NewDeleteTest_suite(void);
PCU_Suite *GetSetPutcharGetcharTest_suite(void);
PCU_Suite *GetTapesizeTest_suite(void);
PCU_Suite *GetTapeptrTest_suite(void);
PCU_Suite *GetProgramsizeTest_suite(void);
PCU_Suite *GetProgramptrTest_suite(void);
PCU_Suite *CheckProgramBracketTest_suite(void);
PCU_Suite *StepTest_suite(void);

int main()
{
	const PCU_SuiteMethod suites[] = {
		NewDeleteTest_suite,
		GetSetPutcharGetcharTest_suite,
		GetTapesizeTest_suite,
		GetTapeptrTest_suite,
		GetProgramsizeTest_suite,
		GetProgramptrTest_suite,
		CheckProgramBracketTest_suite,
		StepTest_suite,
	};
	
	PCU_set_putchar(putchar);
	PCU_enable_color();
	PCU_set_verbose(1);
	
	return PCU_run( suites, ( sizeof(suites) / sizeof(suites[0]) ) );
}
