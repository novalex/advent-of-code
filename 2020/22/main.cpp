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

	simulateGame(playerCards);

	vector<int> winningCards;

	if (playerCards.first.empty()) {
		cout << "Player 2 wins!" << endl;
		winningCards = playerCards.second;
	}
	else {
		cout << "Player 1 wins!" << endl;
		winningCards = playerCards.first;
	}

	int score = calculateScore(winningCards);
	cout << "Final score: " << score << endl;

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

void simulateGame(std::pair<vector<int>, vector<int>>& playerCards) {
	vector<int> player1Cards = playerCards.first;
	vector<int> player2Cards = playerCards.second;
	bool gameOver = false;

	while (!gameOver) {
		int player1Card = player1Cards.at(0);
		player1Cards.erase(player1Cards.begin());
		int player2Card = player2Cards.at(0);
		player2Cards.erase(player2Cards.begin());

		if (player1Card > player2Card) {
			player1Cards.push_back(player1Card);
			player1Cards.push_back(player2Card);
		}
		else {
			player2Cards.push_back(player2Card);
			player2Cards.push_back(player1Card);
		}

		if (player1Cards.empty() || player2Cards.empty()) {
			gameOver = true;
		}
	}

	playerCards.first = player1Cards;
	playerCards.second = player2Cards;
}

int calculateScore(vector<int> cards) {
	int score = 0;
	int multiplier = 1;

	while (!cards.empty()) {
		int index = cards.size() - 1;
		score += cards.at(index) * multiplier;
		cards.pop_back();
		multiplier++;
	}

	return score;
}
