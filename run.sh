g++ -g -std=c++11 -o ste porter2_stemmer.cpp dictionary.cpp main.cpp reader.cpp page.cpp -lpthread -lcurl -I/usr/local/Cellar/libxml++/2.36.0/include/libxml++-2.6 -I/usr/local/Cellar/libxml++/2.36.0/lib/libxml++-2.6/include -I/usr/local/Cellar/glibmm/2.42.0/include/glibmm-2.4 -I/usr/local/Cellar/glibmm/2.42.0/lib/glibmm-2.4/include -I/usr/local/Cellar/glib/2.42.0/include/glib-2.0 -I/usr/local/Cellar/glib/2.42.0/lib/glib-2.0/include -I/usr/local/opt/gettext/include -I/usr/local/Cellar/libsigc++/2.4.0/include/sigc++-2.0 -I/usr/local/Cellar/libsigc++/2.4.0/lib/sigc++-2.0/include -I/usr/include/libxml2 -L/usr/local/Cellar/libxml++/2.36.0/lib -L/usr/local/Cellar/glibmm/2.42.0/lib -L/usr/local/Cellar/glib/2.42.0/lib -L/usr/local/opt/gettext/lib -L/usr/local/Cellar/libsigc++/2.4.0/lib -lxml++-2.6 -lxml2 -lglibmm-2.4 -lgobject-2.0 -lglib-2.0 -lintl -lsigc-2.0  -ltidy -lgumbo -I/usr/local/include/ -L/usr/local/lib