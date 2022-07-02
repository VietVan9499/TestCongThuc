#ifndef TINHCONGTHUC_H
#define TINHCONGTHUC_H

#include <QObject>

class TinhCongThuc : public QObject
{
    Q_OBJECT
public:
    explicit TinhCongThuc(QObject *parent = nullptr);
    double get_degrees(double &input);
    double get_radian(double &input);

    double lat =  16.06085;
    double lon = 108.222;
    void tinhCongThuc();
signals:

};

#endif // TINHCONGTHUC_H
