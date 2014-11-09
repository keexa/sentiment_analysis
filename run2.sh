g++ -g -std=c++11 -o main \
porter2_stemmer.cpp \
dictionary.cpp \
main.cpp \
analyzer.cpp \
reader.cpp \
page.cpp \
file_reader.cpp \
url_reader.cpp \
-lpthread -ltidy -lgumbo -lcurl -I/usr/local/include/ -L/usr/local/lib
