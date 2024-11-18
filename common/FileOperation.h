#pragma once

#include <string>
#include <vector>

class FileOperation {
public:
	virtual ~FileOperation() = default;
	virtual void file_read(const std::string& file_path) = 0;
};