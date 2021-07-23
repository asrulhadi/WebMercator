// WebMercator.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <ios>
#include <iostream>
#include <iomanip>
#include "Projection.hpp"

int main()
{
    std::cout << "Hello World!\n";
    Projection* p = new Projection();
    double x1, y1, x2, y2, x3, y3;

    double x = 11199501.431051;
    double y = 472419.849542;
    double lat = 4.2399447 /*4.239944722387526*/ ;
    double lon = 100.6068331 /*100.606833055814107*/;
    DegMinSec latDMS = DegMinSec(4, 14, 23.801);
    DegMinSec lonDMS = DegMinSec(100, 36, 24.599);

    // https://epsg.io/transform#s_srs=3857&t_srs=4326&x=11199501.4310510&y=472419.8495420
    p->WGS84ToWebMercator(lat, lon, x1, y1);
    p->WGS84ToWebMercator(latDMS, lonDMS, x2, y2);
    p->WGS84ToWebMercator(DegMinSec(lat), DegMinSec(lon), x3, y3);

    std::cout.setf(std::ios::fixed);
    std::cout.precision(15);

    std::cout << "Input Dec: " << lat  << ", " << lon << std::endl;
    std::cout << "Input DMS: " << latDMS.asDecimalDegree() << ", " << lonDMS.asDecimalDegree() << std::endl;
    std::cout << "Input DMS: " << DegMinSec(lat).asDecimalDegree() << ", " << DegMinSec(lon).asDecimalDegree() << std::endl;

    std::cout.precision(7);
    std::cout << "Checking: " << x  << ", " << y  << std::endl;
    std::cout << "Main    : " << x1 << ", " << y1 << std::endl;
    std::cout << "Main DMS: " << x2 << ", " << y2 << std::endl;
    std::cout << "Main Dec: " << x3 << ", " << y3 << std::endl;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
