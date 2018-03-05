#define SOL_CHECK_ARGUMENTS 1

#include "mdiform.h"
#include "ui_mdiform.h"
#include <iostream>
#include <QtWidgets>
#include <QFile>
#include <QFileDialog>
//#include <QFontDatabase>
#include <QMessageBox>
//#include <QTextStream>
//#include <QWebChannel>

MdiForm::MdiForm(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MdiForm),
    _state(new EnvState(parent)),
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

//void MdiForm::openFile(const QString &path)
//{
//    QFile f(path);
//    if (!f.open(QIODevice::ReadOnly)) {
//        QMessageBox::warning(this, windowTitle(),
//                             tr("Could not open file %1: %2").arg(
//                                 QDir::toNativeSeparators(path), f.errorString()));
//        return;
//    }
//    QMessageBox::information(this, windowTitle(),
//                             tr("This file is great: %1").arg(path));
//    f.close();
//    //    m_filePath = path;
//    //    ui->editor->setPlainText(f.readAll());
//}

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
    try{
        //Need to add the project path to our state
        _state.LoadProject(&(path.toStdString()));
        std::string title = _state.RunScript(&std::string("return string.format('%s - %3.2f',conf.project_name, conf.project_version)"));
        setWindowTitle(QString::fromStdString(title));
        std::vector<Document*> docs = _state.GetDocuments();
        std::cout << docs.size() << std::endl;
        for(auto const& doc: docs) {
            openFile(doc->path());
        }
    }
    catch(sol::error& err){
        QMessageBox::information(this, windowTitle(),
            tr("Failed to open project file. Errors: %1\r\nPath: %2").arg(QString::fromUtf8(err.what()), path));
        std::cout << "oops: " << err.what() << std::endl;
        QString errmsg =QString::fromUtf8(err.what());
        ShowError(errmsg);
    }
}


bool MdiForm::isModified() const
{
    return modified;
}

void MdiForm::ShowError(QString &errmsg){
    QMessageBox::warning(this, windowTitle(),
                         tr("Lua Error: %1").arg(errmsg));
}
//void MdiForm::CreateComponents(sol::state *lua){
//    return;
//}

void MdiForm::newFile()
{
    MdiChild *child = createMdiChild();
    child->newFile();
    child->show();
}

void MdiForm::open()
{
    const QString fileName = QFileDialog::getOpenFileName(this);
    if (!fileName.isEmpty())
        openFile(fileName);
}

bool MdiForm::openFile(const QString &fileName)
{
    if (QMdiSubWindow *existing = findMdiChild(fileName)) {
        ui->mdiArea->setActiveSubWindow(existing);
        return true;
    }
    const bool succeeded = loadFile(fileName);
    if (succeeded)
        statusBar()->showMessage(tr("File loaded"), 2000);
    return succeeded;
}

bool MdiForm::loadFile(const QString &fileName)
{
    MdiChild *child = createMdiChild();
    const bool succeeded = child->loadFile(fileName);
    if (succeeded)
        child->show();
    else
        child->close();
    //MdiForm::prependToRecentFiles(fileName);
    return succeeded;
}

MdiChild *MdiForm::createMdiChild()
{
    MdiChild *child = new MdiChild;
    ui->mdiArea->addSubWindow(child);

//#ifndef QT_NO_CLIPBOARD
//    connect(child, &QTextEdit::copyAvailable, cutAct, &QAction::setEnabled);
//    connect(child, &QTextEdit::copyAvailable, copyAct, &QAction::setEnabled);
//#endif

    return child;
}

QMdiSubWindow *MdiForm::findMdiChild(const QString &fileName) const
{
    QString canonicalFilePath = QFileInfo(fileName).canonicalFilePath();

    foreach (QMdiSubWindow *window, ui->mdiArea->subWindowList()) {
        MdiChild *mdiChild = qobject_cast<MdiChild *>(window->widget());
        if (mdiChild->currentFile() == canonicalFilePath)
            return window;
    }
    return 0;
}
