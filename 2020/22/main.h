#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <filesystem>
#include <bits/stdc++.h>

using std::cout;
using std::endl;
using std::exception;
using std::getline;
using std::ifstream;
using std::pair;
using std::string;
using std::vector;
using std::hash;

pair<vector<int>, vector<int>> getPlayerCards(string filename);

void simulateGame(std::pair<vector<int>, vector<int>>& playerCards, vector<uint32_t>& previousGameHashes);

std::size_t hashVectorInt(vector<int> vec);

int calculateScore(vector<int> cards);
