#include "ConfFile.h"

#include <iostream>
#include <memory>


int main() {
    std::map<std::string, std::string> conf_data;

    std::unique_ptr<ConfFile> FileOperation = std::make_unique<ConfFile>();
    FileOperation->file_read("file/config.conf");
    conf_data = FileOperation->get_key_value_pair();

    for (const auto& [key, value] : conf_data) {
        std::cout << key << "=>" << value << std::endl;
    }


    return 0;
}