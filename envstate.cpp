#include "envstate.h"

EnvState::EnvState(QObject *parent = nullptr): QObject(parent),
    _state(),
    _isLoaded(false)
{
    _state = new sol::state();
}

EnvState::~EnvState()
{
    free(_state);
}

sol::optional<std::string> EnvState::GetString(const std::string name)
{
    sol::optional<std::string> str = (*_state)[CN][name];
    return str;
}

sol::optional<double> EnvState::GetNumber(const std::string name)
{
    sol::optional<double> num = (*_state)[CN][name];
    return num;
}

void EnvState::SetProperty(const std::string name, const  std::string value)
{
    (*_state)[CN][name] = value;
}

void EnvState::SetProperty(const std::string name, const  double value)
{
    (*_state)[CN][name] = value;
}

void EnvState::Save()
{
    std::string str = R"(
                    do
                      file = io.open(file_path, 'w+')
                      file:write('conf=')
                      file:write(ser.block(conf,{numformat='%.2g'}))
                      file:close()
                    end
                      )";
    _state->script(str, sol::script_default_on_error);
}

void EnvState::LoadProject(std::string *path)
{
    try
    {
        _state->~state();
        _state = new sol::state();
        _state->open_libraries(sol::lib::base, sol::lib::io, sol::lib::string, sol::lib::package, sol::lib::math, sol::lib::table);
        _state->script_file("parseprojfile.lua", sol::script_default_on_error);
        _state->script_file(*path, sol::script_default_on_error);
        std::string result = (*_state)["parse_proj_1_0"]((*_state)["conf"]);
        //DO SOMETHING WITH RESULT...
        (*_state)["file_path"] = *path;
        _state->script_file(*path, sol::script_default_on_error);
        _state->script("ser = require('serpent')", sol::script_default_on_error);
        _state->script("print(_VERSION) print(file_path) print(conf.project_name)");
        _state->script("print(ser.block(conf,{numformat='%.2g'}))");
    }
    catch (sol::error& err)
    {
        std::cout << "Oops: " << err.what() << std::endl;
    }
}

std::vector<Document *> EnvState::GetDocuments()
{
    std::vector<Document *> docList;
    sol::optional<sol::table> docs = (*_state)[CN]["documents"];
    if(docs){
        for (const auto& key_value_pair : docs.value() )
        {
            sol::object key = key_value_pair.first;
            sol::object value = key_value_pair.second;
            int k = key.as<int>();
            sol::type t = value.get_type();
            switch (t) {
            case sol::type::string: {
                Document *d = new Document(value.as<std::string>());
                docList.push_back(d);
                std::cout << k << ": " << d->path().toStdString() << std::endl;
            }
                break;
            case sol::type::number: {
                auto v = value.as<double>();
                std::cout << k << ": " << v << std::endl;
            }
                break;
            default:{
                std::cout << "hit the default case!" << std::endl;
            }
            }
        }
    }
    return docList;
}

std::string EnvState::RunScript(std::string *script)
{
    std::string str = *script;
    std::string result;
    try
    {
        result = _state->script(str, sol::script_default_on_error);
        if(result != "") return result; else return "";
    }
    catch (sol::error& err)
    {
        std::cout << "Oops: " << err.what() << std::endl;
        return err.what();
    }
}
