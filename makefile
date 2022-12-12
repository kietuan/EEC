


zip: clean
	mkdir project
	cp *.cpp *.h project
	zip -r project.zip project
	rm -rf project

clean:
	rm project.zip
