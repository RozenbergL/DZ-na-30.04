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
	int n, m;
	fin >> n >> m;
	vector <int> nums;
	for (int i = 1; i <= n; i++){
	    nums.push_back(i);
	}
	int answer = -1;
	while (nums.size() > 1){
	    vector <int> prov;
	    int flag = 0;
	    for (int i = 0; i < nums.size(); i++){
	        if (i % 2 == 0){
	            prov.push_back(nums[i]);
	        }
	        if (i % 2 == 1 && nums[i] == m){
	            flag = 1;
	            answer = i / 2 + (n - nums.size());
	        }
	    }
	    nums = prov;
	    if (flag == 1){
	        fout << answer + 1;
	        break;
	    }
	}
	if (answer == -1){
	    fout << n;
	}
    return 0;
}