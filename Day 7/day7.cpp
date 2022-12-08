#include <iostream>
#include <fstream>
#include <vector>
#include <unordered_map>
#include <sstream>
#include <limits.h>

using namespace std;

enum FileType { DIR, DATA };

class File {
    private:
        FileType type;
        size_t size;
        string name;
        unordered_map<string, File*> children;
        File* parent;

    public:
        File(FileType type, size_t size, string name) : type(type), size(size), name(name), parent(NULL) {}

        FileType getType() const {
            return type;
        }

        size_t getSize() {
            if(size == 0) {
                for(auto child : children)
                    size += child.second->getSize();
            }
            return size;
        }

        const string &getName() const {
            return name;
        }

        File* getParent() const {
            return parent;
        }

        const unordered_map<string, File*> &getChildren() const{
            return children;
        }

        void setParent(File* parent) {
            this->parent = parent;
        }

        File* getChild(const string &name) const {
            if(children.find(name) != children.end())
                return children.at(name);
            else
                return NULL;
        }

        void addChild(File* child) {
            children.insert({child->getName(), child});
            children.at(child->getName())->setParent(this);
        }
};

class Parser {
    private:
        string fileName;
    public:
        Parser(string fileName) :  fileName(fileName) {}
        File* getFileSystem() {
            fstream in(fileName);
            File* root = new File{DIR, 0, "/"};
            File* current = root;
            string input;
            getline(in, input); // $ cd /
            
            while(getline(in, input)) {
                stringstream ss(input);
                string firstWord, secondWord, dir;
                ss >> firstWord >> secondWord;
                if(firstWord == "dir") 
                    current->addChild(new File{DIR, 0, secondWord});
                else if(firstWord.at(0) >= '0' && firstWord.at(0) <= '9')
                    current->addChild(new File{DATA, stoul(firstWord), secondWord});
                else if(secondWord == "cd") {
                    ss >> dir;
                    current = dir == ".." ? current->getParent() : current->getChild(dir);
                }
            }
            return root;
        }
};

size_t part1(File* fileSystem) {
    vector<File*> directories = {fileSystem};
    size_t result = 0;
    for(size_t i = 0; i < directories.size(); i++) {
        size_t total_size = directories.at(i)->getSize();
        if(total_size <= 100000) {
            result += total_size;
        }
        for(auto child : directories.at(i)->getChildren()) {
            if(child.second->getType() == DIR) {
                directories.push_back(child.second);
            }
        }
    }
    return result;
}

size_t part2(File* fileSystem) {
    size_t toDelete = 30000000 - (70000000 - fileSystem->getSize());
    vector<File*> directories = {fileSystem};
    size_t minSize = INT_MAX;
    for(size_t i = 0; i < directories.size(); i++) {
        size_t size = directories.at(i)->getSize();
        if(size >= toDelete) {
            minSize = min(size, minSize);
            for(auto child : directories.at(i)->getChildren()) {
                if(child.second->getType() == DIR) {
                    directories.push_back(child.second);
                }
            }
        }
    }
    return minSize;
}

int main()
{
    Parser parser("input.txt");
    File* fileSystem = parser.getFileSystem();
    cout << "Part 1 answer: " << part1(fileSystem) << endl;
    cout << "Part 2 answer: " << part2(fileSystem) << endl;
}