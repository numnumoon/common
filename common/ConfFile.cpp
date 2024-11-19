#include "ConfFile.h"

#include <iostream>
#include <fstream>

namespace {
    void erase_whitespace(std::string& str) {
        str.erase(std::remove_if(str.begin(), str.end(), ::isspace), str.end());
    }
}


void ConfFile::file_read(const std::string& file_path)
{   
    std::ifstream conf_file(file_path);
    if (!conf_file) {
        std::cout << "Failed to open conf file : " + file_path << std::endl;
        return;
    }  
   
    std::string line;
    while (std::getline(conf_file, line)) {

        // フィールド名 or コメント行 or 空白行はスキップ
        if (line[0] == '[' || line[0] == '#' || line.empty())
            continue;

        // [=]を見つけて、key-valueに分割
        size_t delimiterPos = line.find('=');
        std::string key = line.substr(0, delimiterPos);
        std::string value = line.substr(delimiterPos + 1);

        // key-valueに空白文字が入っている場合は除去
        erase_whitespace(key);
        erase_whitespace(value);

        m_key_value_pair[key] = value;
    }
}

std::map<std::string, std::string> ConfFile::get_key_value_pair() const
{
    return m_key_value_pair;
}
