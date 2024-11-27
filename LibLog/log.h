#ifndef LOG_H
#define LOG_H
#include <stdint.h>
#include <stdbool.h>
#define LOG_VERSION 1

typedef enum {
    LOG_EVENTS_OK = 0,
    LOG_PERF,
    LOG_EVENTS_STR,
    LOG_EVENTS_EROR_CRC,
    LOG_EVENTS_EROR_INIT_SERIALPORT
}LOG_EVENTS_t;

#define  LOG_LVL_ASSERT     0
#define  LOG_LVL_ERROR      1
#define  LOG_LVL_WARN       2
#define  LOG_LVL_INFO       3
#define  LOG_LVL_DEBUG      4
#define  LOG_LVL_VERBOSE    5


static bool LOG_TestTrue() {return true;}
static bool LOG_TestFalse() {return false;}
static int LOG_TestSum(int a, int b) {return a+b;}

#pragma pack(push, 1)
typedef struct {
    const uint16_t prefix;
    const uint8_t versinon;
    LOG_EVENTS_t event;
    uint16_t payload_size;
    uint8_t crc;
}LogMessageHeader_t;
#pragma pack(pop)

typedef struct {
    LogMessageHeader_t *header;
    uint8_t *payload;
}LogMessage_t;

typedef struct {
    const char* file;
    const char* func;
    unsigned short line;
} Loglocation_t;

#define CONCAT_(x,y) x##y
#define CONCAT(x,y) CONCAT_(x,y)
#ifdef __cplusplus
extern "C" {
#endif

void LOG_event(LOG_EVENTS_t event);
void LOG_PerfLogPrint(const Loglocation_t *location, const char *code, int perfTime);
void LOG_stringLog(const Loglocation_t *location, uint8_t logLevl, const char *data);

int getTickCount();

#if defined(LOG_BINARY_ENABLE)
#define log_binary(...) LOG_event(__VA_ARGS__); \

#else
#define log_binary(...)       ((void)0);
#endif


#if defined(LOG_PERF_ENABLE)
#define log_perf(...) \
    static Loglocation_t CONCAT(locPerf, __LINE__) = {__FILE__, __FUNCTION__, __LINE__};\
    int CONCAT(curentTime, __LINE__) = getTickCount();\
    __VA_ARGS__;\
    CONCAT(curentTime, __LINE__) = getTickCount() - CONCAT(curentTime, __LINE__);\
    LOG_PerfLogPrint(&CONCAT(locPerf, __LINE__), #__VA_ARGS__, CONCAT(curentTime, __LINE__));
#else
#define log_perf(...)       ((void)0);
#endif




#if !defined(LOG_LVL)
    #define LOG_LVL          -1
#endif

#if LOG_LVL >= LOG_LVL_ASSERT
    #define log_a(...)\
    static Loglocation_t CONCAT(loc, __LINE__) = {__FILE__, __FUNCTION__, __LINE__};\
    LOG_stringLog(&CONCAT(loc, __LINE__),LOG_LVL_ASSERT,__VA_ARGS__);

#else
    #define log_a(...)       ((void)0);
#endif

#if LOG_LVL >= LOG_LVL_ERROR
    #define log_e(...)\
    static Loglocation_t CONCAT(loc, __LINE__) = {__FILE__, __FUNCTION__, __LINE__};\
    LOG_stringLog(&CONCAT(loc, __LINE__),LOG_LVL_ERROR,__VA_ARGS__);
#else
    #define log_e(...)       ((void)0);
#endif

#if LOG_LVL >= LOG_LVL_WARN
    #define log_w(...)\
    static Loglocation_t CONCAT(loc, __LINE__) = {__FILE__, __FUNCTION__, __LINE__};\
    LOG_stringLog(&CONCAT(loc, __LINE__),LOG_LVL_WARN,__VA_ARGS__);
#else
    #define log_w(...)       ((void)0);
#endif

#if LOG_LVL >= LOG_LVL_INFO
    #define log_i(...)\
    static Loglocation_t CONCAT(loc, __LINE__) = {__FILE__, __FUNCTION__, __LINE__};\
    LOG_stringLog(&CONCAT(loc, __LINE__),LOG_LVL_INFO,__VA_ARGS__);
#else
    #define log_i(...)       ((void)0);
#endif

#if LOG_LVL >= LOG_LVL_DEBUG
    #define log_d(...)\
    static Loglocation_t CONCAT(loc, __LINE__) = {__FILE__, __FUNCTION__, __LINE__};\
    LOG_stringLog(&CONCAT(loc, __LINE__),LOG_LVL_DEBUG,__VA_ARGS__);
#else
    #define log_d(...)       ((void)0);
#endif

#if LOG_LVL >= LOG_LVL_VERBOSE
    #define log_v(...)\
    static Loglocation_t CONCAT(loc, __LINE__) = {__FILE__, __FUNCTION__, __LINE__};\
    LOG_stringLog(&CONCAT(loc, __LINE__),LOG_LVL_VERBOSE,__VA_ARGS__);
#else
    #define log_v(...)       ((void)0);
#endif

#endif 
#ifdef __cplusplus
}
#endif // LOG_H

