# clips-project
本项目为 `CLIPS` 规则引擎应用的 `demo`，演示了如何将 `CLIPS` 规则引擎嵌入到 `C++` 项目中。
`CLIPS` 的学习和使用可以参考这篇文章：[CLIPS 规则引擎介绍与使用](https://fevin.art/post/clips-rule-engine-introduction/)

使用示例：
```
✗ ./bin/build.sh
✗ ./dist/clips-project
clips code check syntax and load successfully!
==> f-3     (phase "exe_rule")
==> Activation -100   phase-transfer: f-3,f-1
==> f-4     (var1 1)
==> Activation 0      R1: f-3,f-4
FIRE    1 R1: f-3,f-4
==> f-5     (hit (k testrule1) (v 1))
FIRE    2 phase-transfer: f-3,f-1
<== f-3     (phase "exe_rule")
==> f-6     (phase result)
==> Activation 0      RES_result: f-6,*,f-2
FIRE    3 RES_result: f-6,*,f-2
==> f-7     (DISABLE_RES_RESULT)
<== f-2     (clips_result (hits nil))
==> f-8     (clips_result (hits <Fact-5>))
<== Focus MAIN
3 rules fired
6 mean number of facts (7 maximum).
1 mean number of instances (1 maximum).
1 mean number of activations (2 maximum).
DFN >> get-clips-result ED:1 ()
DFN << get-clips-result ED:1 ()
clips result:{"hits":[{"k":"testrule1","v":1}]}
```

执行结果的最后一行是从规则引擎中获取到的规则执行结果，中间的输出是开启了 `watch all` 功能，而打印出的执行过程。
