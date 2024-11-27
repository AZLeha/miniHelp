#include <stdio.h>

//#define LOG_BINARY_ENABLE
//#define LOG_LVL LOG_LVL_ERROR
#define LOG_LVL LOG_LVL_VERBOSE
//#define LOG_PERF_ENABLE


#include "log.h"

void testF(){
       log_a("This is ASSERT log");
}
int main()
{

    printf("====================TestlogEhample===============\n\n");
    log_perf(
        for(int i = 0; i<1000; i++) {}
         for(int i = 0; i<1000; i++) {}
    );
    log_binary(LOG_EVENTS_EROR_CRC);
    log_a("This is ASSERT log");
    log_e("This is ERROR log");
    log_w("This is WARNING log");
    log_i("This is INFO log");
    log_d("This is DEBUG log");
    log_v("This is VERBOSE log");


       log_a("This is ASSERT log");
    #define make_str( bar ) # bar
    printf( make_str( 42 ));
    //Эквивалент
//    printf("42");

    #define MakePosition( x ) x##X, x##Y, x##Width, x##Height
    int MakePosition( Object );
//    int ObjectX, ObjectY, ObjectWidth, ObjectHeight;
    testF();
    printf("\n");


    return 0;
}





