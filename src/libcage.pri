QT *= core gui

#SKYNET_HEADERS = $$PWD/xmessages.h $$PWD/skypecommon.h $$PWD/skypecommand.h \
               #$$PWD/skycit.h $$PWD/skypeobject.h
LIBCAGE_HEADERS = $$PWD/bn.hpp $$PWD/advertise.hpp

LIBCAGE_SOURCES = $$PWD/advertise.cpp  $$PWD/cagetime.cpp   $$PWD/dgram.cpp  $$PWD/dtun.cpp  \
           $$PWD/natdetector.cpp  $$PWD/peers.cpp  $$PWD/rdp.cpp      $$PWD/timer.cpp \
           $$PWD/cage.cpp       $$PWD/cagetypes.cpp  $$PWD/dht.cpp    \
           $$PWD/packetbuf.cpp    $$PWD/proxy.cpp  $$PWD/rttable.cpp  $$PWD/udphandler.cpp # $$PWD/main.cpp

#        advertise
#        proxy
#        dgram
 #       dht
 #       cagetypes
#        dtun
 #       peers
 #       rttable
#        cage
 #       timer
 #       natdetector
 #       udphandler
   #     rdp
   #     packetbuf
  #      cagetime


HEADERS += $$SKYNET_HEADERS
SOURCES += $$LIBCAGE_SOURCES

DEFINES += EV=TRUE EV_MULTIPLICITY=0 #LIBCAGE_DEBUG=TRUE DEBUG_RDP
