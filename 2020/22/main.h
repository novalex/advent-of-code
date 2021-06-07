#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <filesystem>

using std::cout;
using std::endl;
using std::exception;
using std::getline;
using std::ifstream;
using std::pair;
using std::string;
using std::vector;

std::pair<vector<int>, vector<int>> getPlayerCards(string filename);

void simulateGame(std::pair<vector<int>, vector<int>>& playerCards);

int calculateScore(vector<int> cards);
