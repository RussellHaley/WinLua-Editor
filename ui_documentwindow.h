/********************************************************************************
** Form generated from reading UI file 'documentwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DOCUMENTWINDOW_H
#define UI_DOCUMENTWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>
#include "qwebengineview.h"

QT_BEGIN_NAMESPACE

class Ui_DocumentWindow
{
public:
    QAction *actionOpen;
    QAction *actionSave;
    QAction *actionExit;
    QAction *actionSaveAs;
    QAction *actionNew;
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout;
    QSplitter *splitter;
    QPlainTextEdit *editor;
    QWebEngineView *preview;
    QMenuBar *menubar;
    QMenu *menu_File;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *DocumentWindow)
    {
        if (DocumentWindow->objectName().isEmpty())
            DocumentWindow->setObjectName(QStringLiteral("DocumentWindow"));
        DocumentWindow->resize(800, 600);
        actionOpen = new QAction(DocumentWindow);
        actionOpen->setObjectName(QStringLiteral("actionOpen"));
        actionSave = new QAction(DocumentWindow);
        actionSave->setObjectName(QStringLiteral("actionSave"));
        actionExit = new QAction(DocumentWindow);
        actionExit->setObjectName(QStringLiteral("actionExit"));
        actionSaveAs = new QAction(DocumentWindow);
        actionSaveAs->setObjectName(QStringLiteral("actionSaveAs"));
        actionNew = new QAction(DocumentWindow);
        actionNew->setObjectName(QStringLiteral("actionNew"));
        centralwidget = new QWidget(DocumentWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        horizontalLayout = new QHBoxLayout(centralwidget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        splitter = new QSplitter(centralwidget);
        splitter->setObjectName(QStringLiteral("splitter"));
        splitter->setOrientation(Qt::Horizontal);
        editor = new QPlainTextEdit(splitter);
        editor->setObjectName(QStringLiteral("editor"));
        splitter->addWidget(editor);
        preview = new QWebEngineView(splitter);
        preview->setObjectName(QStringLiteral("preview"));
        splitter->addWidget(preview);

        horizontalLayout->addWidget(splitter);

        DocumentWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(DocumentWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 20));
        menu_File = new QMenu(menubar);
        menu_File->setObjectName(QStringLiteral("menu_File"));
        DocumentWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(DocumentWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        DocumentWindow->setStatusBar(statusbar);

        menubar->addAction(menu_File->menuAction());
        menu_File->addAction(actionNew);
        menu_File->addAction(actionOpen);
        menu_File->addAction(actionSave);
        menu_File->addAction(actionSaveAs);
        menu_File->addSeparator();
        menu_File->addAction(actionExit);

        retranslateUi(DocumentWindow);

        QMetaObject::connectSlotsByName(DocumentWindow);
    } // setupUi

    void retranslateUi(QMainWindow *DocumentWindow)
    {
        DocumentWindow->setWindowTitle(QApplication::translate("DocumentWindow", "MarkDown Editor", nullptr));
        actionOpen->setText(QApplication::translate("DocumentWindow", "&Open...", nullptr));
#ifndef QT_NO_TOOLTIP
        actionOpen->setToolTip(QApplication::translate("DocumentWindow", "Open document", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_SHORTCUT
        actionOpen->setShortcut(QApplication::translate("DocumentWindow", "Ctrl+O", nullptr));
#endif // QT_NO_SHORTCUT
        actionSave->setText(QApplication::translate("DocumentWindow", "&Save", nullptr));
#ifndef QT_NO_TOOLTIP
        actionSave->setToolTip(QApplication::translate("DocumentWindow", "Save current document", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_SHORTCUT
        actionSave->setShortcut(QApplication::translate("DocumentWindow", "Ctrl+S", nullptr));
#endif // QT_NO_SHORTCUT
        actionExit->setText(QApplication::translate("DocumentWindow", "E&xit", nullptr));
#ifndef QT_NO_TOOLTIP
        actionExit->setToolTip(QApplication::translate("DocumentWindow", "Exit editor", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_SHORTCUT
        actionExit->setShortcut(QApplication::translate("DocumentWindow", "Ctrl+Q", nullptr));
#endif // QT_NO_SHORTCUT
        actionSaveAs->setText(QApplication::translate("DocumentWindow", "Save &As...", nullptr));
#ifndef QT_NO_TOOLTIP
        actionSaveAs->setToolTip(QApplication::translate("DocumentWindow", "Save document under different name", nullptr));
#endif // QT_NO_TOOLTIP
        actionNew->setText(QApplication::translate("DocumentWindow", "&New", nullptr));
#ifndef QT_NO_TOOLTIP
        actionNew->setToolTip(QApplication::translate("DocumentWindow", "Create new document", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_SHORTCUT
        actionNew->setShortcut(QApplication::translate("DocumentWindow", "Ctrl+N", nullptr));
#endif // QT_NO_SHORTCUT
        menu_File->setTitle(QApplication::translate("DocumentWindow", "&File", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DocumentWindow: public Ui_DocumentWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DOCUMENTWINDOW_H
