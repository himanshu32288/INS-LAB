#include<bits/stdc++.h>
using namespace std;

void generateKey(int length, string &key){
     if(key.size()>=length)
     return;
     int i=0;
     while(key.size()!=length){
         key+=key[i];
         i++;
         if(i==key.size())
         i=0;
     }
}
string encrypt(string &plain_text,string &key){
    string cipher;  
    for (int i=0;i<plain_text.size();i++){
        int x = ((plain_text[i]-'a') + (key[i]-'a'))%26;
        cipher+=(x+'a');
    }
    return cipher;
}
string decrypt(string &cipher,string &key){
    string plain_text;
    for (int i = 0 ; i < cipher.size(); i++){
        int x = ((cipher [i]-'a') - (key[i]-'a') + 26)%26;
        plain_text+=(x+'a');
    }
    return plain_text;
}
int main(){
    cout<<"Plain Text:";
    string plain_text;
    cin>>plain_text; 
    string key;
    cout<<"Key: ";
    cin>>key; 
    generateKey(plain_text.size(),key); 
    string cipher=encrypt(plain_text,key);  
    cout<<"Cipher Text:"<<cipher<<endl; 
    string decrypted_text=decrypt(cipher,key);
    cout<<"Decrypted Plain Text :"<<decrypted_text;
}