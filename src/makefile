export PATH := $(PATH):$(PWD)/bin:$(CURDIR)
export SHELL := /bin/sh
# export SUBDIRS := $(CURDIR)/txt/methods.txt
export SUBDIRS := $(CURDIR)
export CXX := g++
export CPPFLAGS := -D SUBDIRS="$(SUBDIRS)"
export CXXFLAGS := -I $(SUBDIRS) -Wall -c
# export CXXFLAGS := -Wall -c

# export TXTPATH := $(subst "OptionPricer", "", $(SUBDIRS))

OptionPricer : Tools.o Constants.o Pricer.o Stock.o Option.o TestPricing.o OptionPricer.o ApplicationPricer.o Main.o
	$(CXX) -o OptionPricer -I $(SUBDIRS) $(CPPFLAGS) Tools.o Constants.o Pricer.o Stock.o Option.o TestPricing.o OptionPricer.o ApplicationPricer.o Main.o

Tools.o : Tools.cpp
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) Tools.cpp

Constants.o : Constants.cpp Tools.h
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) Constants.cpp

Pricer.o : Pricer.cpp Constants.h
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) Pricer.cpp

Stock.o : Stock.cpp Constants.h
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) Stock.cpp

Option.o : Option.cpp Stock.h
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) Option.cpp

TestPricing.o : TestPricing.cpp Stock.h Option.h Pricer.h OptionPricer.h
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) TestPricing.cpp

OptionPricer.o : OptionPricer.cpp Pricer.h Stock.h Option.h Tools.h Constants.h 
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) OptionPricer.cpp

ApplicationPricer.o : ApplicationPricer.cpp Stock.h Option.h Pricer.h OptionPricer.h Constants.h
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) ApplicationPricer.cpp

Main.o : Main.cpp TestPricing.h ApplicationPricer.h
	$(CXX)  $(CPPFLAGS) $(CXXFLAGS) Main.cpp

all:
	OptionPricer

clean:
	rm -rf OptionPricer OptionPricer.o Tools.o Constants.o Pricer.o Stock.o Option.o TestPricing.o ApplicationPricer.o Main.o

print:
	echo $(SUBDIRS)
	echo $(CXXFLAGS)
	# echo $(TXTPATH)