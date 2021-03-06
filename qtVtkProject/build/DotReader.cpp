#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include "Dot.h"

using namespace std;
using namespace dt;

vector<Vector3D*> DotReader::GetDot()
{
    vector<Vector3D*> dots = vector<Vector3D*>();

    string filename;
    cout << "Enter name of file in resource directory: ";
    cin >> filename;
    filename = "ile.txt";
    ifstream file(filename);

    double x = 0, y = 0, z = 0;
    int red = 0, green = 0, blue = 0;
    char hex;

    //each row start with a "#"
    while (file >> hex)
    {
        file >> x >> y >> z >> red >> green >> blue;
        Vector3D* dot = new Vector3D(x = (x/100), y = (y/100), z = (z/100), (uint8_t)red, (uint8_t)green, (uint8_t)blue);
        dots.push_back(dot);
    }

    file.close();

    return dots;
}