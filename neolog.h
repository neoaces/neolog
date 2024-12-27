#pragma once
#include <stdio.h> // IWYU pragma: keep
/**
 * @file Neolog
 * @brief Basic library for logging used in neophys.
 *
 */

// TODO Customize the colours for the different log levels (blue for info, green for debug)

#define static nlog_logger_t LOGGER_CONFIG

/**
 * @typedef nlog_LogLevel
 * @brief Level of logging, ERROR < INFO < DEBUG
 *
 */
typedef enum nlog_LogLevel {
    ERROR = 0,
    INFO = 1,
    DEBUG = 2,
} nlog_loglevel_t;

/**
 * @typedef nlog_Logger
 * @brief Configuration struct for logger
 *
 */
typedef struct nlog_Logger {
    nlog_loglevel_t LogLevel; 
    const char* process_name;
} nlog_logger_t;

/**
 * @brief Logs the message at the current level. Takes in a global logger_config to define if it is logged. Any number of variables can be included in the format specifier. There are no checks if there are not enough arguments for the format. 
 *
 * @param logger_config The global configuration of the logger
 * @param level Level of logging for message message
 * @param message Log message
 */
void nlog_log(const nlog_logger_t* logger_config, nlog_loglevel_t level, const char* message, ...);


/**
 * @brief Returns a string representing the current log level.
 *
 * @param level LogLevel
 * @return Name of LogLevel level
 */
const char* _nlog_levelstr(nlog_loglevel_t level);

/**
 * @brief Logs an error, and exits on return
 *
 * @param logger_config The global configuration of the logger
 * @param message Log message
 * @param err Exit code
 */
void nlog_logerr(const nlog_logger_t* logger_config, const char* message, size_t err);
