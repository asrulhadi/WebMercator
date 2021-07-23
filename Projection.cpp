#include <cmath>
#include <iomanip>
#include <iostream>

#include "Projection.hpp"

constexpr double DEG_to_RAD = M_PI / 180.0;
constexpr double M_PI_2 = M_PI / 2;
constexpr double M_PI_4 = M_PI / 4;

/// <summary>
/// Projection from EPSG 4326 (WGS84) to EPSG 3857 (WebMercator)
/// </summary>
/// <param name="lattitude"></param>
/// <param name="longitude"></param>
/// <param name="x"></param>
/// <param name="y"></param>
/// <returns></returns>
bool Projection::WGS84ToWebMercator(double lattitude, double longitude, double& x, double& y)
{
	// check the limit
	if ((lattitude < -85.0511) || (85.0511 < lattitude)) return false;
	if ((longitude < -180) || (180 < longitude)) return false;

	// constant - World circumce
	// based on WebMercator - EPSG3857
	//  Semi-major axis a = 6378137.0 meters
	//  Semi-minor axis b = 6356752.3142 meters
	// wmNum = a * M_PI
	//double wmNum = 20037508.34;
	double wmNum = M_PI * 6378137.0;

	std::cout << std::fixed << std::setprecision(20) << "Longitude: " << longitude << std::endl;
	// TODO: Add your implementation code here.
	x = longitude *  wmNum / 180.0;
	y = std::log(std::tan((90 + lattitude) * M_PI / 360)) / (M_PI / 180);
	y = y * wmNum / 180;

	return true;
}

bool Projection::WGS84ToWebMercator(DegMinSec lattitude, DegMinSec longitude, double& x, double& y)
{
	double dlat = lattitude.asDecimalDegree();
	double dlon = longitude.asDecimalDegree();
	// check the limit
	if ((dlat < -85.0511) || (85.0511 < dlat)) return false;
	if ((dlon < -180) || (180 < dlon)) return false;

	// constant - World circumce
	// based on WebMercator - EPSG3857
	//  Semi-major axis a = 6378137.0 meters
	//  Semi-minor axis b = 6356752.3142 meters
	// wmNum = a * M_PI
	//double wmNum = 20037508.34;
	double earthRadius = 6378137.0;

	std::cout << std::fixed << std::setprecision(20) << "Longitude: " << longitude.asDecimalDegree() << std::endl;
	// TODO: Add your implementation code here.
	x = longitude.asRadian() * earthRadius;
	y = std::log(std::tan(M_PI_4 + lattitude.asRadian() / 2.0)) * earthRadius;

	return true;
}
