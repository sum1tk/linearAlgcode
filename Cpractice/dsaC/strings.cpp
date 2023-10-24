#include <iostream>
using namespace std;
  
bool valid(char *name)
{
    for(int i=0;name[i]!='\0';i++)
    {
        if (!(name[i]>=65&&name[i]<=90||name[i]>=97&&name[i]<=122||name[i]>=48 && name[i]<=57))
        {
            return false;
        }

    }
    return true;
}
void perm(char s[],int k)
{
    static char res[10];//array to store and return result
    static int A[10]={0};//keeping track of used characters
    int i;
    if(s[k]=='\0')
    {
        res[k]='\0';
        printf("%s\n",res);
    }
    else{
    for (i=0;s[i]!='\0';i++)
    {
        if(A[i]==0)
        {
            res[k]=s[i];
            A[i]=1;
            perm(s,k+1);
            A[i]=0;
        }

    }
    }
}
int main()
{
    // length of a string
    char s[]="welcome";
    int i=0;
    while(s[i]!='\0')// looping till null
    {
        i++;
    }
    cout<<i<<endl;
    i=0;

    while(s[i]!='\0') //changing to upper case
    {
        s[i]=s[i]-32; // ascii code manipulation
        i++;
    }
    cout<<s<<endl;
    i=0;

    while(s[i]!='\0')// lower case
    {
        s[i]=s[i]+32;
        i++;
    }
    cout<<s<<endl;
    char a[]="WELCOME";
    for (int i=0;a[i]!='\0';i++)// toggling upper/lower
    {
        if(a[i]>=65 && a[i]<=90)
        {
            a[i]=a[i]+32;
        }
        else if(a[i]>=97 && a[i]<=122)
        {
            a[i]=a[i]-32;
        }
    }
    int vowel=0;
    int consonant=0;
    for(int i=0;a[i]!='\0';i++)// counting vowels
    {
        if(a[i]=='a'||a[i]=='e'||a[i]=='i'||a[i]=='o'||a[i]=='u')
        {
            vowel++;
        }//counting consants by providing ascii range
        else if(a[i]>=65&&a[i]<=90||a[i]>=97&&a[i]<=122)
        {
            consonant++;
        }
        
    }
    cout<<a<<endl;
    cout<<vowel<<endl;
    cout<<consonant<<endl;
    char q[]="how are   u";
    int word=1;
    for (int i=0;q[i]!='\0';i++)
    {
        if(q[i]==' ' && q[i-1]!=' ')//counting words by counting spaces
        {// we se if previous index is non-space to make sure no double counting is done
            word++;
        }
    }
    cout<<word<<endl;
    char name[10]="Anil321";
    cout<<valid(name)<<endl;

    char rev[]="python";
    for (i=0;rev[i]!='\0';i++)
    {   
    }
    cout<<i<<endl;
    char reve[i];
    i=i-1;
    int w;
    for(w=0;i>=0;i--,w++)
    {
        reve[w]=rev[i];
    }
    for (i=0;rev[i]!='\0';i++)
    {   
    }
    reve[w]='\0';
    cout<<reve<<endl;
    int temp;
    int x=i-1;
    for(int z=0;z<x;z++,x--)
    {
        temp=reve[z];
        reve[z]=reve[x];
        reve[x]=temp;
    }
    cout<<reve<<endl;
    char s1[]="painta";
    char s2[]="paint";
    int p=0;
    int o;
    for(o=0;s1[o]!='\0' || s2[p]!='\0';o++,p++)
    {
        if(s1[o]!=s2[p]) break;
    }
    if (s1[o]==s2[p]) printf("equal");
    else if (s1[o]>s2[p]) printf("larger");
    else printf("smaller");
    printf("\n");
    char dupli[]="finding";
    int h[26]={0};
    for (int i=0;dupli[i]!='\0';i++)
    {
        h[dupli[i]-97]++;
        
    }
    for(int i=0;i<26;i++)
    {
        if(h[i]>1)
        {
            printf("%c %d\n",i+97,h[i]);
        }
    }
    for(int i=0;h[i]!='\0';i++)
    {
        cout<<h[i];
    }
    int has,b;
    for (int i=0;dupli[i]!='\0';i++)
    {
        b=1;
        b=b<<(dupli[i]-97);
        if((b & has)>0)
        {
            printf("%c is Duplicate\n",dupli[i]);
        }
        else 
        {
            b=b|has;
        }
    }
    char ana[]="decimal";
    char anag[]="medicak";
    int hash[26]={0};
    for (int u=0;ana[u]!='\0';u++)
    {
        hash[ana[u]-97]++;
    }
    int f;
    for (f=0;anag[f]!='\0';f++)
    {
        if(hash[anag[f]-97]==0)
        {
            printf("not an anagram");
            break;
        }
    }
    if (anag[f]=='\0')
    {
        printf("anagram");
    }
    // permutation of a string -back tracking/brute force/state space tree/recursion
    char st[]="reginaMean";
    perm(st,0);


    return 0;
}