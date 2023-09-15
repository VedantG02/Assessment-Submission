#include <iostream>
#include <vector>
using namespace std;

class Chandrayaan3 {

    int positionX, positionY, positionZ;
    char orientation;

public:
    Chandrayaan3() {
        positionX = positionY = positionZ = 0;
        orientation = 'N';
    }

    Chandrayaan3(int x, int y, int z, char dir) {
        positionX = x;
        positionY = y;
        positionZ = z;
        orientation = dir;
    }

    int getX() {
        return positionX;
    }

    int getY() {
        return positionY;
    }

    int getZ() {
        return positionZ;
    }

    char getOrientation() {
        return orientation;
    }

    void addToX(int a) {
        positionX += a;
    }

    void addToY(int a) {
        positionY += a;
    }

    void addToZ(int a) {
        positionZ += a;
    }

    void setOrientation(char dir) {
        orientation = dir;
    }

    void printFinalStatus() {
        cout << "Final Coordinates: (" << positionX << "," << positionY << "," << positionZ << ")" << endl;
        cout << "Final Orientation: " << orientation << endl;
    }
};

int main() {

    cout << "Enter initial coordinates (x, y, z)" << endl;
    int startX, startY, startZ;
    cout << "Enter x coordinate: ";
    cin >> startX;
    cout << "Enter y coordinate: ";
    cin >> startY;
    cout << "Enter z coordinate: ";
    cin >> startZ;

    char initialOrientation, tempOrientation;
    cout << "Enter initial orientation (N, E, S, W, U, D): ";
    cin >> initialOrientation;

    Chandrayaan3 rover(startX, startY, startZ, initialOrientation);

    cout << "Enter commands and enter '0' after inputting all commands to terminate input:" << endl;

    vector<char> commands;

    while (true) {
        char command;
        cin >> command;
        if (command == '0') {
            break;
        } else {
            commands.push_back(command);
        }
    }

    for (char cmd : commands) {
        switch (cmd) {
            case 'u':
                rover.setOrientation('U');
                break;

            case 'd':
                rover.setOrientation('D');
                break;

            case 'l':
                tempOrientation = rover.getOrientation();
                if (tempOrientation == 'N') {
                    rover.setOrientation('W');
                } else if (tempOrientation == 'E') {
                    rover.setOrientation('N');
                } else if (tempOrientation == 'S') {
                    rover.setOrientation('E');
                } else if (tempOrientation == 'W') {
                    rover.setOrientation('S');
                } else if (tempOrientation == 'U') {
                    rover.setOrientation('N');
                } else if (tempOrientation == 'D') {
                    rover.setOrientation('S');
                }
                break;

            case 'r':
                tempOrientation = rover.getOrientation();
                if (tempOrientation == 'N') {
                    rover.setOrientation('E');
                } else if (tempOrientation == 'E') {
                    rover.setOrientation('S');
                } else if (tempOrientation == 'S') {
                    rover.setOrientation('W');
                } else if (tempOrientation == 'W') {
                    rover.setOrientation('N');
                } else if (tempOrientation == 'U') {
                    rover.setOrientation('S');
                } else if (tempOrientation == 'D') {
                    rover.setOrientation('N');
                }
                break;

            case 'f':
                tempOrientation = rover.getOrientation();
                if (tempOrientation == 'N') {
                    rover.addToY(1);
                } else if (tempOrientation == 'E') {
                    rover.addToX(1);
                } else if (tempOrientation == 'S') {
                    rover.addToY(-1);
                } else if (tempOrientation == 'W') {
                    rover.addToX(-1);
                } else if (tempOrientation == 'U') {
                    rover.addToZ(1);
                } else if (tempOrientation == 'D') {
                    rover.addToZ(-1);
                }
                break;

            case 'b':
                tempOrientation = rover.getOrientation();
                if (tempOrientation == 'N') {
                    rover.addToY(-1);
                } else if (tempOrientation == 'E') {
                    rover.addToX(-1);
                } else if (tempOrientation == 'S') {
                    rover.addToY(1);
                } else if (tempOrientation == 'W') {
                    rover.addToX(1);
                } else if (tempOrientation == 'U') {
                    rover.addToZ(-1);
                } else if (tempOrientation == 'D') {
                    rover.addToZ(1);
                }
                break;

            default:
                break;
        }
    }

    cout << "\nFinal Configuration of Chandrayaan-3:\n" << endl;

    rover.printFinalStatus();
}

