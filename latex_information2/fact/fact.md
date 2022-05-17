# 提出シート

## 結果1: 最初のコンパイル
- 結果貼付欄
```
== Test abs ==
All tests are Ok. [# of Tests = 1, # of pass = 1 (100%)]
```
- 考察記入欄


## 結果2: 最初のテスト
- 結果貼付欄
```
testFact.c:8:21: error: implicit declaration of function 'fact' is invalid in C99 [-Werror,-Wimplicit-function-declaration]
    assertEqualsInt(fact(1), 1);  // 1 の階乗は 1 かどうか?
                    ^
```
- 考察記入欄

## 結果3: プロトタイプ宣言記入後
- 結果貼付欄
```
Undefined symbols for architecture x86_64:
  "_fact", referenced from:
      _testFact in testFact.o
ld: symbol(s) not found for architecture x86_64
clang: error: linker command failed with exit code 1 (use -v to see invocation)
```
- 考察記入欄

## 結果4: 関数の雛形を作成
- 結果貼付欄
```
== Test fact ==
Error in testFact.c(8): a != b (0 != 1)
###### Error exist!!!! [# of Tests = 1, # of pass = 0 (0%)] ######
make: *** [testFact] Error 1
```
- 考察記入欄


## 結果5: 辻褄合わせの成功
- 結果貼付欄
```
== Test fact ==
All tests are Ok. [# of Tests = 1, # of pass = 1 (100%)]
```
- 考察記入欄


## 結果6: テストを追加
- 結果貼付欄
```
== Test fact ==
Error in testFact.c(10): a != b (1 != 2)
Error in testFact.c(11): a != b (1 != 6)
Error in testFact.c(12): a != b (1 != 720)
###### Error exist!!!! [# of Tests = 5, # of pass = 2 (40%)] ######
```
- 考察記入欄

## 結果7: ちゃんとした実装
- 結果貼付欄
```
== Test fact ==
All tests are Ok. [# of Tests = 5, # of pass = 5 (100%)]
```
- 考察記入欄

## 結果8: 0の階乗、負の会場のテスト
- 結果貼付欄
```
== Test fact ==
Error in testFact.c(14): a != b (1 != -1)
Error in testFact.c(15): a != b (6 != -6)
```
- 考察記入欄


## 結果9: 完成
- 結果貼付欄
```
== Test fact ==
All tests are Ok. [# of Tests = 8, # of pass = 8 (100%)]
```
- 考察記入欄
