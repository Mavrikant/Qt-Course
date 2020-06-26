/* scratchpadwizard.cpp */
#include "scratchpadwidget.h"

ScratchpadWidget::ScratchpadWidget(QWidget *parent) : QWidget(parent)
{
    m_drawFlag = false;
}
void ScratchpadWidget::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
    QPainter painter(this);
    painter.setRenderHints(QPainter::Antialiasing | QPainter::SmoothPixmapTransform);

    QPen pen(Qt::black);
    pen.setWidth(3);
    painter.setPen(pen);

    for (QPolygon polyline : m_polylines)
        painter.drawPolyline(polyline);
    painter.drawPolyline(m_polyline);
}
void ScratchpadWidget::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton)
    {
        m_polyline.clear();
        m_polyline.append(event->pos());
        m_drawFlag = true;
    }
}
void ScratchpadWidget::mouseReleaseEvent(QMouseEvent *event)
{
    Q_UNUSED(event);
    if (m_drawFlag)
    {
        m_polylines.append(m_polyline);
        m_drawFlag = false;
    }
}
void ScratchpadWidget::mouseMoveEvent(QMouseEvent *event)
{
    if (m_drawFlag)
    {
        m_polyline.append(event->pos());
        update();
    }
}
