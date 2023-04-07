img-dir     := img
pdf-dir     := pdf
uml-sources := $(wildcard uml/*.uml)
uml-images  := $(patsubst uml/%.uml, $(img-dir)/%.png, $(uml-sources))

md-files    := $(wildcard rendu/*.md)
pdf-outputs  := $(patsubst rendu/%.md, $(pdf-dir)/%.pdf, $(md-files))

pandoc-args := -f markdown+raw_html+link_attributes-markdown_in_html_blocks -t pdf --lua-filter=parse-html.lua --template ./template.tex\
	--resource-path=. --toc 

.PHONY = all uml pdf clean

all: uml pdf

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

$(pdf-dir)/%.pdf: rendu/%.md uml
	mkdir -p $(pdf-dir)
	pandoc $(pandoc-args) -o $@ $<

$(img-dir)/%.png: uml/%.uml
	plantuml -o ../$(img-dir) $<

clean:
	rm -rf img pdf
