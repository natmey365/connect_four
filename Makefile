CXX=g++
CXXFLAGS=-Wall -Ibackend/inc -Iai/inc -Idata/inc
SRC=src
BLD=build
BCKND=backend/src
AI=ai/src
DATA=data/src
INC=
SRC=${SRC}/%.o ${BCKND}/%.o ${AI}/%.o ${DATA}/%.o
OBJS=${BLD}/main.o ${BLD}/game.o ${BLD}/board.o ${BLD}/space.o ${BLD}/piece.o ${BLD}/player.o ${BLD}/randomPlayer.o

all: ${OBJS} ${}

main: ${OBJS}
	${CXX} ${CXXFLAGS} -o $@ $^

${BLD}/%.o: ${SRC}/%.cpp
	${CXX} ${CXXFLAGS} -c -o $@ $<

${BLD}/%.o: ${BCKND}/%.cpp
	${CXX} ${CXXFLAGS} -c -o $@ $<

${BLD}/%.o: ${AI}/%.cpp
	${CXX} ${CXXFLAGS} -c -o $@ $<

clean:
	rm -rf *.o build/*.o main
