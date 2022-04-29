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
	vector <vector <int>> sp;
	for (int i = 0; i < n; i++){
	    vector <int> prov;
	    for (int j = 0; j < n; j++){
	        prov.push_back(0);
	    }
	    sp.push_back(prov);
	}
	int count = 1;
	int flag = 0;
	int ind1 = 0;
	int ind2 = 0;
	while (count <= n * n){
	    if (flag % 4 == 0){
	        while (true){
	            if (sp[ind1][ind2] != 0){
	                ind2--;
	                ind1++;
	                break;
	            }
	            sp[ind1][ind2] = count;
	            count++;
	            ind2++;
	            if (ind2 == n){
	                ind2--;
	                ind1++;
	                break;
	            }
	        }
	    }
	    if (flag % 4 == 1){
	        while (true){
	            if (sp[ind1][ind2] != 0){
	                ind1--;
	                ind2--;
	                break;
	            }
	            sp[ind1][ind2] = count;
	            count++;
	            ind1++;
	            if (ind1 == n){
	                ind1--;
	                ind2--;
	                break;
	            }
	        }
	    }
	    if (flag % 4 == 2){
	        while (true){
	            if (sp[ind1][ind2] != 0){
	                ind2++;
	                ind1--;
	                break;
	            }
	            sp[ind1][ind2] = count;
	            count++;
	            ind2--;
	            if (ind2 == -1){
	                ind2++;
	                ind1--;
	                break;
	            }
	        }
	    }
	    if (flag % 4 == 3){
	        while (true){
	            if (sp[ind1][ind2] != 0){
	                ind1++;
	                ind2++;
	                break;
	            }
	            sp[ind1][ind2] = count;
	            count++;
	            ind1--;
	            if (ind1 == -1){
	                ind1++;
	                ind2++;
	                break;
	            }
	        }
	    }
	    flag++;
	}
	for (int i = 0; i < n; i++){
	    for (int j = 0; j < n; j++){
	        fout << sp[i][j] << " ";
	    }
	    fout << endl;
	}
    return 0;
}