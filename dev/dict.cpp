#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
using namespace std;

/*this is new let me commit */
#define FILE_LENGTH 100

ifstream infile("dictionary.txt");

/*deep copy string */
string dcopy(string s)
{
        string ret = "";
	int temp;
        for(int i=0; i<s.length(); i++)
	{
		temp = (int)s[i];
                ret+= (char)temp;
	}
        return ret;
}

/*fill dictionary */
void fillDictionary(string splitArray[FILE_LENGTH][20])
{
	int wordNumber, begin, arrCount=0;
	string line, temp="";
        for(wordNumber = 0;getline(infile, line); wordNumber++)
        {
                for(begin=0; begin <line.length(); begin++)
                 {
                        if(line[begin] == ' ')
                        {
                                splitArray[wordNumber][arrCount] = dcopy(temp);
                                arrCount++;
                                temp = "";
                        }
                        else
                                temp+=line[begin];
                }
		arrCount = 0;
        }
}

/*print dictionary contents */
void printArrayContents(string array[FILE_LENGTH][20])
{
	for(int i=0; i<FILE_LENGTH; i++)
        {
                for(int j=0; j<20; j++)
                {
			if(array[i][j] == "")
				break;
                        cout<<array[i][j]<<"\t";
                }
                cout<<"\n\n";
	}
}


void printCubes(string grapheme[20], int check[10])
{
	int length = atoi(grapheme[1].c_str());


        /*print numbers above graphemes */
        for(int i=0; i<length; i++)
                cout<<i<<"\t";
        cout<<"\n";


        /*print random order graphemes*/
        for(int i=0; i<length; i++)
                for(int j=0;j<length;j++)
                        if(check[j] == i)
                                cout<< grapheme[2+check[j]] <<"\t";
        cout<<"\n";
}

/*randomizes word and prints to screen */
string printRandomOrder(string grapheme[20])
{
	srand(time(NULL));
	string temp="";
	int length = atoi(grapheme[1].c_str());
	int check[10]={-1,-1,-1,-1,-1,-1,-1,-1,-1,-1};

	for(int i=0; i<length; i++)
	{
		int random = rand()%length;
		for(int j=0; j<length; j++)
		{
			if(check[j] != random)
			{
				if(j==i)
				{
	 				check[i] = random;
					stringstream ss;
					ss<<check[i];
					temp+=ss.str();
				}
			}
			else
			{
				i--;
				break;
			}
		}
	}

	printCubes(grapheme, check);

	return temp;
}

/* main game function */
void game(string splitArray[FILE_LENGTH][20])
{
	string input;
	for(int i=0; i<FILE_LENGTH; i++)
	{
		cout << "place cubes in correct order\n\n";
		string ans = printRandomOrder(splitArray[i]);

		while(true){
			cout << ans <<": ";
				cin >> input;

			if(ans == input)
			{
				cout << "Congratulations you're correct!\n\n";
				break;
			}
			else if(ans.find(input) != std::string::npos)
			{
				cout << "These cubes match!\n";
			}
			else
				cout << "dont match\n";
		}
	}
}



int main()
{
	string splitArray[FILE_LENGTH][20];
	fillDictionary(splitArray);

	game(splitArray);
	//printArrayContents(splitArray);

}


