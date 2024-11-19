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

        // �t�B�[���h�� or �R�����g�s or �󔒍s�̓X�L�b�v
        if (line[0] == '[' || line[0] == '#' || line.empty())
            continue;

        // [=]�������āAkey-value�ɕ���
        size_t delimiterPos = line.find('=');
        std::string key = line.substr(0, delimiterPos);
        std::string value = line.substr(delimiterPos + 1);

        // key-value�ɋ󔒕����������Ă���ꍇ�͏���
        erase_whitespace(key);
        erase_whitespace(value);

        m_key_value_pair[key] = value;
    }
}

std::map<std::string, std::string> ConfFile::get_key_value_pair() const
{
    return m_key_value_pair;
}
