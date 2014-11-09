This is a project to try simple sentimental analysis given a text (or urls).


To compile just run
sh ./run.sh

The project needs gumbo-parser ad a dependency.

You may want to install it with
brew update
brew install gumbo-parser
on a Mac.

To execute it
./main files.txt positive-words.txt negative-words.txt