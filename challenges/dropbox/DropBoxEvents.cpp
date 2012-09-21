#include <cstdio>
#include <climits>
#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

#define DEBUG_CODE 1

class FileSystemEntity
{
	std::string name;
	std::string hash;

	bool isDir;
	std::vector<FileSystemEntity *> _children;

	void display (int lineNum) {
#if DEBUG_CODE
		cout << lineNum << ": ";
		display();
#endif //DEBUG_CODE
	}

	void display () {
#if DEBUG_CODE
		cout << "this: " << this << " | name: " << name << " | hash: " << hash << " | isDir: " << isDir;
#endif //DEBUG_CODE
	}

	FileSystemEntity* findOrCreateChildDirectory (std::string directoryName) {
#if DEBUG_CODE
		cout << __LINE__ << ": findOrCreateChildDirectory: " << this << " " << directoryName << endl;
#endif //DEBUG_CODE
		// start from the beginning of the array
		std::vector<FileSystemEntity *>::iterator itPos = _children.begin();
		// clear all children elements
		for (; itPos < _children.end(); itPos++) {
			FileSystemEntity *current = *itPos;
			if (current->name == directoryName) {
				return current;
			}
		}

		FileSystemEntity *newChild = new FileSystemEntity (directoryName, "-");
		addChild (newChild);
		return newChild;
	}

public:
	FileSystemEntity (std::string inName, std::string inHash) : name(inName), hash(inHash) {
		if ("-" == hash) {
			isDir = true;
		}
		else {
			isDir = false;
		}
#if DEBUG_CODE
		cout << __LINE__ << ": new: "; display(); cout << endl;
#endif //DEBUG_CODE
	}

	~FileSystemEntity () {
#if DEBUG_CODE
		cout << __LINE__ << ": ~FileSystemEntity: " << this << " - (" << name << ", " << hash << ")" << endl;
#endif //DEBUG_CODE
		// start from the beginning of the array
		std::vector<FileSystemEntity *>::iterator itPos = _children.begin();
		// clear all children elements
		for (; itPos < _children.end(); itPos++)
			delete *itPos; // free the element from memory
		// finally, clear all elements from the vector
		_children.clear();
	}

	bool addChild (FileSystemEntity *newChild) {
#if DEBUG_CODE
		cout << __LINE__ << ": addChild of: " << name << ": "; newChild->display(); cout << endl;
#endif //DEBUG_CODE
		assert (isDir);

		size_t found = newChild->name.find("/", 1);
		if (string::npos == found) {
			_children.push_back (newChild);
		}
		else {
			std::string parentDirectoryName = newChild->name.substr (1, found-1);
			newChild->name = newChild->name.substr (found+1);

			FileSystemEntity *parentDirectory = findOrCreateChildDirectory (parentDirectoryName);
			parentDirectory->addChild (newChild);
		}
	}
};

int main (int argc, char* argv[])
{
	int rows = 0, count = 0;
	FileSystemEntity *dropboxRoot = new FileSystemEntity ("__ROOT__", "-");

	FileSystemEntity *tempChild = new FileSystemEntity ("/test/1.txt", "f2fa762f");
	dropboxRoot->addChild (tempChild);
	tempChild = new FileSystemEntity ("/test/2.txt", "f2fa762f");
	dropboxRoot->addChild (tempChild);
	tempChild = new FileSystemEntity ("/test/7.txt", "f2fa762f");
	dropboxRoot->addChild (tempChild);
	tempChild = new FileSystemEntity ("/test/3.txt", "f2fa762f");
	dropboxRoot->addChild (tempChild);
	tempChild = new FileSystemEntity ("/test2/3.txt", "f2fa762f");
	dropboxRoot->addChild (tempChild);
	tempChild = new FileSystemEntity ("/test/4.txt", "f2fa762f");
	dropboxRoot->addChild (tempChild);

	cout << "\nDone with the creation!\n\n";

	delete dropboxRoot;

	return 0;
}
