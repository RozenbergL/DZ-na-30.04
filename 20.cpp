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
	int n;
	fin >> n;
	vector <int> nums(n);
	for (int i = 0; i < n; i++){
	    fin >> nums[i];
	}
	int answer = 0;
	for (int i = 0; i < n - 1; i++){
	    int count = 0;
	    int flag = 0;
	    if (nums[i] < nums[i + 1]){
	        flag = -1;
	    }else{
	        flag = 1;
	    }
	    for (int j = i + 1; j < n; j++){
	        if ((nums[j + 1] - nums[j]) * flag > 0){
	            count++;
	            flag *= -1;
	        }else{
                if (count + 2 > answer){
                    answer = count + 2;
	            }
	            break;
	        }
	    }
	    if (count + 1 > answer){
            answer = count + 1;
	    }
	}
	fout << answer;
    return 0;
}