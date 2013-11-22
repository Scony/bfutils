EXE=bf

all: $(EXE)

$(EXE): src/
	make -C src/
	cp src/$(EXE) $(EXE)

clean: 
	make -C src/ clean
	rm -f $(EXE)

.PHONY: all, clean
