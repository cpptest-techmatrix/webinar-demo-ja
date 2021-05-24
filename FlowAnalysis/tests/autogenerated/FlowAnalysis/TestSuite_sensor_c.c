#include "cpptest.h"

/* CPPTEST_TEST_SUITE_CODE_BEGIN AdditionalIncludes */
/* CPPTEST_TEST_SUITE_CODE_END AdditionalIncludes */

CPPTEST_CONTEXT("/FlowAnalysis/sensor.c");
CPPTEST_TEST_SUITE_INCLUDED_TO("/FlowAnalysis/sensor.c");

EXTERN_C_LINKAGE void TestSuite_sensor_c_269316db_testSuiteBegin(void);
EXTERN_C_LINKAGE int TestSuite_sensor_c_269316db_callTest(const char*);

CPPTEST_TEST_SUITE(TestSuite_sensor_c_269316db);
        CPPTEST_TEST_SUITE_SETUP(TestSuite_sensor_c_269316db_testSuiteSetUp);
        CPPTEST_TEST_SUITE_TEARDOWN(TestSuite_sensor_c_269316db_testSuiteTearDown);
CPPTEST_TEST(TestSuite_sensor_c_269316db_test_case);
CPPTEST_TEST_SUITE_END();
        

void TestSuite_sensor_c_269316db_test_case(void);
CPPTEST_TEST_SUITE_REGISTRATION(TestSuite_sensor_c_269316db);

void TestSuite_sensor_c_269316db_testSuiteSetUp(void);
void TestSuite_sensor_c_269316db_testSuiteSetUp(void)
{
/* CPPTEST_TEST_SUITE_CODE_BEGIN TestSuiteSetUp */
/* CPPTEST_TEST_SUITE_CODE_END TestSuiteSetUp */
}

void TestSuite_sensor_c_269316db_testSuiteTearDown(void);
void TestSuite_sensor_c_269316db_testSuiteTearDown(void)
{
/* CPPTEST_TEST_SUITE_CODE_BEGIN TestSuiteTearDown */
/* CPPTEST_TEST_SUITE_CODE_END TestSuiteTearDown */
}

void TestSuite_sensor_c_269316db_setUp(void);
void TestSuite_sensor_c_269316db_setUp(void)
{
/* CPPTEST_TEST_SUITE_CODE_BEGIN TestCaseSetUp */
/* CPPTEST_TEST_SUITE_CODE_END TestCaseSetUp */
}

void TestSuite_sensor_c_269316db_tearDown(void);
void TestSuite_sensor_c_269316db_tearDown(void)
{
/* CPPTEST_TEST_SUITE_CODE_BEGIN TestCaseTearDown */
/* CPPTEST_TEST_SUITE_CODE_END TestCaseTearDown */
}


/* CPPTEST_TEST_CASE_BEGIN test_case */
/* CPPTEST_TEST_CASE_CONTEXT int addSignals(int, int, int) */
void TestSuite_sensor_c_269316db_test_case()
{
/* CPPTEST_TEST_CASE_DATA_BEGIN */
#if 0

<?xml version="1.0" encoding="UTF-8" standalone="no"?>
<testcase>
    <metadata/>
    <steps>
        <step id="MultiVariableStep" uid="0" version="1">
            <step id="VariableStep" version="1">
                <name>_signalA</name>
                <type>int</type>
                <value>0</value>
            </step>
            <step id="VariableStep" version="1">
                <name>_signalB</name>
                <type>int</type>
                <value>0</value>
            </step>
            <step id="VariableStep" version="1">
                <name>_temp</name>
                <type>int</type>
                <value>0</value>
            </step>
            <step id="VariableStep" version="1">
                <name>_return</name>
                <type>int</type>
                <value/>
            </step>
        </step>
        <step id="CallStep" uid="1" version="1">
            <comment>Tested function call</comment>
            <return>_return</return>
            <name>addSignals</name>
            <params>_signalA, _signalB, _temp</params>
        </step>
        <step id="AssertionsStep" uid="2" version="1">
            <step id="AssertionStep" uid="2.0" version="1">
                <type>CPPTEST_ASSERT_INTEGER_EQUAL</type>
                <P1>0</P1>
                <P2>_return</P2>
                <P3/>
                <P4/>
            </step>
        </step>
    </steps>
</testcase>

#endif
/* CPPTEST_TEST_CASE_DATA_END */
int _signalA = 0;
int _signalB = 0;
int _temp = 0;
int _return;
/* CPPTEST_TC_STEP_UID:1 */
_return = addSignals(_signalA, _signalB, _temp);
/* CPPTEST_TC_STEP_UID:2.0 */
CPPTEST_ASSERT_INTEGER_EQUAL(0, _return);
}
/* CPPTEST_TEST_CASE_END test_case */
