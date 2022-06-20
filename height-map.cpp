// main function gangsters 

// Calling the boys 
#include <iostream>
#include <fstream> 
#include <windows.h>
#include <string> 

void readDataFile(std::string fileIn, char** data);
float computeDistance(char * data, int indexAlpha, indexBravo);

int main()
{
    std::string preFile = "/workspace/mt-helens-map/pre.data";
    std::string postFile = "/workspace/mt-helens-map/post.data";

    char* preBuffer = NULL;
    char* postBuffer = NULL;

    readDataFile(preFile, &preBuffer);
    readDataFile(preFile, &postBuffer);

    delete[] preBuffer;
    delete[] postBuffer; 

    return 0;
}

void readDataFile(std::string fileIn, char** data)
{
    std::ifstream ifs(fileIn, std::ifstream::binary);
    if(ifs)
    {
        ifs.seekg(0, ifs.end);
        int leng = ifs.tellg();
        ifs.seekg(0, ifs.beg);

        *data = new char[leng];
        std::cout << "Reading " << leng << " characters...\n";
        ifs.read(*data, leng);
        
        if(ifs)
            std::cout << "all chars read successfully. \n";
        else
            std::cout << "error: only" << ifs.gcount() << " could be read";
        
        ifs.close(); 
    }
}