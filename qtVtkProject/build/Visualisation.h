#ifndef VISUALISATION_H
#define VISUALISATION_H

#include "DataStructure.h"

namespace dt
{
    class Visualisation
    {
    public:
        bool IsShowWireframe;

        Visualisation(bool isShowWireframe = false);
        ~Visualisation();

        void ReconstructIn3D(std::vector<Vector3D*>& dots, std::vector<std::tuple<int, int, int>*>& mesh);
    };
}

#endif