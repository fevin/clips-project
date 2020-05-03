#include "lib/clips-factory.h"

namespace project {
namespace lib {
ClipsFactory::ClipsFactory(const std::string &rules, bool whether_check_syntax) : _rules(rules), _whether_check_syntax(whether_check_syntax) {
}

void ClipsFactory::Destroy(void *clips) {
    if (clips) {
        DestroyEnvironment(clips);
    }
}

void *ClipsFactory::Create() {
    return createClipsEnvFromRuleString();
}

void *ClipsFactory::createClipsEnvFromRuleString() {
    std::string error_rules = "";
    clips_ptr clips;
    if (_whether_check_syntax) {
        std::string error_rules = "";
        clips = CreateClipsWithSyntaxCheck(_rules, error_rules);
        if (!error_rules.empty()) {
            std::cerr << "clips syntax error, code:" << error_rules << std::endl;
        }
        std::cout << "clips code check syntax and load successfully!" << std::endl;
    } else {
        clips = CreateClips(_rules);
        std::cout << "clips code load successfully!" << std::endl;
        std::cout << _rules << std::endl;
    }
    return clips.release();
}

};  // namespace lib
};  // namespace project
