#include <iostream>
#include <vector>
#include <cstring>
#include "headers/fileio.hpp"
#include "headers/formatting.hpp"

int main(int argc, char* argv[]) {
	std::string file; int compact = 0; std::string output; std::string language;
bool debug = false;
	for (int i = 0; i < argc - 1; i++) {
		if (!std::strcmp(argv[i], "-f") && isFileReal(argv[i + 1])) file = argv[i + 1];
		if (!std::strcmp(argv[i], "-c")) compact = atoi(argv[i + 1]);
		if (!std::strcmp(argv[i], "-o")) output = argv[i + 1];
		if (!std::strcmp(argv[i], "-l")) language = argv[i + 1];
		if (!std::strcmp(argv[i], "-d")) debug = 1;
		if (!std::strcmp(argv[i], "-h")) {
			std::cout << "usage stuff..." << std::endl;
			return 0;
		}
	}
	if (!!file.compare("")) {
		std::vector<std::string> fileContents = readFile(file);
        if (fileContents.empty()) {
            std::cout << "File not found" << std::endl;
            return 1;
        }
		std::cout << "Opened File " << file << std::endl << "Type " << filetype(file) << std::endl << "File size: " << fileSize(file) << " Bytes" << std::endl;
        // Compaction begins here
        if (!filetype(file).compare(".py")) {
           pyRemoveAnnatations(fileContents);
           pyFormat(fileContents);
        } else {
            std::cout << "File type not supported" << std::endl;
        }
        // Compaction ends here
        if (!!output.compare("")) {
        writeFile(output, fileContents);
        std::cout << "Compacted File size: " << fileSize(output) << " Bytes" << std::endl;
        } else {
            writeFile("output" + filetype(file), fileContents);
            std::cout << "Compacted File size: " << fileSize("output" + filetype(file)) << " Bytes" << std::endl;
        }
    } else {
        std::cout << "No file specified" << std::endl;
        std::cout << "usage stuff..." << std::endl;
    }
}
