#include <iostream>
using namespace std;
  
class Diagonal
{
    private:
        int n;
        int *A;
    public:
    Diagonal(int n)
    {
        this->n=n;
        A=new int[n];
    }
    void Set(int i,int j,int x);
    int Get(int i,int j);
    void Display();
    ~Diagonal(){delete []A;}
        
};


void Diagonal::Set(int i,int j,int x)
{
    if (i==j) A[i-1]=x; //if i==j then index is valid - to get 1,1 we need to access 0
}

int Diagonal::Get(int i,int j)
{
    if (i==j) return A[i-1];
    else return 0;
}
void Diagonal::Display()
{
    int i,j;
    for (i=0;i<n;i++)       //traverse rows
    {
        for (j=0;j<n;j++)   //traverse columns(cells)
        {
            if (i==j) cout<<A[i]<<" ";
            else cout<<0<<" ";
        }
        cout<<endl;
    }

}

class LowerTriangular
{
    private:
        int n;
        int *A;
    public:
    LowerTriangular(int n)
    {
        this->n=n;
        A=new int[n*(n+1)/2];  // number of non zero elements =1+2+3+4+5+......+n=n(n+1)/2

    }
    void Set(int i,int j,int x);
    int Get(int i,int j);
    void Display();
    ~LowerTriangular(){delete []A;}
        
};


void LowerTriangular::Set(int i,int j,int x)
{
    if (i>=j) A[(i*(i-1)/2)+j-1]=x; 
}

int LowerTriangular::Get(int i,int j)
{
    if (i>=j) return A[(i*(i-1)/2)+j-1];
    else return 0;
}
void LowerTriangular::Display()
{
    int i,j;
    for (i=1;i<=n;i++)       //traverse rows
    {
        for (j=1;j<=n;j++)   //traverse columns(cells)
        {
            if (i>=j) cout<<A[(i*(i-1)/2)+j-1]<<" ";
            else cout<<0<<" ";
        }
        cout<<endl;
    }

}

class UpperTriangular
{
    private:
        int n;
        int *A;
    public:
    UpperTriangular(int n)
    {
        this->n=n;
        A=new int[n*(n+1)/2];  // number of non zero elements =1+2+3+4+5+......+n=n(n+1)/2

    }
    void Set(int i,int j,int x);
    int Get(int i,int j);
    void Display();
    ~UpperTriangular(){delete []A;}
        
};

void UpperTriangular::Set(int i,int j,int x)
{
    if (j>=i) A[(j*(j-1)/2)+i-1]=x; 
}

int UpperTriangular::Get(int i,int j)
{
    if (j>=i) return A[(j*(j-1)/2)+i-1];
    else return 0;
}
void UpperTriangular::Display()
{
    int i,j;
    for (i=1;i<=n;i++)       //traverse rows
    {
        for (j=1;j<=n;j++)   //traverse columns(cells)
        {
            if (j>=i) cout<<A[(j*(j-1)/2)+i-1]<<" ";
            else cout<<0<<" ";
        }
        cout<<endl;
    }

}

class Symetric
{
    private:
        int n;
        int *A;
    public:
    Symetric(int n)
    {
        this->n=n;
        A=new int[n*(n+1)/2];  // number of non zero elements =1+2+3+4+5+......+n=n(n+1)/2

    }
    void Set(int i,int j,int x);
    int Get(int i,int j);
    void Display();
    ~Symetric(){delete []A;}
        
};

void Symetric::Set(int i,int j,int x)
{
    if (j>=i) A[(j*(j-1)/2)+i-1]=x; 
}

int Symetric::Get(int i,int j)
{
    if (j>=i) return A[(j*(j-1)/2)+i-1];
    else return 0;
}
void Symetric::Display()
{
    int i,j;
    for (i=1;i<=n;i++)       //traverse rows
    {
        for (j=1;j<=n;j++)   //traverse columns(cells)
        {
            if (j>=i) cout<<A[(j*(j-1)/2)+i-1]<<" ";
            else cout<<A[(i*(i-1)/2)+j-1]<<" ";
        }
        cout<<endl;
    }

}


int main()
{
    // diagonal matrix m[i,j]=0 if i<>j
    //to avoid space wastage in storing zero elements we take a single dimensional array
    Diagonal a=Diagonal(4);
    a.Set(1,1,5);a.Set(2,2,8);a.Set(3,3,9);a.Set(4,4,12);
    a.Get(1,1);
    a.Display();
    cout<<endl;

    //                                                          Lower triangle matrix
    // m[i,j]=0 if i<j 
    // m[i,j]<>0 if i>=j
    // number of non zero elements =1+2+3+4+5+......+n=n(n+1)/2
    // number of zero elements = total - number of non zero elements
    //                         = n^2-(n(n-1)/2) 
    //                         = (n^2-n)-2=n(n-1)/2



    //                                                          lower tri row major mapping

    // A[1,1|2,1|2,2|3,1|3,2|3,3|4,1|4,2|4,3|4,4]
    //  row1|  2    |      3    |       4
    
    // index(A[4][3]=(1+2+3)+2=8
    //                  |    |
    //          ->4th row    -> skking to 2nd element

    // index(A[5][4])=(1+2+3+4)+3

    // formula[i][j]==[i(i-1)/2]+j-1
    //              normal sum of n 
    //              natural numbers



    //                                                           lower tri column mapping
    //                                               11  12   13
    // A[1,1|2,1|3,1|4,1|5,1|2,2|3,2|4,2|5,2|3,3|4,3|5,3|4,4|5,4|5,5]
    //    col 1             |     2         |   3       |    4  | 5

    //A[4][4]=(5+4+3) +0=12
    //            |    |
    //   ->4th column   in 4th column

    //A[5][4]=(5+4+3) +1=13
    //A[5][3]=(5+4) +2=11

    //formula= [n+n-1+n-2+.....n-(j-2)]+(i-j)
    //to reach third column skip two cols(j-1) cols
    //one col has n-(j-1) elemts
    //so to skip the last column we get n-(j-2)

    ////formula= [n+n-1+n-2+.....n-(j-2)]+(i-j)
    // n is present j-1 times
    //n(j-1)-(1+2+3....+(j-2))+(i-j)
    //n(j-1)-[(j-2+1)(j-2)/2]+(i-j)
    //n(j-1)=[(j-1)(j-2)/2]+{i-j}

    LowerTriangular b=LowerTriangular(4);
    b.Set(1,1,5);b.Set(2,2,8);b.Set(3,3,9);b.Set(4,4,12);
    b.Set(2,1,5);b.Set(3,2,8);b.Set(4,3,9);b.Set(2,2,12);b.Set(3,1,5);b.Set(3,3,8);b.Set(4,1,9);b.Set(4,2,12);b.Set(4,4,9);
    b.Get(1,1);
    b.Display();
    cout<<endl;






    //                                              Upper triangular 
    // m[i,j]=0 if i<j 
    // m[i,j]<>0 if i>=j
    // lets say 5x5 matrix 
    //first row 5 elements + second row 4 element+.....+1
    //non-zero elements=n+n-1+n-2+....+2+1
    //         =(n+1)*n/2
    //zero=n^2-((n+1)*n/2)



    //                                            Upper triangular row mapping
    //A=[n]                                                   13
    //A=[1,1|1,2|1,3|1,4|1,5|2,2|2,3|2,4|2,5|3,3|3,4|3,5|4,4|4,5|5,5]
    //          row 1       |    2          |   3       |   4   | 5
    //index(A[4,5])=(5+4+3)+1
    //A[i,j]= n+n-1+n-(i-2)+j-i
    //=(j-1)n-(1+2+3+..(j-2))+j-1
    //=[(j-1)n-(j-1)(j-2)/2]+(j-i)



    //                                           Upper triangular row mapping
    //A=[1,1|1,2|2,2|1,3|2,3|3,3|1,4|2,4|3,4|4,4|1,5|2,5|3,5|4,5|5,5]
    //  col1|   2   |  3        |   4           | 5
    //index(A[4,5])=1+2+3+4)+3
    //       [i,j] =1+2+..j-1)+i-1
    //             =(j-1)j/2+i-1
    UpperTriangular c=UpperTriangular(4);
    c.Set(1,1,5);c.Set(1,2,8);c.Set(1,3,9);c.Set(1,4,12);c.Set(2,2,5);
    c.Set(2,3,5);c.Set(2,4,8);c.Set(3,3,9);c.Set(3,4,12);c.Set(4,4,5);
    c.Get(1,1);
    c.Display();
    cout<<endl;



    //                                              Symetric matrix
    //m[i,j]=m[j,i]
    // we can use upper/lower triangular matrix to reprsent it 
    Symetric d=Symetric(4);
    d.Set(1,1,5);d.Set(1,2,8);d.Set(1,3,9);d.Set(1,4,12);d.Set(2,2,5);
    d.Set(2,3,5);d.Set(2,4,8);d.Set(3,3,9);d.Set(3,4,12);d.Set(4,4,5);
    d.Get(1,1);
    d.Display();
    cout<<endl;


    //                                              Tridiagonal/Triband
    // main diagonal(regular diagonal)  -> i-j=0
    // lower diagonal(diagonal below main) -> i-j=1
    //upper (vice-versa) -> i-j=-1

    //m[i,j]=non zero if |i-j|<=1
    //m[i,j]=0 if |i-j|>1

    //n(non zero elements)=n+n-1+n-1=3n-2
    //zero elements n^2-3n-2
    // array representation ->frst upper then main then lower or reverse
    //A=[2,1|3,2|4,3|5,4|1,1|2,2|3,3|4,4|5,5|1,2|2,3|3,4|4,5]
    //      lower       |          main     |    upper
    //index(A[i,j])
    //if i-j=1
    //lower =j-1
    //if   i-j=0
    //main =n-1+i-1=n+i-2
    //if i-j=-1
    //uper=2n-1+i-1=2n+i-2



    //                                               toeplitz matrix
    //m[i,j]=m[i-1,j-1](basiclly diagonals are filled with same element)
    //thus its only necessary to store the first row and column
    //elements=2n-1
    //  0 1 2 3 4  5 6 7 8 
    //a[2,3,4,5,6,|7,8,9,10]
    //  upper tri   lower tri
    //     i<=j      i>j
    //case 1 i<=j
    //A[i,j]=j-i

    //case2 

    //      row     column
    //A(p[i,j])


    return 0;
}