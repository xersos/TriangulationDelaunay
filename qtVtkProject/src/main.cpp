#include <iostream>
#include <string>
#include <vector>
#include "Dot.h"
#include "Triangulation.h"
#include "Visualisation.h"

using namespace std;
using namespace dt;

void ClearMemory(vector<Vector3D*>&, vector<tuple<int, int, int>*>&);

int main()
{
    try
    {
        int cmd;
        cout << "Choose dot source by key in [1/2]:\n 1 = Random generator\n 2 = Dot file\n";
        cin >> cmd;

        vector<Vector3D*> dots
            = cmd == 1
            ? DotGenerator().GetSphericalDots()
            : DotReader().GetDot();

        DelaunayTriangulation triangulation = DelaunayTriangulation();
        vector<tuple<int, int, int>*> mesh = triangulation.GetTriangulationResult(dots);
        cout << triangulation.GetStatistics() << endl;

        Visualisation visualization = Visualisation(false);
        visualization.ReconstructIn3D(dots, mesh);

        ClearMemory(dots, mesh);
    }
    catch (exception e)
    {
        cout << e.what() << endl;
        system("pause");
    }

    return 0;
}

void ClearMemory(vector<Vector3D*>& dots, vector<tuple<int, int, int>*>& mesh)
{
    vector<Vector3D*>::iterator itDots;
    for (itDots = dots.begin(); itDots != dots.end(); itDots++)
    {
        delete* itDots;
    }

    vector<tuple<int, int, int>*>::iterator itMesh;
    for (itMesh = mesh.begin(); itMesh != mesh.end(); itMesh++)
    {
        delete* itMesh;
    }
}