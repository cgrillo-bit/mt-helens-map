// SurfaceDistancer.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <vector>

void readDataFile(std::string fileIn, char** data);
float computeDistance(char* data, int indexA, int indexB);

int getSize(char* s) {
    char* t;
    for (t = s; *t != '\0'; t++)
        ;
    return t - s;
}

int main()
{
    std::string preFile = "Resources\\st-helens\\pre.data";
    std::string postFile = "Resources\\st-helens\\post.data";

    char* preBuffer = NULL;
    char* postBuffer= NULL;

    readDataFile(preFile, &preBuffer);
    readDataFile(preFile, &postBuffer);

    int t = getSize(preBuffer);
    for (int i = 0; i < t; i++)
        std::cout << static_cast<unsigned int>(preBuffer[i]) << " ";


    delete[] preBuffer;
    delete[] postBuffer;
    
    return 0;
}

void readDataFile(std::string fileIn, char** data)
{
    std::ifstream ifs(fileIn, std::ifstream::binary);
    if (ifs)
    {
        ifs.seekg(0, ifs.end);
        int length = ifs.tellg();
        ifs.seekg(0, ifs.beg);

        *data = new char[length];
        std::cout << "Reading " << length << " characters...\n";
        ifs.read(*data, length);

        if (ifs)
            std::cout << "all characters read sucessfully.\n";
        else
            std::cout << "error: only " << ifs.gcount() << " could be read";

        ifs.close();
    }
}