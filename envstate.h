#ifndef ENVSTATE_H
#define ENVSTATE_H

#include <QObject>

#define SOL_CHECK_ARGUMENTS 1
#include "sol.hpp"
#include <iostream>
#include <list>
#include <iterator>
#include "document.h"

#define CN "conf"
#define NUM_NIL 0xFFFFFFFFC4653601

//#include "../../assert.hpp"
#include <QObject>
#include <QString>

class EnvState: public QObject
{
    Q_OBJECT
//    Q_PROPERTY(QString text MEMBER m_text NOTIFY textChanged FINAL)

public:
    EnvState(QObject *parent);
    ~EnvState();
    sol::optional<std::string> GetString(const std::string name);
    sol::optional<double> GetNumber(const std::string name);
    void SetProperty(const std::string name, const  std::string value);
    void SetProperty(const std::string name, const double value);
    void LoadProject(std::string *path);
    void Save();
    bool isLoaded();
    std::string RunScript(std::string *script);
    std::vector<Document *> GetDocuments();
private:
    sol::state* _state;  
    bool _isLoaded;
};

#endif // ENVSTATE_H
