CC	:= gcc -std=c23
CCC	:= x86_64-w64-mingw32-gcc
FLAGS	:= -Wall -Wextra -Wpedantic -O3
DEBUG	:= -g
INC	:= -Iinc -Iinc/freetype2
LIB	:= -Llibs -lSDL3 -lSDL3_image -lSDL3_mixer -lfreetype -static-libgcc -static-libstdc++
WLIB	:= -Llibswin -lSDL3 -lSDL3_image -lSDL2_mixer -lfreetype -static-libgcc -static-libstdc++
LIBDEB	:= -lSDL3 -lSDL3_image -lSDL3_mixer -lfreetype -static-libgcc -static-libstdc++
PROJECT	:= hispa
PSTATIC	:= games
WPROJ	:= game.exe
STATIC	:= static/libfreetype.a static/libSDL3.a static/libSDL3_image.a static/libSDL3_mixer.a -static-libgcc -static-libstdc++
S	:= dep/libbrotlidec.a dep/libbrotlicommon.a dep/libbrotlienc.a dep/libasound.a dep/libbz2.a dep/libpng16.a dep/libharfbuzz.a
LIBC	:= dep/libc.a dep/libm.a
STA	:= -Wl,-Bstatic -lz -lm -lc -Wl,-Bstatic
QUIET	:= -static

SRC	:= src
WSRC	:= src
OBJ	:= obj
WOBJ	:= objwin
SOURCES	:= $(wildcard $(SRC)/*.c)
OBJS	:= $(addprefix $(OBJ)/, $(notdir $(SOURCES:.c=.o)))
WOBJS	:= $(addprefix $(WOBJ)/, $(notdir $(SOURCES:.c=.o)))

.PHONY: dll so



linker: $(PROJECT)

static: $(PSTATIC)

$(PSTATIC): $(OBJ) $(OBJS)
	$(CC) $(OBJS) $(STATIC) $(S) $(STA) -o $(PSTATIC)

$(PROJECT): $(OBJ) $(OBJS)
	$(CC) $(OBJS) -o $(PROJECT)

deb: $(OBJ) $(OBJS)
	mkdir -p deb
	$(CC) $(OBJS) $(LIBDEB) -o deb/$(PROJECT)

$(OBJ)/%.o: $(SRC)/%.c
	$(CC) $(FLAGS) $(INC) $(DEBUG) -c $< -o $@

cleanall:
	rm -fr obj/*
	rm build/game
push:
	git remote -v
	git remote set-url origin git@github.com-Feavr555:Feavr555/HISPA-LENGUAJE.git
	git push -u origin main

win32: $(WPROJ)


$(WPROJ): $(WOBJ) $(WOBJS)
	$(CCC) $(WOBJS) $(WLIB) -o build/$(PROJECT) -mwindows

$(WOBJ)/%.o: $(WSRC)/%.cpp
	$(CCC) $(FLAGS) $(INC) $(DEBUG) -c $< -o $@

wcleanall:
	rm -fr objwin/*
	rm build/game.exe

dll:
	@objdump -p build/game.exe | grep "DLL"

so:
	@ldd build/game


all:
	@mkdir -p build
	g++ -std=c++23 src/*.cpp -Iinc -Iinc/freetype2 -Llibs -lSDL3 -lSDL3_image -lSDL3_image -lfreetype -o build/game \
	-static-libgcc -static-libstdc++
	@cp -r libs/* build/
win:
	@mkdir -p build
	x86_64-w64-mingw32-g++ -std=c++23 src/*.cpp -Iinc -Iinc/freetype2 -Llibs -w -Wl,-subsystem,windows -lSDL3 -lSDL3_image -lSDL3_mixer -lfreetype \
	-o bin/game \
	-static-libgcc -static-libstdc++
	@cp -r libs/* build/

run:
	@cd build/ && ./game
r: run

wrun:
	@cd build/ && wine ./game
wr: wrun

clean:
	rm bin/game

#g++ 01_hello_SDL.cpp -IC:\mingw_dev_lib\include\SDL2 -LC:\mingw_dev_lib\lib -w -Wl,-subsystem,windows -lmingw32 -lSDL2main -lSDL2 -o 01_hello_SDL
#-w -Wl,-subsystem,windows -lmingw32
