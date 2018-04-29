#include<iostream>
#include<fstream>
#include<sstream>
#include<string>

void read(std::string &str)
{
    std::string inFileName;
    std::cout<<"Enter file name: \n";
    std::cin>>inFileName;
    std::ifstream inFile;
    inFile.open(inFileName);//open the input file
    std::stringstream strStream;
    strStream << inFile.rdbuf();//read the file
    str = strStream.str();//str holds the content of the file
}

int jumpf(int i,std::string input)
{
    int open=1,closed=0;
    while(open>closed)
    {
        ++i;
        if(input[i]=='[')
            ++open;
        if(input[i]==']')
            ++closed;
    }
    return i+1;
}

int jumpb(int i,std::string input)
{
    int open=0,closed=1;
    while(closed>open)
    {
        --i;
        if(input[i]=='[')
            ++open;
        if(input[i]==']')
            ++closed;
    }
    return i+1;
}

void run(std::string input)
{
    char arr[100000]={};
    int p=0;
    for(int i=0;i<input.length();i++)
    {
        if(input[i]=='['&&arr[p]==0)
            i=jumpf(i,input);
        if(input[i]==']'&&arr[p]!=0)
            i=jumpb(i,input);
        if(input[i]=='+')
            ++arr[p];
        if(input[i]=='-')
            --arr[p];
        if(input[i]=='>')
            ++p;
        if(input[i]=='<')
            --p;
        if(input[i]=='.')
            std::cout<<arr[p];
        if(input[i]==',')
        {
            int in;
            std::cin>>in;
            arr[p]=in;
        }
    }
}

int main()
{
    std::string input;
    read(input);
    run(input);
    return 0;
}
