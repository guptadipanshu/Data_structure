EXE = testscene
OBJS =  png.o rgbapixel.o  image.o scene.o testscene.o 
OBJS2 =  png.o rgbapixel.o  image.o scene.o testimage.o 
EXE2=testimage
COMPILER = g++
COMPILER_OPTS = -c -g -O0 -Wall -Werror
LINKER = g++
LINKER_OPTS = -lpng

all : testimage testscene 

$(EXE) : $(OBJS)
	$(LINKER) $(OBJS) $(LINKER_OPTS) -o $(EXE)


$(EXE2) : $(OBJS2)
	$(LINKER) $(OBJS2) $(LINKER_OPTS) -o $(EXE2)
testimage.o : testimage.cpp png.h rgbapixel.h image.h 
	$(COMPILER) $(COMPILER_OPTS) testimage.cpp

testscene.o : testscene.cpp png.h rgbapixel.h image.h scene.h
	$(COMPILER) $(COMPILER_OPTS) testscene.cpp

png.o : png.cpp png.h rgbapixel.h
	$(COMPILER) $(COMPILER_OPTS) png.cpp

rgbapixel.o : rgbapixel.cpp rgbapixel.h
	$(COMPILER) $(COMPILER_OPTS) rgbapixel.cpp

image.o : image.cpp image.h
	$(COMPILER) $(COMPILER_OPTS) image.cpp

scene.o : scene.cpp scene.h
	$(COMPILER) $(COMPILER_OPTS) scene.cpp


clean :
	-rm -f *.o $(EXE) $(EXE2)
