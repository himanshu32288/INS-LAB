#include<bits/stdc++.h>
using namespace std; 
int shift=2;
string encrypt(string &plain_text){
    string cipher;
    for(auto x:plain_text){
        int num_val=x-'a';
        num_val-=shift;
        if(num_val<0)
        num_val+=26;
        int cipher_num_val=num_val%26;
        cipher+=(cipher_num_val+'a');
    }
    return cipher;
}
string decrypt(string &cipher){
    string plain_text;
    for(auto x:cipher){
        int num_val=x-'a';
        num_val+=shift;
        int cipher_num_val=num_val%26;
        plain_text+=(cipher_num_val+'a');
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