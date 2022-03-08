#include <string>
#include <stdexcept>
using  namespace std;

namespace ariel{
    string mat(int c, int r, char Symbol1,char Symbol2){
        if(c%2==0 || r%2==0 || c<0 || r<0)
        {
            throw std::invalid_argument("only odd positive number can be a row or colum");
        }
        string s;
         if(c==1 && r==1)
        {
            s+=Symbol1;
            return s;
        }
        if(r==1)
        {
            for(int i=0;i<c;i++)
            {
                s+=Symbol1;
            }
            return s;
        }
         if(c==1)
        {
            for(int i=0;i<r;i++)
            {
                s+=Symbol1;
                s+="\n";
            }
            return s;
        }
        int i=0;
        int j=0;
        int maxr=r-1;
        int maxc=c-1;
        char** matrix= new char*[r];
        for (int row=0;row<r;row++)
        {
            matrix[row]=new char[c];
        }
        char symbol=Symbol1;
        while (maxr>=0 && maxc>=0)
        {
            if (i%2==0 && j%2==0)
            {
                symbol=Symbol1;
            }
            else
            {
                symbol=Symbol2;
            }
            
            for(int tempj=j;tempj<maxc;tempj++)
            {
                matrix[i][tempj]=symbol;
                matrix[maxr][tempj]=symbol;
            }
            for(int tempi=i;tempi<=maxr;tempi++)
            {
                matrix[tempi][j]=symbol;
                matrix[tempi][maxc]=symbol;
            }
            i++;
            j++;
            maxr--;
            maxc--;
        }
        for(int tempr=0;tempr<r;tempr++)
        {
            for(int tempc=0;tempc<c;tempc++)
            {
                s+=matrix[tempr][tempc];
            }
            s+="\n";
        }
        for (int row=0;row<r;row++)
        {
            delete[] matrix[row];
        }
        delete[] matrix;
        return s;
    };
}


