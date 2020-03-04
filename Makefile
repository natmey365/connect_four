CXX=g++
CXXFLAGS=-Wall -Ibackend/inc -Iai/inc -Idata/inc
SRC=src
BLD=build
BCKND=backend/src
AI=ai/src
DATA=data/src
INC=
#SRC=${SRC}/%.o ${BCKND}/%.o ${AI}/%.o ${DATA}/%.o
OBJS=${BLD}/main.o ${BLD}/game.o ${BLD}/board.o ${BLD}/space.o ${BLD}/piece.o ${BLD}/player.o ${BLD}/randomPlayer.o

main: build/main.o build/game.o build/board.o build/space.o build/piece.o build/player.o build/randomPlayer.o
	${CXX} ${CXXFLAGS} -o $@ $^

##### 	src/ 		#####
build/main.o: src/main.cpp
	mkdir -p build
	${CXX} ${CXXFLAGS} -c -o $@ src/main.cpp

##### 	backend/	#####
build/game.o: backend/src/game.cpp backend/inc/game.h
	mkdir -p build
	${CXX} ${CXXFLAGS} -c -o $@ backend/src/game.cpp

build/board.o: backend/src/board.cpp backend/inc/board.h
	mkdir -p build
	${CXX} ${CXXFLAGS} -c -o $@ backend/src/board.cpp

build/space.o: backend/src/space.cpp backend/inc/space.h
	mkdir -p build
	${CXX} ${CXXFLAGS} -c -o $@ backend/src/space.cpp

build/piece.o: backend/src/piece.cpp backend/inc/piece.h
	mkdir -p build
	${CXX} ${CXXFLAGS} -c -o $@ backend/src/piece.cpp

build/player.o: backend/src/player.cpp backend/inc/player.h
	mkdir -p build
	${CXX} ${CXXFLAGS} -c -o $@ backend/src/player.cpp

#####	ai/		#####
build/randomPlayer.o: ai/src/randomPlayer.cpp ai/inc/randomPlayer.h
	mkdir -p build
	${CXX} ${CXXFLAGS} -c -o $@ ai/src/randomPlayer.cpp

build/nnPlayer.o: ai/src/nnPlayer.cpp ai/inc/nnPlayer.h
	mkdir -p build
	${CXX} ${CXXFLAGS} -c -o $@ ai/src/nnPlayer.cpp

#####	clean		#####
clean:
	rm -rf *.o build/*.o main
