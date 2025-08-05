
CC := cl

SOURCE_DIR := src
OUTPUT_DIR := build

SOURCES := $(wildcard $(SOURCE_DIR)/*.cpp)
HEADERS := $(wildcard $(SOURCE_DIR)/*.h)

.PHONY: all
all: clean compile run

compile: $(SOURCES) $(HEADERS)
	$(CC) /Fo"$(OUTPUT_DIR)"\ $(SOURCES) /std:c++17 /link /out:$(OUTPUT_DIR)\main.exe

.PHONY: run
run:
	.\$(OUTPUT_DIR)\main.exe

clean:
	del $(OUTPUT_DIR)\*.obj
	del $(OUTPUT_DIR)\*.exe
