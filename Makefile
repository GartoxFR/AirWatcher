	# Doc compiling variables
img-dir     := img
pdf-dir     := pdf
uml-sources := $(wildcard uml/*.uml)
uml-images  := $(patsubst uml/%.uml, $(img-dir)/%.png, $(uml-sources))

md-files    := $(wildcard rendu/*.md)
pdf-outputs  := $(patsubst rendu/%.md, $(pdf-dir)/%.pdf, $(md-files))

pandoc-args := -f markdown+raw_html+link_attributes-markdown_in_html_blocks -t pdf --lua-filter=parse-html.lua --template ./template.tex\
	--resource-path=. --toc --listings --number-sections

# Code compiling variables
ECHO = echo
GCC = g++
CCFLAGS = -g -ansi -pedantic -Wall -std=c++2a -fsanitize=address -fno-omit-frame-pointer
LDFLAGS = -g -fsanitize=address -fno-omit-frame-pointer
EXE_NAME = airwatcher
SOURCEDIR=src
BUILDDIR=build
BINDIR=bin
EXE = $(BINDIR)/$(EXE_NAME)
SOURCES = $(wildcard $(SOURCEDIR)/**/*.cpp) $(wildcard $(SOURCEDIR)/*.cpp)
OBJECTS = $(SOURCES:$(SOURCEDIR)/%.cpp=$(BUILDDIR)/%.o)
DEP=$(OBJECTS:%.o=%.d)

.PHONY = run code uml pdf clean

all: code

code: $(EXE)

run: code
	@./$(EXE)

# Doc compiling rules
pdf: $(pdf-outputs)

$(pdf-output): uml $(md-files)

	for file in $(md-files); do\
		cat $$file;\
		echo;echo;\
	done \
	| sed 's/\[\(.*\)\](\(.*\)#\(.*\))/[\1](#\3)/g' \
	| sed 's/href="\(.*\)#\(.*\)"/href="#\2"/g'\
	| pandoc  $(pandoc-args) -o $(pdf-output)

uml: $(uml-images)

$(pdf-dir)/%.pdf: rendu/%.md $(uml-images)
	mkdir -p $(pdf-dir)
	pandoc $(pandoc-args) -o $@ $<

$(img-dir)/%.png: uml/%.uml
	plantuml -o ../$(img-dir) $<

# Clean up
clean:
	rm -rf img pdf
	rm $(DEP) $(OBJECTS) $(EXE)

# Code rules
$(EXE) : $(OBJECTS)
	@mkdir -p $(@D)
	@$(GCC) -o $(@) $(OBJECTS) $(LDFLAGS)

-include $(DEP)

$(BUILDDIR)/%.o : $(SOURCEDIR)/%.cpp
	@mkdir -p $(@D)
	@$(ECHO) "Compiling $<..."
	@$(GCC) $(CCFLAGS) -MMD -c $< -o $@

dir: 
	@mkdir -p $(BUILDDIR)
	@mkdir -p $(BINDIR)
