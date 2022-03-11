#include <string>
#include <stdexcept>
#include <vector>
#include <iostream>
using  namespace std;

namespace ariel{
    string mat(int c, int r, char Symbol1,char Symbol2){
        const int minSymbol=33;
        const int maxSymbol=126;
        // make sure the inputs are correct
        if(c%2==0 || r%2==0 || c<0 || r<0) 
        {
            throw std::invalid_argument("only odd positive number can be a row or colum");
        }
        if(Symbol1<minSymbol || Symbol2<minSymbol || Symbol1>maxSymbol || Symbol2>maxSymbol)
        {
            throw std::invalid_argument("try diffrent symbol");
        }
        string s;
        // if the row or column is equal to 1 there is no reason to construct a vector
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
        // the first line
        int i=0; 
        // the first colum
        int j=0;
        // the last line
        int maxr=r-1;
        // the last colum
        int maxc=c-1;
        vector<vector<char>> matrix(r,vector<char>(c));
        char symbol=Symbol1;
        //enter to the loop as long as the row and column of the maximum is more then 0
        while (maxr>0 && maxc>0)
        {
            // if the row and column are even it is the first sign if not it is the second sign because we start from the first sign and then the second
            if (i%2==0 && j%2==0)
            {
                symbol=Symbol1;
            }
            else
            {
                symbol=Symbol2;
            }
            // first fill in the two extreme rows (top and down)
            for(int tempj=j;tempj<=maxc;tempj++)
            {
                matrix[i][tempj]=symbol;
                matrix[maxr][tempj]=symbol;
            }
            // then fill in the two extreme colum (right and left)
            for(int tempi=i;tempi<=maxr;tempi++)
            {
                matrix[tempi][j]=symbol;
                matrix[tempi][maxc]=symbol;
            }
            // reduce the matrix by one on each side
            i++;
            j++;
            maxr--;
            maxc--;
        }
        // copy the matrix to the string
        for(int tempr=0;tempr<r;tempr++)
        {
            for(int tempc=0;tempc<c;tempc++)
            {
                s+=matrix[tempr][tempc];
            }
            if (tempr!=r-1)
            {
                  s+="\n";
            }
        }
        return s;
    };
}


