WIIUSE_INCLUDE=-I/c/frameworks/wiiuse
WIIUSE_LIBS=-L/c/frameworks/wiiuse -lwiiuse

BOOST_INCLUDE=-I/c/boost
BOOST_LIBS=-L/c/boost/stage/lib -lboost_thread-mgw45-mt-1_46_1

MIIMANAGER_INCLUDE=-I/c/frameworks/CMWii/include
MIIMANAGER_LIBS=-L/c/frameworks/CMWii/bin -lCMWii

WX_INCLUDE=`wx-config --cxxflags`
WX_LIBS=`wx-config --libs`

INCLUDES=$(WIIUSE_INCLUDE) $(BOOST_INCLUDE) $(MIIMANAGER_INCLUDE) $(WX_INCLUDE)
LIBS=$(WIIUSE_LIBS) $(BOOST_LIBS) $(MIIMANAGER_LIBS) $(WX_LIBS)

all: cmii

Debug: cmii

Release: cmii

cmii: *.o
		g++ *.o $(LIBS) -o build/cmii.exe

*.o: *.cpp
		g++ $(INCLUDES) -g -c *.cpp

cleanDebug: clean

cleanRelease: clean

clean:
		rm *.o
		rm build/cmii.exe

