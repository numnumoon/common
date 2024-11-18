#pragma once

#include "FileOperation.h"

#include <map>

class Conf : public FileOperation{
public:
	// �f�t�H���g�R���X�g���N�^
	Conf() = default;

	// �t�@�C���p�X���w�肷��R���X�g���N�^
	Conf(const std::string& file_path, std::map<std::string, std::string> conf);

	// FileOperation ����Čp������܂���
	void file_read(const std::string& file_path)override;

private:
	std::string m_file_path;
	std::map<std::string, std::string> m_conf;
};

