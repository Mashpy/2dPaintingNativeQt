#include <QtGui>
#include "helper.h"

//! [0]
Helper::Helper()
{
    QLinearGradient gradient(QPointF(50, -20), QPointF(80, 20));
    gradient.setColorAt(0.0, Qt::red);
    gradient.setColorAt(1.0, Qt::blue);

    background = QBrush(QColor(64, 32, 64));
    circleBrush = QBrush(gradient);
    circlePen = QPen(Qt::black);
    circlePen.setWidth(1);
    textPen = QPen(Qt::white);
    textFont.setPixelSize(50);
}
//! [0]

//! [1]
void Helper::paint(QPainter *painter, QPaintEvent *event, int elapsed)
{
    painter->fillRect(event->rect(), background);
    painter->translate(100, 100);
//! [1]

//! [2]
    painter->save();
    painter->setBrush(circleBrush);
    painter->setPen(circlePen);
    painter->rotate(elapsed * 0.030);

    qreal r = elapsed/1000.0;
    int n = 30;
    for (int i = 0; i < n; ++i) {
        painter->rotate(30);
        qreal radius = 0 + 120.0*((i+r)/n);
        qreal circleRadius = 1 + ((i+r)/n)*20;
        painter->drawEllipse(QRectF(radius, -circleRadius,
                                    circleRadius*2, circleRadius*2));
    }
    painter->restore();
//! [2]

//! [3]
    painter->setPen(textPen);
    painter->setFont(textFont);
    painter->drawText(QRect(-50, -50, 100, 100), Qt::AlignCenter, "Qt");
}
//! [3]
