CC = gcc
FLAGS = -g -Wall -lm
ARCH := $(shell uname -m)
BINARIES = ./macos-$(ARCH)

unityfolder = ./unity
program_obj_files = stack.o bintree.o numbers.o timer.o highscore.o

# --------------------------
# Initiales Programm bauen (zum ausprobieren)
# --------------------------
doble_initial:
	$(CC) -o doble_initial $(BINARIES)/libdoble_complete.a

# --------------------------
# Selbst implementiertes Programm bauen
# --------------------------
doble : main.o $(program_obj_files)
	$(CC) $(FLAGS) $^ -o doble

$(program_obj_filesobj_files): %.o: %.c
	$(CC) -c $(FLAGS) $^ -o $@

# --------------------------
# Unit Tests
# --------------------------
unitTests:
	echo "needs to be implemented"

# --------------------------
# Clean
# --------------------------
clean:
	rm -f *.o doble