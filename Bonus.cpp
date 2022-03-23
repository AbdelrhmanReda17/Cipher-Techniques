#include <bits/stdc++.h>
#include <iostream>
#include <unistd.h>
#include <string>
#include <sstream>
#include <map>

using namespace std;
string key;
char cipher_alphabet[26];
int choosing;
string type_choose;
// affine cipher  message
void affine_cipher_message()
{
    cout << "=> Affine Cipher\n";
    string character = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int x = 0;
    string text;
    cout << "Enter Message To Cipher : "<< endl;
    cin.ignore();
    getline(cin,text);
    for (int i =0 ; i<text.size() ;i++)
    {
        text[i]=toupper(text[i]);
    }
    for (int z =0 ; z <= text.size() ; z++)
    {
        for (int i=0 ; i <= 26 ; i++)
        {
            // this part to ignore the space ..
            if ((char)text[z] == 32)
            {
                break;
            }
            else if ((char)text[z] == (char)character[i])
            {
                x = (5*i+8)%26;
                text[z] = character[x];
                break;
            }
        }
    }
    cout << "Cipher is : " << text;

}

void affine_decipher_message()
{
    cout << "=> Affine Decipher\n";
    string character = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int x = 0;
    string text;
    cout << "Enter Message To Decipher : "<< endl;
    cin.ignore();
    getline(cin,text);
    for (int i =0 ; i<text.size() ;i++)
    {
        text[i]=toupper(text[i]);
    }
    for (int z =0 ; z <= text.size() ; z++)
    {
        for (int i=0 ; i <= 26 ; i++)
        {
            // this part to ignore the space ..
            if ((char)text[z] == 32)
            {
                break;
            }
            else if ((char)text[z] == (char)character[i])
            {
                int x ;
                x = (21*(i-8)) % 26;
                if (x < 0) {x = x + 26;}
                text[z] = character[x];
                break;
            }
        }
    }
    cout << "Decipher is : " << text;

}
// Caesar cipher
void caesar_cipher_message()
{
    cout << "=> Caesar Decipher\n";
    int shifts;
    cout<<"Enter Number of Shifts:";
    cin>> shifts;
    string message;
    cout<<"please enter the massage to Cipher : ";
    cin.ignore();
    getline(cin,message);
    for (int i = 0 ; i < message.length() ;i++)
    {
        message[i]=toupper(message[i]);
    }
    if (abs(shifts) > 26)
    {
        shifts = shifts%26;
    }
    for (int i=0 ; i< message.length() ; i++)
    {
        if (!isalpha(message[i]))
        {
                cout<<char(message[i]);
                continue;
        }
        int x = int (message[i]+shifts);
        if (x <= 90 && x >= 65){
            cout<<char(x);
        }
        else if ( x > 90 )
        {
        x-=26;
        cout<<char(x);
        }
        else
        {
        x+=26;
        cout<<char(x);
        }

    }
}
void caesar_decipher_message()
{
    cout << "=> Caesar Decipher\n";
    int shifts;
    cout<<"enter Number of Shifts:";
    cin>> shifts;
    string message;
    cout<<"please enter the massage to Decipher : ";
    cin.ignore();
    getline(cin,message);
    for (int i = 0 ; i < message.length() ;i++)
    {
        message[i]=toupper(message[i]);
    }

    if (abs(shifts) > 26)
    {
        shifts = shifts%26;
    }

    for (int i=0 ; i< message.length() ; i++)
    {
        if (!isalpha(message[i]))
        {
                cout<<char(message[i]);
                continue;
        }
        int x = int (message[i]-shifts);
        if (x <= 90 && x >= 65){
            cout<<char(x);
        }
        else if ( x > 90 )
        {
        x-=26;
        cout<<char(x);
        }
        else
        {
        x+=26;
        cout<<char(x);
        }

    }
}
//Atbash Cipher

void Atbash_cipher_message(){
    cout << "=> Atbash Cipher\n";
    cout<<"Please enter the message to cipher: "<<"\n";
    string message;
    cin.clear();
    cin.sync();
    while(message.empty())getline(cin,message);    //Allows the user to separate words with a space

    string alpha_uppercase="ZYXWVUTSRQPONMLKJIHGFEDCBA";
    string alpha_lowercase="zyxwvutsrqponmlkjihgfedcba";
    int len =message.length();
    string encryption;
    int ascii_char;
    for(int i=0;i<len;i++){
        ascii_char=message[i];
        if(ascii_char==32){      //The beginning of the encryption conditions
            encryption+=" ";
        }else if (ascii_char>='A' && ascii_char<='Z'){
            encryption+=alpha_uppercase[ascii_char-65];

        }else{
            encryption+=alpha_lowercase[ascii_char-97];
        }

    }

    cout<<"your encrypted message: "<<"\n"<<encryption;
}

void Atbash_decipher_message(){
    cout << "=> Atbash Decipher\n";
    cout<<"Please enter the message to decipher: "<<"\n";
    string message;
    cin.clear();
    cin.sync();
    while(message.empty())getline(cin,message);   //Allows the user to separate words with a space

    string alpha_uppercase="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string alpha_lowercase="abcdefghijklmnopqrstuvwxyz";
    int len = message.length();
    string Decryption;
    int ascii_char;
    for(int i=0;i<len;i++){
        ascii_char = message[i];
        if(ascii_char==32){      //The beginning of the decryption conditions
            Decryption+=" ";
        }else if(ascii_char>='A' && ascii_char<='Z'){
            Decryption+=alpha_uppercase[abs(ascii_char-90)];
        }else{
            Decryption+=alpha_lowercase[abs(ascii_char-122)];
        }

    }
    cout<<"your decrypted message: "<<"\n"<<Decryption;


}
// Vignere cipher
void vignere_cipher()
{
 string key, text, code, ciph;
    cout << "Enter The KeyWord: ";
    getline(cin, key);
    cout << "Enter The Message you want to Cipher: ";
    getline(cin, text);
    int i = 0;
    while(code.size() < text.size())
    {
        code += toupper(key[i]);
        i++;
        if(i == key.size())
            i = 0;
    }
    for(int j = 0; j < text.size(); j++)
    {
        if(isalpha(text[j]))
        {
            char tmp = char((int(toupper(text[j])) + int(toupper(code[j]))) % 26 + 65);
            ciph += tmp;
        }
        else
            ciph += text[j];
    }
    cout << "The Ciphered Message: " << ciph << endl;
}

void vignere_decipher()
{
    string key, text, diciph, code;
    cout << "Enter The KeyWord: ";
    getline(cin, key);
    cout << "Enter a Message You Want to Decipher: ";
    getline(cin, text);
    int i = 0;
    while(code.size() < text.size())
    {
        code += toupper(key[i]);
        i++;
        if(i == key.size())
            i = 0;
    }
    i = 0;
    while(i < text.size())
    {
        for(char j = 65; j <= 90; j++)
        {
            if(int(j + toupper(code[i])) % 26 == toupper(text[i]) - 65 && isalpha(text[i]))
            {
                diciph += j;
                i++;
            }
        }
        if(!isalpha(text[i]))
        {
            diciph += text[i];
            i++;
        }
    }
    cout << "The Diciphered Message: " << diciph << endl;
}
//Baconian Cipher
string Baconian_cipher(string mess)
{
    string letters = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string code[26] = {"aaaaa","aaaab","aaaba","aaabb","aabaa","aabab","aabba","aabbb","abaaa","abaab","ababa","ababb","abbaa","abbab","abbba","abbbb",
    "baaaa","baaab","baaba","baabb","babaa","babab","babba","babbb","bbaaa","bbaab"} ;
    string ciph;
    for(int i=0 ;i < mess.size() ;i++)
    {
        for(int j = 0 ;j < letters.size(); j++)
        {
            if(mess[i] == letters[j])
                ciph += code[j] ;

        }
        if(mess[i] == ' ')
            ciph += " ";
    }
    cout << ciph << endl;

}
string Baconian_dicipher(string mess)
{
    string letters = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string code = "aaaaaaaaabaaabaaaabbaabaaaababaabbaaabbbabaaaabaabababaababbabbaaabbababbbaabbbbbaaaabaaabbaababaabbbabaabababbabbababbbbbaaabbaab";
    string diciph;
    int i = 0;
    while(i < mess.size())
    {
        for(int j = 0; j < code.size(); j += 5)
        {
            if(mess.substr(i,5) == code.substr(j,5))
            {
                diciph += letters[j / 5];
                i += 5;
            }
        }
        if(mess[i] == ' ')
        {
            diciph += " ";
            i++;
        }
    }

    return diciph;
}
// simple sub cipher
void simple_alphabet()
{
    string character = "abcdefghijklmnopqrstuvwxyz";
    int z = 5;
        for( int i=0 ; i <= 26 ; i++ )
        {
            if ((char)character[i] == (char)key[0])
            {
                cipher_alphabet[0] = key[0];
            }
            else if ((char)character[i]==(char)key[1])
            {
                cipher_alphabet[1]= key[1];
            }
            else if ((char)character[i]==(char)key[2])
            {
                cipher_alphabet[2]= key[2];
            }
            else if ((char)character[i]==(char)key[3])
            {
                cipher_alphabet[3]= key[3];
            }
            else if ((char)character[i]==(char)key[4])
            {
                cipher_alphabet[4]= key[4];
            }
            else
            {
                cipher_alphabet[z]=character[i];
                z++;
            }
        }

}
void simple_cipher()
{
    cout << "Please Let's create the Cipher Alphabet First"<<endl<<"Enter a Key 5 unique letters : "<<endl;
    cin >> key;
    if (key.length()==5 && (key[0] != key[1]) && (key[0]!= key[2])&& (key[0] != key[3])&& (key[0] != key[4])&& (key[1] != key[2])&& (key[1] != key[3])&& (key[1] != key[4]) && (key[2] != key[3]) && (key[2] != key[4]) && (key[3] != key[4]))
    {
        // here we make the key in the lower case..
        for (int i =0 ;i<key.length();i++)
        {
            key[i]=tolower(key[i]);
        }
        simple_alphabet();
        sleep(3);
        system("CLS");
        cout << "Cipher Alphabet is Done !! "<< endl;
    }
    else
    {
        cout<<"Wrong Letter ! "<<endl;
        sleep(3);
        system("CLS");
        simple_cipher();
    }

}
void simple_cipher_message()
{
    string character = "abcdefghijklmnopqrstuvwxyz";
    string text;
    cout << "Enter Message To Cipher : "<< endl;
    cin.ignore();
    getline(cin,text);
    for (int i =0 ; i<text.size() ;i++)
    {
        text[i]=tolower(text[i]);
    }
    for (int z =0 ; z <= text.size() ; z++)
    {
        for (int i=0 ; i <= 26 ; i++)
        {
            if ((char)text[z] == 32)
            {
                break;
            }
            else if ((char)text[z] == (char)character[i])
            {
                text[z] = cipher_alphabet[i];
                break;
            }
        }
    }
    cout << "Cipher is : " << text;

}
void simple_decipher_message()
{
    string character = "abcdefghijklmnopqrstuvwxyz";
    string text;
    cout << "Enter Message To Decipher : "<< endl;
    cin.ignore();
    getline(cin,text);
    for (int i =0 ; i<text.size() ;i++)
    {
        text[i]=tolower(text[i]);
    }
    for (int z =0 ; z <= text.size() ; z++)
    {
        for (int i=0 ; i <= 26 ; i++)
        {
            if ((char)text[z] == 32)
            {
                break;
            }
            else if ((char)text[z] == (char)cipher_alphabet[i])
            {
                text[z] = character[i];
                break;
            }
        }
    }
    cout << "Decipher is : " << text;

}
//polybius cipher
string polybius_cipher(string mess, int key[], int length)
{
    string s1[5] = {"ABCDE", "FGHIK", "LMNOP", "QRSTU", "VWXYZ"};  // Our Main String
    string s2[5] = {"ABCDE", "FGHIK", "LMNOP", "QRSTU", "VWXYZ"};  // Second String for the Swaping processes
    for(int i = 0; i < 5; i++)  // Swaping every single row according to the key
    {
        s1[key[i]-1][0] = s2[i][0];
        s1[key[i]-1][1] = s2[i][1];
        s1[key[i]-1][2] = s2[i][2];
        s1[key[i]-1][3] = s2[i][3];
        s1[key[i]-1][4] = s2[i][4];
    }

    for(int i = 0; i < 5; i++)
        s2[i] = s1[i];

    for(int i = 0; i < 5; i++)  // Swaping every single column according to the key
    {
        s1[i][key[0]-1] = s2[i][0];
        s1[i][key[1]-1] = s2[i][1];
        s1[i][key[2]-1] = s2[i][2];
        s1[i][key[3]-1] = s2[i][3];
        s1[i][key[4]-1] = s2[i][4];
    }
    string ciph = "";
    for(int i = 0; i < mess.size(); i++)
    {
        if(int(mess[i]) >= 97)  // All Letters to Upper
            mess[i] -= 32;
    }
    for(int i = 0; i < mess.size(); i++)
    {
        if(mess[i] == 'J' || mess[i] == 'j')  // Every 'J' in the Message Turns to 'I'
            mess[i] = 'I';

        if(mess[i] == ' ')  // Ignore The space(Don't cipher it)
            ciph += " ";
        else
        {
            for(int j = 0; j < 5; j++)
            {
                for(int x = 0; x < 5; x++)
                {
                    if(s1[j][x] == mess[i])  // Every Letters is Replaced with their row's and column's number
                    {
                        string tmp = to_string(j+1) + to_string(x+1);
                        ciph += tmp;
                    }
                }
            }
        }
    }
    return ciph;
}

string polybius_decipher(string mess, int key[], int length)
{
    string s1[5] = {"ABCDE", "FGHIK", "LMNOP", "QRSTU", "VWXYZ"};  // Our Main String
    string s2[5] = {"ABCDE", "FGHIK", "LMNOP", "QRSTU", "VWXYZ"};  // Second String for the Swaping processes
    for(int i = 0; i < 5; i++)  // Swaping every single row according to the key
    {
        s1[key[i]-1][0] = s2[i][0];
        s1[key[i]-1][1] = s2[i][1];
        s1[key[i]-1][2] = s2[i][2];
        s1[key[i]-1][3] = s2[i][3];
        s1[key[i]-1][4] = s2[i][4];
    }

    for(int i = 0; i < 5; i++)
        s2[i] = s1[i];

    for(int i = 0; i < 5; i++)  // Swaping every single column according to the key
    {
        s1[i][key[0]-1] = s2[i][0];
        s1[i][key[1]-1] = s2[i][1];
        s1[i][key[2]-1] = s2[i][2];
        s1[i][key[3]-1] = s2[i][3];
        s1[i][key[4]-1] = s2[i][4];
    }
    string diciph = "";
    int i = 0;
    while(i < mess.size())
    {
        if(mess[i] == ' ')  // Ignore The space(Don't Dicipher it)
        {
            diciph += " ";
            i++;
        }
        else
        {
            int a, b;
            stringstream ss1, ss2;  // Take Every Two string Numbers in ciphered text and convert it to integer
            ss1 << mess[i];
            ss2 << mess[i+1];
            ss1 >> a;
            ss2 >> b;
            diciph += s1[a-1][b-1];  // Replace the row's number, and column number with its letter in the table
            i += 2;
        }
    }
    return diciph;
}
// Morse cipher
void morse_cipher(string text)
{
    map<char, string> cipher
    {
        {'A', ".-"},
        {'B', "-..."},
        {'C', "-.-."},
        {'D', "-.."},
        {'E', "."},
        {'F', "..-."},
        {'G', "--."},
        {'H', "...."},
        {'I', ".."},
        {'J', ".---"},
        {'K', "-.-"},
        {'L', ".-.."},
        {'M', "--"},
        {'N', "-."},
        {'O', "---"},
        {'P', ".--."},
        {'Q', "--.-"},
        {'R', ".-."},
        {'S', "..."},
        {'T', "-"},
        {'U', "..-"},
        {'V', "...-"},
        {'W', ".--"},
        {'X', "-..-"},
        {'Y', "-.--"},
        {'Z', "--.."},
        {'1', ".----"},
        {'2', "..---"},
        {'3', "...--"},
        {'4', "....-"},
        {'5', "....."},
        {'6', "-...."},
        {'7', "--..."},
        {'8', "---.."},
        {'9', "----."},
        {'0', "-----"}
    };
    for(char i: text)
    {
        if(i == ' ')
            cout << "   ";
        else
            cout << cipher[toupper(i)] << " ";
    }
    cout << endl;
}
void morse_decipher(string text)
{
    map<char, string> cipher
    {
        {'A', ".-"},
        {'B', "-..."},
        {'C', "-.-."},
        {'D', "-.."},
        {'E', "."},
        {'F', "..-."},
        {'G', "--."},
        {'H', "...."},
        {'I', ".."},
        {'J', ".---"},
        {'K', "-.-"},
        {'L', ".-.."},
        {'M', "--"},
        {'N', "-."},
        {'O', "---"},
        {'P', ".--."},
        {'Q', "--.-"},
        {'R', ".-."},
        {'S', "..."},
        {'T', "-"},
        {'U', "..-"},
        {'V', "...-"},
        {'W', ".--"},
        {'X', "-..-"},
        {'Y', "-.--"},
        {'Z', "--.."},
        {'1', ".----"},
        {'2', "..---"},
        {'3', "...--"},
        {'4', "....-"},
        {'5', "....."},
        {'6', "-...."},
        {'7', "--..."},
        {'8', "---.."},
        {'9', "----."},
        {'0', "-----"}
    };
    int i = 0;
    while(i < text.size())
    {
        string pattern = "";
        if(text[i] == ' ' && text[i+1] == ' ' && text[i+2] == ' ')
        {
            cout << " ";
            i += 3;
        }
        else if(text[i] == ' ')
        {
            i++;
        }
        while(text[i] != ' ' && i != text.size())
        {
            pattern += text[i];
            i++;
        }
        for(char letter = 65; (int)letter < 91; letter++)
        {
            if(cipher[letter] == pattern)
                cout << letter;
        }

    }
    cout << endl;
}
//xor cipher
string xor_cipher(string mess, char k)
{
    string ciph = "", h;

    for(char i: mess)
    {
        if(i != ' ')
        {
            stringstream ss;
            string s;
            char tmp = (char)((int)toupper(k) ^ (int)toupper(i));
            if((int)tmp < 16)
                ss << "0";

            ss << hex << int(tmp);
            ss >> s;
            h += s;
            ciph += tmp;
        }
        else
        {
            h += " ";
            ciph += " ";
        }
    }
    return ciph + "   " + "(Hexa  " + h + ')';
}

string xor_dicipher(string mess, char k)
{
    string diciph = "";
    int i = 0;
    while(i < mess.size())
    {
        string carry = "";
        if(mess[i] == ' ')
        {
            diciph += " ";
            i++;
        }
        carry += mess[i];
        carry += mess[i+1];
        char tmp = stoi(carry, 0, 16);
        diciph += (char)((tmp) ^ (int)toupper(k));
        i += 2;
    }
    return diciph;
}
//Rail-fence cipher
void rail_cipher_message()
{
    string str;
    string cipher;
    cout<<"Enter Message To Cipher :";
    cin.get();
    int temp = 0;
    getline(cin,str);
    vector<char> arr(str.size() , '.');
    vector<char> arr1(str.size() , '.');
    vector<char> arr2(str.size() , '.');
    for (int x =0 ; x<str.size() ; x++)
    {
        if (str[x]== ' ')
        {
            str.replace(x,1,"");
        }
    }
    for (int x =0 ; x<str.size(); x+=4)
    {
        arr[x]=str[x];
    }

    for (int x = 1 ; x<str.size(); x+=2)
    {
        arr1[x]=str[x];

    }
    for (int x =2 ; x<str.size(); x+=4)
    {
        arr2[x]=str[x];

    }
    for (int i=0 ; i<arr.size();i++)
    {
        if (isalpha(arr[i]))
        {
            cipher += arr[i];
        }
    }
    for (int i=0 ; i<arr1.size();i++)
    {
        if (isalpha(arr1[i]))
        {
            cipher += arr1[i];
        }
    }
    for (int i=0 ; i<arr2.size();i++)
    {
        if (isalpha(arr2[i]))
        {
            cipher += arr2[i];
        }
    }
    cout << "Cipher text : " << cipher <<endl;
    cout << "Pattern : " << endl;
    for (int i=0 ; i< str.size() ; i++)
    {
        cout << arr[i];

    }
    cout << endl;
    for (int i=0 ; i< str.size() ; i++)
    {
        cout << arr1[i];

    }
    cout << endl;
    for (int i=0 ; i< str.size() ; i++)
    {
        cout << arr2[i];

    }
    cout << endl;


}
void rail_decipher_message()
{
    string str;
    cout<<"Enter Message To Decipher : ";
    cin.get();
    getline(cin,str);
    char decipher[str.size()+1];
    int i = 0;
    int x = 0;
    while ( i < str.size() /4 )
    {
        decipher[x]=str[i];
        i++;
        x+=4;
    }
    x=1;
    while (i < ((str.size())/4+(str.size())/2) )
    {
        decipher[x]=str[i];
        i++;
        x+=2;
    }
    x=2;
    while (i < str.size() )
    {
        decipher[x]=str[i];
        i++;
        x+=4;
    }

    cout << decipher << endl;
}
void mainmassege()
{
        cout << "AHLAN YA USER !!"<<endl;
        cout << "What do you want today !" <<endl << "[1] Cipher a Message" <<endl<< "[2] Decipher a Message" << endl<< ": ";
        cin >> type_choose;
        if (type_choose == "1")
        {
                if (choosing == 1)
                {
                    sleep(3);
                    system("CLS");
                    affine_cipher_message();
                }
                else if (choosing == 2)
                {
                    sleep(3);
                    system("CLS");
                    caesar_cipher_message();
                }
                else if (choosing == 3)
                {
                    sleep(3);
                    system("CLS");
                    Atbash_cipher_message();
                }
                else if (choosing == 4)
                {
                    sleep(3);
                    system("CLS");
                    cout << "=> Vignere cipher\n";
                    cin.get();
                    vignere_cipher();
                }
                else if (choosing == 5)
                {
                    sleep(3);
                    system("CLS");
                    string text;
                    cout << "=> Baconian cipher\n";
                    cout << "Enter a Message You Want to Cipher: ";
                    cin.get();
                    getline(cin, text);
                    for(int i = 0; i < text.size(); i++)
                        if(int(text[i]) >= 97)
                            text[i] -= 32;
                    cout<<"Ciphered Message : " << Baconian_cipher(text) << endl;
                }
                else if (choosing == 6)
                {
                    sleep(3);
                    system("CLS");
                    cout << "=> Simple Substitution cipher\n";
                    simple_cipher();
                    simple_cipher_message();
                }
                else if (choosing == 7)
                {
                    sleep(3);
                    system("CLS");
                    int key[5];
                    cout << "=> Polybius cipher\n";
                    cout << "Enter The Key: ";
                    for(int i = 0; i < 5; i++)
                        cin >> key[i];
                    while(cin.fail())  // Defensive Programming
                    {
                        cin.clear();
                        cin.sync();
                        cout << "INVALID INPUT!\n";
                        cout << "Enter The Key: ";

                        for(int i = 0; i < 5; i++)
                            cin >> key[i];
                    }
                    cout << "Enter The Message you want to Cipher(ALPHAPETS ONLY): ";
                    string mess;
                    cin.get();
                    getline(cin,mess);

                    cout << "The Ciphered Message: " << polybius_cipher(mess, key, 5) << "\n\n" << endl;
                }
                else if (choosing == 8)
                {
                   sleep(3);
                   system("CLS");
                   string text;
                   cout << "=> Morse cipher\n";
                   cout << "Enter The Message you want to Cipher: ";
                   cin.get();
                   getline(cin, text);
                   cout << "Ciphered Message: ";
                   morse_cipher(text);

                }
                else if (choosing == 9)
                {
                   sleep(3);
                   system("CLS");
                   char key;
                   string text;
                   cout << "=> XOR cipher\n";
                   cout << "Enter The key of Encryption: ";
                   cin >> key;
                   cin.get();
                   cout << "Enter The Message you want to Cipher: ";
                   getline(cin, text);
                   cout << "The Ciphered Message: " << xor_cipher(text, key) << endl;

                }
                else if (choosing == 10)
                {
                    sleep(3);
                    system("CLS");
                    cout << "=> Rail-fence cipher\n";
                    rail_cipher_message();
                }

        }
        else if (type_choose == "2")
        {
                if (choosing == 1)
                {
                    sleep(3);
                    system("CLS");
                    affine_decipher_message();
                }
                else if (choosing == 2)
                {
                    sleep(3);
                    system("CLS");
                    caesar_decipher_message();
                }
                else if (choosing == 3)
                {
                    sleep(3);
                    system("CLS");
                    Atbash_decipher_message();

                }
                else if (choosing == 4)
                {
                    sleep(3);
                    system("CLS");
                    cout << "=> Vignere Decipher\n";
                    cin.get();
                    vignere_decipher();
                }
                else if (choosing == 5)
                {
                    sleep(3);
                    system("CLS");
                    string text;
                    cout << "=> Baconian Decipher\n";
                    cout << "Enter a Message You want to Dicipher: ";
                    cin.get();
                    getline(cin, text);
                    cout<<"Decipherd Message: " << Baconian_dicipher(text) <<endl;
                }
                else if (choosing == 6)
                {
                    sleep(3);
                    system("CLS");
                    cout << "=> Simple Substitution decipher\n";
                    simple_cipher();
                    simple_decipher_message();
                }
                else if (choosing == 7)
                {
                   sleep(3);
                    system("CLS");
                    int key[5];
                    cout << "=> Polybius Decipher\n";
                    cout << "Enter The Key: ";
                    for(int i = 0; i < 5; i++)
                        cin >> key[i];
                    while(cin.fail())  // Defensive Programming
                    {
                        cin.clear();
                        cin.sync();
                        cout << "INVALID INPUT!\n";
                        cout << "Enter The Key: ";

                        for(int i = 0; i < 5; i++)
                            cin >> key[i];
                    }
                    cout << "Enter The Message you want to Cipher(ALPHAPETS ONLY): ";
                    string mess;
                    cin.get();
                    getline(cin,mess);

                    cout << "The Ciphered Message: " << polybius_decipher(mess, key, 5) << "\n\n" << endl;
                }
                else if (choosing == 8)
                {
                   sleep(3);
                   system("CLS");
                   cout << "=> Morse Decipher\n";
                   cout << "Enter The Message you want to Decipher: ";
                   string text;
                   cin.get();
                   getline(cin, text);
                   cout << "Deciphered Message: ";
                   morse_decipher(text);

                }
                else if (choosing == 9)
                {
                    sleep(3);
                    system("CLS");
                    char key;
                    string text;
                    cout << "=> XOR Decipher\n";
                    cout << "Enter The key of Decryption: ";
                    cin >> key;
                    cin.get();
                    cout << "Enter The Message you want to Dicipher(in Hexa): ";
                    getline(cin, text);
                    cout << "The Message: " << xor_dicipher(text, key) << endl;
                }
                else if (choosing == 10)
                {
                    sleep(3);
                    system("CLS");
                    cout << "=> Rail-fence Decipher\n";
                    rail_decipher_message();
                }

        }
        else
         {
            cout << "YOU ENTER A WRONG NUMBER !!" << endl;
            return mainmassege();
         }


}


int main()
{
    while(true)
    {
        cout << "CHOOSE A CIPHER PLEASE \n";
        cout << "[1] Affine Cipher\n"
             << "[2] Caesar Cipher\n"
             << "[3] Atbash Cipher\n"
             << "[4] Vignere Cipher\n"
             << "[5] Baconian Cipher\n"
             << "[6] Simple Substitution Cipher\n"
             << "[7] Polybius Square Cipher\n"
             << "[8] Morse Code Cipher\n"
             << "[9] XOR Cipher\n"
             << "[10] Rail-fence Cipher\n"
             << "[0] End\n=> ";
        cin >> choosing;
        while(cin.fail())  // Defensive Programming
        {
            cin.clear();
            cin.sync();
            cout << "INVALID INPUT!\n=> ";
            cin >> choosing;
        }
        if(choosing == 0)
        {
            cout << "EXIT" << endl;
            break;
        }else
        {
        sleep(3);
        system("CLS");
        mainmassege();
        break;
        }
    }
    return 0;
}
