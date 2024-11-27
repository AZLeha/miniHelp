#include <cxxtest/TestSuite.h>
#include <log.h>

class MyTestSuite : public CxxTest::TestSuite
{
public:
    void testSum( void ) {
        TS_ASSERT( 1 + 1 > 1 );
        TS_ASSERT_EQUALS(LOG_TestSum(3,7), 10);
    }

    void testTrue( void ) {
        TS_ASSERT( LOG_TestTrue());
    }

    void testFalse() {
        TS_ASSERT_DIFFERS(LOG_TestFalse(),true)
    }
};
