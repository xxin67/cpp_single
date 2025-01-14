#include<iostream>
#include<string>
using namespace std;

void con(void);
void sort(void);
void rep(void);
void day_rep(void);

int main()
{
    con();
    sort();
    rep();
    day_rep();
    system("pause");
}

void con(void)
{   
    cout<<"con:"<<endl;
    string s1("cat"),s2,s3;
    s2 = s1;
    s3.assign("jump");
    cout<<s2<<endl;
    cout<<s3<<endl;
    cout<<s2<<s3<<endl;
    s1 += s3;
    cout<<s1<<endl;
    s1.append("and yell");
    cout<<s1<<endl;
    s1[0] = 'h';
    cout<<s1<<endl;
    cout<<endl;
}

void sort(void)
{   
    cout<<"sort:"<<endl;
    string name[5] = {"Li Hua","He Xiaoming","Zhang Li","Sun Fei","Chen Bao"};
    string s;
    int i,j,k;
    for(i=0;i<4;i++)
    {
        k = i;
        for(j=i+1;j<5;j++)
        {
            if(name[i]>name[j])
                k = j;
        }
        if(k!=i)
        {
            s = name[k];
            name[k] = name[i];
            name[i] = s;
        }
    }
    for(i = 0;i<5;i++)
    {
        cout<<"name["<<i<<"]="<<name[i]<<endl;
    }
    cout<<endl;
}

void rep(void)
{
    cout<<"rep:"<<endl;
    string alphabet = "A,B,C,D,E,F,G,H,I,J,K,L,M,N,O,P,Q,R,S,T,U,V,W,X,Y,Z";
    int x = alphabet.find(",");
    while(x!=string::npos)
    {
        alphabet.replace(x,1,";");
        x = alphabet.find(",",x+1);
    }
    cout<<alphabet<<endl;
    cout<<endl;
}

void day_rep(void)
{
    cout<<"day_rep:"<<endl;
    cout<<"Enter the day in American format"<<"(e.g.,December 25,2001):\n";
    string date;
    getline(cin,date,'\n');
    int i = date.find(" ");
    string month = date.substr(0,i);
    int k = date.find(",");
    string day = date.substr(i+1,k-i-1);
    string year = date.substr(k,date.size()-1);
    string newdate = day + " " + month + year;
    cout<<"Original date:"<<date<<endl;
    cout<<"Converted date:"<<newdate<<endl;
}