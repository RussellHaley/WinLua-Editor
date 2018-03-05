TEMPLATE = app

QT += webenginewidgets webchannel
CONFIG += c++14

HEADERS += \
    previewpage.h \
    document.h \
    mdiform.h \
    sol_assert.hpp \
    documentwindow.h \
    envstate.h \
    mdichild.h

SOURCES = \
    main.cpp \
    previewpage.cpp \
    document.cpp \
    mdiform.cpp \
    documentwindow.cpp \
    envstate.cpp \
    mdichild.cpp

RESOURCES = \
    resources/markdowneditor.qrc

FORMS += \
    mdiform.ui \
    documentwindow.ui

DISTFILES += \
    resources/3rdparty/MARKDOWN-LICENSE.txt \
    resources/3rdparty/MARKED-LICENSE.txt

win32:INCLUDEPATH += "C:\Program Files\WinLua\Lua\5.3\include"
#win32:INCLUDEPATH += "C:\Program Files\WinLua\Lua\5.3\include" "C:\Users\russh\Git\sol2\single"
#unix:INCLUDEPATH += "/home/user/extra headers"

win32:LIBS += "C:\Program Files\WinLua\Lua\5.3\bin\lua53.lib"
#win32:LIBS += "C:\Program Files\WinLua\Lua\5.3\bin\lua53.lib"
#win32:LIBS += "C:\Program Files (x86)\WinLua\Lua\5.3\staticlib\lua53.lib"
#unix:LIBS += "-L/home/user/extra libs" -lextra

# install
target.path = $$[QT_INSTALL_EXAMPLES]/webenginewidgets/markdowneditor
INSTALLS += target
