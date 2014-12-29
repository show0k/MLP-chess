sources  = main.cpp
sources += board.cpp
sources += move.cpp
sources += ia.cpp
sources += api.cpp

program = chessEngine

objects = $(sources:.cpp=.cpp)
depends = $(sources:.cpp=.cpp)

OPTIONS   = -W -Wall
#OPTIONS  += -O3
#OPTIONS  += -g  # debug info
OPTIONS  += -pg # profiling
OPTIONS  +=-std=c++11

CC=g++

all: 
	$(CC) $(sources) $(OPTIONS) -o $(program)
    

clean:
	#-rm -f $(objects)
	#-rm -f $(depends)
	-rm -f $(program)

