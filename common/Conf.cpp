#include "Conf.h"

#include <iostream>
#include <fstream>


Conf::Conf(const std::string& file_path, std::map<std::string, std::string> conf)
    : m_file_path(file_path), m_conf(conf)
{
    file_read(file_path);

    for (const auto& [key, value] : m_conf) {
        std::cout << key << " => " << value << "\n";
    }
}

void Conf::file_read(const std::string& file_path)
{   
    std::ifstream conf_file(m_file_path);
    if (!conf_file.is_open())
        return;
   
    m_conf.clear();
    std::string line;
    while (std::getline(conf_file, line)) {
        int delimiterPos = line.find('=');
        std::string key = line.substr(0, delimiterPos);
        std::string value = line.substr(delimiterPos + 1);
        m_conf[key] = value;
    }
}