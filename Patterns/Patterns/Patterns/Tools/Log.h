#pragma once

#include <source_location>

void Log_old(const char* message);

void Log(const char* message, std::source_location loc = std::source_location::current());

