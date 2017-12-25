#include <iostream>

using namespace std;
int row,col;
class matrix
{
    int a[10][10];
public:
    void ele()
    {int i,j;
        cout<<"Enter "<<row*col<<"elements of the matrix:";
        for(i=0;i<row;i++)
        {
            for(j=0;j<col;j++)
                cin>>a[i][j];
        }
    }
    matrix(int p=0);


    matrix operator +(matrix &m)
    {int i,j;
        matrix m2;
        for(i=0;i<row;i++)
        {
            for(j=0;j<col;j++)
                m2.a[i][j]=a[i][j]+m.a[i][j];
        }
        return m2;
    }
    void display()
    {
        int i,j;
        for(i=0;i<row;i++)
        {
            for(j=0;j<col;j++)
            {
                cout<<a[i][j]<<"\t";
            }
            cout<<"\n";
        }
    }
};
matrix::matrix(int p)
{
    int i,j;
        for(i=0;i<row;i++)
        {
            for(j=0;j<col;j++)
            {
                a[i][j]=p;
            }
        }

}
int main()
{
    cout<<"Enter number of rows and coloumns of the matrix:";
    cin>>row>>col;
    matrix m1,m2(2),m3;
    m1.ele();
    m1.display();
    m3=m1+m2;
    cout<<"Matrix after adding 2:\n";
    m3.display();

    return 0;
}