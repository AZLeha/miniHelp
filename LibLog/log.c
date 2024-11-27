#include "log.h"
#include <stdio.h>
#include <sys/time.h>

#define LOG_PRFIX 0x0FAA

static const char LOG_LVL_c[] = {'A','E','W','I','D','V'};

static  LogMessageHeader_t logeHeader = {.prefix = LOG_PRFIX, .versinon = LOG_VERSION};

static LogMessage_t message = {.header = &logeHeader, .payload = NULL};


void LOG_event(LOG_EVENTS_t event)
{
    logeHeader.event = event;
    logeHeader.payload_size = 0;
    logeHeader.crc = 0xAA;
    if(event == LOG_EVENTS_STR) return;

    const uint8_t *header = (uint8_t*)&logeHeader;
    for(int i = 0; i<sizeof (LogMessageHeader_t); i++){
        printf("0x%.2X ", header[i]);
    }
    printf("\r\n");
}


void LOG_stringLog(const Loglocation_t *location, uint8_t logLevl, const char *data)
{
    message.header->event =LOG_EVENTS_STR;
    logeHeader.crc = 0xAA;
    logeHeader.payload_size = 0;

    const uint8_t *header = (uint8_t*)&logeHeader;
    for(int i = 0; i<sizeof (LogMessageHeader_t); i++){
        printf("0x%.2X ", header[i]);
    }
    printf(" %c: %s %s %d (%s)\r\n",LOG_LVL_c[logLevl],location->file, location->func, location->line, data);
}


void LOG_PerfLogPrint(const Loglocation_t *location, const char *code, int perfTime)
{
    message.header->event =LOG_PERF;
    logeHeader.crc = 0xAA;
    logeHeader.payload_size = 0;

    const uint8_t *header = (uint8_t*)&logeHeader;
    for(int i = 0; i<sizeof (LogMessageHeader_t); i++){
        printf("0x%.2X ", header[i]);
    }

    printf(" PERF: %s %s %d (%s), time=%d\r\n",location->file, location->func, location->line, code, perfTime);
}


int getTickCount(){

    return clock();
}
