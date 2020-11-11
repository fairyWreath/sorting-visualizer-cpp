#include "config.hpp"

Config::~Config() {
	if (fileStream.is_open()) {
		fileStream.close();
	}
}

void Config::setPath(const std::string& path) {
	filePath = path;
}

void Config::startStream() {
	if (!fileStream.is_open()) {
		fileStream.open(filePath.c_str());
		if (!fileStream.good()) {
			throw std::exception("File does not exist / cannot be opened");
		}
	}
}

void Config::parse() {
	startStream();
	options.clear();		// clear options map

	std::string line = "";
	while (std::getline(fileStream, line)) {
		size_t pos = line.find("=");	// size_t is an int type used for sizes
		std::string key = line.substr(0, pos);		// deepcopy string; (index, length to copy)
		std::string value = line.substr(pos + 1);	// no 2nd parameter means copy to end

		if (key.empty() || value.empty()) {
			continue;
		}
		options[key] = Option(value);
	}
}

Option Config::getOption(const std::string& key) const {
	if (options.find(key) == std::end(options)) {
		throw std::exception("No option with that key");
	}
	return options.at(key);
}