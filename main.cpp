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

void run(std::string input,size_t arrsize,int input_method)
{
    char* arr=new char[arrsize]();
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
            if(input_method==1)
            {
                int in;
                std::cin>>in;
                arr[p]=in;
            }
            else
                std::cin>>arr[p];
        }
    }
}

int main()
{
    std::string input;
    size_t arrsize=10000; //default
    int input_method=1; //1 for numbers and 2 for ASCII
    std::cout<<"Type your command:\n";
    std::cout<<"size \ninput \nrun \nexit \n";
    while(1)
    {
        std::cin>>input;
        if(input=="run")
        {
            input="";
            read(input);
            run(input,arrsize,input_method);
            break;
        }
        else if(input=="size")
        {
            std::cout<<"Enter the size of the array:\n";
            std::cin>>arrsize;
        }
        else if(input=="input")
        {
            std::cout<<"Enter 1 for numbers or 2 for ASCII characters:\n";
            std::cin>>input_method;
        }
        else if(input=="exit")
            break;
        else
            std::cout<<"Command not found\n";
    }
    return 0;
}
