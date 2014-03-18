// There is a building of 100 floors. If an egg drops from the Nth floor or 
// above it will break. If it’s dropped from any floor below, it will not break.
// You’re given 2 eggs. 
// Find N, while minimizing the number of drops for the worst case.

straight forward solution:
egg 1: 1(10)  2(20)  3(30) ... 9(90)
egg 2: 9(1-9) 9(11-19)     ... 9(81-89)
Expectation: 1/10 * {(10+18)*9 / 2 + (9+1+4)} = 14

load balanced solution:
egg 1: 1(14)     2(27)     3(39)     ... 11(99)
egg 2: 13(1-13)  12(15-26) 11(28-38) ... 3(96-98)
Expectation: 14
