FLAGS =

ifeq ($(OS), Windows_NT)
	$(error Windows is not supported)
else
	UNAME := $(shell uname)
	ifeq ($(UNAME), Darwin)
		FLAGS += -b
	endif
endif

all: cadar-crossrefs-short.bib cadar-crossrefs-xshort.bib

cadar-crossrefs-short.bib: cadar-crossrefs.bib
	./shorten-crossrefs.sh $(FLAGS) $< > $@

cadar-crossrefs-xshort.bib: cadar-crossrefs.bib
	./shorten-crossrefs.sh $(FLAGS) -x $< > $@

clean:
	rm cadar-crossrefs-short.bib cadar-crossrefs-xshort.bib
