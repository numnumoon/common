#pragma once

#include "FileOperation.h"

#include <map>

class Conf : public FileOperation{
public:
	// デフォルトコンストラクタ
	Conf() = default;

	// ファイルパスを指定するコンストラクタ
	Conf(const std::string& file_path, std::map<std::string, std::string> conf);

	// FileOperation を介して継承されました
	void file_read(const std::string& file_path)override;

private:
	std::string m_file_path;
	std::map<std::string, std::string> m_conf;
};

