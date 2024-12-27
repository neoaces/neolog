#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <time.h>
#include "neolog.h"

void nlog_logerr(const nlog_logger_t* logger_config, const char* message, size_t err) {
    nlog_log(logger_config, ERROR, message);
    exit(err);
}

void nlog_log(const nlog_logger_t* logger_config, nlog_loglevel_t level, const char* message, ...) {
    // General format: [ datetime | log level | process name ] message
    assert(logger_config != NULL);
    
    va_list args;
    va_start(args, message);

    if (logger_config->LogLevel >= level) {
		time_t t = time(NULL);
		struct tm *tm  = localtime(&t);
		char s[64];
		strftime(s, 64, "%Y:%H:%M:%S", tm);
		
		printf("\033[31m[%s | %s | %s ]\033[0m ", s, _nlog_levelstr(level), logger_config->process_name);
		vprintf(message, args); // Uses the variadic arguments to print out the format specifiers.
		printf("\n");
		
		fflush(stdout);
    }

    va_end(args);
}

const char* _nlog_levelstr(nlog_loglevel_t level) {
    switch (level) {
	case ERROR:
	    return "ERROR";
	    break;
	case DEBUG:
	    return "DEBUG";
	    break;
	case INFO:
	    return "INFO";
	    break;
	default:
	    "";
	    break;
    }
}
