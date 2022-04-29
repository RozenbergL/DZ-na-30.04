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
	int k, m;
	fin >> k >> m;
	vector <pair <int, int>> sp;
	for (int i = 0; i < m; i++){
	    pair <int, int> p;
	    fin >> p.second >> p.first;
	    sp.push_back(p);
	}
	sort(sp.begin(), sp.end());
	for (int i = m - 1; i >= 0; i--){
	    if (sp[i].second + 1 == k){
	        k = sp[i].second;
	    }
	    else if (sp[i].second == k){
	        k = sp[i].second + 1;
	    }
	}
	fout << k;
    return 0;
}