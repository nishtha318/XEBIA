#include<iostream>
#include<string.h>
using namespace std;

//functions
void check_palindrome(string str , string temp);
void count_frequencies(string str , int freq[26]);
void replace_vowel(string str , char s);

int main()
{
    char s;
    string str;
    string temp = "";
    int freq[26]= {0};


    cout << "Enter any string : " << endl ;
    getline(cin , str);

    
    check_palindrome(str , temp);
    count_frequencies(str, freq);


    cout << "enter any character you want to replace the vowels with :" ;
    cin >> s;
    replace_vowel(str,s);

}

void check_palindrome(string str , string temp)
{
    for(int i = str.length() - 1 ; i >= 0 ; i-- )
    {
        temp += str[i];

    }

    if (temp == str)
    {
        cout << "the string is a palindrome" << endl;
    }
    else
    {
        cout << "the string is not a palindrome" << endl;
    }

}

void count_frequencies(string str , int freq[26])
{
    
    for( char ch : str)
    {
        //converting uppercases to lowercases
        if(ch >= 'A' && ch <= 'Z' )
        {
            ch += 32;
        }

        //counting freq
        freq [ch - 'a']++;
    }

    cout << "letter frequencies:\n";
    for(int i = 0 ; i < 26 ; i++)
    {
        if(freq[i] > 0)
        {
            cout << char(i + 'a') << ":" << " " << freq[i] << endl;
        }
    }


}


void replace_vowel(string str , char s )
{
    //passing &ch with reference so that change is directly made 
    for( char &ch : str)
    {
        if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' || 
            ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U')
        {
            ch = s;
        }
    }
    cout << str << endl;
}
