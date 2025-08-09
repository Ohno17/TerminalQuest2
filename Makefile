
CC := cl

SOURCE_DIR := src
OUTPUT_DIR := build

RESULT := build/main.exe

SOURCES := $(wildcard $(SOURCE_DIR)/*.cpp)
HEADERS := $(wildcard $(SOURCE_DIR)/*.hpp)

.PHONY: all
all: clean $(RESULT) run

$(RESULT): $(SOURCES) $(HEADERS)
	$(CC) /Fo"$(OUTPUT_DIR)"\ $(SOURCES) /std:c++17 /link /out:$(OUTPUT_DIR)\main.exe

.PHONY: run
run:
	.\$(OUTPUT_DIR)\main.exe

.PHONY: clean
clean:
	del $(OUTPUT_DIR)\*.obj
	del $(OUTPUT_DIR)\*.exe
