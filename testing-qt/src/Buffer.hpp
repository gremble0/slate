#pragma once

#include <QApplication>
#include <QWidget>

class Buffer : public QWidget
{
    Q_OBJECT

public:
    Buffer(QWidget *parent = nullptr);
};
