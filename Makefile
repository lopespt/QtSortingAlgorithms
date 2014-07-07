
PRO   = QtSortingAlgorithms.pro
QMAKE = /Users/wachs/Qt/5.2.1/clang_64/bin/qmake

all:	QtMakefile
	$(MAKE) -f QtMakefile

clean:
	rm -fr QtMakefile QtMakefile.debug QtMakefile.release debug release

clearQrcs:
	rm -f release/qrc_*
	

createPro: clearQrcs
	$(QMAKE) -project -o $(PRO) "QT+=core gui widgets sql network opengl" "CONFIG += console c++11" "RESOURCES = resources.qrc"

QtMakefile: createPro
	$(QMAKE) -o QtMakefile $(PRO) CONFIG+=debug_and_release

debug:	QtMakefile
	$(MAKE) -f QtMakefile debug

release:	QtMakefile
	$(MAKE) -f QtMakefile release

.PHONY: all clean debug clean-debug release clean-release