rpgmake: *.c *.h struct/*.h data/*.c data/*.h config/*.c config/*.h
	gcc *.c data/*.c config/*.c -o text_rpg.exe
