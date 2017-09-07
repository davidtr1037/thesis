all: thesis.pdf

thesis.pdf : $(shell ls *.tex bib_files/*.bib) 
	pdflatex thesis
	bibtex thesis
	pdflatex thesis
	pdflatex thesis

clean:
	rm -f *.pdf *.aux *.blg *.log *.bbl *.out

