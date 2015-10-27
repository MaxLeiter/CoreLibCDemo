include .knightos/variables.make

#INCLUDE+=add to your include path

HEADERS:=$(wildcard *.h)

ALL_TARGETS:=$(BIN)corelibcdemo

$(BIN)corelibcdemo: $(OUT)main.o $(OUT)crt0.o
	mkdir -p $(BIN)
	scas $(ASFLAGS) $(OUT)crt0.o $(LIBRARIES) $(OUT)main.o -o $(BIN)corelibcdemo

include .knightos/sdk.make
