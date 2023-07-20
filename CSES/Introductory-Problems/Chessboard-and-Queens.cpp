#include<bits/stdc++.h>

using namespace std;

int total_count = 0;
int position[8];

void process(string board[8], int level){//level is the column
    if(level==8){
        total_count++;//board is valid
        return;
    }
    else{
        for(int ctr1=0;ctr1<8;ctr1++){//loop through each row
            if(board[level][ctr1]=='*') continue;
            position[level] = ctr1;
            //check if iz valid
            bool valid = true;
            for(int ctr2=0;ctr2<level;ctr2++){
                //go through each position before current
                if(ctr1==position[ctr2]){//they are in the same row
                    valid = false;
                    break;
                }
                if(abs(ctr1-position[ctr2])==abs(ctr2-level)){
                    valid = false;
                    break;
                }
            }
            if(valid){
                //go a deeper level
                level++;
                process(board,level);
                level--;
            }
        }
    }
}

int main(){
    string board[8];
    for(int ctr1=0;ctr1<8;ctr1++){
        cin>>board[ctr1];
    }
    process(board,0);
    cout<<total_count;
    return 0;
}
