# A compilação funciona no ambiente Linux.
# Necessita da biblioteca de desenvolvimento do GTK, libgtkmm-3.0-dev
main:
	g++ ./src/*.cpp -o main.out `pkg-config --cflags --libs gtkmm-3.0` -Iinclude -std=c++17
	./main.out
