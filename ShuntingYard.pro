TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt
CONFIG += c++11


#WINDOWS
# put SFML file in the same location as project
#LIBS += -L"..\SFML-2.3.2\lib"
#LIBS += -L"..\SFML-2.3.2\bin"

#MAC
LIBS += -L"/usr/local/lib"

CONFIG(release, debug|release): LIBS += -lsfml-audio -lsfml-graphics -lsfml-system -lsfml-network -lsfml-window
CONFIG(debug  , debug|release): LIBS += -lsfml-audio -lsfml-graphics -lsfml-system -lsfml-network -lsfml-window

#WINDOWS
#INCLUDEPATH += "..\SFML-2.3.2\include"
#DEPENDPATH += "..\SFML-2.3.2\include"

#MAC
INCLUDEPATH += "/usr/local/include"
DEPENDPATH += "/usr/local/include"

SOURCES += main.cpp \
    token.cpp \
    integer.cpp \
    operator.cpp \
    rightparen.cpp \
    leftparen.cpp \
    tokenizer.cpp \
    topostfix.cpp \
    generatepoints.cpp \
    game.cpp \
    function.cpp

HEADERS += \
    token.h \
    integer.h \
    operator.h \
    rightparen.h \
    leftparen.h \
    tokenizer.h \
    ../../../../Stack_and_Queue/Stack_and_Queue/myqueue.h \
    topostfix.h \
    ../../../../Stack_and_Queue/Stack_and_Queue/mystack.h \
    generatepoints.h \
    game.h \
    constants.h \
    ../../../../Vector_Template/vector.h \
    function.h
