CXX = g++
CFLAGS = -Wall -std=c++11
INCLUDE = -Iinclude -I/usr/local/include -I/usr/include
LDFLAGS = -L/usr/local/lib -I/usr/lib
LDLIBS = -lcurl

SOURCES = main.cpp twilio.cpp pulse.cpp
OUT = bin/moyo

all: build

build: $(SOURCES)
	$(CXX) -o $(OUT) $(INCLUDE) $(LDFLAGS) $(CFLAGS) $(SOURCES) $(LDLIBS)

clean:
	rm -rf bin/cpp_demo
