#define SOL_CHECK_ARGUMENTS 1

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
    ui(new Ui::MdiForm),
    m_pCurrentProject(new sol::state),
    modified(false)
{
    ui->setupUi(this);
    connect(ui->actionOpen_Project, &QAction::triggered, this, &MdiForm::onProjectOpen);
//    connect(ui->Sol2Button, &QPushButton::clicked, this, &MdiForm::ExecuteLua);
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
    if (isModified()) {
        QMessageBox::StandardButton button = QMessageBox::question(this, windowTitle(),
                             tr("You have unsaved changes. Do you want to open a new document anyway?"));
        if (button != QMessageBox::Yes)
            std::cout << "=======SAVE STATE HERE==========" << std::endl;
            return;
    }

    QString path = QFileDialog::getOpenFileName(this,
                                                tr("Open Project Configuration"), "", tr("Project File (*.lcf)"));
    if (path.isEmpty())
        return;

    //    openFile(path);
    LoadProject(path);
}

void MdiForm::LoadProject(const QString &path)
{
    if(m_pCurrentProject != NULL){free(m_pCurrentProject);}

    m_pCurrentProject = new sol::state();
    std::cout << "=== opening a state ===" << std::endl;
    std::cout << path.toStdString();
    sol::state lua;
    // open some common libraries
    lua.open_libraries( sol::lib::base, sol::lib::string );
    try{
        lua.script_file("parseprojfile.lua", sol::script_default_on_error);
        lua.script_file(path.toStdString(), sol::script_default_on_error);
        std::string result = lua["parse_proj_1_0"](lua["conf"]);
        if(result != ""){
            QMessageBox::information(this, windowTitle(),
                tr("Failed to open project file. Errors: %1\r\nPath: %2").arg(QString::fromStdString(result), path));
        }
        else
        {
            std::string title = lua.script("return string.format('%s - %3.2f',conf.project_name, conf.project_version)");
            setWindowTitle(QString::fromStdString(title));
        }
    }
    catch(sol::error& err){
        std::cout << "oops: " << err.what() << std::endl;
        ShowError(err.what());
    }
}

bool MdiForm::isModified() const
{
    return modified;
}

void MdiForm::ShowError(QString errmsg){
    QMessageBox::warning(this, windowTitle(),
                         tr("Lua Error: %1").arg(errmsg));
}
//void MdiForm::CreateComponents(sol::state *lua){
//    return;
//}
