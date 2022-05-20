//
// Created by batuh on 5/20/2022.
//

#ifndef UNTITLED1_UTILS_H
#define UNTITLED1_UTILS_H

#include <iostream>
#include <string>
#include <filesystem>
#include <fstream>

using namespace std;
using filesystem::current_path;
namespace fs = filesystem;

string findExtension(const string &fileName)
{
    string::size_type idx;
    idx = fileName.rfind('.');

    if (idx != string::npos)
    {
        return fileName.substr(idx + 1);
    }
    else
        return "NO_EXTENSION";
}

int fileCount(const filesystem::path &myPath)
{
    int index = 0;
    for (const auto &file : fs::directory_iterator(myPath))
    {
        index++;
    }
    return index;
}

string splitter(const string &myString)
{
    string::size_type idx;
    idx = myString.rfind('\\');

    if (idx != string::npos)
        return myString.substr(idx + 1);
    return "";
}

string getFileSize(const string &filename)
{
    return to_string(filesystem::file_size(filename));
}

string filesize(const string &filename)
{
    ifstream in(filename, ifstream::ate | ifstream::binary);
    return to_string(in.tellg());
}


vector<vector<string>> files2dVector(const filesystem::path &myPath, int &file_count)
{
    file_count = fileCount(myPath);
    int row = fileCount(myPath);
    int index = 0;
    vector<vector<string>> files(row);

    for (const auto &file : fs::directory_iterator(myPath))
    {
        string path_string = file.path().string();
        int col = 3;
        files[index] = vector<string>(col);

        files[index][0] = splitter((path_string));
        files[index][1] = findExtension(path_string);
        files[index][2] = filesize(splitter((path_string)));
        index++;
    }
    return files;
}



#endif //UNTITLED1_UTILS_H
