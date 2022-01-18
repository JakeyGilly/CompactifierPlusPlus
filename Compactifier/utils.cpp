int getLineFromChar(char* fileContents, int charIndex) {
    int line = 1;
    for (int i = 0; i < charIndex; i++) {
        if (fileContents[i] == '\n') line++;
    }
    return line;
}
