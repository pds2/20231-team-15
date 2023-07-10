OS_EXTENSION :=

# Detected operating system extension
ifeq ($(OS), Windows_NT) # Windows
	OS_EXTENSION := exe
else ifeq ($(shell uname), Linux) # Linux
	OS_EXTENSION := out
endif

terminal:
	g++ -Iinclude ./src/*.cpp ./program/terminal-main.cpp -o main.$(OS_EXTENSION)
	./main.$(OS_EXTENSION)

# A compilação da interface funciona no ambiente Linux.
# Necessita da biblioteca de desenvolvimento do GTK, libgtkmm-3.0-dev.
gui:
	g++ ./src/*.cpp ./src/widgets/*.cpp ./program/gui-main.cpp -o main.out `pkg-config --cflags --libs gtkmm-3.0` -Iinclude -std=c++17
	./main.out

test:
	g++ -Iinclude ./src/*.cpp ./tests/*.cpp ./program/tester.cpp -o test.$(OS_EXTENSION)
	./test.$(OS_EXTENSION)
