#include<iostream>
#include<cmath>
#include<limits.h>

using namespace std;

//A* alogrithm to solve 8 puzzle problem

//Global variable to keep track of number of moves taken
int g = 0;

void Print(int puzzle[]){
    for(int i = 0; i < 9; i++){
        if(i % 3 == 0) cout << '\n';
        if(puzzle[i] == -1) cout << "_ ";
        else cout << puzzle[i] << " ";
    }
    cout << "\n\n";
}

void moveLeft(int start[], int position){
    swap(start[position], start[position - 1]);
}

void moveRight(int start[], int position){
    swap(start[position], start[position + 1]);
}

void moveUp(int start[], int position){
    swap(start[position], start[position - 3]);
}

void moveDown(int start[], int position){
    swap(start[position], start[position + 3]);
}


void Copy(int temp[], int real[]){
    for(int i = 0; i < 9; i++) temp[i] = real[i];
}


/*
For every number find difference in position in goal state and inital state
Difference in vertical + difference in horizontal i.e Manhattan Distance
*/
int heuristic(int start[], int goal[]){
    int h = 0;    
    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
            if (start[i] == goal[j] && start[i] != -1){
                h += abs((j - i) / 3) + abs((j - i) % 3);
            }
        }
    }
    return h + g;
}


void moveTile(int start[], int goal[]){
    int emptyAt = 0;
    for(int i = 0; i < 9; i++){
        if(start[i] == -1){
            emptyAt = i;
            break;
        }
    }

    int t1[9],t2[9],t3[9],t4[9],f1 = INT_MAX,f2 = INT_MAX,f3 = INT_MAX,f4 = INT_MAX;
    Copy(t1, start);
    Copy(t2, start);
    Copy(t3, start);
    Copy(t4, start);

    int row = emptyAt / 3;
    int col = emptyAt % 3;

    if(col - 1 >= 0){
        moveLeft(t1, emptyAt);
        f1 = heuristic(t1, goal);
    }
    
    if(col + 1 < 3){
        moveRight(t2, emptyAt);
        f2 = heuristic(t2, goal);
    }

    if(row + 1 < 3){
        moveDown(t3, emptyAt);
        f3 = heuristic(t3, goal);
    }
    
    if(row - 1 >= 0){
        moveUp(t4, emptyAt);
        f4 = heuristic(t4, goal);
    }
    
    
    //Find Least Heuristic State and Make the Move
    if(f1 <= f2 && f1 <= f3 && f1 <= f4 ){
        moveLeft(start, emptyAt);
    }
    else if(f2 <= f1 && f2 <= f3 && f2 <= f4 ){
        moveRight(start, emptyAt);
    }
    else if(f3 <= f1 && f3 <= f2 && f3 <= f4 ){
        moveDown(start, emptyAt);
    }
    else{
        moveUp(start, emptyAt);
    }
}

void solveEight(int start[], int goal[]){
    g++;
    //Move Tile
    moveTile(start, goal);
    Print(start);
    //Get Heuristic Value
    int f = heuristic(start, goal);
    if(f == g){
        cout << "Solved in " << f << " moves\n";
        return;
    }
    solveEight(start, goal);
}

/*
Count the number of inversion
If odd then unsolvable
else solvable
*/

bool solvable(int start[]){
    int invrs = 0;
    for(int i = 0; i < 9; i++){
        //1 2 3 -1 4 6 7 5 8

        if(start[i] <= 1) continue;
        for(int j = i + 1; j < 9; j++){
            if(start[j] == -1) continue;
            if(start[i] > start[j]) invrs++;
        }
    }
    return invrs & 1 ? false : true;
}

// void printImpossible(){
//     cout << R"(|￣￣￣￣￣￣￣￣￣￣￣|
//  ITS IMPOSSIBLE TO SOLVE
// |＿＿＿＿＿＿＿＿＿＿＿|
//    (\__/)  ||
//    (•ㅅ•)  ||
//    /  　  づ
// )" << '\n';
// }

int main(){
    int start[9];
    int goal[9];
    cout << "Enter the start state:(Enter -1 for empty):";
    for(int i = 0; i < 9; i++){
        cin >> start[i];
    }
    cout << "Enter the goal state:(Enter -1 for empty):";
    for(int i = 0; i < 9; i++){
        cin >> goal[i];
    }

    // verify if possible to solve
    Print(start);
    if(solvable(start)) solveEight(start, goal);
    else cout << "\nImpossible To Solve\n";

    return 0;
}

/*
Test Cases
1 2 3 -1 4 6 7 5 8
1 2 3 4 5 6 7 8 -1

1 2 3 4 8 -1 7 6 5
1 2 3 4 5 6 7 8 -1


1 2 3 4 5 6 -1 8 7
1 2 3 4 5 6 7 8 -1

*/
