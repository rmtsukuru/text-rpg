rpgmake: main.c level.c player.c skill.c menu.c data/text.c config/system.c config/options.c
	gcc main.c level.c player.c skill.c menu.c data/text.c config/*.c -o text_rpg.exe
