CFLAGS = -Wall -fpic -coverage -lm

rngs.o: rngs.h rngs.c
	gcc -c rngs.c -g  $(CFLAGS)

dominion.o: dominion.h dominion.c rngs.o
	gcc -c dominion.c -g  $(CFLAGS)

adventurer:
	gcc -fprofile-arcs -ftest-coverage -Wall -std=c99 dominion.c randomtestadventurer.c rngs.c -o randomtestadventurer -lm -g

runTestDominion:
	gcc -fprofile-arcs -ftest-coverage -Wall -std=c99 dominion.c testdominion.c rngs.c -o testdominion -lm -g

#tarantula makefile stuff
testcase1:
	gcc -fprofile-arcs -ftest-coverage -Wall -std=c99 dominion.c testcase1.c rngs.c -o testcase1 -lm -g

testcase2:
	gcc -fprofile-arcs -ftest-coverage -Wall -std=c99 dominion.c testcase2.c rngs.c -o testcase2 -lm -g

testcase3:
	gcc -fprofile-arcs -ftest-coverage -Wall -std=c99 dominion.c testcase3.c rngs.c -o testcase3 -lm -g

testcase4:
	gcc -fprofile-arcs -ftest-coverage -Wall -std=c99 dominion.c testcase4.c rngs.c -o testcase4 -lm -g

testcase5:
	gcc -fprofile-arcs -ftest-coverage -Wall -std=c99 dominion.c testcase5.c rngs.c -o testcase5 -lm -g

testcase6:
	gcc -fprofile-arcs -ftest-coverage -Wall -std=c99 dominion.c testcase6.c rngs.c -o testcase6 -lm -g

testcase7:
	gcc -fprofile-arcs -ftest-coverage -Wall -std=c99 dominion.c testcase7.c rngs.c -o testcase7 -lm -g

testcase8:
	gcc -fprofile-arcs -ftest-coverage -Wall -std=c99 dominion.c testcase8.c rngs.c -o testcase8 -lm -g

testcase9:
	gcc -fprofile-arcs -ftest-coverage -Wall -std=c99 dominion.c testcase9.c rngs.c -o testcase9 -lm -g

testcase10:
	gcc -fprofile-arcs -ftest-coverage -Wall -std=c99 dominion.c testcase10.c rngs.c -o testcase10 -lm -g

testcase11:
	gcc -fprofile-arcs -ftest-coverage -Wall -std=c99 dominion.c testcase11.c rngs.c -o testcase11 -lm -g

testcase12:
	gcc -fprofile-arcs -ftest-coverage -Wall -std=c99 dominion.c testcase12.c rngs.c -o testcase12 -lm -g

testout1: testcase1
	./testcase1 &> testcase1.out
	gcov dominion.c >> testcase1.out
	cat dominion.c.gcov >> testcase1.out

testout2: testcase2
	./testcase2 &> testcase2.out
	gcov dominion.c >> testcase2.out
	cat dominion.c.gcov >> testcase2.out

testout3: testcase3
	./testcase3 &> testcase3.out
	gcov dominion.c >> testcase3.out
	cat dominion.c.gcov >> testcase3.out

testout4: testcase4
	./testcase4 &> testcase4.out
	gcov dominion.c >> testcase4.out
	cat dominion.c.gcov >> testcase4.out

testout5: testcase5
	./testcase5 &> testcase5.out
	gcov dominion.c >> testcase5.out
	cat dominion.c.gcov >> testcase5.out

testout6: testcase6
	./testcase6 &> testcase6.out
	gcov dominion.c >> testcase6.out
	cat dominion.c.gcov >> testcase6.out

testout7: testcase7
	./testcase7 &> testcase7.out
	gcov dominion.c >> testcase7.out
	cat dominion.c.gcov >> testcase7.out

testout8: testcase8
	./testcase8 &> testcase8.out
	gcov dominion.c >> testcase8.out
	cat dominion.c.gcov >> testcase8.out

testout9: testcase9
	./testcase9 &> testcase9.out
	gcov dominion.c >> testcase9.out
	cat dominion.c.gcov >> testcase9.out

testout10: testcase10
	./testcase10 &> testcase10.out
	gcov dominion.c >> testcase10.out
	cat dominion.c.gcov >> testcase10.out

testout11: testcase11
	./testcase11 &> testcase11.out
	gcov dominion.c >> testcase11.out
	cat dominion.c.gcov >> testcase11.out

testout12: testcase12
	./testcase12 &> testcase12.out
	gcov dominion.c >> testcase12.out
	cat dominion.c.gcov >> testcase12.out
#end make tarantula stuff

runAdventurer: adventurer
	./randomtestadventurer &> randomtestadventurer.out
	gcov dominion.c >> randomtestadventurer.out
	cat dominion.c.gcov >> randomtestadventurer.out

randomcard:
	gcc -fprofile-arcs -ftest-coverage -Wall -std=c99 dominion.c randomtestcard.c rngs.c -o randomtestcard -lm -g

runRandomCard: randomcard
	./randomtestcard &> randomtestcard.out
	gcov dominion.c >> randomtestcard.out
	cat dominion.c.gcov >> randomtestcard.out

testdom: runTestDominion
	./testdominion &> testdominion.out
	gcov dominion.c >> testdominion.out
	cat dominion.c.gcov >> testdominion.out

testSuite: runTestDominion adventurer randomcard unit1 unit2 unit3 unit4 card1 card2 card3 card4
	./testdominion &> fulltest.out
	./unittest1 >> fulltest.out
	./unittest2 >> fulltest.out
	./unittest3 >> fulltest.out
	./unittest4 >> fulltest.out
	./cardtest1 >> fulltest.out
	./cardtest2 >> fulltest.out
	./cardtest3 >> fulltest.out
	./cardtest4 >> fulltest.out
	./randomtestcard >> fulltest.out
	./randomtestadventurer >> fulltest.out

testdomdiff: runTestDominion
	./testdominion &> gameResults.out

testdomdiff2: runTestDominion
	./testdominion &> gameResults2.out

playdom: dominion.o playdom.c
	gcc -o playdom playdom.c -g dominion.o rngs.o $(CFLAGS)

playdom2: dominion.o playdom2.c
	gcc -o playdom2 playdom2.c -g dominion.o rngs.o $(CFLAGS)

testDrawCard: testDrawCard.c dominion.o rngs.o
	gcc -o testDrawCard -g  testDrawCard.c dominion.o rngs.o $(CFLAGS)

badTestDrawCard: badTestDrawCard.c dominion.o rngs.o
	gcc -o badTestDrawCard -g  badTestDrawCard.c dominion.o rngs.o $(CFLAGS)

testBuyCard: testDrawCard.c dominion.o rngs.o
	gcc -o testDrawCard -g  testDrawCard.c dominion.o rngs.o $(CFLAGS)

testAll: dominion.o testSuite.c
	gcc -o testSuite testSuite.c -g  dominion.o rngs.o $(CFLAGS)

unit1:
	gcc -fprofile-arcs -ftest-coverage -Wall -std=c99 dominion.c unittest1.c rngs.c -o unittest1 -lm -g

unit2:
	gcc -fprofile-arcs -ftest-coverage -Wall -std=c99 dominion.c unittest2.c rngs.c -o unittest2 -lm -g

unit3:
	gcc -fprofile-arcs -ftest-coverage -Wall -std=c99 dominion.c unittest3.c rngs.c -o unittest3 -lm -g

unit4:
	gcc -fprofile-arcs -ftest-coverage -Wall -std=c99 dominion.c unittest4.c rngs.c -o unittest4 -lm -g

card1:
	gcc -fprofile-arcs -ftest-coverage -Wall -std=c99 dominion.c cardtest1.c rngs.c -o cardtest1 -lm -g

card2:
	gcc -fprofile-arcs -ftest-coverage -Wall -std=c99 dominion.c cardtest2.c rngs.c -o cardtest2 -lm -g

card3:
	gcc -fprofile-arcs -ftest-coverage -Wall -std=c99 dominion.c cardtest3.c rngs.c -o cardtest3 -lm -g

card4:
	gcc -fprofile-arcs -ftest-coverage -Wall -std=c99 dominion.c cardtest4.c rngs.c -o cardtest4 -lm -g

myTest:
	./unittest1 &> unittestresult.out
	./unittest2 >> unittestresult.out
	./unittest3 >> unittestresult.out
	./unittest4 >> unittestresult.out
	./cardtest1 >> unittestresult.out
	./cardtest2 >> unittestresult.out
	./cardtest3 >> unittestresult.out
	./cardtest4 >> unittestresult.out
	gcov dominion.c >> unittestresult.out
	cat dominion.c.gcov >> unittestresult.out

interface.o: interface.h interface.c
	gcc -c interface.c -g  $(CFLAGS)

runtests: testDrawCard
	./testDrawCard &> unittestresult.out
	gcov dominion.c >> unittestresult.out
	cat dominion.c.gcov >> unittestresult.out


player: player.c interface.o
	gcc -o player player.c -g  dominion.o rngs.o interface.o $(CFLAGS)

all: playdom player testDrawCard testBuyCard badTestDrawCard

clean:
	rm -f *.o playdom.exe playdom testDominion test.exe test player testcase1 testcase2 testcase3 testcase4 testcase5 testcase6 testcase7 testcase8 testcase9 testcase10 testcase11 testcase12 unittest1 unittest2 unittest3 unittest4 cardtest1 cardtest2 cardtest3 cardtest4 player.exe testInit testInit.exe *.gcov *.gcda *.gcno *.so
