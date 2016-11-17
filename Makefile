all:
	g++ -Wall -g -std=c++11 src/*.cpp src/entitees/*.cpp src/patterns/*.cpp -L./lib -I./include -lSDL2 -lSDL2main -lpthread -ldl -o "Space Intruders"
run:
	LIBGL_DEBUG=verbose LD_LIBRARY_PATH=./lib ./"Space Intruders"

clean:
	rm -f ./"Space Intruders"
