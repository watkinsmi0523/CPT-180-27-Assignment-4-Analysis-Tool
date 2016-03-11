#include <iostream>
#include <fstream>
#include <vector>
#include <string.h>


using namespace std;

int main(int argc, char *argv[]){

    string file_path;
    string read;
    if (argv[1]){
        file_path = static_cast<string>(argv[1]);

    }else if (static_cast<string>(argv[2]) == "search"){
        if (argv[3]){
            string search_word = static_cast<string>(argv[3]);
            int line_num = 0;
            int line_pos = 0;


            ifstream inFile;
            inFile.open(file_path);

            ofstream outFile;
            outFile.open("./search");

            outFile << "Searched for: " << search_word << endl;
            outFile << "Located on : " << endl;
            outFile << "Pos\t\tLine" << endl;



            if(inFile.is_open()){
                while(getline(inFile, read)){
                    line_pos = read.find(search_word, 0);
                    line_num++;

                    while(line_pos >= 0){
                        outFile << ++line_pos << "\t\t" << line_num << endl;
                        line_pos = read.find(search_word, line_pos);
                    }

                }
            inFile.close();
            outFile.close();
            }
        }



    }else if(static_cast<string>(argv[2]) == "sort"){
        if (static_cast<string>(argv[3]) == "asc") {
            ifstream inFile;
            inFile.open(file_path);

            ofstream outFile;
            outFile.open("./sort_asc");

            vector<int> sort;
            int value;
            while (inFile >> value){
                sort.push_back(value);
            }

            int unsorted = sort.size();


            for(int i = 0; i < unsorted - 1; i++){
                for(int j = 0; j < unsorted - i - 1; j++){
                    int temp = sort[j];
                    sort[j] = sort[j + 1];
                    sort[j + 1] = temp;

                }
            }
            for(int i = 0; i < unsorted; i++) {
                outFile << sort[i] << endl;
            }

            inFile.close();
            outFile.close();

        }else if (static_cast<string>(argv[3]) == "desc"){

            ifstream inFile;
            inFile.open(file_path);

            ofstream outFile;
            outFile.open("./sort_asc");

            vector<int> sort;
            int value;
            while (inFile >> value){
                sort.push_back(value);
            }

            int unsorted = sort.size();


            for(int i = 0; i < unsorted - 1; i++){
                for(int j = 0; j > unsorted - i - 1; j++){
                    int temp = sort[j];
                    sort[j] = sort[j + 1];
                    sort[j + 1] = temp;

                }
            }
            for(int i = 0; i < unsorted; i++) {
                outFile << sort[i] << endl;
            }

            inFile.close();
            outFile.close();

        }else if (static_cast<string>(argv[2]) == "count"){



    }


return 0;
}

