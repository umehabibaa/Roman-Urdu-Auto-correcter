#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <sstream>
#include <limits>

using namespace std;

// Levenshtein distance calculation
// Function to calculate Levenshtein distance between two strings
int levenshteinDistance(const string& word1, const string& word2) {
    // Get the length of both strings
    int len1 = word1.size();
    int len2 = word2.size();

    // Creating a 2D vector to store the distances and it is initialized with zeros
    vector<vector<int>> dp(len1 + 1, vector<int>(len2 + 1));

    // Initializing the first column of the dp array
    for (int i = 0; i <= len1; i++) {
        dp[i][0] = i; // Distance of any first string to an empty second string
    }
    // Initializing the first row of the dp array
    for (int j = 0; j <= len2; j++) {
        dp[0][j] = j; // Distance of any second string to an empty first string
    }

    // Computing the distances between substrings of both strings
    for (int i = 1; i <= len1; i++) {
        for (int j = 1; j <= len2; j++) {
            // If the current characters are the same, no operation is needed
            // Copy the value from the top-left diagonal
            if (word1[i - 1] == word2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1];
            }
            // If the characters are different, consider the operations
            else {
                // Calculate the minimum cost among insertion, deletion, or substitution
                dp[i][j] = min({
                    dp[i - 1][j] + 1,    // Cost of deletion
                    dp[i][j - 1] + 1,    // Cost of insertion
                    dp[i - 1][j - 1] + 1 // Cost of substitution
                });
            }
        }
    }
    // The bottom-right cell contains the final Levenshtein distance
    return dp[len1][len2];
}


// Mini Dictionary
class Dictionary {
private:
    vector<string> words;

public:
    Dictionary()
     {
        
        words = { "a","ap","aap","aaj","aik","ab","aesa","agay","ajeeb","aesay","aanay","Allah","ayaadat","aur","afsoos","asaan","aai","aye","ayega","aana","acha","andha","apna","ahista","araam","aainda","asmaan","abhi","apna","azaab","aye","aya",
        "bura","bilkul","baat","bohat","bnana","bezaar","banegi","beghum","betho","beta","baghair","beemar","biwi","beti","bilkul","bana","baaki","bhoolti","btati","baal","bakwaas","bad","bhara","bara","badtameez","baat","bolna","budh","bhai","batao","bolta","bolti",
        "bhoolta","baadil","bhaagna","bus","bataya","bhi","baaki","batain",
        "chaar", "chaltay","chahta","chahti","choti", "chali","chor","chali","chalao","chalo","chahye","chaand",
        "dimagh","dia","dil","do","doon","diya","dost","dekha","dafa","dono","dekhein","daal","doon","doongi","duniya","dua","din",
        "eid",
        "fazool","farmain","faida",
        "gi","gaana","gao","gaali","ghamand","ga","gai","gaya","ghantay","gay","ghar",
        "har","hafiz","hafta", "ho", "haan","hoon","huwi","haq","himmat","hum","harkat","hotay","hai","hain","hai","huwa","haal","hota",
        "istemal","itwaar","intezaar","itna","is","inkaar","itni","istemaal",
        "jana","jaye","jummah raat","jummah","ji","jaga","jao","jaun","jaoon","jo","jaag","jana","jayega","janwar",
        "khushi", "kesi","karta","karti","keh","kehti","kal","ko","kamiyaab","k","kehta","khairiat","kaam","kharab","khayaal","kahein","khuda","kar","karo","karein","kia", "kar","karoon","kaisay","khuda","khabar","kay","koi","kaam","kar","kal","karein","koi","ki",
        "karay","karwaya","karna","kyun","kaho","kitnay","khush","kaat","karwa","kahan","khuda","khair","ka","khushamdeed","khol","khola","kara",
        "lambay","log","lena","lo","lagta","laga","lagain","lafz","likho",
        "mein","milein","mera","mujhay","meri","mushkil","mehmaan","maazrat","mazay","madad","masla","moqa","meine","mar"
        "nahi","namaz","na","ne","nazdeek","nazar","neechay","nikkah","naashta","nizaam","naam","nikal","na","nasal",
        "or",
        "pasand","pehlay","parho","parhi","piyaar","paaye","peer","pareshan","paas","pata",
        "qeemat","qismat","qaaim","qudrat","qareeb",
        "raat", "rehta","rehti","raha","rahi", "ruko","rakhna","rahay","rahoon","rakho","rakhtay","raha",
        "subha","salam","shaam","so","shaadi","saktay","soch","shareef","samaan","sun","sambhaal","sambhaalo","samajhta","si","seedha","samjha","shoro","sakht","socha","samajhti","shukriya","suno","sunao","saat","se","say","samjha","shararti","suno","shakal",
        "sab","sabar","saans","sahi",
        "tor","teen","thi","tabiyat","tha","tou","toot","thi","tum","tha","tayaar","tu", "theak","tez","tumhari","tumhara","tumhein","tumhay","thak","tab",
        "us","umeed","ura","urh","usay","uthti","uthta","uth",
        "wesay","waqt","wo", "wala","walay","wahan","wohi",
        "yaar","ye","yaad","yahan","ya",
        "ziyada","zara","zindagi","zaheen","zid","ziddi","zada"
        };
   
    }

    string findClosestWord(const string& inputWord) 
    {
        int minDistance = numeric_limits<int>::max();
        string closestWord;

        for (const auto& word : words) {
            int distance = levenshteinDistance(inputWord, word);
            if (distance < minDistance) {
                minDistance = distance;
                closestWord = word;
            }
        }
        return closestWord;
    }
};

// split sentence into words
vector<string> splitWords(const string& sentence) {
    vector<string> words;
    stringstream ss(sentence);
    string word;
    while (ss >> word) {
        words.push_back(word);
    }
    return words;
}

int main() 
{   
    cout<<"\n\n\t\t----------------------------------------------------------------------------------------------";
    cout<<"\n\t\t----------------------------------------------------------------------------------------------";
    cout<<"\n\n\n\t\t\t\t  K    H    U    S    H       A    A    M    D    E    E    D ! \n\n\t\t\t\t\t U  R  D  U    A  U  T  O - C  O  R  R  E  C  T  O  R   ";
    cout<<"\n\n\t\t----------------------------------------------------------------------------------------------";
    cout<<"\n\t\t----------------------------------------------------------------------------------------------"; 
char ch;    

do
{
     char ch;
    cout<<"\n\n\n\n\t\t1). Enter a sentence. \n\t\t2). Exit.\n\t\tEnter your choice(1/2):";
    cin>>ch;
    system("cls");
    switch(ch)
    {
    case '1':
{
    Dictionary dict;
    string sentence;
    cout << "\n\n\n\n\tEnter a Roman Urdu sentence (For better results, use only Urdu words and avoid entering names): \n\t";
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore the newline character in the buffer
    getline(cin, sentence);
    vector<string> words = splitWords(sentence);
    cout <<"\n\n\n\t\t\t";
    for (const auto& word : words)
    {
        string correctedWord = dict.findClosestWord(word);
        cout << correctedWord << " ";
    }
   
    cout << endl;
    break; 
}
case '2': 
    {
        cout<<"\n\n\t\t----------------------------------------------------------------------------------------------";
    cout<<"\n\t\t----------------------------------------------------------------------------------------------";
    cout<<"\n\n\n\t\t\t\t\t\t  S   H   U   K   R   I   Y   A  \a";
    cout<<"\n\n\t\t----------------------------------------------------------------------------------------------";
    cout<<"\n\t\t----------------------------------------------------------------------------------------------"; 
    }
    exit(0);
    break; 
    }
   
} 
while (ch!='2');

return 0;
}
