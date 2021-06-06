#include <string>
#include <iostream>
#include <filesystem>

using std::cout;
using std::endl;
using std::string;
using std::filesystem::exists;

int main(int argc, char *argv[]) {
	if (argc == 1 || *argv[1] == '\0') {
		cout << "No input filename provided" << endl;
		return 1;
	}

	string filename = argv[1];
	if (!exists(filename)) {
		cout << "Input filename not found" << endl;
		return 1;
	}

	return 0;
}
