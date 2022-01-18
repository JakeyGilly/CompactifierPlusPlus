//
//  fileio.hpp
//  Compactifier
//
//  Created by Jake Gillman on 14/01/2022.
//

#ifndef fileio_h
#define fileio_h

std::string filetype(std::string);
bool isFileReal(std::string);
std::string readFile(std::string);
int fileSize(std::string);
void writeFile(std::string, std::string);

#endif /* fileio_h */
