#File: makefile
#Kelsey Clater
#CS3024
#Fall 2017

all: compiler executor

compiler: compiler.o fileHandler.o noblanks.o symbolTable.o helper.o ccore.o stack.o transducer.o tdim.o tread.o twrite.o tstop.o tcdump.o tlisto.o tnop.o tgoto.o tifa.o taread.o tawrite.o tsubp.o tloopend.o tloop.o tlread.o tlwrite.o tif.o tcls.o tassignment.o
	gcc -o compiler compiler.o fileHandler.o noblanks.o symbolTable.o helper.o ccore.o stack.o transducer.o tdim.o tread.o twrite.o tstop.o tcdump.o tlisto.o tnop.o tgoto.o tifa.o taread.o tawrite.o tsubp.o tloopend.o tloop.o tlread.o tlwrite.o tif.o tcls.o tassignment.o

executor: executor.o ehelper.o fileHandler.o object.o core.o literal.o range.o lstack.o astack.o eloopHelper.o edim.o eread.o ewrite.o estop.o ecdump.o elisto.o enop.o egoto.o eifa.o earead.o eawrite.o esubp.o eloop.o eloopend.o elread.o elwrite.o eif.o ecls.o eassignment.o
	gcc -o executor executor.o ehelper.o fileHandler.o object.o core.o literal.o range.o lstack.o astack.o eloopHelper.o edim.o eread.o ewrite.o estop.o ecdump.o elisto.o enop.o egoto.o eifa.o earead.o eawrite.o esubp.o eloop.o eloopend.o elread.o elwrite.o eif.o ecls.o eassignment.o -lm

#COMPILER FILES
compiler.o: compiler.c compiler.h fileHandler.h noblanks.h symbolTable.h constants.h helper.h ccore.h tdim.h tread.h twrite.h tstop.h tcdump.h tlisto.h tnop.h tgoto.h tifa.o taread.h tawrite.h tsubp.h tloopend.h tloop.h tlread.h tlwrite.h tif.h tcls.h tassignment.h
	gcc -c compiler.c

noblanks.o: noblanks.c noblanks.h helper.h
	gcc -c noblanks.c

symbolTable.o: symbolTable.c symbolTable.h constants.h helper.h ccore.h
	gcc -c symbolTable.c

helper.o: helper.c helper.h constants.h
	gcc -c helper.c

stack.o: stack.c stack.h constants.h
	gcc -c stack.c

transducer.o: transducer.c transducer.h constants.h stack.h
	gcc -c transducer.c

tdim.o: tdim.c tdim.h symbolTable.h helper.h constants.h
	gcc -c tdim.c

tread.o: tread.c tread.h symbolTable.h helper.h constants.h
	gcc -c tread.c

twrite.o: twrite.c twrite.h symbolTable.h helper.h constants.h
	gcc -c twrite.c

tstop.o: tstop.c tstop.h symbolTable.h helper.h constants.h
	gcc -c tstop.c

tcdump.o: tcdump.c tcdump.h symbolTable.h helper.h constants.h
	gcc -c tcdump.c

tlisto.o: tlisto.c tlisto.h symbolTable.h helper.h constants.h
	gcc -c tlisto.c

tnop.o: tnop.c tnop.h symbolTable.h helper.h constants.h
	gcc -c tnop.c

tgoto.o: tgoto.c tgoto.h symbolTable.h helper.h constants.h
	gcc -c tgoto.c

tifa.o: tifa.c tifa.h symbolTable.h helper.h constants.h
	gcc -c tifa.c

taread.o: taread.c taread.h symbolTable.h helper.h constants.h
	gcc -c taread.c

tawrite.o: tawrite.c tawrite.h symbolTable.h helper.h constants.h
	gcc -c tawrite.c

tsubp.o: tsubp.c tsubp.h symbolTable.h helper.h constants.h
	gcc -c tsubp.c

tloop.o: tloop.c tloop.h symbolTable.h helper.h constants.h
	gcc -c tloop.c

tloopend.o: tloopend.c tloopend.h symbolTable.h helper.h constants.h
	gcc -c tloopend.c

tlread.o: tlread.c tlread.h symbolTable.h helper.h constants.h
	gcc -c tlread.c

tlwrite.o: tlwrite.c tlwrite.h symbolTable.h helper.h constants.h
	gcc -c tlwrite.c

tif.o: tif.c tif.h symbolTable.h helper.h constants.h
	gcc -c tif.c

tcls.o: tcls.c tcls.h symbolTable.h helper.h constants.h
	gcc -c tcls.c

tassignment.o: tassignment.c tassignment.h symbolTable.h helper.h constants.h transducer.h
	gcc -c tassignment.c

#EXECUTOR FILES
executor.o: executor.c executor.h ehelper.h fileHandler.h object.h core.h literal.h range.h constants.h lstack.h astack.h edim.h eread.h ewrite.h estop.h ecdump.h elisto.h enop.h egoto.h eifa.h earead.h eawrite.h esubp.h eloop.h eloopend.h elread.h elwrite.h eif.h ecls.h eassignment.h
	gcc -c executor.c

ehelper.o: ehelper.c ehelper.h constants.h
	gcc -c ehelper.c

eloopHelper.o: eloopHelper.c eloopHelper.h constants.h core.h lstack.h
	gcc -c eloopHelper.c

object.o: object.c object.h constants.h
	gcc -c object.c

literal.o: literal.c literal.h constants.h
	gcc -c literal.c

range.o: range.c range.h constants.h
	gcc -c range.c

lstack.o: lstack.c lstack.h constants.h
	gcc -c lstack.c

astack.o: astack.c stack.h constants.h
	gcc -c astack.c

edim.o: edim.c edim.h constants.h object.h core.h range.h
	gcc -c edim.c

eread.o: eread.c eread.h constants.h object.h core.h
	gcc -c eread.c

ewrite.o: ewrite.c ewrite.h constants.h object.h core.h
	gcc -c ewrite.c

estop.o: estop.c estop.h constants.h object.h core.h
	gcc -c estop.c

ecdump.o: ecdump.c ecdump.h constants.h object.h core.h
	gcc -c ecdump.c

elisto.o: elisto.c elisto.h constants.h object.h core.h
	gcc -c elisto.c

enop.o: enop.c enop.h
	gcc -c enop.c

egoto.o: egoto.c egoto.h constants.h object.h core.h
	gcc -c egoto.c

eifa.o: eifa.c eifa.h constants.h object.h core.h
	gcc -c eifa.c

earead.o: earead.c earead.h constants.h object.h core.h range.h
	gcc -c earead.c

eawrite.o: eawrite.c eawrite.h constants.h object.h core.h range.h
	gcc -c eawrite.c

esubp.o: esubp.c esubp.h constants.h object.h core.h
	gcc -c -lm esubp.c

eloop.o: eloop.c eloop.h constants.h object.h core.h lstack.h eloopHelper.h
	gcc -c eloop.c

eloopend.o: eloopend.c eloopend.h constants.h object.h core.h lstack.h eloopHelper.h
	gcc -c eloopend.c

elread.o: elread.c elread.h constants.h object.h literal.h
	gcc -c elread.c

elwrite.o: elwrite.c elwrite.h constants.h object.h literal.h
	gcc -c elwrite.c

eif.o: eif.c eif.h constants.h object.h core.h
	gcc -c eif.c

ecls.o: ecls.c ecls.h constants.h
	gcc -c ecls.c

eassignment.o: eassignment.c eassignment.h constants.h object.h core.h range.h astack.h
	gcc -c eassignment.c

ccore.o: ccore.c ccore.h constants.h helper.h
	gcc -c ccore.c

core.o: core.c core.h constants.h ehelper.h
	gcc -c core.c

fileHandler.o: fileHandler.c fileHandler.h constants.h
	gcc -c fileHandler.c

#CLEAN
clean: 
	rm *.o *.noblanks *.literal *.obj compiler executor
