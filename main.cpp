#include <iostream>
#include <string>

using namespace std;
//gb var
char grid[3][3]={{'1','2','3'},{'4','5','6'},{'7','8','9'}};
char cur_marker;
int cur_player;

void draw() {
    cout<<" "<<grid[0][0]<<" | "<<grid[0][1]<<" | "<<grid[0][2]<<endl;
    cout<<"---|---|---"<<endl;
    cout<<" "<<grid[1][0]<<" | "<<grid[1][1]<<" | "<<grid[1][2]<<endl;
    cout<<"---|---|---"<<endl;
    cout<<" "<<grid[2][0]<<" | "<<grid[2][1]<<" | "<<grid[2][2]<<endl;
}

bool placeMarker(int slot) {
    int row=(slot-1)/3;
    int col=(slot-1)%3;
    if (grid[row][col] != 'X' && grid[row][col] != 'O') {
        grid[row][col] = cur_marker;
        return true;
    } else return false;
}

int winner() {
    for (int i=0;i<3;i++) {
        if(grid[i][0]==grid[i][1]&&grid[i][1]==grid[i][2]) return cur_player;
    }
    for(int i=0;i<3;i++) {
        if (grid[0][i] == grid[1][i] && grid[1][i] == grid[2][i]) return cur_player;
    }
    if(grid[0][0]==grid[1][1]&&grid[1][1]==grid[2][2]) return cur_player;
    if(grid[0][2]==grid[1][1]&&grid[1][1]==grid[2][0]) return cur_player;
    return 0;//continue
}

void swap() {
    if(cur_marker=='X') cur_marker = 'O';
    else cur_marker='X';

    if(cur_player==1) cur_player = 2;
    else cur_player=1;
}

void game() {
    cout<<"Player 1, choose your marker(X or O): ";
    char marker_p1;
    cin>>marker_p1;

    cur_player=1;
    cur_marker=marker_p1;
    draw();
    int player_won;

    for(int i=0;i<9;i++) {
        cout<<"It's player "<<cur_player<<"'s turn. Enter your slot: ";
        int slot;
        cin>>slot;

        if(slot<1||slot>9) {
            cout << "Invalid slot! Try again.\n";
            i--;
            continue;
        }

        if (!placeMarker(slot)) {
            cout<<"It's occupied! Try another one.\n";
            i--;
            continue;
        }
        draw();
        player_won=winner();
        if(player_won==1) { cout<<"Player 1 wins!\n"; return; }
        else if(player_won==2) { cout<<"Player 2 wins!\n"; return; }

        swap();
    }
    cout<<"That's a draw!\n";
}

int main() {
    game();
    return 0;
}