OS_EXTENSION :=

# Detected operating system extension
ifeq ($(OS), Windows_NT) # Windows
	OS_EXTENSION := exe
else ifeq ($(shell uname), Linux) # Linux
	OS_EXTENSION := out
endif

main:
	g++ -Iinclude ./src/*.cpp -o main.$(OS_EXTENSION)
	./main.$(OS_EXTENSION)
