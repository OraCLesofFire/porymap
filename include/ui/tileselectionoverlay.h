#ifndef TILESELECTIONOVERLAY_H
#define TILESELECTIONOVERLAY_H

#include <QGraphicsItem>
#include <QPainter>
#include <QSet>
#include <QPoint>

class TileSelectionOverlay : public QGraphicsItem
{
public:
    TileSelectionOverlay(const QSize &tileSize) : m_tileSize(tileSize) {}

    QRectF boundingRect() const override {
        return QRectF(0, 0, 0, 0); // not used by our manual paint path — flagging to verify once it builds
    }

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *) override {
        painter->save();
        painter->setPen(QPen(QColor(255, 255, 255), 1));
        painter->setBrush(QColor(255, 255, 255, 80));
        for (const QPoint &tile : m_selection) {
            painter->drawRect(QRectF(tile.x() * m_tileSize.width(), tile.y() * m_tileSize.height(),
                                      m_tileSize.width(), m_tileSize.height()));
        }
        painter->restore();
    }

    void setSelection(const QSet<QPoint> &selection) { m_selection = selection; }

private:
    QSize m_tileSize;
    QSet<QPoint> m_selection;
};

#endif