#pragma once

#include "FileOperation.h"

#include <map>

class ConfFile : public FileOperation{
public:
	// FileOperation ‚ğ‰î‚µ‚ÄŒp³‚³‚ê‚Ü‚µ‚½
	void file_read(const std::string& file_path) override;

	std::map<std::string, std::string> get_key_value_pair() const;

private:
	std::map<std::string, std::string> m_key_value_pair;
};

