#include <string>
#include "clips.h"

extern "C" long long str_to_integer(void *env) {
    // argument checking, return 0 if failed
    long long default_value = 0;
    auto argc = EnvRtnArgCount(env);
    if (argc > 2 || argc == 0) return default_value;
    if (argc == 2) {
        default_value = EnvRtnLong(env, 2);
    }

    try {
        return std::stoll(EnvRtnLexeme(env, 1));
    } catch (...) {
        return default_value;
    }
}
