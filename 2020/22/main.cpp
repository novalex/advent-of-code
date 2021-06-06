#include "main.h"

int main(int argc, char* argv[]) {
	if (argc == 1 || *argv[1] == '\0') {
		cout << "No input filename provided" << endl;
		return 1;
	}

	string filename = argv[1];
	if (!std::filesystem::exists(filename)) {
		cout << "Input filename not found" << endl;
		return 1;
	}

	pair<vector<int>, vector<int>> playerCards;
	try {
		playerCards = getPlayerCards(filename);
	}
	catch (const std::exception& e) {
		cout << "Failed reading input: " << e.what() << endl;
		return 1;
	}

	return 0;
}

pair<vector<int>, vector<int>> getPlayerCards(string filename) {
	ifstream file(filename);

	if (!file.is_open()) {
		throw std::runtime_error("Could not open input file");
	}

	vector<int> player1Cards;
	vector<int> player2Cards;

	auto assignCards = &player1Cards;
	string line;
	while (getline(file, line)) {
		int cardNumber;
		try {
			cardNumber = stoi(line);
		}
		catch (const exception& e) {
			if (line.find("Player 2") != string::npos) {
				// Start assigning player 2 cards.
				assignCards = &player2Cards;
			}

			continue;
		}

		assignCards->push_back(cardNumber);
	}

	return std::make_pair(player1Cards, player2Cards);
}
