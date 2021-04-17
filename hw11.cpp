//Rahi, Alif
//211 21B/21F/22A/33A Homework 11

#include <iostream>
#include <cstdlib>
using namespace std;

bool ok(int q[8], int c){
    for(int i=0; i<c; i++){
        if( (c-i)== abs (q[c]-q[i]) || q[c]==q[i] )
            return false;
    }
    return true;
}

void print(int b[8], int &c){
      typedef char box[5][7];
      box bb, wb, wq, bq, *board[8][8];
        for(int i=0; i<5; i++)
            for(int j=0; j<7; j++){
                wb[i][j]=' ';
                bb[i][j]=char(219);
                wq[i][j]=' ';
                bq[i][j]=char(219);
        }

    wq[1][1]=char(219);
    wq[2][1]=char(219);
    wq[3][1]=char(219);
    wq[3][2]=char(219);
    wq[3][3]=char(219);
    wq[3][4]=char(219);
    wq[3][5]=char(219);
    wq[2][3]=char(219);
    wq[1][3]=char(219);
    wq[1][5]=char(219);
    wq[2][5]=char(219);

    bq[1][1]=' ';
    bq[2][1]=' ';
    bq[3][1]=' ';
    bq[3][2]=' ';
    bq[3][3]=' ';
    bq[3][4]=' ';
    bq[3][5]=' ';
    bq[2][3]=' ';
    bq[1][3]=' ';
    bq[1][5]=' ';
    bq[2][5]=' ';

    for(int i=0; i<8; i++)
        for(int j=0; j<8; j++)
            if((i+j)%2==0)
                board[i][j]=&wb;
            else
                board[i][j]=&bb;

    for(int p=0; p<8; p++){
        for(int q=0; q<8; q++){
            if(b[p]==q){
              if((p+q)%2==0)
                    board[b[p]][p]=&wq;
              else
                    board[b[p]][p]=&bq;
            }
        }
    }

    cout<<"Solution number: "<<c<<endl;
 
    cout<<"   ";
    for(int i=0; i<7; i++)
        cout<<' ';
    cout<<endl;

    for(int i=0; i<8; i++)
        for(int k=0; k<5; k++){
            cout<<"  "<<char(179);
            for(int j=0; j<8; j++)
                for(int l=0; l<7; l++)
                    cout<<(*board[i][j])[k][l];
                    cout<<char(179)<<endl;
            
    }
     
    cout<<"   ";
    for(int i=0; i<7*8; i++)
        cout<<char(196);
        cout<<endl;

             c++;
}

void backtrack(int &c){
    c--;
    if(c==-1) exit(0);
}

int main(){
    int q[8];
    q[0]=0;
    int c=0, counter =1;
    while(c>=0){
        c++;
        if(c==8){
            print(q,counter);
            backtrack(c);
        }
        else{
            q[c]=-1;
        }

        while(c>=0){
            q[c]++;
            if(q[c]==8) backtrack(c);
            else{
                if(ok(q,c))
                    break;
                   }
        }
    }
    return 0;
}
