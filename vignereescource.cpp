#include<bits/stdc++.h>
using namespace std;

// This function generates the key in
// a cyclic manner until it's length isi'nt
// equal to the length of original text
string generateKey(string str, string key)
{
	int x = str.size();

	for (int i = 0; i<str.size(); i++)
	{
		if (x == i)
			i = 0;
		if (key.size() == str.size())
			break;
		key.push_back(key[i]);
	}
	return key;
}

// This function returns the encrypted text
// generated with the help of the key
string cipherText(string str, string key)
{
	string cipher_text;

	for (int i = 0; i < str.size(); i++)
	{
		// converting in range 0-25
		char x = (str[i] + key[i]) %26;

		// convert into alphabets(ASCII)
		x += 'A';

		cipher_text.push_back(x);
	}
	return cipher_text;
}

// This function decrypts the encrypted text
// and returns the original text
string originalText(string cipher_text, string key)
{
	string orig_text;

	for (int i = 0 ; i < cipher_text.size(); i++)
	{
		// converting in range 0-25
		char x = (cipher_text[i] - key[i] + 26) %26;

		// convert into alphabets(ASCII)
		x += 'A';
		orig_text.push_back(x);
	}
	return orig_text;
}

// Driver program to test the above function
int main()
{
	string str;
	start: ;
	cout<<"Would you like to encrypt(1) or decrypt(2)? ";
	int option;
	int i=0;
	string keyword;
	cin>>option;
	switch(option)
	{
	    case 1:
	    {
	        tryagain: ;
        cout<<"Warning! Capital letter allowed only!\n";
	     cout<<"Enter the plain text: ";
	     cin>>str;
	     cout<<"Enter the key: ";
	     cin>>keyword;
	     while(i!=str.length())
	{
	    if(str[i]>90)
	    goto tryagain;
	    i++;
	}
	i=0;
	while(i!=keyword.length())
	{
	    
	    if(keyword[i]>90)
	    goto tryagain;
	    i++;
	}
	
	string key = generateKey(str, keyword);
	string cipher_text = cipherText(str, key);
	cout << "Ciphertext : "
		<< cipher_text << "\n";
		return(0);
	    }
	    break;
	    case 2:
	    {
	        again: ;
        cout<<"Warning! Capital letter allowed only!\n";
	     cout<<"Enter the ciphered text: ";
	     cin>>str;
	     cout<<"Enter the key: ";
	     cin>>keyword;
	     while(i!=str.length())
	{
	    if(str[i]>90)
	    goto again;
	    i++;
	}
	i=0;
	while(i!=keyword.length())
	{
	    
	    if(keyword[i]>90)
	    goto again;
	    i++;
	}
	
	string key = generateKey(str, keyword);
	string cipher_text=str;
	cout << "Original/Decrypted Text : "
		<< originalText(cipher_text, key);
		return(0);
	    } break;
	    default: 
	    {
	        cout<<endl<<"Enter the correct option! "<<endl;
	        goto start;
	    }
	}
