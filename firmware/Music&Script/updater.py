import os


counter = 0;
musiclist = [] 
for music in os.listdir("./"): 
    musiclist.append(music)


musiclist.sort()

addedIndex = "0"
for music in musiclist:
    while ( len(addedIndex) < 4):
        addedIndex = "0" + addedIndex + str(counter)
    print( "\"" + addedIndex + music + "\",")
    counter = counter + 1
