#include <iostream>
#include <vector>
using namespace std;

class Chandrayaan3 {

    int posX, posY, posZ;
    char heading;

public:
    Chandrayaan3() {
        posX = posY = posZ = 0;
        heading = 'O';
    }

    Chandrayaan3(int x, int y, int z, char dir) {
        posX = x;
        posY = y;
        posZ = z;
        heading = dir;
    }

    int getX() {
        return posX;
    }

    int getY() {
        return posY;
    }

    int getZ() {
        return posZ;
    }

    char getHeading() {
        return heading;
    }

    void addToX(int a) {
        posX += a;
    }

    void addToY(int a) {
        posY += a;
    }

    void addToZ(int a) {
        posZ += a;
    }

    void setHeading(char a) {
        heading = a;
    }

    void printFinalStatus() {
        cout << "Final Coordinates : (" << posX << "," << posY << "," << posZ << ")" << endl;
        cout << "Final Heading : " << heading << endl;
    }
};

int main() {

    cout << "Enter initial coordinates (x, y, z)" << endl;
    int initialX, initialY, initialZ;
    cout << "Enter x coordinate : ";
    cin >> initialX;
    cout << "Enter y coordinate : ";
    cin >> initialY;
    cout << "Enter z coordinate : ";
    cin >> initialZ;

    char initialHeading, tempHeading;
    cout << "Enter initial heading : ";
    cin >> initialHeading;

    Chandrayaan3 rover(initialX, initialY, initialZ, initialHeading);

    cout << "Enter commands and enter 0 after inputting all commands to terminate input : " << endl;

    vector<char> commands;

    while (1) {
        char cmd;
        cin >> cmd;
        if (cmd == '0') {
            break;
        }
        else {
            commands.push_back(cmd);
        }
    }

    for (char cmd : commands) {

        switch (cmd) {
        case 'u':
            rover.setHeading('U');
            break;

        case 'd':
            rover.setHeading('D');
            break;

        case 'l':
            tempHeading = rover.getHeading();
            if (tempHeading == 'N') {
                rover.setHeading('W');
            }
            else if (tempHeading == 'E') {
                rover.setHeading('N');
            }
            else if (tempHeading == 'S') {
                rover.setHeading('E');
            }
            else if (tempHeading == 'W') {
                rover.setHeading('S');
            }
            else if (tempHeading == 'U') {
                rover.setHeading('N');
            }
            else if (tempHeading == 'D') {
                rover.setHeading('S');
            }
            break;

        case 'r':

            tempHeading = rover.getHeading();
            if (tempHeading == 'N') {
                rover.setHeading('E');
            }
            else if (tempHeading == 'E') {
                rover.setHeading('S');
            }
            else if (tempHeading == 'S') {
                rover.setHeading('W');
            }
            else if (tempHeading == 'W') {
                rover.setHeading('N');
            }
            else if (tempHeading == 'U') {
                rover.setHeading('S');
            }
            else if (tempHeading == 'D') {
                rover.setHeading('N');
            }
            break;

        case 'f':

            tempHeading = rover.getHeading();

            if (tempHeading == 'N') {
                rover.addToY(1);
            }
            else if (tempHeading == 'E') {
                rover.addToX(1);
            }
            else if (tempHeading == 'S') {
                rover.addToY(-1);
            }
            else if (tempHeading == 'W') {
                rover.addToX(-1);
            }
            else if (tempHeading == 'U') {
                rover.addToZ(1);
            }
            else if (tempHeading == 'D') {
                rover.addToZ(-1);
            }

            break;

        case 'b':
            tempHeading = rover.getHeading();

            if (tempHeading == 'N') {
                rover.addToY(-1);
            }
            else if (tempHeading == 'E') {
                rover.addToX(-1);
            }
            else if (tempHeading == 'S') {
                rover.addToY(1);
            }
            else if (tempHeading == 'W') {
                rover.addToX(1);
            }
            else if (tempHeading == 'U') {
                rover.addToZ(-1);
            }
            else if (tempHeading == 'D') {
                rover.addToZ(1);
            }

        default:
            break;
        }
    }

    cout << "\nFinal Configuration of Chandrayaan3\n" << endl;

    rover.printFinalStatus();
}

