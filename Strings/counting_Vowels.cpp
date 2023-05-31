#include<iostream>
using namespace std;
int main()
{ int i,vcount=0,Ccount=0,space=0;
    char c[]="How are you";
    for(i=0;c[i]!='\0';i++)
    { 
        if(c[i]=='a'||c[i]=='A'||c[i]=='e'||c[i]=='E'||c[i]=='i'||c[i]=='I'||c[i]=='O'||c[i]=='o'|| c[i]=='u'||c[i]=='U')
        vcount++;
        else if(c[i]==' ')
        space++;
        else
        Ccount++;
    }
    cout<<"Vowels are = "<<vcount<<endl<<"Consonants are = "<<Ccount;
    return 0;
}