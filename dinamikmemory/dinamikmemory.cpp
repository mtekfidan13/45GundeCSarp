#include <iostream> 
#include <cstdlib> 
#include <ctime>
#include <algorithm>
#include <vector>
using namespace std;
// done

void createTubes(int);
void printTubes();
void printCountAndPrompt();
void getMovement(int*, int*);
int checkMoveIsValid(int, int);
void playMove(int, int, int);
bool checkFinish();
int a;
int tubes[1000][4];
int countPlay = 0;

int main() {

    int countOfLiquid;
    int move1, move2;
    char again;
    cout << "Kaç adet tüp oluşturmak istiyorsunuz: ";
    cin >> a;
    //int tubes[a][4];
    int en_az = 1;
    int en_fazla = a - 2;
    createTubes(a);
    while (1) {
        printTubes();
        printCountAndPrompt();
        getMovement(&move1, &move2);
        countOfLiquid = checkMoveIsValid(move1, move2);
        while (!countOfLiquid) {
            system("cls");
            printTubes();
            cout << "Please enter valid move!" << endl;
            printCountAndPrompt();
            getMovement(&move1, &move2);
            countOfLiquid = checkMoveIsValid(move1, move2);
        }
        playMove(move1, move2, countOfLiquid);
        system("cls");
        if (checkFinish()) {
            printTubes();
            cout << "GAME FINISHED!" << endl;
            cout << "Your Score is : " << countPlay << endl;
            cout << "Do you want to play again?(y/n)" << endl;
            cin >> again;
            if (again == 'y') {
                system("cls");
                createTubes(a);
            }
            else {
                cout << "Win!" << endl;
                break;
            }
        }

    }

    return 0;
}


void createTubes() {
    
    countPlay = 0;
    int en_az = 1;
    int en_fazla = a - 2;

    int arr1[a];
    int arr2[a * 4];

    // Set seed value for random number generator
    srand(time(NULL));

    // n-2. tüpe kadar doldurulmasını sağlayacak elemanların yerleştirilmesi için
    for (int s = 0; s < a; s++) {
        if (s < a - 2) {
            // pick a number that has not already appeared 4 times
            int num;
            bool valid = false;
            while (!valid) {
                num = rand() % (en_fazla - en_az + 1) + en_az;
                int count = 0;
                for (int i = 0; i < s; i++) {
                    for (int j = 0; j < 4; j++) {
                        if (arr2[i * 4 + j] == num) {
                            count++;
                            if (count == 4) {
                                break;
                            }
                        }
                    }
                    if (count == 4) {
                        break;
                    }
                }
                if (count < 4) {
                    valid = true;
                }
            }
            arr1[s] = num;
            for (int q = 0; q < 4; q++) {
                arr2[(s * 4) + q] = (q == 0) ? num : arr2[(s * 4) + q - 1];
            }
        }
        else {
            for (int q = 0; q < 4; q++) {
                arr2[(s * 4) + q] = 0;
            }
        }
    }

    // shuffle the elements except for the last 8 elements
    for (int t = 0; t < a * 4 - 8; t++) {
        int randomIndex = rand() % (a * 4 - t - 8) + t;
        int temp = arr2[t];
        arr2[t] = arr2[randomIndex];
        arr2[randomIndex] = temp;
    }

    // place back the last 8 elements as they were
    for (int i = a * 4 - 8; i < a * 4; i++) {
        arr2[i] = 0;
    }

    // populate the tubes array with the shuffled numbers
    for (int w = 0; w < a; w++) {
        for (int com = 0; com < 4; com++) {
            tubes[w][com] = arr2[(w * 4) + com];
        }
    }
}

void printTubes() {
    cout << endl;
    int arr2[a * 4];
    int k = 0;
    for (int i = 3; i >= 0; i--) {
        for (int j = 0; j < a; j++) {
            arr2[k] = tubes[j][i]; // tubes array'inden okunan sayıları arr2 array'ine kaydediyoruz
            cout << " | " << arr2[k] << " | ";
            k++;
        }
        cout << endl;
    }
    cout << "---------------------------------------------------------------" << endl; // blok açıldı ve kod düzgün çalışacak hale getirildi
}



void printCountAndPrompt() {
    cout << "Play count : " << countPlay << endl;
    cout << "Enter a move :";
}

void getMovement(int* move1, int* move2) {
    cin >> *move1 >> *move2;
    if (*move1 > 5 || *move1 < 1 || *move2>5 || *move2 < 1 || *move1 == *move2) {
        system("cls");
        printTubes();
        cout << "Please enter valid move!" << endl;
        printCountAndPrompt();
        getMovement(move1, move2);
    }
}




int checkMoveIsValid(int move1, int move2) {
    int countOfLiquid = 0;
    int topLiquid = 0;
    for (int i = 3; i >= 0; i--) {
        if (tubes[move1 - 1][i] != 0 && topLiquid == 0) {
            topLiquid = tubes[move1 - 1][i];
            countOfLiquid++;
        }
        else if (tubes[move1 - 1][i] == topLiquid && topLiquid != 0) {
            countOfLiquid++;
        }
        else if (tubes[move1 - 1][i] != topLiquid && topLiquid != 0) {
            break;
        }
    }
    for (int i = 3; i > 3 - countOfLiquid; i--) {
        if (tubes[move2 - 1][i] != 0) {
            return 0;
        }
    }
    return countOfLiquid;
}

void playMove(int move1, int move2, int countOfLiquid) {
    countPlay++;
    int tempCount = countOfLiquid;
    int temp;
    for (int i = 3; i >= 0; i--) {
        if (tubes[move1 - 1][i] != 0 && tempCount > 0) {
            temp = tubes[move1 - 1][i];
            tubes[move1 - 1][i] = 0;
            tempCount--;
        }
    }
    tempCount = countOfLiquid;
    for (int i = 0; i < 4; i++) {
        if (tubes[move2 - 1][i] == 0 && tempCount > 0) {
            tubes[move2 - 1][i] = temp;
            tempCount--;
        }
    }
}

bool checkFinish() {
    int temp;
    for (int i = 0; i < 5; i++) {
        temp = tubes[i][0];
        for (int j = 1; j < 4; j++) {
            if (tubes[i][j] != temp) {
                return false;
            }
        }
    }
    return true;
}