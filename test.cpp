#include <cstdio>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#define PB push_back
#define MP make_pair
#define X first
#define Y second
using namespace std ;
typedef long long ll;

map<string, vector<string>> meaningGroups; // Chinese to English words
map<string, string> words;		// English to Chinese
vector<string> wordsList;

/* aim: 
	1. input new word, 
		A. identify the group by Chinese
		B. identify the group by one synonym
		C. same word will ask modify first
		D. inport the data by specific data format
	2. display
		A. input chinese, display group
		B. input a word, display its group
		C. display all the data, chinese first and words second
	
   DS: 
    1. Chinese -> vector<words>
	2. words -> Chinese
*/

int main() {	
	// 1.D
	string tmp;
	scanf("%s", tmp);
	while (tmp != "Q") {
		string Chinese = tmp;
		wordsList.clear();
		scanf("%s", tmp); char c = getchar();
		while (c != '\n') {
			wordsList.PB(tmp);
			scanf("%s", tmp); char c = getchar();
		}
		meaningGroups[Chinese] = wordsList;
		scanf("%s", tmp);
	}
	
	string info = "Please input data:\n";
	info +=		  "1. Input a word to display its meaning group.\n" +
	info +=		  "2. Input 2 words to insert a new record.\n" +
	info +=		  "3. Input \"SHOWALL\" to display all the meaning groups.\n" +
	info +=		  "4. Input \"SAVE\" to save on disk.\n" +
	info +=		  "5. Input \"Q\" to quit the program.\n";
	
	printf("%s\n", info);
	string s1, s2;
	scanf("%s", s1); char c = getchar();
	if (c != '\n') scanf("%s", s2);
	
	// 1. 2A & 2B
	if (c == '\n') {
		string chineseMeaning;
		if (meaningGroups.find(s1) != meaningGroups.end()) {
			chineseMeaning = s1;
		} else if (words.find(s1) != words.end()) {
			chineseMeaning = words[s1];
		} else {
			printf("Not Found!\n");
		}
		
		printf("%s\n", chineseMeaning);
		for (auto it = meaningGroups[chineseMeaning].begin(); it != meaningGroups[chineseMeaning].end(); ++it) {
			printf("%s ", (*it));
		}putchar('\n');
	}
	
	
	return 0;
}

