#include <regex>
#include "clips.h"

using std::regex;
using std::regex_match;

extern "C" int rlike(void *env) {
    // argument checking, return false if failed
    DATA_OBJECT temp;
    if (EnvArgCountCheck(env, "rlike", EXACTLY, 2) == -1) return 0;
    if (EnvArgTypeCheck(env, "rlike", 1, SYMBOL_OR_STRING, &temp) == 0)
        return 0;
    if (EnvArgTypeCheck(env, "rlike", 2, SYMBOL_OR_STRING, &temp) == 0)
        return 0;
    try {
        const regex pattern(EnvRtnLexeme(env, 1));
        bool match = regex_match(EnvRtnLexeme(env, 2), pattern);
        return match ? 1 : 0;
    } catch (...) {
        return 0;
    }
}
