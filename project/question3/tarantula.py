import sys
#this program effectively converts a file with many gcov outputs of fails and passes into arrays of integers used to calculate the tarantula formula

totalpassed = 6
totalfailed = 6
tarantulaResults = [0] * lenDominion

lineCount = 0 # keeps track of lines
failPass = 3; # keeps track of fail or pass test case

lenDominion = 1490 # length of the code being inspected
flagLine = 1499 # how often the pass/fail flag showsup
failInc = 1 # holds number of the array we store it to
passInc = 1
# for 6 passing test cases and 6 failing test cases
passArray1 = [0] * lenDominion
passArray2 = [0] * lenDominion
passArray3 = [0] * lenDominion
passArray4 = [0] * lenDominion
passArray5 = [0] * lenDominion
passArray6 = [0] * lenDominion

failArray1 = [0] * lenDominion
failArray2 = [0] * lenDominion
failArray3 = [0] * lenDominion
failArray4 = [0] * lenDominion
failArray5 = [0] * lenDominion
failArray6 = [0] * lenDominion

index = 0;

with open(sys.argv[1], 'r') as my_file:
    for line in my_file:
        if lineCount % flagLine == 0:
            index = 0

            if(failPass == 0): #increments to the next array
                failInc = failInc + 1
            elif(failPass == 1):
                passInc = passInc + 1

            if line == "P\n": #sets flag if we are looking at a fail or pass test
                print("P")
                failPass = 1
            elif line == "F\n":
                print("F")
                failPass = 0

        elif lineCount % flagLine > 8: #filters out useless gcov lines
            count = line.partition(":")[0]
            count = count.lstrip()

            if(count == "-"):
                count = 0
            elif(count == "#####"):
                count = 0
            else:
                count = int(count)

            if (failPass == 1):
                if passInc == 1:
                    passArray1[index] = count
                elif passInc == 2:
                    passArray2[index] = count
                elif passInc == 3:
                    passArray3[index] = count
                elif passInc == 4:
                    passArray4[index] = count
                elif passInc == 5:
                    passArray5[index] = count
                elif passInc == 6:
                    passArray6[index] = count
            else:
                if failInc == 1:
                    failArray1[index] = count
                elif failInc == 2:
                    failArray2[index] = count
                elif failInc == 3:
                    failArray3[index] = count
                elif failInc == 4:
                    failArray4[index] = count
                elif failInc == 5:
                    failArray5[index] = count
                elif failInc == 6:
                    failArray6[index] = count
            index = index + 1
        lineCount = lineCount + 1;

print passArray1
print len(passArray1)

for x in range(0,1490):
    if(failArray[x] > 0):
