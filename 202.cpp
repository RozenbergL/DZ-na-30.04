#include <iostream>
#include <algorithm>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

int main()
{
	ifstream fin;
	ofstream fout;
	fin.open("input.txt");
	fout.open("output.txt");
	string str;
	fin >> str;
	string substring;
	fin >> substring;
	vector <int> answer;
	for (int i = 0; i <= str.size() - substring.size(); i++){
	    if (str.substr(i, substring.size()) == substring){
	        answer.push_back(i);   
	    }
	}
	for (auto now : answer){
	    fout << now << " ";
	}
    return 0;
}