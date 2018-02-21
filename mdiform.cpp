#include "mdiform.h"
#include "ui_mdiform.h"
#include <iostream>
#include <QFile>
#include <QFileDialog>
//#include <QFontDatabase>
#include <QMessageBox>
//#include <QTextStream>
//#include <QWebChannel>

MdiForm::MdiForm(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MdiForm)
{
    ui->setupUi(this);
    connect(ui->actionOpen_Project, &QAction::triggered, this, &MdiForm::onProjectOpen);

    std::cout << "=== opening a state example ===" << std::endl;

    sol::state lua;
    // open some common libraries
    lua.open_libraries(sol::lib::base, sol::lib::package);
    lua.script("print('bark bark bark!')");

    std::cout << std::endl;
}

MdiForm::~MdiForm()
{
    delete ui;
}

void MdiForm::openFile(const QString &path)
{
    QFile f(path);
    if (!f.open(QIODevice::ReadOnly)) {
        QMessageBox::warning(this, windowTitle(),
                             tr("Could not open file %1: %2").arg(
                                 QDir::toNativeSeparators(path), f.errorString()));
        return;
    }
    QMessageBox::information(this, windowTitle(),
                             tr("This file is great: %1").arg(path));

    f.close();
//    m_filePath = path;
//    ui->editor->setPlainText(f.readAll());
}

void MdiForm::onFileOpen(){}
void MdiForm::onExit(){}

void MdiForm::onProjectOpen()
{
//    if (isModified()) {
//        QMessageBox::StandardButton button = QMessageBox::question(this, windowTitle(),
//                             tr("You have unsaved changes. Do you want to open a new document anyway?"));
//        if (button != QMessageBox::Yes)
//            return;
//    }

    QString path = QFileDialog::getOpenFileName(this,
        tr("Open Project Configuration"), "", tr("Project File (*.lcf)"));
    if (path.isEmpty())
        return;

    openFile(path);
}
