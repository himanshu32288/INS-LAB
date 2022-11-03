#include <bits/stdc++.h>
using namespace std;
/*
1.5*5 matrix i/j together no repetation row wise insertion done
Encryption
1.(x,y)-> (xrow,xcol) & (yrow,ycol)
2. if ycol=xcol ,(x,y)->([(xrow+1)%5,xcol],[(yrow+1)%5,ycol])
3.if yROW=xROW ,(x,y)->([xrow,(xcol+1)%5],[yrow,(ycol+1)%5])
4.else (x,y)->([yrow,xcol],[xrow,ycol])
Decryption
1.(x,y)-> (xrow,xcol) & (yrow,ycol)
2.if ycol=xcol ,(x,y)->([(xrow-1)%5,xcol],(yrow-1)%5,ycol)
3.if yROW=xROW ,(x,y)->([xrow,(xcol-1)%5],[yrow,(ycol-1)%5])
4.else (x,y)->([yrow,xcol],[xrow,ycol])
*/
map<char, int> char_pos;
pair<int, int> get_row_col(int num){
    return {num / 6, num % 6};
}
string pair_split(string &plain_text){
    string modified_text;
    int text_size = plain_text.size();
    int i = 0;
    for (i = 1; i < text_size; i += 2){
        if (plain_text[i - 1] == plain_text[i]){
            modified_text += plain_text[i - 1];
            modified_text += 'x';
            i--;
        }
        else{
            modified_text += plain_text[i - 1];
            modified_text += plain_text[i];
        }
    }
    if (i == text_size){
        modified_text += plain_text[text_size - 1];
        modified_text += 'z';
    }
    return modified_text;
}
string encrypt(string &plain_text, vector<vector<char>> key_matrix){
    string cipher;
    string modified_text = pair_split(plain_text); 
    for (int i = 0; i < modified_text.size(); i += 2){
        pair<int,int> pair1 = get_row_col(char_pos[modified_text[i]]);
        int row1=pair1.first;
        int col1=pair1.second;
        pair<int,int> pair2 = get_row_col(char_pos[modified_text[i + 1]]);
        int row2=pair2.first;
        int col2=pair2.second; 
        if (row1 == row2){
            cipher += key_matrix[row1][(col1 + 1) % 5];
            cipher += key_matrix[row2][(col2 + 1) % 5];
        }
        else if (col1 == col2){
            cipher += key_matrix[(row1 + 1) % 5][col1];
            cipher += key_matrix[(row2 + 1) % 5][col2];
        }else{
            cipher += key_matrix[row1][col2];
            cipher += key_matrix[row2][col1];
        }
    }
    return cipher;
}
string decrypt(string &cipher,vector<vector<char>> key_matrix){
    string plain_text;
    for (int i = 0; i < cipher.size(); i += 2){
        pair<int,int> pair1 = get_row_col(char_pos[cipher[i]]);
        int row1=pair1.first;
        int col1=pair1.second;
        pair<int,int> pair2 = get_row_col(char_pos[cipher[i + 1]]);
        int row2=pair2.first;
        int col2=pair2.second;
        if (row1 == row2){ 
            if(col1==0)
            col1=5;
            if(col2==0)
            col2=5;
            plain_text += key_matrix[row1][col1 - 1];
            plain_text += key_matrix[row2][col2 - 1];
        }
        else if (col1 == col2){
            if(row1==0)
            row1=5;
            if(row2==0)
            row2=5;
            plain_text += key_matrix[row1 - 1][col1];
            plain_text += key_matrix[row2 - 1][col2];
        }else{
            plain_text += key_matrix[row1][col2];
            plain_text += key_matrix[row2][col1];
        }
    }
    return plain_text;
}
vector<vector<char>> generate_key_matrix(string &Key){
    vector<vector<char>> key_matrix(5, vector<char>(5, '.'));
    vector<bool> used_char(26, false);
    used_char['j' - 'a'] = true;
    int i = 0, j = 0;
    for (auto c : Key){
        if (used_char[c - 'a'])
            continue;
        used_char[c - 'a'] = true;
        key_matrix[i][j] = c;
        char_pos[c] = i * 6 + j; 
        
        j++;
        if (j == 5){
            i++;
            j = 0;
        }
    }
    for (int chr = 0; chr < 26; chr++){
        if (used_char[chr])
            continue;
        used_char[chr] = true;
        key_matrix[i][j] = chr + 'a';
        char_pos[chr + 'a'] = i * 6 + j;
        j++; 
        if (j == 5){
            i++;
            j = 0;
        }
    }
    return key_matrix;
}
int main(){
    cout << "Plain Text:";
    string plain_text;
    cin >> plain_text;
    string Key;
    cout << "Key:";
    cin >> Key;
    vector<vector<char>> key_matrix = generate_key_matrix(Key);
    for (auto x : key_matrix){
        for (auto y : x){
            cout << y << " ";
        }
        cout << endl;
    }
   
    string cipher = encrypt(plain_text, key_matrix);
    cout<<"Cipher Text:"<<cipher<<"\n";
    
    string decrypted_text=decrypt(cipher,key_matrix); 
    
    cout<<"Decrypted Plain Text :"<<decrypted_text;
}