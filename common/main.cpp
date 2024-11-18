#include "Conf.h"

#include <iostream>
#include <memory>


int main() {
    std::map<std::string, std::string> conf_data;

    std::unique_ptr<FileOperation> FileOperation = std::make_unique<Conf>("file/config.conf", conf_data);

    return 0;
}