#include <iostream>
#include <limits>
#include "utils.h"
#include "MultiLList.h"

using namespace std;

int main() {

    cout << "Enter a valid path:\n";
    string input_path;
    cin >> input_path;
    // filesystem::path cwd = input_path;
    // filesystem::path cwd = filesystem::current_path();
    filesystem::path cwd = input_path;
    int file_count;
    vector files = files2dVector(cwd, file_count);
    MultiLinkedList myMLList;

    for (int i = 0; i < file_count; i++)
    {
        myMLList.addNode(files[i][0], files[i][1], files[i][2]);
    }

    myMLList.printInfosName();

    bool flag = true;
    while (flag) {
        cout << "Options:\n" <<
             "1: Search filename:\n" <<
             "2: Search extension:\n" <<
             "3: Search file size:\n" <<
             "4: Remove filename from list:\n" <<
             "5: Update the list:\n" <<
             "6: Traverse list\n" <<
             "7: Exit." << endl;

        int arg;
        cin >> arg;
        int input_traverse_list;
        string input_name, input_ext, input_size, temp;

        switch (arg) {
            case 1:
                cout << "Enter file name:\n";
                cin >> input_name;
                myMLList.searchFileName(input_name);
                break;
            case 2:
                cout << "Enter file extension:\n";
                cin >> input_ext;
                myMLList.searchFileExt(input_ext);
                break;
            case 3:
                cout << "Enter file size:\n";
                cin >> input_size;
                myMLList.searchFileSize(input_size);
                break;
            case 4:
                cout << "Enter file name:\n";
                cin.ignore(80, '\n');
                cin >> input_name;
                myMLList.deleteNode(input_name);
                break;
            case 5:
                myMLList.destroyList();
                for (int i = 0; i < file_count; i++)
                {
                    myMLList.addNode(files[i][0], files[i][1], files[i][2]);
                }
                break;
            case 6:
                cout << "Please enter sorting order:\n" <<
                        "1: Ordered by filename\n" <<
                        "2: Ordered by file extension\n" <<
                        "3: Ordered by file size\n";
                cin >> input_traverse_list;
                switch (input_traverse_list) {
                    case 1:
                        myMLList.printInfosName();
                        break;
                    case 2:
                        myMLList.printInfosExt();
                        break;
                    case 3:
                        myMLList.printInfosSize();
                        break;
                }
                break;
            case 7:
                cout << "See you later, alligator!";
                flag = false;
                break;
            default:
                flag = false;
                cout << "Non-valid argument, run again!\n";
                break;
        }
    }
}
