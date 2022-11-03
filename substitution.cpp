#include<bits/stdc++.h>
using namespace std;   
string key = "wciefghzpkjnmrlqotsavbdxyu";
string encrypt(string &plain_text){
    string cipher;  
    for(auto x:plain_text){
        cipher+=key[x-'a'];
    }
    return cipher;
}
string decrypt(string &cipher){
    string plain_text; 
    unordered_map<char,int> key_map;
    for(int i=0;i<26;i++){
        key_map[key[i]]=i;
    } 
    for(auto x:cipher){
        plain_text+=key_map[x]+'a';
    }
    return plain_text;
}
int main(){ 
    cout<<"Plain Text:";
    string plain_text;
    cin>>plain_text;
    string cipher=encrypt(plain_text); 
    cout<<"Cipher Text:"<<cipher<<endl; 
    string decrypted_text=decrypt(cipher);
    cout<<"Decrypted Plain Text :"<<decrypted_text;
}