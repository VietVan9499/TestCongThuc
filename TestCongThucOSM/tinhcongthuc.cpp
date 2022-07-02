#include "tinhcongthuc.h"
#include "qdebug.h"
#include <QtMath>

TinhCongThuc::TinhCongThuc(QObject *parent)
    : QObject{parent}
{

}

// công thức độ -> rad
double TinhCongThuc::get_degrees(double &input)
{
    const double halfC = M_PI / 180;
    return input * halfC;
}

double TinhCongThuc::get_radian(double &input)
{
    const double halfC = 180 / M_PI;
    return input * halfC;
}



void TinhCongThuc::tinhCongThuc()
{
    double latRad = get_degrees(lat);
    double lonRad = get_degrees(lon);
    qDebug() << "latRad: "  << latRad;
    qDebug() << "lonRad: "  << lonRad;

    double d = 20;
    double R = 6371;
    double r = d / R;
    qDebug() << "r: "  << r;
    double latMin = latRad - r;
    double latMax = latRad + r;
    qDebug() << "latMin: "  << latMin;
    qDebug() << "latMax: "  << latMax;

    double latMinDegress = get_radian(latMin);
    double latMaxDegress = get_radian(latMax);
    qDebug() << "latMinDegress: "  << latMinDegress;
    qDebug() << "latMaxDegress: "  << latMaxDegress;

    double deltaLon = asin(sin(r) / cos(latRad));
    qDebug() << "deltaLon: "  << deltaLon;

    double lonMin = lonRad - deltaLon;

    double lonMax = lonRad + deltaLon;

    double lonMaxDegress = get_radian(lonMin);
    double lonMaxRadDegress = get_radian(lonMax);


    qDebug() << "latMinDegress: "  << latMinDegress;
    qDebug() << "latMaxDegress: "  << latMaxDegress;
    qDebug() << "lonMaxDegress: "    << lonMaxDegress;
    qDebug() << "lonMaxRadDegress: " << lonMaxRadDegress;

}
