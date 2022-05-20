//
// Created by batuh on 5/20/2022.
//

#ifndef UNTITLED1_MULTILLIST_H
#define UNTITLED1_MULTILLIST_H

#include <string>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

class MyLinkedList {
public:
    struct ListNode {
        ListNode *next_name, *next_ext, *next_size;
        string infos[3];

        ListNode(const string &name, const string &ext, const string &size) {
            next_name = next_ext = next_size = nullptr;
            infos[0] = name; infos[1] = ext; infos[2] = size;
        }
    };
    ListNode *head_name, *head_ext, *head_size;
    int fileCount = 0;

    MyLinkedList() {
        head_name = head_ext = head_size = nullptr;
    }

    ~MyLinkedList() {
        ListNode *curr_name = head_name, *curr_ext = head_ext, *curr_size = head_size;
        ListNode *nextNodeName = nullptr, *nextNodeExt = nullptr, *nextNodeSize = nullptr;

        while (curr_name != nullptr) {
            nextNodeName = curr_name->next_name;
            delete curr_name;
            curr_name = nextNodeName;
        }
        while (curr_ext != nullptr) {
            nextNodeExt = curr_ext->next_ext;
            delete curr_ext;
            curr_ext = nextNodeExt;
        }
        while (curr_size != nullptr) {
            nextNodeSize = curr_size->next_size;
            delete curr_size;
            curr_size = nextNodeSize;
        }
    }

    void addNode(const string &name, const string &ext, const string &size) {
        ListNode *node = new ListNode(name, ext, size);

        //////////////////////// NAME SIDE ////////////////////////
        ListNode *curr_name;
        if(head_name == nullptr || (head_name->infos[0] >= name)) {
            node->next_name = head_name;
            head_name = node;
        }
        else {
            curr_name = head_name;
            while(curr_name->next_name != nullptr && curr_name->next_name->infos[0] < name) {
                curr_name = curr_name->next_name;
            }
            node->next_name = curr_name->next_name;
            curr_name->next_name = node;
        }

        //////////////////////// EXTENSION SIDE ////////////////////////
        ListNode *curr_ext;
        if(head_ext == nullptr || (head_ext->infos[1] >= ext)) {
            node->next_ext = head_ext;
            head_ext = node;
        }
        else {
            curr_ext = head_ext;
            while(curr_ext->next_ext != nullptr && curr_ext->next_ext->infos[1] < ext) {
                curr_ext = curr_ext->next_ext;
            }
            node->next_ext = curr_ext->next_ext;
            curr_ext->next_ext = node;
        }

        //////////////////////// SIZE SIDE ////////////////////////
        ListNode *curr_size;
        if(head_size == nullptr || (stoi(head_size->infos[2]) >= stoi(size))) {
            node->next_size = head_size;
            head_size = node;
        }
        else {
            curr_size = head_size;
            while(curr_size->next_size != nullptr && stoi(curr_size->next_size->infos[2]) < stoi(size)) {
                curr_size = curr_size->next_size;
            }
            node->next_size = curr_size->next_size;
            curr_size->next_size = node;
        }
        fileCount++;
    }

    void printInfosName() const {
        for (ListNode *tmp = head_name; tmp != nullptr; tmp = tmp->next_name)
        {
            cout << tmp->infos[0] << " ||| " << tmp->infos[1] << " ||| " << tmp->infos[2];
            cout << endl;
        }
        cout << endl;
    }


    void printInfosExt() const {
        for (ListNode *tmp = head_ext; tmp != nullptr; tmp = tmp->next_ext)
        {
            cout << tmp->infos[1] << " ||| " << tmp->infos[0] << " ||| " << tmp->infos[2];
            cout << endl;
        }
        cout << endl;
    }

    void printInfosSize() const {
        for (ListNode *tmp = head_size; tmp != nullptr; tmp = tmp->next_size)
        {
            cout << tmp->infos[2] << " ||| " << tmp->infos[0] << " ||| " << tmp->infos[1];
            cout << endl;
        }
        cout << endl;
    }

    void searchFileName(const string &name) {
        bool flag = false;
        for (ListNode *tmp = head_name; tmp != nullptr; tmp = tmp->next_name)
        {
            if (tmp->infos[0] == name)
            {
                cout << tmp->infos[0] << " " << tmp->infos[1] << " " << tmp->infos[2];
                flag = true;
                cout << endl;
            }
        }
        if (flag)
            cout << "There is no other file with that extension." << endl;
        else
            cout << "There is no file with that extension." << endl;
    }

    void searchFileExt(const string &ext) {
        bool flag = false;
        for (ListNode *tmp = head_ext; tmp != nullptr; tmp = tmp->next_ext)
        {
            if (tmp->infos[1] == ext)
            {
                cout << tmp->infos[0] << " " << tmp->infos[1] << " " << tmp->infos[2];
                flag = true;
                cout << endl;
            }
        }
        if (flag)
            cout << "There is no other file with that extension." << endl;
        else
            cout << "There is no file with that extension." << endl;
    }

    void searchFileSize(const string &size) {
        bool flag = false;
        for (ListNode *tmp = head_size; tmp != nullptr; tmp = tmp->next_size)
        {
            if (tmp->infos[2] >= size)
            {
                cout << tmp->infos[0] << " " << tmp->infos[1] << " " << tmp->infos[2];
                flag = true;
                cout << endl;
            }
        }
        if (flag)
            cout << "There is no other file with that extension." << endl;
        else
            cout << "There is no file with that extension." << endl;
    }

    void deleteNode(const string &filename) {
        ListNode *temp_name = head_name, *temp_ext = head_ext, *temp_size = head_size;
        ListNode *prev_name = nullptr, *prev_ext = nullptr, *prev_size = nullptr;

        if (temp_name != nullptr && temp_name->infos[0] == filename) {
            head_name = temp_name->next_name;
            head_ext = temp_ext->next_ext;
            head_size = temp_size->next_size;
            delete temp_name, temp_ext, temp_size;
            return;
        } else {
            while (temp_name != nullptr && temp_name->infos[0] != filename) {
                prev_name = temp_name;
                prev_ext = temp_ext;
                prev_size = temp_size;
                temp_name = temp_name->next_name;
                temp_ext = temp_ext->next_ext;
                temp_size = temp_size->next_size;
            }
            if (temp_name == nullptr)
                return;
            prev_name->next_name = temp_name->next_name;
            prev_ext->next_ext = temp_ext->next_ext;
            prev_size->next_size = temp_size->next_size;
            delete temp_name; temp_ext, temp_size;
        }
    }

    void destroyList() {
        for (int i = 0; i < fileCount; i++) {
            ListNode *temp_name = head_name, *temp_ext = head_ext, *temp_size = head_size;
            if (temp_name != nullptr) {
                head_name = temp_name->next_name;
                head_ext = temp_ext->next_ext;
                head_size = temp_size->next_size;
            }
        }
        fileCount = 0;
    }

};

#endif //UNTITLED1_MULTILLIST_H
