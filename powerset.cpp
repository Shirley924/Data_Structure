#include<iostream>
#include<vector>
#include<string>
#include<sstream>
using namespace std;

void set(vector<string> const &str,vector<string> &temp,int h,int m, int k);

int main(){

        while(!cin.eof()){
        vector<string> str;
        vector<string> temp;
        string tmp,put;

        getline(cin,put);
        istringstream delim(put);
        while(getline(delim,tmp,' ')){
                str.push_back(tmp);
        }
        cout<<"{ }"<<endl;

        for(int i=0;i<str.size();++i){
                set(str,temp,0,str.size()-i,1);
        }
        }

        return 0;
}

void set(vector<string> const &str,vector<string> &temp,int h,int m,int k){

        if(k>m){
                cout<<"{";
                for(int i=0;i<temp.size()-1;i++){
                        cout<<temp.at(i)<<",";
                }
                cout<<temp.at(temp.size()-1)<<"}"<<endl;
                return;
        }
        else
        {
                for(int j=h;j<str.size()-m+k;++j){
                        //存
                        temp.push_back(str.at(j));
                        set(str,temp,j+1,m,k+1);
                        //刪
                        temp.pop_back();
                }
        }
}
