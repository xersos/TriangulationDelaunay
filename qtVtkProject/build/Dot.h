#ifndef DOT_H
#define DOT_H

#include "DataStructure.h"

namespace dt
{
    class DotGenerator
    {
    private:
        Vector3D* GetRandomDot();
        Vector3D* GetRandomDotEvenlyDistributed();
    public:
        std::vector<Vector3D*> GetSphericalDots();
    };

    class DotReader
    {
    public:
        std::vector<Vector3D*> GetDot();
    };
}

#endif