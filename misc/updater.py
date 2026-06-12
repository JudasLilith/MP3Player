import os

musiclist = [] 
for music in os.listdir("./"): 
    musiclist.append(music)


musiclist.sort()

for music in musiclist:
    print("const char song" + music.index() \"" + music + "\",")

