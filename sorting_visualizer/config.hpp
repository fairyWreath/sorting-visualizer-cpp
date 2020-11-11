#ifndef CONFIG_HPP
#define CONFIG_HPP

#include "option.hpp"
#include <fstream>
#include <map>

class Config {
public:
	Config() : filePath("") {}
	~Config();
	void setPath(const std::string& path);
	void parse();
	Option getOption(const std::string& key) const;


private:
	std::string filePath;
	std::ifstream fileStream;
	std::map<std::string, Option> options;		// dict in STL

	void startStream();
};

#endif