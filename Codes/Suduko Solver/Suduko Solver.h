Appendix A: Sudoku puzzle solver code
#include <iostream>
#include <fstream>

using namespace std;

class error{
private:
   int total,row,col,box;
public:
   error(){total=0;row=0;col=0;box=0;}
   int rowerr(){return row++;}
   int colerr(){return col++;}
   int boxerr(){return box++;}
   int errtotal(){return (total+row+col+box);}
   int errrow(){return row;}
   int errcol(){return col;}
   int errbox(){return box;}
};

class sudoku{
private:
   int grid[9][9];
   int row,col;
public:
   void import();
   void Export();
   void print();
   bool solve(error &stats);
   bool checkempty(int(&grid)[9][9],int &row,int &col, error &stats);
   bool rowcheck(int (&grid)[9][9],int &row,int &col, int &number, error &stats);
   bool colcheck(int (&grid)[9][9],int &row,int &col, int &number, error &stats);
   bool boxcheck(int (&grid)[9][9],int &row,int &col, int &number, error &stats);
   bool numberclear(int(&grid)[9][9],int &row,int &col, int &number, error &stats);
};

int main(){
   sudoku GiveMeAnAPls;
   error stats;

   GiveMeAnAPls.import();
   cout<<endl;
   cout<<" Input: "<<endl;
   GiveMeAnAPls.print();
   GiveMeAnAPls.solve(stats);
   cout<<endl;
   cout<<" Output: "<<endl;
   GiveMeAnAPls.print();
   GiveMeAnAPls.Export();
   cout<<endl;
   cout<<"Total errors: "<<stats.errtotal()<<endl;
   cout<<"Box errors: "<<stats.errbox()<<endl;
   cout<<"Row errors: "<<stats.errrow()<<endl;
   cout<<"Column errors: "<<stats.errcol();
   cout<<endl;
}



/*imports the textfile "input.txt"*/
void sudoku::import(){
   ifstream input;
   input.open("input.txt");
   for(row=0;row<=8;row++){
       for(col=0;col<=8;col++){
           input>>grid[row][col];
       }
   }
   input.close();
}

/*exports to a new textfile "Export.txt"*/
void sudoku::Export(){
   ofstream export_("export.txt");
   for(row=0;row<=8;row++){
       for(col=0;col<=8;col++){
            export_<<grid[row][col]<<" ";
       }
   export_<<endl;
   }
export_.close();
}

/*prints the suduko grid*/
void sudoku::print(){
   for(row=0;row<=8;row++){
       for(col=0;col<=8;col++){
           cout<<" "<<grid[row][col];
       }
   cout<<endl<<endl;
   }
}

/*very top function, includes recursion*/
bool sudoku::solve(error &stats){
   int row,col;
   if(!checkempty(grid,row,col,stats))
       return true;

   /*found empty cell. Must fill;*/
   for(int number=1; number<10;number++){
       if (numberclear(grid,row,col,number,stats)){
           grid[row][col]=number;
           if (this->solve(stats)){
               return true;}
           else
               grid[row][col]=0;
           }
       }
   return false;
}

/*looks for empty cell empty cell*/
bool sudoku::checkempty(int(&grid)[9][9],int &row,int &col,error &stats){
   for(row=0;row<9;row++){
       for(col=0;col<9;col++){
           if (grid[row][col]==0){
               return true;
           }
       }
   }
   return false;
}

/*checks row for duplicates*/
bool sudoku::rowcheck(int (&grid)[9][9],int &row,int &col, int &number, error &stats){
   for(int i=0;i<9;i++){
       if(grid[row][i]==number){
           this->print();
           stats.rowerr();
           cout<<"ERROR #"<<stats.errtotal()<<": ROW: "<<row<<" NUM: "<<number<<" COL: "<<col<<"&"<<i<<endl;
           cout<<endl<<endl;
           return true;
       }
   }
   return false;
};

/*checks column for duplicates*/
bool sudoku::colcheck(int (&grid)[9][9],int &row,int &col, int &number, error &stats){
   for(int i=0;i<9;i++){
       if(grid[i][col]==number){
           this->print();
           stats.colerr();
           cout<<"ERROR #"<<stats.errtotal()<<": COL: "<<col<<" NUM: "<<number<<" ROW: "<<row<<"&"<<i<<endl;
           cout<<endl<<endl;
           return true;
       }
   }
   return false;
};

/*checks 3x3 region for duplicates*/
bool sudoku::boxcheck(int (&grid)[9][9],int &row,int &col, int &number, error &stats){
   int rowstart = row-row%3;
   int colstart = col-col%3;
   int region;

   for (int i=0;i<3;i++){
       for (int j=0;j<3;j++){
           if (grid[rowstart+i][colstart+j]==number){
               this->print();
               stats.boxerr();
               /*
               Format:
                   1   2   3
                   4   5   6
                   7   8   9
               */
               switch(rowstart){
                   case 0: switch (colstart){
                           case 0: region = 1; break;
                           case 3: region = 2; break;
                           case 6: region = 3; break;
                           } break;
                   case 3: switch (colstart){
                           case 0: region = 4; break;
                           case 3: region = 5; break;
                           case 6: region = 6; break;
                           } break;
                   case 6: switch (colstart){
                           case 0: region = 7; break;
                           case 3: region = 8; break;
                           case 6: region = 9; break;
                           } break;
                   }

               cout<<"ERROR #"<<stats.errtotal()<<": REG: "<<region<<" NUM: "<<number<<" AT : "<<row<<"&"<<col<<" AND "<< rowstart+i<<"&"<<colstart+j<<endl;
               cout<<endl<<endl;
               return true;
           }
       }
   }
   return false;
};

/*checks if cell is clear for row,column,and region*/
bool sudoku::numberclear(int (&grid)[9][9],int &row,int &col, int &number, error &stats){
   return (!boxcheck(grid,row,col,number,stats))&&(!rowcheck(grid,row,col,number,stats))&&(!colcheck(grid,row,col,number,stats));
};

