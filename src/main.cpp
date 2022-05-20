#define PYTHON "py"
#define CPP "cpp"
#define C "c"

#include <iostream>
#include <vector>
#include <cstring>
#include "headers/tokeniser.hpp"
#include "headers/fileio.hpp"


int main(int argc, char* argv[]) {
	std::string file; int compact = 0; std::string output; bool debug = false;
	for (int i = 0; i < argc - 1; i++) {
		if (!std::strcmp(argv[i], "-f") && isFileReal(argv[i + 1])) file = argv[i + 1];
		if (!std::strcmp(argv[i], "-c")) compact = atoi(argv[i + 1]);
		if (!std::strcmp(argv[i], "-o")) output = argv[i + 1];
		if (!std::strcmp(argv[i], "-d")) debug = 1;
		if (!std::strcmp(argv[i], "-h")) {
			std::cout << "No file specified" << std::endl;
            std::cout << "CompactiferPlusPlus V1.0" << std::endl;
            std::cout << "Usage: " << argv[0] << " [options]" << std::endl;
            std::cout << "Compacts a Python File" << std::endl << std::endl;
            std::cout << "Options:" << std::endl;
            std::cout << "\t-f <file> : Specify the file to be compacted [Required]" << std::endl;
            std::cout << "\t-c <int> : Specify the compaction level of the program" 
            << std::endl << "\t\t0 - No compaction" 
            << std::endl << "\t\t1 - Remove comments and format"
            << std::endl << "\t\t2 - Optimize Code for Compaction" 
            << std::endl << "\t\t3 - More optimize"
            << std::endl << "\t\tRead More about compaction levels in https://github.com/JakeyGilly/CompactifierPlusPlus/blob/main/stages.md" << std::endl;
            std::cout << "\t-o <file> : Specify the output file" << std::endl;
            std::cout << "\t-d : Enable debug mode" << std::endl;
            std::cout << "\t-h : Print this help message" << std::endl;
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
        std::string extention;
        std::string lang = filetype(file);
        if (lang == PYTHON) {
            extention = PYTHON;
            std::vector<std::string> tokens = tokenise("the quick brown fox jumps over the lazy dog");
            for (auto token : tokens) {
                std::cout << token << std::endl;
            }
        } else if (lang == C) {
            extention = C;
        } else if (lang == CPP) {
            extention = CPP;
        } else {
            std::cout << "File type not supported" << std::endl;
            return 1;
        }
        // Compaction ends here
        if (!!output.compare("")) {
        writeFile(output, fileContents);
        std::cout << "Compacted File size: " << fileSize(output) << " Bytes" << std::endl;
        } else {
            writeFile("output." + extention, fileContents);
            std::cout << "Compacted File size: " << fileSize("output." + extention) << " Bytes" << std::endl;
        }
    } else {
        std::cout << "No file specified" << std::endl;
        std::cout << "CompactiferPlusPlus V1.0" << std::endl;
        std::cout << "Usage: " << argv[0] << " [options]" << std::endl;
        std::cout << "Compacts a Python File" << std::endl << std::endl;
        std::cout << "Options:" << std::endl;
        std::cout << "\t-f <file> : Specify the file to be compacted [Required]" << std::endl;
        std::cout << "\t-c <int> : Specify the compaction level of the program" << std::endl 
        << "\t\t0 - No compaction" << std::endl
        << "\t\t1 - Remove comments and format" << std::endl
        << "\t\t2 - Optimize Code for Compaction" << std::endl
        << "\t\t3 - More optimize" << std::endl
        << "\t\tRead More about compaction levels in https://github.com/JakeyGilly/CompactifierPlusPlus/blob/main/stages.md" << std::endl;
        std::cout << "\t-o <file> : Specify the output file" << std::endl;
        std::cout << "\t-l <language> : Specify the language of the file" << std::endl;
        std::cout << "\t-d : Enable debug mode" << std::endl;
        std::cout << "\t-h : Print this help message" << std::endl;
        return 0;
    }
}