
CC := cl

SOURCE_DIR := src
OUTPUT_DIR := build

SOURCES := $(wildcard $(SOURCE_DIR)/*.cpp)
HEADERS := $(wildcard $(SOURCE_DIR)/*.h)

.PHONY: windows
windows: clean compile_windows run

compile_windows: $(SOURCES) $(HEADERS)
	$(CC) /Fo$(OUTPUT_DIR)\ $(SOURCES) /link /out:$(OUTPUT_DIR)\main.exe

.PHONY: run
run:
	.\$(OUTPUT_DIR)\main.exe

clean:
	del $(OUTPUT_DIR)\*.obj
	del $(OUTPUT_DIR)\*.exe
