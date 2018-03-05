/********************************************************************************
** Form generated from reading UI file 'mdiform.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MDIFORM_H
#define UI_MDIFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDockWidget>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMdiArea>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MdiForm
{
public:
    QAction *actionNew_Project;
    QAction *actionOpen_Project;
    QAction *actionNew_File;
    QAction *actionOpen_File;
    QAction *action_Close;
    QAction *actionE_xit;
    QWidget *centralwidget;
    QMdiArea *mdiArea;
    QMenuBar *menubar;
    QMenu *menuFile;
    QMenu *menu_View;
    QStatusBar *statusbar;
    QDockWidget *dockWidget;
    QWidget *dockWidgetContents;
    QPushButton *Sol2Button;

    void setupUi(QMainWindow *MdiForm)
    {
        if (MdiForm->objectName().isEmpty())
            MdiForm->setObjectName(QStringLiteral("MdiForm"));
        MdiForm->resize(800, 600);
        actionNew_Project = new QAction(MdiForm);
        actionNew_Project->setObjectName(QStringLiteral("actionNew_Project"));
        actionOpen_Project = new QAction(MdiForm);
        actionOpen_Project->setObjectName(QStringLiteral("actionOpen_Project"));
        actionNew_File = new QAction(MdiForm);
        actionNew_File->setObjectName(QStringLiteral("actionNew_File"));
        actionOpen_File = new QAction(MdiForm);
        actionOpen_File->setObjectName(QStringLiteral("actionOpen_File"));
        action_Close = new QAction(MdiForm);
        action_Close->setObjectName(QStringLiteral("action_Close"));
        actionE_xit = new QAction(MdiForm);
        actionE_xit->setObjectName(QStringLiteral("actionE_xit"));
        centralwidget = new QWidget(MdiForm);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        mdiArea = new QMdiArea(centralwidget);
        mdiArea->setObjectName(QStringLiteral("mdiArea"));
        mdiArea->setGeometry(QRect(40, 0, 761, 551));
        MdiForm->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MdiForm);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 21));
        menuFile = new QMenu(menubar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        menu_View = new QMenu(menubar);
        menu_View->setObjectName(QStringLiteral("menu_View"));
        MdiForm->setMenuBar(menubar);
        statusbar = new QStatusBar(MdiForm);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        MdiForm->setStatusBar(statusbar);
        dockWidget = new QDockWidget(MdiForm);
        dockWidget->setObjectName(QStringLiteral("dockWidget"));
        dockWidgetContents = new QWidget();
        dockWidgetContents->setObjectName(QStringLiteral("dockWidgetContents"));
        Sol2Button = new QPushButton(dockWidgetContents);
        Sol2Button->setObjectName(QStringLiteral("Sol2Button"));
        Sol2Button->setGeometry(QRect(20, 100, 80, 21));
        dockWidget->setWidget(dockWidgetContents);
        MdiForm->addDockWidget(static_cast<Qt::DockWidgetArea>(1), dockWidget);

        menubar->addAction(menuFile->menuAction());
        menubar->addAction(menu_View->menuAction());
        menuFile->addAction(actionNew_Project);
        menuFile->addAction(actionOpen_Project);
        menuFile->addSeparator();
        menuFile->addAction(actionNew_File);
        menuFile->addAction(actionOpen_File);
        menuFile->addSeparator();
        menuFile->addAction(action_Close);
        menuFile->addAction(actionE_xit);

        retranslateUi(MdiForm);

        QMetaObject::connectSlotsByName(MdiForm);
    } // setupUi

    void retranslateUi(QMainWindow *MdiForm)
    {
        MdiForm->setWindowTitle(QApplication::translate("MdiForm", "MainWindow", nullptr));
        actionNew_Project->setText(QApplication::translate("MdiForm", "&New Project...", nullptr));
        actionOpen_Project->setText(QApplication::translate("MdiForm", "&Open Project...", nullptr));
        actionNew_File->setText(QApplication::translate("MdiForm", "Ne&w File...", nullptr));
        actionOpen_File->setText(QApplication::translate("MdiForm", "Op&en File...", nullptr));
        action_Close->setText(QApplication::translate("MdiForm", "&Close", nullptr));
        actionE_xit->setText(QApplication::translate("MdiForm", "E&xit", nullptr));
        menuFile->setTitle(QApplication::translate("MdiForm", "File", nullptr));
        menu_View->setTitle(QApplication::translate("MdiForm", "&View", nullptr));
        Sol2Button->setText(QApplication::translate("MdiForm", "Sol2 Button!", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MdiForm: public Ui_MdiForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MDIFORM_H
