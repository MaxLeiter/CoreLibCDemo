include .knightos/variables.make
HEADERS:=$(wildcard *.h)
ALL_TARGETS:=$(BIN)corelibcdemo $(APPS)corelibcdemo.app $(SHARE)icons/corelibcdemo.img

$(BIN)corelibcdemo: $(OUT)main.o $(OUT)crt0.o
	mkdir -p $(BIN)
	scas $(ASFLAGS) $(OUT)crt0.o $(LIBRARIES) $(OUT)main.o -o $(BIN)corelibcdemo

$(APPS)corelibcdemo.app: config/corelibcdemo.app
	mkdir -p $(APPS)
	cp config/corelibcdemo.app $(APPS)

$(SHARE)icons/corelibcdemo.img: config/corelibcdemo.png
	mkdir -p $(SHARE)icons
	kimg -c config/corelibcdemo.png $(SHARE)icons/corelibcdemo.img

include .knightos/sdk.make
