#pragma once

#define assert_param(expr) ((expr) ? (void)0U : assert_failed(__FILE__, __LINE__))
void assert_failed(char const* file, unsigned line);
