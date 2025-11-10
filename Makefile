# ===== Compiler and flags =====
CC = gcc
CFLAGS = -Wall -Wextra -g
TARGET = snake
SRC = main.c start.c gameover.c
OBJ = $(SRC:.c=.o)

# ===== Detect OS =====
ifeq ($(OS),Windows_NT)
    # Windows (MinGW or similar)
    RM = del /Q
    EXE = .exe
    LDFLAGS =
else
    # macOS or Linux
    RM = rm -f
    EXE =
    LDFLAGS = -lncurses
endif

# ===== Build rules =====
all: $(TARGET)$(EXE)

$(TARGET)$(EXE): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $(OBJ) $(LDFLAGS)

run: $(TARGET)$(EXE)
	./$(TARGET)$(EXE)

clean:
	$(RM) $(TARGET)$(EXE) $(OBJ) a.out

.PHONY: all run clean
