CC=g++ -Wall

SOURCES=bf.cpp Exception.cpp File.cpp Interpreter.cpp Memory.cpp DynamicMemory.cpp SmallInterpreter.cpp
OBJECTS=$(SOURCES:.cpp=.o)

all: bf

bf: $(OBJECTS) 
	$(CC) -o $@ $(OBJECTS) $(LIBS)

$(OBJECTS): %.o: %.cpp # $(HEADERS)
	$(CC) -c $< -o $@

clean:
	-rm -rf *~ *.o bf
