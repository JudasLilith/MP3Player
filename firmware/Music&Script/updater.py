import os

counter = 0;
musiclist = [] 
for music in os.listdir("./"): 
    musiclist.append(music)


musiclist.sort()

addedIndex = ""
for music in musiclist:
    print( "const char PROGMEM [] " + music + " = " + "\"" + addedIndex + music + "\"" + ";")
    counter = counter + 1

    #print(counter)

    
