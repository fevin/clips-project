#pragma once
#include <string>
#include <stdexcept>
#include <unordered_map>

#include "lib/clips-utils.h"

namespace project {
namespace lib {
class ClipsFactory {
   public:
    ClipsFactory(const std::string &rules, bool whether_check_syntax = false);
    void *Create();
    void Destroy(void *clips);

   private:
    void *createClipsEnvFromRuleString();

    std::string _rules;
    bool _whether_check_syntax;
};
};  // namespace lib
};  // namespace project
