# CompactifierPlusPlus
![GitHub Repo stars](https://img.shields.io/github/stars/JakeyGilly/CompactifierPlusPlus?style=social)
[![License](https://img.shields.io/badge/License-MIT-blue)](#license)
![GitHub last commit](https://img.shields.io/github/last-commit/JakeyGilly/CompactifierPlusPlus)
![GitHub issues](https://img.shields.io/github/issues-raw/JakeyGilly/CompactifierPlusPlus)
![GitHub commit activity](https://img.shields.io/github/commit-activity/m/JakeyGilly/CompactifierPlusPlus)

## About
This project is designed to compact code in Python (more languages coming soon)

This project was inteded to be made in The C Language but I decided to switch to C++ becuase it has more features and better support for Strings.

This project is still in development and I am working on it.

## Usage
You can clone this repository using ```$ git clone https://github.com/JakeyGilly/CompactifierPlusPlus.git``` or grab a release from the releases tab.

Build the project using 
```
$ make
```

Next you execute the Compactifier with the file needed to compact and the compact level as the parameters using 
```
$ ./Compactifier.out -f /path/to/file (Linux/Mac)

$ Compactifier.exe -f /path/to/file (Windows)
```
Compactifier arguments include
* -f (file path)
* -c (compaction level)
* -o (output file path)
* -d (debug mode)
* -l (language)

## Contributing
Contributions of all types are welcome and encouraged. You can help fix bugs, optimize existing code, add good practices and more. Just open a pull request saying what you have changed or fixed and I will look into it.
Look at the CodeCompactor project board or the future Todo section below to find what would help me.


## Future Todo
### Stages
There will be 3 stages of compactness that Compacter can handle
* A bit compact (level 1)
* Compact (level 2)
* Annoyingly compact (level 3)

You can find out more about the stages [here](http://github.com/JakeyGilly/CompactifierPlusPlus/blob/main/stages.md)

### Features
* Compact Formatting
* Debug Mode


Made by Jake Gillman
