img-dir     := img
uml-sources := $(wildcard uml/*.uml)
uml-images  := $(patsubst uml/%.uml, $(img-dir)/%.png, $(uml-sources))

md-files    := 
pdf-output  := specs.pdf

pandoc-args := -f markdown+raw_html+link_attributes-markdown_in_html_blocks -t pdf --lua-filter=parse-html.lua --template ./template.tex\
	--resource-path=fenetres --resource-path=. --number-sections --toc 

.PHONY = all uml 

all: uml

pdf: $(pdf-output)

$(pdf-output): uml $(md-files)

	for file in $(md-files); do\
		cat $$file;\
		echo;echo;\
	done \
	| sed 's/\[\(.*\)\](\(.*\)#\(.*\))/[\1](#\3)/g' \
	| sed 's/href="\(.*\)#\(.*\)"/href="#\2"/g'\
	| pandoc  $(pandoc-args) -o $(pdf-output)

uml: $(uml-images)

$(img-dir)/%.png: uml/%.uml
	plantuml -o ../$(img-dir) $<

