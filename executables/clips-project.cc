#include "lib/clips-factory.h"
#include "lib/clips-utils.h"
#include "lib/json.hpp"

using json = nlohmann::json;
const std::string getClipsCode();

int main(int argc, char **argv) {
    auto clips_code = getClipsCode();
    auto clips_factory = project::lib::ClipsFactory(clips_code, true);
    auto clips_env = clips_factory.Create();
    json facts;
    facts["phase"] = "exe_rule";
    facts["var1"] = 1;
    int halt = 0;
    auto result = project::lib::ClipsModuleExecute(clips_env, facts, 100000, "get-clips-result", "", halt);
    std::cout << "clips result:" << result.dump() << std::endl;
}

const std::string getClipsCode() {
    const std::string clips_code = "\
(deffacts control-info \
  (phase-after \"exe_rule\" result) \
) \
(defrule phase-transfer \
  (declare (salience -100)) \
  ?phase <- (phase ?current) \
  (phase-after ?current ?next) \
=> \
  (retract ?phase) \
  (assert (phase ?next)) \
) \
(deftemplate clips_result \
    (multislot hits) \
) \
(deftemplate hit \
  (slot k) \
  (slot v) \
) \
(deffacts default_clips_result \
  (clips_result (hits nil)) \
) \
(deffunction get-clips-result () \
  (nth 1 (find-fact ((?fact clips_result)) TRUE))) \
(defrule RES_result \
  (phase result) \
  (not (DISABLE_RES_RESULT)) \
  ?current <- (clips_result) \
=> \
  (assert (DISABLE_RES_RESULT)) \
  (modify ?current (hits (find-all-facts ((?hit hit)) (neq ?hit:v nil)))) \
) \
(defrule R1 \
  (phase \"exe_rule\") \
  (var1 1) \
  => \
  (assert (hit (k testrule1) (v 1) )) \
) \
";
    return clips_code;
}
