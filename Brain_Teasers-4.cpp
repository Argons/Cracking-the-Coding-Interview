// A bunch of men are on an island. A genie comes down and gathers everyone 
// together and places a magical hat on some people’s heads (i.e., at least 
// one person has a hat). The hat is magical: it can be seen by other people, 
// but not by the wearer of the hat himself. To remove the hat, those (and 
// only those who have a hat) must dunk themselves underwater at exactly 
// midnight. If there are n people and c hats, how long does it take the men 
// to remove the hats? The men cannot tell each other (in any way) that they 
// have a hat.

// FOLLOW UP
// Prove that your solution is correct.

Men must realize themselves that they are wearing the hat to remove it.
Assume they are all intelligent and capable of making deductions,
case c == 1: time = 1;
case c == 2: time = 1 + 1 = 2;
...
...
case c == n: time = time(n-1) + 1 = n;
