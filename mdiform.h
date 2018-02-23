#ifndef MDIFORM_H
#define MDIFORM_H

#include <QMainWindow>
#include <QObject>
#include <QWidget>
#include <QString>
#include "sol.hpp"
#include "sol_assert.hpp"

#define SOL_CHECK_ARGUMENTS 1

QT_BEGIN_NAMESPACE
namespace Ui {
class MdiForm;
}
QT_END_NAMESPACE

class MdiForm : public QMainWindow
{
    Q_OBJECT
public:
    explicit MdiForm(QWidget *parent = nullptr);
    ~MdiForm();
    void openFile(const QString &path);

signals:

private slots:
//    void onFileNew();
    void onFileOpen();
    void onProjectOpen();
//    void onFileSave();
//    void onFileSaveAs();
    void onExit();

private:
    Ui::MdiForm *ui;
    sol::state *m_pCurrentProject;
    bool modified;
    void LoadProject(const QString &path);
    void ShowError(QString errmsg);
    bool isModified() const;
};

#endif // MDIFORM_H
