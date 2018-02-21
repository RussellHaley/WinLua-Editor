TEMPLATE = app

QT += webenginewidgets webchannel
CONFIG += c++11

HEADERS += \
    mainwindow.h \
    previewpage.h \
    document.h \
    mdiform.h \
    C:\Users\russh\Git\sol2\single\sol.hpp

SOURCES = \
    main.cpp \
    mainwindow.cpp \
    previewpage.cpp \
    document.cpp \
    mdiform.cpp

RESOURCES = \
    resources/markdowneditor.qrc

FORMS += \
    mainwindow.ui \
    mdiform.ui

DISTFILES += \
    resources/3rdparty/MARKDOWN-LICENSE.txt \
    resources/3rdparty/MARKED-LICENSE.txt

win32:INCLUDEPATH += "C:\Program Files (x86)\WinLua\Lua\5.3\include" "C:\Users\russh\Git\sol2\single"
unix:INCLUDEPATH += "/home/user/extra headers"

win32:LIBS += "C:\Program Files (x86)\WinLua\Lua\5.3\bin\lua53.lib"
unix:LIBS += "-L/home/user/extra libs" -lextra

# install
target.path = $$[QT_INSTALL_EXAMPLES]/webenginewidgets/markdowneditor
INSTALLS += target